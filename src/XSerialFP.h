#ifndef _XSERIALFP_H_
#define _XSERIALFP_H_

#include "XSFPFF320.h"
#include "XSFPSerial.h"
#include "XSFPHandler.h"

class XSerialFP
{
public:
  XSerialFP();
  ~XSerialFP();

public:
  std::string aircraft_desc(void) { return aircraft_desc_; }
  void aircraft_desc(char *desc) { aircraft_desc_ = desc; }

  XSFPSerial & mcp(void) { return mcp_; }
  XSFPSerial & cdu(void) { return cdu_; }
  XSFPHandler & mcp_handler(void) { return mcp_handler_; }
  XSFPHandler & cdu_handler(void) { return cdu_handler_; }
  XSFPFF320 & ff320_api(void) { return ff320_api_; }

private:
  std::string aircraft_desc_;

  XSFPSerial mcp_;
  XSFPSerial cdu_;

  XSFPHandler mcp_handler_;
  XSFPHandler cdu_handler_;

  XSFPFF320 ff320_api_;
};

extern XSerialFP serialfp;

#endif /* _XSERIALFP_H_ */

