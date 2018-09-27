
#include <stdio.h>
#include <stdarg.h>

#include "XSFPLog.h"

/*
int XSFPLog(const char *format, ...)
{
  va_list arg;
  int done;
  char buffer[256];

  va_start (arg, format);
  done = vsnprintf(buffer, 256, format, arg);
  va_end (arg);

  XPLMDebugString(buffer);

  return done;
}
*/

