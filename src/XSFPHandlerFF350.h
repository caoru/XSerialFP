#ifndef _XSFPHANDLERFF350_H_
#define _XSFPHANDLERFF350_H_

#include <iostream>
#include <regex>

#include "XSFPHandler.h"

class XSFPHandlerFF350 : public XSFPHandler
{
public:
  XSFPHandlerFF350();
  ~XSFPHandlerFF350();

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

#endif /* _XSFPHANDLERFF350_H_ */

