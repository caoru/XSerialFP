
#include <unistd.h>

#include "XPLMDataAccess.h"

#include "XSerialFP.h"
#include "XSFPFF320Def.h"
#include "XSFPLog.h"
#include "XSFPHandler.h"
#include "XSFPHandlerFF320.h"

XSFPHandlerFF320::XSFPHandlerFF320()
{
}

XSFPHandlerFF320::~XSFPHandlerFF320()
{
}

void XSFPHandlerFF320::PerformCDU(void)
{
  int intValue = 1;

  if (results_[2] == "R0")
  {
    if (results_[3] == "C0")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_NUM1, intValue);
    else if (results_[3] == "C1")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_NUM2, intValue);
    else if (results_[3] == "C2")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_NUM3, intValue);
    else if (results_[3] == "C3")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_A, intValue);
    else if (results_[3] == "C4")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_B, intValue);
    else if (results_[3] == "C5")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_C, intValue);
    else if (results_[3] == "C6")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_D, intValue);
    else if (results_[3] == "C7")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_E, intValue);
  }
  else if (results_[2] == "R1")
  {
    if (results_[3] == "C0")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_NUM4, intValue);
    else if (results_[3] == "C1")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_NUM5, intValue);
    else if (results_[3] == "C2")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_NUM6, intValue);
    else if (results_[3] == "C3")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_F, intValue);
    else if (results_[3] == "C4")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_G, intValue);
    else if (results_[3] == "C5")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_H, intValue);
    else if (results_[3] == "C6")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_I, intValue);
    else if (results_[3] == "C7")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_J, intValue);
  }
  else if (results_[2] == "R2")
  {
    if (results_[3] == "C0")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_NUM7, intValue);
    else if (results_[3] == "C1")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_NUM8, intValue);
    else if (results_[3] == "C2")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_NUM9, intValue);
    else if (results_[3] == "C3")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_K, intValue);
    else if (results_[3] == "C4")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_L, intValue);
    else if (results_[3] == "C5")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_M, intValue);
    else if (results_[3] == "C6")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_N, intValue);
    else if (results_[3] == "C7")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_O, intValue);
  }
  else if (results_[2] == "R3")
  {
    if (results_[3] == "C0")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_NUM0, intValue);
    else if (results_[3] == "C1")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_POIN, intValue);
    else if (results_[3] == "C2")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_PLMI, intValue);
    else if (results_[3] == "C3")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_P, intValue);
    else if (results_[3] == "C4")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_Q, intValue);
    else if (results_[3] == "C5")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_R, intValue);
    else if (results_[3] == "C6")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_S, intValue);
    else if (results_[3] == "C7")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_T, intValue);
  }
  else if (results_[2] == "R4")
  {
    if (results_[3] == "C0")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_LF1, intValue);
    else if (results_[3] == "C1")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_LF2, intValue);
    else if (results_[3] == "C2")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_LF3, intValue);
    else if (results_[3] == "C3")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_U, intValue);
    else if (results_[3] == "C4")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_V, intValue);
    else if (results_[3] == "C5")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_W, intValue);
    else if (results_[3] == "C6")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_X, intValue);
    else if (results_[3] == "C7")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_Y, intValue);
  }
  else if (results_[2] == "R5")
  {
    if (results_[3] == "C0")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_LF4, intValue);
    else if (results_[3] == "C1")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_LF5, intValue);
    else if (results_[3] == "C2")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_LF6, intValue);
    else if (results_[3] == "C3")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_Z, intValue);
    else if (results_[3] == "C4")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_SP, intValue);
    else if (results_[3] == "C5")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_OVFY, intValue);
    else if (results_[3] == "C6")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_SLA, intValue);
    else if (results_[3] == "C7")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_CLR, intValue);
  }
  else if (results_[2] == "R6")
  {
    if (results_[3] == "C0")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_RF6, intValue);
    else if (results_[3] == "C1")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_RF5, intValue);
    else if (results_[3] == "C2")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_RF4, intValue);
    else if (results_[3] == "C3")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_RF3, intValue);
    else if (results_[3] == "C4")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_RF2, intValue);
    else if (results_[3] == "C5")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_RF1, intValue);
    else if (results_[3] == "C6")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_LEFT, intValue);
    else if (results_[3] == "C7")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_UP, intValue);
  }
  else if (results_[2] == "R7")
  {
    if (results_[3] == "C0")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_FPLN, intValue);
    else if (results_[3] == "C1")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_RAD, intValue);
    else if (results_[3] == "C2")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_FUEL, intValue);
    else if (results_[3] == "C3")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_SEC, intValue);
    else if (results_[3] == "C4")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_ATC, intValue);
    else if (results_[3] == "C5")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_MCDU, intValue);
    else if (results_[3] == "C6")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_RIGHT, intValue);
    else if (results_[3] == "C7")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_DOWN, intValue);
  }
  else if (results_[2] == "R8")
  {
    if (results_[3] == "C0")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_DIR, intValue);
    else if (results_[3] == "C1")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_PROG, intValue);
    else if (results_[3] == "C2")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_PERF, intValue);
    else if (results_[3] == "C3")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_INIT, intValue);
    else if (results_[3] == "C4")
      serialfp.ff320_api().SetValueIntByName(FF320_MCDU_DATA, intValue);
  }
}

void XSFPHandlerFF320::PerformSPD(void)
{
  int intValue;

  if (results_[2] == "SEL")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_SpeedMode.Target", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.FCU_SpeedMode.Target", 0, 5);
#if 0
    usleep(500000);
    intValue = 0;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_SpeedMode.Target", intValue);
#endif
  }
  else if (results_[2] == "SPD")
  {
    intValue = -1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_SpeedMode.Target", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.FCU_SpeedMode.Target", 0, 5);
  }
  else if (results_[2] == "N1")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_Mach.Click", intValue);
  }
  else if (results_[2] == "LVL")
  {
    XPLMCommandOnce(XPLMFindCommand("sim/autopilot/autothrottle_toggle"));
  }
  else
  {
    intValue = std::stoi(results_[2]);
    serialfp.ff320_api().SetValueIntByName("Aircraft.FMGS.FCU1.Speed", intValue);
  }
}

void XSFPHandlerFF320::PerformHDG(void)
{
  int intValue;

  if (results_[2] == "SEL")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_LateralMode.Target", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.FCU_LateralMode.Target", 0, 5);
  }
  else if (results_[2] == "HDG")
  {
    intValue = -1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_LateralMode.Target", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.FCU_LateralMode.Target", 0, 5);
  }
  else if (results_[2] == "HLD")
  {
  }
  else
  {
    intValue = std::stoi(results_[2]);
    serialfp.ff320_api().SetValueIntByName("Aircraft.FMGS.FCU1.Lateral", intValue);
  }
}

void XSFPHandlerFF320::PerformALT(void)
{
  int intValue;

  if (results_[2] == "SEL")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_AltitudeMode.Target", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.FCU_AltitudeMode.Target", 0, 5);
  }
  else if (results_[2] == "HLD")
  {
    intValue = -1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_AltitudeMode.Target", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.FCU_AltitudeMode.Target", 0, 5);
  }
  else
  {
    intValue = std::stoi(results_[2]);
    serialfp.ff320_api().SetValueIntByName("Aircraft.FMGS.FCU1.Altitude", intValue);
  }
}

void XSFPHandlerFF320::PerformVVS(void)
{
  int intValue;

  if (results_[2] == "SEL")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_VerticalMode.Target", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.FCU_VerticalMode.Target", 0, 5);
  }
  else if (results_[2] == "HLD")
  {
    intValue = -1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_VerticalMode.Target", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.FCU_VerticalMode.Target", 0, 5);
  }
  else
  {
    intValue = std::stoi(results_[2].str().substr(0, 3));
    serialfp.ff320_api().SetValueIntByName("Aircraft.FMGS.FCU1.Vertical", intValue);
  }
}

void XSFPHandlerFF320::PerformAPL(void)
{
  int intValue;
  float floatValue;

  if (results_[2] == "CMDA")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.BrakeAuto1.Click", intValue);
  }
  else if (results_[2] == "CMDB")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.BrakeAuto3.Click", intValue);
  }
  else if (results_[2] == "CMDC")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.BrakeAuto2.Click", intValue);
  }
  else if (results_[2] == "VNAV")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_FlightDirL.Click", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.EFIS_FlightDirL.Click", 0, 5);
  }
  else if (results_[2] == "LNAV")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_LandSysL.Click", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.EFIS_LandSysL.Click", 0, 5);
  }
  else if (results_[2] == "LOC")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_Localizer.Click", intValue);
  }
  else if (results_[2] == "APP")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_Approach.Click", intValue);
  }
  else if (results_[2] == "TOGA")
  {
    intValue = -1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_BaroModeL.Target", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.EFIS_BaroModeL.Target", 0, 5);
  }
  else if (results_[2] == "TOGN")
  {
    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.Cockpit.Panel.EFIS_BaroTypeL.Target");

    if (intValue == 0) intValue = 1;
    else intValue = 0;

    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_BaroTypeL.Target", intValue);
  }
  else if (results_[2] == "AT")
  {
    if (results_[3] == "+")
    {
      floatValue = 0.0f;
      XPLMSetDataf(XPLMFindDataRef("sim/cockpit2/controls/speedbrake_ratio"), floatValue);
    }
    else if (results_[3] == "-")
    {
      floatValue = 0.5f;
      XPLMSetDataf(XPLMFindDataRef("sim/cockpit2/controls/speedbrake_ratio"), floatValue);
    }
  }
  else if (results_[2] == "FD")
  {
    if (results_[3] == "+")
    {
      intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.Cockpit.Pedestal.ParkBrake.Target");
      if (intValue == 1)
        XPLMCommandOnce(XPLMFindCommand("sim/flight_controls/brakes_toggle_max"));
    }
    else if (results_[3] == "-")
    {
      intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.Cockpit.Pedestal.ParkBrake.Target");
      if (intValue == 0)
        XPLMCommandOnce(XPLMFindCommand("sim/flight_controls/brakes_toggle_max"));
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
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_AutoPilot1.Click", intValue);
  }
  else if (results_[2] == "CWSB")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.FCU_AutoPilot2.Click", intValue);
  }
}

void XSFPHandlerFF320::PerformBAR(void)
{
  int intValue;

  if (results_[2] == "SEL")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_BaroModeL.Target", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.EFIS_BaroModeL.Target", 0, 5);
  }
  else if (results_[2] == "+")
  {
    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.Cockpit.Panel.EFIS_BaroL.Position");

    intValue++;
    if (intValue > 1000) intValue = 1000;

    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_BaroL.Position", intValue);
  }
  else if (results_[2] == "-")
  {
    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.Cockpit.Panel.EFIS_BaroL.Position");

    intValue--;
    if (intValue < -1000) intValue = -1000;

    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_BaroL.Position", intValue);
  }
}

void XSFPHandlerFF320::PerformNDM(void)
{
  int intValue;

  if (results_[2] == "+")
  {
    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.Cockpit.Panel.EFIS_NavModeL.Target");

    intValue++;
    if (intValue > 4) intValue = 4;

    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_NavModeL.Target", intValue);
  }
  else if (results_[2] == "-")
  {
    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.Cockpit.Panel.EFIS_NavModeL.Target");

    intValue--;
    if (intValue < 0) intValue = 0;

    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_NavModeL.Target", intValue);
  }
}

void XSFPHandlerFF320::PerformNDR(void)
{
  int intValue;

  if (results_[2] == "+")
  {
    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.Cockpit.Panel.EFIS_NavRangeL.Target");

    intValue++;
    if (intValue > 5) intValue = 5;

    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_NavRangeL.Target", intValue);
  }
  else if (results_[2] == "-")
  {
    intValue = serialfp.ff320_api().GetValueIntByName("Aircraft.Cockpit.Panel.EFIS_NavRangeL.Target");

    intValue--;
    if (intValue < 0) intValue = 0;

    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_NavRangeL.Target", intValue);
  }
}

void XSFPHandlerFF320::PerformEFI(void)
{
  int intValue;

  if (results_[2] == "MTR")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.ShieldMastCautL.Click", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.ShieldMastCautL.Click", 0, 5);
  }
  else if (results_[2] == "FPV")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.ShieldMastWarnL.Click", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.ShieldMastWarnL.Click", 0, 5);
  }
  else if (results_[2] == "WX")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_NavType1L.Click", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.EFIS_NavType1L.Click", 0, 5);
  }
  else if (results_[2] == "STA")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_NavType2L.Click", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.EFIS_NavType2L.Click", 0, 5);
  }
  else if (results_[2] == "WPT")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_NavType3L.Click", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.EFIS_NavType3L.Click", 0, 5);
  }
  else if (results_[2] == "ARPT")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_NavType4L.Click", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.EFIS_NavType4L.Click", 0, 5);
  }
  else if (results_[2] == "DATA")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_NavType5L.Click", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.EFIS_NavType5L.Click", 0, 5);
  }
  else if (results_[2] == "POS")
  {
  }
  else if (results_[2] == "TERR")
  {
    intValue = 1;
    serialfp.ff320_api().SetValueIntByName("Aircraft.Cockpit.Panel.EFIS_TerrMapL.Click", intValue);
    XSFPFF320AddUpdateData("Aircraft.Cockpit.Panel.EFIS_TerrMapL.Click", 0, 5);
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

void XSFPHandlerFF320::PerformCOM(void)
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

void XSFPHandlerFF320::PerformNAV(void)
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

void XSFPHandlerFF320::PerformADF(void)
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

void XSFPHandlerFF320::PerformDME(void)
{
  if (results_[2] == "SEL")
  {
  }
}

void XSFPHandlerFF320::PerformTRN(void)
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
    char name[64];
    intValue = 1;
    //intValue = std::stoi(results_[3]);

    //XSFPLog("Set TRN %s(%d)\n", results_[3].str().c_str(), intValue);

    strcpy(name, "Aircraft.Cockpit.Pedestal.ATC_Num9.Click");
    serialfp.ff320_api().SetValueIntByName(name, intValue);

    XSFPFF320AddUpdateData(name, 1, 5);

    snprintf(name, 64, "Aircraft.Cockpit.Pedestal.ATC_Num%s.Click",
             results_[3].str().substr(0, 1).c_str());
    XSFPFF320AddUpdateData(name, 1, 10);

    snprintf(name, 64, "Aircraft.Cockpit.Pedestal.ATC_Num%s.Click",
             results_[3].str().substr(1, 1).c_str());
    XSFPFF320AddUpdateData(name, 1, 15);

    snprintf(name, 64, "Aircraft.Cockpit.Pedestal.ATC_Num%s.Click",
             results_[3].str().substr(2, 1).c_str());
    XSFPFF320AddUpdateData(name, 1, 20);

    snprintf(name, 64, "Aircraft.Cockpit.Pedestal.ATC_Num%s.Click",
             results_[3].str().substr(3, 1).c_str());
    XSFPFF320AddUpdateData(name, 1, 25);

    //XSFPLog("Set TRN %s(%d)\n", results_[3].str().c_str(), intValue);
    //serialfp.ff320_api().SetValueIntByName("Aircraft.Navigation.Transponder1.Code", intValue);
    //XPLMSetDatai(XPLMFindDataRef("sim/cockpit/radios/transponder_code"), intValue);
    //XPLMSetDatai(XPLMFindDataRef("sim/cockpit2/radios/actuators/transponder_code"), intValue);
  }
}

void XSFPHandlerFF320::PerformCTL(void)
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

