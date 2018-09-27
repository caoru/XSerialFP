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

  virtual void PerformCDU(void) = 0;
  virtual void PerformSPD(void) = 0;
  virtual void PerformHDG(void) = 0;
  virtual void PerformALT(void) = 0;
  virtual void PerformVVS(void) = 0;
  virtual void PerformAPL(void) = 0;
  virtual void PerformBAR(void) = 0;
  virtual void PerformNDM(void) = 0;
  virtual void PerformNDR(void) = 0;
  virtual void PerformEFI(void) = 0;
  virtual void PerformCOM(void) = 0;
  virtual void PerformNAV(void) = 0;
  virtual void PerformADF(void) = 0;
  virtual void PerformDME(void) = 0;
  virtual void PerformTRN(void) = 0;
  virtual void PerformCTL(void) = 0;

protected:
  std::regex regex_;
  std::string message_;
  std::smatch results_;
};

#endif /* _XSFPHANDLER_H_ */

