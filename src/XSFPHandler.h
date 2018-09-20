#ifndef _XSFPHANDLER_H_
#define _XSFPHANDLER_H_

#include <iostream>
#include <regex>

class XSFPHandler
{
public:
  XSFPHandler();
  ~XSFPHandler();

  void Perform(std::string message);

private:
  void Parse(void);

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
  std::regex regex_;
  std::string message_;
  std::smatch results_;
};

#endif /* _XSFPHANDLER_H_ */

