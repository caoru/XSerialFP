#ifndef _XSERIALFP_H_
#define _XSERIALFP_H_

#include "XSFPFF320.h"
#include "XSFPSerial.h"
#include "XSFPHandler.h"

enum {
  XSFP_AIRCRAFT_TYPE_UNKNOWN = 0,
  XSFP_AIRCRAFT_TYPE_FF320,
  XSFP_AIRCRAFT_TYPE_FF350,
  XSFP_AIRCRAFT_TYPE_MAX
};

class XSerialFP
{
public:
  XSerialFP();
  ~XSerialFP();

public:
  int aircraft_type(void) { return aircraft_type_; }
  void aircraft_type(int type) { aircraft_type_ = type; }

  std::string aircraft_desc(void) { return aircraft_desc_; }
  void aircraft_desc(char *desc) { aircraft_desc_ = desc; }

  XSFPSerial & mcp(void) { return mcp_; }
  XSFPSerial & cdu(void) { return cdu_; }

  XSFPHandler * mcp_handler(void) { return mcp_handler_; }
  void mcp_handler(XSFPHandler *handler) { mcp_handler_ = handler; }

  XSFPHandler * cdu_handler(void) { return cdu_handler_; }
  void cdu_handler(XSFPHandler *handler) { cdu_handler_ = handler; }

  XSFPFF320 & ff320_api(void) { return ff320_api_; }

private:
  int aircraft_type_;
  std::string aircraft_desc_;

  XSFPSerial mcp_;
  XSFPSerial cdu_;

  XSFPHandler *mcp_handler_;
  XSFPHandler *cdu_handler_;

  XSFPFF320 ff320_api_;
};

extern XSerialFP serialfp;

#endif /* _XSERIALFP_H_ */

