#ifndef _XSFPLOG_H_
#define _XSFPLOG_H_

#include "XPLMUtilities.h"

static char __log_printf_buffer[4096];
#define XSFPLog(fmt, ...) snprintf(__log_printf_buffer, 4096, "XSerialFP: " fmt "\n", ##__VA_ARGS__), XPLMDebugString(__log_printf_buffer)

//int XSFPLog(const char *format, ...);

#endif /* _XSFPLOG_H_ */

