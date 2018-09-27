
#include <unistd.h>

#include "XPLMDataAccess.h"

#include "XSerialFP.h"
#include "XSFPFF350Def.h"
#include "XSFPLog.h"
#include "XSFPHandler.h"
#include "XSFPHandlerFF350.h"

XSFPHandlerFF350::XSFPHandlerFF350()
{
}

XSFPHandlerFF350::~XSFPHandlerFF350()
{
}

void XSFPHandlerFF350::PerformCDU(void)
{
  float floatValue = 1.0f;
  if (results_[2] == "R0")
  {
    if (results_[3] == "C0")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Key1"));
    else if (results_[3] == "C1")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Key2"));
    else if (results_[3] == "C2")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Key3"));
    else if (results_[3] == "C3")
      XPLMSetDataf(XPLMFindDataRef("1-sim/188/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyA"));
    else if (results_[3] == "C4")
      XPLMSetDataf(XPLMFindDataRef("1-sim/190/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyB"));
    else if (results_[3] == "C5")
      XPLMSetDataf(XPLMFindDataRef("1-sim/191/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyC"));
    else if (results_[3] == "C6")
      XPLMSetDataf(XPLMFindDataRef("1-sim/192/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyD"));
    else if (results_[3] == "C7")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyE"));
  }
  else if (results_[2] == "R1")
  {
    if (results_[3] == "C0")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Key4"));
    else if (results_[3] == "C1")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Key5"));
    else if (results_[3] == "C2")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Key6"));
    else if (results_[3] == "C3")
      XPLMSetDataf(XPLMFindDataRef("1-sim/189/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyF"));
    else if (results_[3] == "C4")
      XPLMSetDataf(XPLMFindDataRef("1-sim/194/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyG"));
    else if (results_[3] == "C5")
      XPLMSetDataf(XPLMFindDataRef("1-sim/195/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyH"));
    else if (results_[3] == "C6")
    {
      floatValue = XPLMGetDataf(XPLMFindDataRef("1-sim/196/button"));
      if (floatValue == 1.0f) floatValue = 0.0f;
      else floatValue = 1.0f;
      XPLMSetDataf(XPLMFindDataRef("1-sim/196/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyI"));
    }
    else if (results_[3] == "C7")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyJ"));
  }
  else if (results_[2] == "R2")
  {
    if (results_[3] == "C0")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Key7"));
    else if (results_[3] == "C1")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Key8"));
    else if (results_[3] == "C2")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Key9"));
    else if (results_[3] == "C3")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyK"));
    else if (results_[3] == "C4")
      XPLMSetDataf(XPLMFindDataRef("1-sim/197/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyL"));
    else if (results_[3] == "C5")
      XPLMSetDataf(XPLMFindDataRef("1-sim/198/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyM"));
    else if (results_[3] == "C6")
      XPLMSetDataf(XPLMFindDataRef("1-sim/199/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyN"));
    else if (results_[3] == "C7")
      XPLMSetDataf(XPLMFindDataRef("1-sim/200/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyO"));
  }
  else if (results_[2] == "R3")
  {
    if (results_[3] == "C0")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Key0"));
    else if (results_[3] == "C1")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyDecimal"));
    else if (results_[3] == "C2")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyPM"));
    else if (results_[3] == "C3")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyO"));
    else if (results_[3] == "C4")
      XPLMSetDataf(XPLMFindDataRef("1-sim/202/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyQ"));
    else if (results_[3] == "C5")
      XPLMSetDataf(XPLMFindDataRef("1-sim/203/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyR"));
    else if (results_[3] == "C6")
      XPLMSetDataf(XPLMFindDataRef("1-sim/204/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyS"));
    else if (results_[3] == "C7")
      XPLMSetDataf(XPLMFindDataRef("1-sim/205/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyT"));
  }
  else if (results_[2] == "R4")
  {
    if (results_[3] == "C0")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1LSK1L"));
    else if (results_[3] == "C1")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1LSK2L"));
    else if (results_[3] == "C2")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1LSK3L"));
    else if (results_[3] == "C3")
      XPLMSetDataf(XPLMFindDataRef("1-sim/207/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyU"));
    else if (results_[3] == "C4")
      XPLMSetDataf(XPLMFindDataRef("1-sim/206/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyV"));
    else if (results_[3] == "C5")
      XPLMSetDataf(XPLMFindDataRef("1-sim/209/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyW"));
    else if (results_[3] == "C6")
      XPLMSetDataf(XPLMFindDataRef("1-sim/210/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyX"));
    else if (results_[3] == "C7")
      XPLMSetDataf(XPLMFindDataRef("1-sim/211/button"), floatValue);
      //XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyY"));
  }
  else if (results_[2] == "R5")
  {
    if (results_[3] == "C0")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1LSK4L"));
    else if (results_[3] == "C1")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1LSK5L"));
    else if (results_[3] == "C2")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1LSK6L"));
    else if (results_[3] == "C3")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyZ"));
    else if (results_[3] == "C4")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeySpace"));
    else if (results_[3] == "C5")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyOverfly"));
    else if (results_[3] == "C6")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeySlash"));
    else if (results_[3] == "C7")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1KeyClear"));
  }
  else if (results_[2] == "R6")
  {
    if (results_[3] == "C0")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1LSK6R"));
    else if (results_[3] == "C1")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1LSK65"));
    else if (results_[3] == "C2")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1LSK64"));
    else if (results_[3] == "C3")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1LSK63"));
    else if (results_[3] == "C4")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1LSK62"));
    else if (results_[3] == "C5")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1LSK61"));
    else if (results_[3] == "C6")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1SlewLeft"));
    else if (results_[3] == "C7")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1SlewUp"));
  }
  else if (results_[2] == "R7")
  {
    if (results_[3] == "C0")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Fpln"));
    else if (results_[3] == "C1")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1RadNav"));
    else if (results_[3] == "C2")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1FuelPred"));
    else if (results_[3] == "C3")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1SecFpln"));
    else if (results_[3] == "C4")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1ATC"));
    else if (results_[3] == "C5")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Menu"));
    else if (results_[3] == "C6")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1SlewRight"));
    else if (results_[3] == "C7")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1SlewDown"));
  }
  else if (results_[2] == "R8")
  {
    if (results_[3] == "C0")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1DirTo"));
    else if (results_[3] == "C1")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Prog"));
    else if (results_[3] == "C2")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Perf"));
    else if (results_[3] == "C3")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Init"));
    else if (results_[3] == "C4")
      XPLMCommandOnce(XPLMFindCommand("AirbusFBW/MCDU1Data"));
  }
}

void XSFPHandlerFF350::PerformSPD(void)
{
  int intValue;
  float floatValue;

  if (results_[2] == "SEL")
  {
    floatValue = -1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/fcu/spd/jump"), floatValue);
    XPLMCommandOnce(XPLMFindCommand("AirbusFBW/PushSPDSel"));
  }
  else if (results_[2] == "SPD")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/fcu/spd/jump"), floatValue);
    XPLMCommandOnce(XPLMFindCommand("AirbusFBW/PullSPDSel"));
  }
  else if (results_[2] == "N1")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_Mach.Click", intValue);
  }
  else if (results_[2] == "LVL")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/150/button"), floatValue);
  }
  else
  {
    floatValue = std::stoi(results_[2]);
    XPLMSetDataf(XPLMFindDataRef("sim/cockpit/autopilot/airspeed"), floatValue);
  }
}

void XSFPHandlerFF350::PerformHDG(void)
{
  float floatValue;

  if (results_[2] == "SEL")
  {
    floatValue = -1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/fcu/hdg/jump"), floatValue);
    XPLMCommandOnce(XPLMFindCommand("AirbusFBW/PushHDGSel"));
  }
  else if (results_[2] == "HDG")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/fcu/hdg/jump"), floatValue);
    XPLMCommandOnce(XPLMFindCommand("AirbusFBW/PullHDGSel"));
  }
  else if (results_[2] == "HLD")
  {
  }
  else
  {
    floatValue = std::stoi(results_[2]);
    XPLMSetDataf(XPLMFindDataRef("sim/cockpit/autopilot/heading_mag"), floatValue);
  }
}

void XSFPHandlerFF350::PerformALT(void)
{
  float floatValue;

  if (results_[2] == "SEL")
  {
    floatValue = -1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/fcu/alt/jump"), floatValue);
    XPLMCommandOnce(XPLMFindCommand("AirbusFBW/PushAltitude"));
  }
  else if (results_[2] == "HLD")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/fcu/alt/jump"), floatValue);
    XPLMCommandOnce(XPLMFindCommand("AirbusFBW/PullAltitude"));
  }
  else
  {
    floatValue = std::stoi(results_[2]) * 100.0f;
    XPLMSetDataf(XPLMFindDataRef("sim/cockpit/autopilot/altitude"), floatValue);
  }
}

void XSFPHandlerFF350::PerformVVS(void)
{
  float floatValue;

  if (results_[2] == "SEL")
  {
    floatValue = -1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/fcu/vvi/jump"), floatValue);
    XPLMCommandOnce(XPLMFindCommand("AirbusFBW/PushVSSel"));
  }
  else if (results_[2] == "HLD")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/fcu/vvi/jump"), floatValue);
    XPLMCommandOnce(XPLMFindCommand("AirbusFBW/PullVSSel"));
  }
  else
  {
    floatValue = std::stoi(results_[2]) * 10.0f;
    XPLMSetDataf(XPLMFindDataRef("sim/cockpit/autopilot/vertical_velocity"), floatValue);
  }
}

void XSFPHandlerFF350::PerformAPL(void)
{
  int intValue;
  float floatValue;

  if (results_[2] == "CMDA")
  {
    floatValue = XPLMGetDataf(XPLMFindDataRef("1-sim/225/button"));
    if (floatValue == 1.0f) floatValue = 0.0f;
    else floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/225/button"), floatValue);
  }
  else if (results_[2] == "CMDB")
  {
    floatValue = XPLMGetDataf(XPLMFindDataRef("1-sim/224/button"));
    if (floatValue == 1.0f) floatValue = 0.0f;
    else floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/224/button"), floatValue);
  }
  else if (results_[2] == "CMDC")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.BrakeAuto2.Click", intValue);
  }
  else if (results_[2] == "VNAV")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/147/button"), floatValue);
  }
  else if (results_[2] == "LNAV")
  {
    floatValue = XPLMGetDataf(XPLMFindDataRef("1-sim/144/button"));
    if (floatValue == 1.0f) floatValue = 0.0f;
    else floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/144/button"), floatValue);
  }
  else if (results_[2] == "LOC")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/146/button"), floatValue);
  }
  else if (results_[2] == "APP")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/152/button"), floatValue);
  }
  else if (results_[2] == "TOGA")
  {
  }
  else if (results_[2] == "TOGN")
  {
    intValue = XPLMGetDatai(XPLMFindDataRef("1-sim/pres/pressModeLeft"));
    if (intValue == 0) intValue = 1;
    else intValue = 0;
    XPLMSetDatai(XPLMFindDataRef("1-sim/pres/pressModeLeft"), intValue);
  }
  else if (results_[2] == "AT")
  {
    if (results_[3] == "+")
    {
      floatValue = -0.5f;
      XPLMSetDataf(XPLMFindDataRef("sim/cockpit2/controls/speedbrake_ratio"), floatValue);
    }
    else if (results_[3] == "-")
    {
      floatValue = 0.0f;
      XPLMSetDataf(XPLMFindDataRef("sim/cockpit2/controls/speedbrake_ratio"), floatValue);
    }
  }
  else if (results_[2] == "FD")
  {
    if (results_[3] == "+")
    {
      intValue = XPLMGetDatai(XPLMFindDataRef("1-sim/parckBrake"));
      if (intValue == 0)
      {
        intValue = 1;
        XPLMSetDatai(XPLMFindDataRef("1-sim/parckBrake"), intValue);
        XPLMCommandOnce(XPLMFindCommand("sim/flight_controls/brakes_toggle_max"));
      }
    }
    else if (results_[3] == "-")
    {
      intValue = XPLMGetDatai(XPLMFindDataRef("1-sim/parckBrake"));
      if (intValue == 1)
      {
        intValue = 0;
        XPLMSetDatai(XPLMFindDataRef("1-sim/parckBrake"), intValue);
        XPLMCommandOnce(XPLMFindCommand("sim/flight_controls/brakes_toggle_max"));
      }
    }
  }
  else if (results_[2] == "MAST")
  {
    if (results_[3] == "+")
    {
      XPLMCommandOnce(XPLMFindCommand("sim/flight_controls/landing_gear_up"));
    }
    else if (results_[3] == "-")
    {
      XPLMCommandOnce(XPLMFindCommand("sim/flight_controls/landing_gear_down"));
    }
  }
  else if (results_[2] == "CWSA")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/148/button"), floatValue);
  }
  else if (results_[2] == "CWSB")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/149/button"), floatValue);
  }
}

void XSFPHandlerFF350::PerformBAR(void)
{
  int intValue;
  float floatValue;

  if (results_[2] == "SEL")
  {
    floatValue = -1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/fcu/pressLeft/jump"), floatValue);
  }
  else if (results_[2] == "+")
  {
    intValue = XPLMGetDatai(XPLMFindDataRef("1-sim/pres/pressModeLeft/switch"));
    floatValue = XPLMGetDataf(XPLMFindDataRef("1-sim/pres/pressLeftRotary"));

    if (intValue == 1)
    {
      floatValue += 3.0f;
    }
    else
    {
      floatValue += 1.0f;
    }
    if (floatValue > 200.0f) floatValue = 200.0f;

    XPLMSetDataf(XPLMFindDataRef("1-sim/pres/pressLeftRotary"), floatValue);
  }
  else if (results_[2] == "-")
  {
    intValue = XPLMGetDatai(XPLMFindDataRef("1-sim/pres/pressModeLeft/switch"));
    floatValue = XPLMGetDataf(XPLMFindDataRef("1-sim/pres/pressLeftRotary"));

    if (intValue == 1)
    {
      floatValue -= 3.0f;
    }
    else
    {
      floatValue -= 1.0f;
    }
    if (floatValue < -200.0f) floatValue = -200.0f;

    XPLMSetDataf(XPLMFindDataRef("1-sim/pres/pressLeftRotary"), floatValue);
  }
}

void XSFPHandlerFF350::PerformNDM(void)
{
  float floatValue;

  if (results_[2] == "+")
  {
    floatValue = XPLMGetDataf(XPLMFindDataRef("1-sim/fcu/ndModeLeft/switch"));

    floatValue++;
    if (floatValue > 4.0f) floatValue = 4.0f;

    XPLMSetDataf(XPLMFindDataRef("1-sim/fcu/ndModeLeft/switch"), floatValue);
  }
  else if (results_[2] == "-")
  {
    floatValue = XPLMGetDataf(XPLMFindDataRef("1-sim/fcu/ndModeLeft/switch"));

    floatValue--;
    if (floatValue < 0.0f) floatValue = 0.0f;

    XPLMSetDataf(XPLMFindDataRef("1-sim/fcu/ndModeLeft/switch"), floatValue);
  }
}

void XSFPHandlerFF350::PerformNDR(void)
{
  float floatValue;

  if (results_[2] == "+")
  {
    floatValue = XPLMGetDataf(XPLMFindDataRef("1-sim/fcu/ndZoomLeft/switch"));

    floatValue++;
    if (floatValue > 6.0f) floatValue = 6.0f;

    XPLMSetDataf(XPLMFindDataRef("1-sim/fcu/ndZoomLeft/switch"), floatValue);
  }
  else if (results_[2] == "-")
  {
    floatValue = XPLMGetDataf(XPLMFindDataRef("1-sim/fcu/ndZoomLeft/switch"));

    floatValue--;
    if (floatValue < 0.0f) floatValue = 0.0f;

    XPLMSetDataf(XPLMFindDataRef("1-sim/fcu/ndZoomLeft/switch"), floatValue);
  }
}

void XSFPHandlerFF350::PerformEFI(void)
{
  int intValue;
  float floatValue;

  if (results_[2] == "MTR")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/130/button"), floatValue);
  }
  else if (results_[2] == "FPV")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/131/button"), floatValue);
  }
  else if (results_[2] == "WX")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/134/button"), floatValue);
  }
  else if (results_[2] == "STA")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/135/button"), floatValue);
  }
  else if (results_[2] == "WPT")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/136/button"), floatValue);
  }
  else if (results_[2] == "ARPT")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/137/button"), floatValue);
  }
  else if (results_[2] == "DATA")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/138/button"), floatValue);
  }
  else if (results_[2] == "POS")
  {
  }
  else if (results_[2] == "TERR")
  {
    floatValue = 1.0f;
    XPLMSetDataf(XPLMFindDataRef("1-sim/141/button"), floatValue);
  }
  else if (results_[2] == "VOR")
  {
    if (results_[3] == "1")
    {
      XPLMCommandOnce(XPLMFindCommand("sim/flight_controls/flaps_up"));
    }
    else if (results_[3] == "2")
    {
      intValue = 2;
      serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Pedestal.TCAS_Traffic.Target", intValue);
    }
  }
  else if (results_[2] == "ADF")
  {
    if (results_[3] == "1")
    {
      XPLMCommandOnce(XPLMFindCommand("sim/flight_controls/flaps_down"));
    }
    else if (results_[3] == "2")
    {
      intValue = 0;
      serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Pedestal.TCAS_Traffic.Target", intValue);
    }
  }
}

void XSFPHandlerFF350::PerformCOM(void)
{
  int intValue;
  if (results_[2] == "SEL")
  {
  }
  else if (results_[2] == "s")
  {
  }
  else if (results_[2] == "S")
  {
  }
  else if (results_[2] == "x")
  {
    intValue = std::stoi(results_[3]) + 10000;
    XPLMSetDatai(XPLMFindDataRef("sim/cockpit/radios/com1_freq_hz"), intValue);
  }
  else if (results_[2] == "X")
  {
    intValue = std::stoi(results_[3]) + 10000;
    XPLMSetDatai(XPLMFindDataRef("sim/cockpit/radios/com2_freq_hz"), intValue);
  }
}

void XSFPHandlerFF350::PerformNAV(void)
{
  int intValue;

  if (results_[2] == "SEL")
  {
  }
  else if (results_[2] == "s")
  {
  }
  else if (results_[2] == "S")
  {
  }
  else if (results_[2] == "x")
  {
    intValue = std::stoi(results_[3]) + 10000;
    XPLMSetDatai(XPLMFindDataRef("sim/cockpit/radios/nav1_freq_hz"), intValue);
  }
  else if (results_[2] == "X")
  {
    intValue = std::stoi(results_[3]) + 10000;
    XPLMSetDatai(XPLMFindDataRef("sim/cockpit/radios/nav1_freq_hz"), intValue);
  }
}

void XSFPHandlerFF350::PerformADF(void)
{
  if (results_[2] == "SEL")
  {
  }
  else if (results_[2] == "s")
  {
  }
  else if (results_[2] == "S")
  {
  }
  else if (results_[2] == "x")
  {
  }
  else if (results_[2] == "X")
  {
  }
}

void XSFPHandlerFF350::PerformDME(void)
{
  if (results_[2] == "SEL")
  {
  }
}

void XSFPHandlerFF350::PerformTRN(void)
{
  int intValue;

  if (results_[2] == "SEL")
  {
  }
  else if (results_[2] == "S")
  {
  }
  else if (results_[2] == "X")
  {
    intValue = std::stoi(results_[3]);
    XPLMSetDatai(XPLMFindDataRef("sim/cockpit/radios/transponder_code"), intValue);
    XPLMSetDatai(XPLMFindDataRef("sim/cockpit2/radios/actuators/transponder_code"), intValue);
  }
}

void XSFPHandlerFF350::PerformCTL(void)
{
  if (results_[2] == "BN0")
  {
  }
  else if (results_[2] == "BN1")
  {
  }
  else if (results_[2] == "BN2")
  {
  }
  else if (results_[2] == "BN3")
  {
  }
  else if (results_[2] == "BN4")
  {
  }
  else if (results_[2] == "BN5")
  {
  }
  else if (results_[2] == "BN6")
  {
  }
  else if (results_[2] == "BN7")
  {
  }
}

