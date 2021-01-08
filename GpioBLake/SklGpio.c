/** @file
    A simple, basic, application showing how the Hello application could be
    built using the "Standard C Libraries" from StdLib.

    Copyright (c) 2010 - 2011, Intel Corporation. All rights reserved.<BR>
    This program and the accompanying materials
    are licensed and made available under the terms and conditions of the BSD License
    which accompanies this distribution. The full text of the license may be found at
    http://opensource.org/licenses/bsd-license.

    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
**/
#include "GpioBLake.h"

VOID SKL_DumpAllPCH_H()
{
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM0, SKL_GPPAbase, GroupSize24);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM0, SKL_GPPBbase, GroupSize24);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPCbase, GroupSize24);
   
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPDbase, GroupSize24);
     
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPEbase, GroupSize13);
   Print(L"\n");
      
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPFbase, GroupSize24);
     
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPGbase, GroupSize24);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPHbase, GroupSize24);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM2, SKL_GPDbase, GroupSize12);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM3, SKL_GPPIbase, GroupSize11);
   Print(L"\n");
}

VOID SKL_DumpAllPCH_LP ()
{
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM0, SKL_LPGPPAbase, GroupSize24);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM0, SKL_LPGPPBbase, GroupSize24);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_LPGPPCbase, GroupSize24);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_LPGPPDbase, GroupSize24);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_LPGPPEbase, GroupSize24);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM2, SKL_LPGPDbase, GroupSize12);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM3, SKL_LPGPPFbase, GroupSize24);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM3, SKL_LPGPPGbase, GroupSize8);
}

VOID SKL_DumpCommunity0()
{

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM0, SKL_GPPAbase, GroupSize24);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM0, SKL_GPPBbase, GroupSize24);
}

VOID SKL_DumpCommunity1PCH_H()
{

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPCbase, GroupSize24);
   
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPDbase, GroupSize24);
       
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPEbase, GroupSize13);
   Print(L"\n");
      
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPFbase, GroupSize24);
   
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPGbase, GroupSize24);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPHbase, GroupSize24);
}

VOID SKL_DumpCommunity1PCH_LP ()
{
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPCbase, GroupSize24);
   
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_GPPDbase, GroupSize24);
      
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM1, SKL_LPGPPEbase, GroupSize24);
}

VOID SKL_DumpCommunity2()
{
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM2, SKL_GPDbase, GroupSize12);
}

VOID SKL_DumpCommunity3PCH_H()
{
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM3, SKL_GPPIbase, GroupSize11);  
   Print(L"\n");
}

VOID SKL_DumpCommunity3PCH_LP ()
{
   ParseAndPrintPadStatus(SKL_PID_GPIOCOM3, SKL_LPGPPFbase, GroupSize24);

   ParseAndPrintPadStatus(SKL_PID_GPIOCOM3, SKL_LPGPPGbase, GroupSize8);
}

VOID SKL_DumpLockStatusPCH_H()
{
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM0, SKL_GPPAbase, SKL_GPPAPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM0, SKL_GPPAbase, SKL_GPPAPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM0, SKL_GPPBbase, SKL_GPPBPadLockbase,  GroupSize24);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM0, SKL_GPPBbase, SKL_GPPBPadTxLockbase,  GroupSize24);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_GPPCbase, SKL_GPPCPadLockbase,  GroupSize24);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_GPPCbase, SKL_GPPCPadTxLockbase,  GroupSize24);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_GPPDbase, SKL_GPPDPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_GPPDbase, SKL_GPPDPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_GPPEbase, SKL_GPPEPadLockbase, GroupSize13);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_GPPEbase, SKL_GPPEPadTxLockbase, GroupSize13);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_GPPFbase, SKL_GPPFPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_GPPFbase, SKL_GPPFPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_GPPGbase, SKL_GPPGPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_GPPGbase, SKL_GPPGPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_GPPHbase, SKL_GPPHPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_GPPHbase, SKL_GPPHPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM2, SKL_GPDbase, SKL_GPDPadLockbase, GroupSize12);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM2, SKL_GPDbase, SKL_GPDPadTxLockbase, GroupSize12);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM3, SKL_GPPIbase, SKL_GPPIPadLockbase, GroupSize11);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM3, SKL_GPPIbase, SKL_GPPIPadTxLockbase, GroupSize11);
}

VOID SKL_DumpLockStatusPCH_LP()
{
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM0, SKL_LPGPPAbase, SKL_LPGPPAPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM0, SKL_LPGPPAbase, SKL_LPGPPAPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM0, SKL_LPGPPBbase, SKL_LPGPPBPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM0, SKL_LPGPPBbase, SKL_LPGPPBPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_LPGPPCbase, SKL_LPGPPCPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_LPGPPCbase, SKL_LPGPPCPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_LPGPPDbase, SKL_LPGPPDPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_LPGPPDbase, SKL_LPGPPDPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_LPGPPEbase, SKL_LPGPPEPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM1, SKL_LPGPPEbase, SKL_LPGPPEPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM2, SKL_LPGPDbase, SKL_LPGPDPadLockbase, GroupSize12);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM2, SKL_LPGPDbase, SKL_LPGPDPadTxLockbase, GroupSize12);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM3, SKL_LPGPPFbase, SKL_LPGPPFPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM3, SKL_LPGPPFbase, SKL_LPGPPFPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(SKL_PID_GPIOCOM3, SKL_LPGPPGbase, SKL_LPGPPGPadLockbase, GroupSize8);
   ParseAndPrintLockStatus(SKL_PID_GPIOCOM3, SKL_LPGPPGbase, SKL_LPGPPGPadTxLockbase, GroupSize8);
}
