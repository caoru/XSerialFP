
//#pragma warning(disable: 4996)

#include <iostream>
#include <regex>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#if IBM
  #include <windows.h>
#endif
#if LIN
	#include <GL/gl.h>
#elif __GNUC__
	#include <OpenGL/gl.h>
#else
	#include <GL/gl.h>
#endif

//XPLMDefs.h
#include "XPLMDisplay.h"
#include "XPLMGraphics.h"
#include "XPLMProcessing.h"
#include "XPLMDataAccess.h"
#include "XPLMPlugin.h"

#include "SharedValue.h"

#include "XSerialFP.h"
#include "XSFPMenu.h"
#include "XSFPSerial.h"
#include "XSFPHandler.h"
#include "XSFPDebugWindow.h"

#ifndef XPLM300
  #error This is made to be compiled against the XPLM300 SDK
#endif

XSerialFP serialfp;

char mcp_fpdata[128];
char cdu_fpdata[128];
std::string mcp_fpbuffer;
int mcp_fpbuffer_recv = 0;
std::string cdu_fpbuffer;
int cdu_fpbuffer_recv = 0;
//int g_serial_fd = -1;

float    initFF(float elapsedMe, float elapsedSim, int counter, void *refcon);
float    MCPSerialPortAccessCB(float elapsedMe, float elapsedSim, int counter, void *refcon);
float    CDUSerialPortAccessCB(float elapsedMe, float elapsedSim, int counter, void *refcon);

PLUGIN_API int XPluginStart(
  char *    outName,
  char *    outSig,
  char *    outDesc)
{
  strcpy(outName, "SerialFP");
  strcpy(outSig, "frag.XSerialFP");
  strcpy(outDesc, "Plugin to supply MCP and CDU for SerialFP");

  strcpy(mcp_fpdata, "Not Ready");
  strcpy(cdu_fpdata, "Not Ready");

  XSFPMenuCreate();

  XSFPDebugWindowCreate();

  serialfp.mcp().Connect("/dev/tty.usbserial-A4001LAE");
  serialfp.cdu().Connect("/dev/tty.usbserial-A4001rMr");
  //g_serial_fd = XSFPSerialConnect("/dev/tty.usbserial-A4001LAE");

  XPLMRegisterFlightLoopCallback(initFF, 1.0, NULL);

  //XPLMRegisterFlightLoopCallback(SerialPortAccessCB, 1.0, NULL);

  //return (g_window != NULL);;
  return 1;
}

PLUGIN_API void XPluginStop(void)
{
  //char cmdrst[8] = {0x43, 0x4D, 0x44, 0x52, 0x53, 0x54, 0x00, 0x01};

  // Since we created this menu, we'll be good citizens and clean it up as well
  XSFPMenuDestroy();
  // If we were able to add a command to the aircraft menu, it will be automatically removed for us when we're unloaded

  XSFPDebugWindowDestroy();

  serialfp.mcp().Disconnect();
  serialfp.cdu().Disconnect();
  //write(g_serial_fd, cmdrst, 8);
  //XSFPSerialDisconnect(g_serial_fd);
}

PLUGIN_API void XPluginDisable(void) { }
PLUGIN_API int XPluginEnable(void) { return 1; }
PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFrom, int inMsg, void * inParam)
{
  XPLMDataRef AcfDescription = NULL;
  int ByteVals[500];

  if (inFrom == XPLM_PLUGIN_XPLANE)
  {
    switch(inMsg) {
      case XPLM_MSG_PLANE_LOADED:
        AcfDescription = XPLMFindDataRef("sim/aircraft/view/acf_descrip");
        if (AcfDescription != NULL)
        {
          XPLMGetDatab(AcfDescription, ByteVals, 0, 500);
          serialfp.aircraft_desc((char *)&ByteVals);
        }
        break;
    }
  }
}

float initFF(float elapsedMe, float elapsedSim, int counter, void * refcon)
{
  if (!serialfp.ff320_api().Initialize()) return -1.0;

  XPLMRegisterFlightLoopCallback(MCPSerialPortAccessCB, 1.0, NULL);
  XPLMRegisterFlightLoopCallback(CDUSerialPortAccessCB, 1.0, NULL);

  return 0;
}

float MCPSerialPortAccessCB(float elapsedMe, float elapsedSim, int counter, void * refcon)
{
  char buffer[16];
  int len;
  int i;

  memset(buffer, 0x00, 16);

  len = serialfp.mcp().Receive(buffer, 8);
  //len = read(g_serial_fd, buffer, 8);

  for (i = 0; i < len; i++)
  {
    mcp_fpbuffer_recv++;
    if (isprint(buffer[i]))
      mcp_fpbuffer += buffer[i];

    if (mcp_fpbuffer_recv == 8)
    {
      strcpy(mcp_fpdata, mcp_fpbuffer.c_str());
      serialfp.mcp_handler().Perform(mcp_fpbuffer);

      mcp_fpbuffer.clear();
      mcp_fpbuffer_recv = 0;
    }
  }

  return 0.01;
}

float CDUSerialPortAccessCB(float elapsedMe, float elapsedSim, int counter, void * refcon)
{
  char buffer[16];
  int len;
  int i;

  memset(buffer, 0x00, 16);

  len = serialfp.cdu().Receive(buffer, 8);
  //len = read(g_serial_fd, buffer, 8);

  for (i = 0; i < len; i++)
  {
    cdu_fpbuffer_recv++;
    if (isprint(buffer[i]))
      cdu_fpbuffer += buffer[i];

    if (cdu_fpbuffer_recv == 8)
    {
      strcpy(cdu_fpdata, cdu_fpbuffer.c_str());
      serialfp.cdu_handler().Perform(cdu_fpbuffer);

      cdu_fpbuffer.clear();
      cdu_fpbuffer_recv = 0;
    }
  }

  return 0.01;
}

XSerialFP::XSerialFP()
  : aircraft_desc_ ("Unknown")
{
}

XSerialFP::~XSerialFP()
{
}

