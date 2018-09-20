
#include <string.h>

#include "XPLMPlugin.h"

#include "XSFPMenu.h"

int g_menu_container_idx; // The index of our menu item in the Plugins menu
XPLMMenuID g_menu_id; // The menu container we'll append all our menu items to

bool XSFPMenuCreate(void)
{
  g_menu_container_idx = XPLMAppendMenuItem(XPLMFindPluginsMenu(), "XSerialFP", 0, 0);
  g_menu_id = XPLMCreateMenu("XSerialFP", XPLMFindPluginsMenu(), g_menu_container_idx, XSFPMenuHandler, NULL);
  XPLMAppendMenuItem(g_menu_id, "Settings", (void *)"Settings", 1);
  XPLMAppendMenuSeparator(g_menu_id);
  XPLMAppendMenuItem(g_menu_id, "Toggle Shortcuts", (void *)"Shortcuts ", 1);
  XPLMAppendMenuItemWithCommand(g_menu_id, "Toggle Flight Configuration (Command-Based)", XPLMFindCommand("sim/operation/toggle_flight_config"));
  XPLMAppendMenuItem(g_menu_id, "Reload", (void *)"Reload", 1);
  XPLMAppendMenuItem(g_menu_id, "Test", (void *)"Test", 1);
  XPLMAppendMenuItem(g_menu_id, "Test 2", (void *)"Test 2", 1);

  return true;
}

void XSFPMenuDestroy()
{
  XPLMDestroyMenu(g_menu_id);
}

void XSFPMenuHandler(void * in_menu_ref, void * in_item_ref)
{
  if(!strcmp((const char *)in_item_ref, "Settings"))
  {
    XPLMCommandOnce(XPLMFindCommand("sim/operation/toggle_settings_window"));
  }
  else if(!strcmp((const char *)in_item_ref, "Shortcuts"))
  {
    XPLMCommandOnce(XPLMFindCommand("sim/operation/toggle_key_shortcuts_window"));
  }
  else if(!strcmp((const char *)in_item_ref, "Reload"))
  {
    XPLMReloadPlugins();
  }
}

