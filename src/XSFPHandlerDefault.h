#ifndef _XSFPHANDLERDEFAULT_H_
#define _XSFPHANDLERDEFAULT_H_

#include <iostream>
#include <regex>

#include "XSFPHandler.h"

class XSFPHandlerDefault : public XSFPHandler
{
public:
  XSFPHandlerDefault();
  ~XSFPHandlerDefault();

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

protected:
};

#endif /* _XSFPHANDLERDEFAULT_H_ */

