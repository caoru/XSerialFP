#ifndef _XSFPHANDLERFF320_H_
#define _XSFPHANDLERFF320_H_

#include <iostream>
#include <regex>

#include "XSFPHandler.h"

class XSFPHandlerFF320 : public XSFPHandler
{
public:
  XSFPHandlerFF320();
  ~XSFPHandlerFF320();

private:
  void PerformCDU(void);
  void PerformSPD(void);
  void PerformHDG(void);
  void PerformALT(void);
  void PerformVVS(void);
  void PerformAPL(void);
  void PerformBAR(void);
  void PerformNDM(void);
  void PerformNDR(void);
  void PerformEFI(void);
  void PerformCOM(void);
  void PerformNAV(void);
  void PerformADF(void);
  void PerformDME(void);
  void PerformTRN(void);
  void PerformCTL(void);

private:
};

#endif /* _XSFPHANDLERFF320_H_ */

