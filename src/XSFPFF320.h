#ifndef _XSFPFF320_H_
#define _XSFPFF320_H_

#include "XPLMPlugin.h"

#include "SharedValue.h"

class XSFPFF320
{
public:
  XSFPFF320();
  ~XSFPFF320();

public:
  bool Initialize(void);

  int GetValueIntByName(const char *name);
  void SetValueIntByName(const char *name, int value);

  float GetValueFloatByName(const char *name);
  void GetValueFloatByName(const char *name, float value);

  bool initialized(void) { return initialized_; }

private:
  XPLMPluginID plugin_id_;
  SharedValuesInterface	api_;
  int version_;
  bool initialized_;
};

void XSFPFF320AddUpdateData(const char *name, int value, int counter);

#endif /* _XSFPFF320_H_ */

