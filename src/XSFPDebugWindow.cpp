
#include <stdio.h>
#include <string.h>

#include "XPLMDisplay.h"
#include "XPLMGraphics.h"
#include "XPLMDataAccess.h"
#include "XPLMPlugin.h"

#include "XSerialFP.h"
#include "XSFPDebugWindow.h"

extern char mcp_fpdata[128];
extern char cdu_fpdata[128];

static XPLMWindowID	g_window;

void				draw(XPLMWindowID in_window_id, void * in_refcon);

int					dummy_mouse_handler(XPLMWindowID in_window_id, int x, int y, int is_down, void * in_refcon) { return 0; }
XPLMCursorStatus	dummy_cursor_status_handler(XPLMWindowID in_window_id, int x, int y, void * in_refcon) { return xplm_CursorDefault; }
int					dummy_wheel_handler(XPLMWindowID in_window_id, int x, int y, int wheel, int clicks, void * in_refcon) { return 0; }
void				dummy_key_handler(XPLMWindowID in_window_id, char key, XPLMKeyFlags flags, char virtual_key, void * in_refcon, int losing_focus) { }

bool XSFPDebugWindowCreate(void)
{
  int global_desktop_bounds[4]; // left, bottom, right, top
	XPLMGetScreenBoundsGlobal(&global_desktop_bounds[0], &global_desktop_bounds[3], &global_desktop_bounds[2], &global_desktop_bounds[1]);

	XPLMCreateWindow_t params;
	params.structSize = sizeof(params);
	params.left = global_desktop_bounds[0] + 50;
	params.bottom = global_desktop_bounds[1] + 150;
	params.right = global_desktop_bounds[0] + 350;
	params.top = global_desktop_bounds[1] + 450;
	params.visible = 1;
	params.drawWindowFunc = draw;
	params.handleMouseClickFunc = dummy_mouse_handler;
	params.handleRightClickFunc = dummy_mouse_handler;
	params.handleMouseWheelFunc = dummy_wheel_handler;
	params.handleKeyFunc = dummy_key_handler;
	params.handleCursorFunc = dummy_cursor_status_handler;
	params.refcon = NULL;
	params.layer = xplm_WindowLayerFloatingWindows;
	params.decorateAsFloatingWindow = 1;

	g_window = XPLMCreateWindowEx(&params);

	XPLMSetWindowPositioningMode(g_window, xplm_WindowPositionFree, -1);
	XPLMSetWindowGravity(g_window, 0, 1, 0, 1); // As the X-Plane window resizes, keep our size constant, and our left and top edges in the same place relative to the window's left/top
	XPLMSetWindowResizingLimits(g_window, 200, 200, 500, 500); // Limit resizing our window: maintain a minimum width/height of 200 boxels and a max width/height of 500
	XPLMSetWindowTitle(g_window, "Debug Window");

  return true;
}

void XSFPDebugWindowDestroy(void)
{
  XPLMDestroyWindow(g_window);
	g_window = NULL;
}

void	draw(XPLMWindowID in_window_id, void * in_refcon)
{
	char scratch_buffer[150];
	float col_white[] = {1.0, 1.0, 1.0};

	XPLMSetGraphicsState(
			0 /* no fog */,
			0 /* 0 texture units */,
			0 /* no lighting */,
			0 /* no alpha testing */,
			1 /* do alpha blend */,
			1 /* do depth testing */,
			0 /* no depth writing */
	);

	// We draw our rudimentary button boxes based on the height of the button text
	int char_height;
	XPLMGetFontDimensions(xplmFont_Proportional, NULL, &char_height, NULL);

	int l, t, r, b;
	XPLMGetWindowGeometry(in_window_id, &l, &t, &r, &b);
  int y = t - 2 * char_height;

  int intValue;
  float floatValue;

  sprintf(scratch_buffer, "Aircraft:");
  XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
  y -= 1.5 * char_height;

  sprintf(scratch_buffer, "  %s", serialfp.aircraft_desc().c_str());
  XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
  y -= 1.5 * char_height;

  sprintf(scratch_buffer, "SerialFP MCP: %s\n", mcp_fpdata);
  XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
  y -= 1.5 * char_height;

  sprintf(scratch_buffer, "SerialFP CDU: %s\n", cdu_fpdata);
  XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
  y -= 1.5 * char_height;

  floatValue = XPLMGetDataf(XPLMFindDataRef("sim/cockpit/autopilot/altitude"));
  intValue = XPLMCanWriteDataRef(XPLMFindDataRef("sim/cockpit/autopilot/altitude"));
  sprintf(scratch_buffer, "Altitude: %f(%d)\n", floatValue, intValue);
  XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
  y -= 1.5 * char_height;

  if (serialfp.ff320_api().initialized())
  {
    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.FMGS.FCU1.Altitude");
		sprintf(scratch_buffer, "FF Altitude: %d\n", intValue);
		XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
		y -= 1.5 * char_height;

    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.FMGS.FCU1.Lateral");
    sprintf(scratch_buffer, "FF HDG: %d\n", intValue);
    XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
    y -= 1.5 * char_height;

    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.FMGS.FCU1.Speed");
    sprintf(scratch_buffer, "FF Speed: %d\n", intValue);
    XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
    y -= 1.5 * char_height;

    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.FMGS.FCU1.Vertical");
    sprintf(scratch_buffer, "FF Vertical: %d\n", intValue);
    XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
    y -= 1.5 * char_height;

    floatValue = serialfp.ff320_api().GetValueFloatByName("Aircraft.Cockpit.Pedestal.ParkBrake.Position");
    sprintf(scratch_buffer, "FF ABP: %f\n", floatValue);
    XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
    y -= 1.5 * char_height;

    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.Cockpit.Pedestal.ParkBrake.Target");
    sprintf(scratch_buffer, "FF ABT: %d\n", intValue);
    XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
    y -= 1.5 * char_height;

    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.Cockpit.Pedestal.ParkBrake.State1");
    sprintf(scratch_buffer, "FF AB1: %d\n", intValue);
    XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
    y -= 1.5 * char_height;

    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.Cockpit.Pedestal.ParkBrake.State2");
    sprintf(scratch_buffer, "FF AB2: %d\n", intValue);
    XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
    y -= 1.5 * char_height;

    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.Navigation.Transponder1.Code");
    sprintf(scratch_buffer, "FF TRN: %d\n", intValue);
    XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
    y -= 1.5 * char_height;
  }

  floatValue = XPLMGetDataf(XPLMFindDataRef("sim/cockpit2/controls/speedbrake_ratio"));
  sprintf(scratch_buffer, "SPD BRK: %f\n", floatValue);
  XPLMDrawString(col_white, l, y, scratch_buffer, NULL, xplmFont_Proportional);
  y -= 1.5 * char_height;
}

