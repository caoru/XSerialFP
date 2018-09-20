
#include <vector>

#include <stdio.h>

#include "XSerialFP.h"
#include "XSFPLog.h"
#include "XSFPFF320.h"

typedef struct {
  char name[128];
  int counter;
  int value;
} XSFPFF320UpdataData;

void ffAPIUpdateCallback(double step, void *tag); // FFAPI Constructor
std::vector<XSFPFF320UpdataData *> g_update_data;

XSFPFF320::XSFPFF320()
  : plugin_id_(XPLM_NO_PLUGIN_ID),
    version_(0),
    initialized_(false)
{
}

XSFPFF320::~XSFPFF320()
{
}

bool XSFPFF320::Initialize(void)
{
  plugin_id_ = XPLMFindPluginBySignature(XPLM_FF_SIGNATURE);
  if (plugin_id_ == XPLM_NO_PLUGIN_ID) return false;

  XPLMSendMessageToPlugin(plugin_id_, XPLM_FF_MSG_GET_SHARED_INTERFACE, &api_);

  version_ = api_.DataVersion();

  if (api_.DataAddUpdate != NULL) {
    void *tag = (void*)"ffa320connector";
    api_.DataAddUpdate(&ffAPIUpdateCallback, tag);

    initialized_ = true;

    return true;
  }

  return false;
}

int XSFPFF320::GetValueIntByName(const char *name)
{
  int ffid;
  int value;

  ffid = api_.ValueIdByName(name);
  api_.ValueGet(ffid, &value);

  return value;
}

void XSFPFF320::SetValueIntByName(const char *name, int value)
{
  int ffid;

  ffid = api_.ValueIdByName(name);
  api_.ValueSet(ffid, &value);
}

float XSFPFF320::GetValueFloatByName(const char *name)
{
  int ffid;
  float value;

  ffid = api_.ValueIdByName(name);
  api_.ValueGet(ffid, &value);

  return value;
}

void XSFPFF320::GetValueFloatByName(const char *name, float value)
{
  int ffid;

  ffid = api_.ValueIdByName(name);
  api_.ValueSet(ffid, &value);
}

void XSFPFF320AddUpdateData(const char *name, int value, int counter)
{
  XSFPFF320UpdataData *data;

  data = (XSFPFF320UpdataData *)malloc(sizeof(XSFPFF320UpdataData));
  if (data == NULL) return ;

  strcpy(data->name, name);
  data->counter = counter;
  data->value = value;

  g_update_data.push_back(data);;
}

void ffAPIUpdateCallback(double step, void *tag)
{
  std::vector<XSFPFF320UpdataData *>::iterator iter = g_update_data.begin();
  XSFPFF320UpdataData *item;

  if (!serialfp.ff320_api().initialized()) return;

  for (iter = g_update_data.begin(); iter != g_update_data.end(); )
  {
    item = (XSFPFF320UpdataData *)(*iter);

    if (item->counter <= 0)
    {
      serialfp.ff320_api().SetValueIntByName(item->name, item->value);
      iter = g_update_data.erase(iter);
      free(item);
    }
    else
    {
      item->counter--;
      iter++;
    }
  }
}

