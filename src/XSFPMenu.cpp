
#include <string.h>

#include "XPLMPlugin.h"

#include "XSFPDebugWindow.h"
#include "XSFPMenu.h"

int g_menu_container_idx; // The index of our menu item in the Plugins menu
XPLMMenuID g_menu_id; // The menu container we'll append all our menu items to

bool XSFPMenuCreate(void)
{
  g_menu_container_idx = XPLMAppendMenuItem(XPLMFindPluginsMenu(), "XSerialFP", 0, 0);
  g_menu_id = XPLMCreateMenu("XSerialFP", XPLMFindPluginsMenu(), g_menu_container_idx, XSFPMenuHandler, NULL);
  XPLMAppendMenuItem(g_menu_id, "Debug Window", (void *)"Debug Window", 1);
  XPLMAppendMenuSeparator(g_menu_id);

  return true;
}

void XSFPMenuDestroy()
{
  XPLMDestroyMenu(g_menu_id);
}

void XSFPMenuHandler(void * in_menu_ref, void * in_item_ref)
{
  if(!strcmp((const char *)in_item_ref, "Debug Window"))
  {
    XSFPDebugWindowCreate();
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

