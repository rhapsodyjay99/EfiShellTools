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

VOID TGL_DumpAllPCH_H()
{

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM0, TGL_GPPAbase, GroupSize15);
   Print(L"\n");

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM0, TGL_GPPRbase, GroupSize20);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM0, TGL_GPPBbase, GroupSize24);
  
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_GPPDbase, GroupSize24);
     
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_GPPCbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_GPPSbase, GroupSize8);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_GPPGbase, GroupSize16);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM2, TGL_GPDbase, GroupSize13);
   Print(L"\n");
  
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM3, TGL_GPPEbase, GroupSize13);
   Print(L"\n");

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM3, TGL_GPPFbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM4, TGL_GPPHbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM4, TGL_GPPJbase, GroupSize10);
   Print(L"\n");
 
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM4, TGL_GPPKbase, GroupSize12);  

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM5, TGL_GPPIbase, GroupSize15);  
   Print(L"\n");

}

VOID TGL_DumpAllPCH_LP()
{

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM0, TGL_LPGPPBbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM0, TGL_LPGPPTbase, GroupSize2);
   Print(L"\n");

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM0, TGL_LPGPPAbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_LPGPPSbase, GroupSize8);
 
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_LPGPPHbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_LPGPPDbase, GroupSize20);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_LPGPPUbase, GroupSize2);
   Print(L"\n");

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM2, TGL_LPGPDbase,  GroupSize12);
 
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM4, TGL_LPGPPCbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM4, TGL_LPGPPFbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM4, TGL_LPGPPEbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM5, TGL_LPGPPRbase, GroupSize8);
   Print(L"\n");
}

VOID TGL_DumpCommunity0PCH_H()
{
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM0, TGL_GPPAbase, GroupSize15);
   Print(L"\n");

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM0, TGL_GPPRbase, GroupSize20);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM0, TGL_GPPBbase, GroupSize24);
}

VOID TGL_DumpCommunity0PCH_LP()
{
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM0, TGL_LPGPPBbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM0, TGL_LPGPPTbase, GroupSize2);
   Print(L"\n");

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM0, TGL_LPGPPAbase, GroupSize24);
}


VOID TGL_DumpCommunity1PCH_H()
{
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_GPPDbase, GroupSize24);
     
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_GPPCbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_GPPSbase, GroupSize8);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_GPPGbase, GroupSize16);
}

VOID TGL_DumpCommunity1PCH_LP()
{
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_LPGPPSbase, GroupSize8);
 
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_LPGPPHbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_LPGPPDbase, GroupSize20);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM1, TGL_LPGPPUbase, GroupSize2);
   Print(L"\n");
}

VOID TGL_DumpCommunity2()
{
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM2, TGL_GPDbase,  GroupSize13);
   Print(L"\n");
}

VOID TGL_DumpCommunity2_LP()
{
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM2, TGL_LPGPDbase,  GroupSize12);
   Print(L"\n");
}

VOID TGL_DumpCommunity3PCH_H()
{
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM3, TGL_GPPEbase, GroupSize13);
   Print(L"\n");

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM3, TGL_GPPFbase, GroupSize24);
}

VOID TGL_DumpCommunity3PCH_LP()
{
  // ParseAndPrintPadStatus(CNL_PID_GPIOCOM3, CNL_LPGPPAudbase, GroupSize8);
  Print(L"Tiger Lake LP don't have GPIO Community 3\n");
}

VOID TGL_DumpCommunity4PCH_H()
{
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM4, TGL_GPPHbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM4, TGL_GPPJbase, GroupSize10);
   Print(L"\n");
 
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM4, TGL_GPPKbase, GroupSize12);  
}

VOID TGL_DumpCommunity4PCH_LP()
{  
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM4, TGL_LPGPPCbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM4, TGL_LPGPPFbase, GroupSize24);

   ParseAndPrintPadStatus(TGL_PID_GPIOCOM4, TGL_LPGPPEbase, GroupSize24);
   Print(L"\n");
}

VOID TGL_DumpCommunity5PCH_H()
{  
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM5, TGL_GPPIbase, GroupSize15);  
   Print(L"\n");
}

VOID TGL_DumpCommunity5PCH_LP()
{  
   ParseAndPrintPadStatus(TGL_PID_GPIOCOM5, TGL_LPGPPRbase, GroupSize8);
   Print(L"\n");
}

/*
VOID CNL_DumpLockStatusPCH_H()
{

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM0, CNL_GPPAbase, CNL_GPPAPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM0, CNL_GPPAbase, CNL_GPPAPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM0, CNL_GPPBbase, CNL_GPPBPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM0, CNL_GPPBbase, CNL_GPPBPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM1, CNL_GPPCbase, CNL_GPPCPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM1, CNL_GPPCbase, CNL_GPPCPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM1, CNL_GPPDbase, CNL_GPPDPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM1, CNL_GPPDbase, CNL_GPPDPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM1, CNL_GPPGbase, CNL_GPPGPadLockbase, GroupSize8);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM1, CNL_GPPGbase, CNL_GPPGPadTxLockbase, GroupSize8);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM2, CNL_GPDbase,  CNL_GPDPadLockbase,  GroupSize12);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM2, CNL_GPDbase,  CNL_GPDPadTxLockbase,  GroupSize12);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM3, CNL_GPPKbase, CNL_GPPKPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM3, CNL_GPPKbase, CNL_GPPKPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM3, CNL_GPPHbase, CNL_GPPHPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM3, CNL_GPPHbase, CNL_GPPHPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM3, CNL_GPPEbase, CNL_GPPEPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM3, CNL_GPPEbase, CNL_GPPEPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM3, CNL_GPPFbase, CNL_GPPFPadLockbase, GroupSize13);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM3, CNL_GPPFbase, CNL_GPPFPadTxLockbase, GroupSize13);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM4, CNL_GPPIbase, CNL_GPPIPadLockbase, GroupSize15);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM4, CNL_GPPIbase, CNL_GPPIPadTxLockbase, GroupSize15);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM4, CNL_GPPJbase, CNL_GPPJPadLockbase, GroupSize12);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM4, CNL_GPPJbase, CNL_GPPJPadTxLockbase, GroupSize12);

}

VOID CNL_DumpLockStatusPCH_LP()
{
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM0, CNL_LPGPPAbase, CNL_LPGPPAPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM0, CNL_LPGPPAbase, CNL_LPGPPAPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM0, CNL_LPGPPBbase, CNL_LPGPPBPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM0, CNL_LPGPPBbase, CNL_LPGPPBPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM0, CNL_LPGPPGbase, CNL_LPGPPGPadLockbase, GroupSize8);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM0, CNL_LPGPPGbase, CNL_LPGPPGPadTxLockbase, GroupSize8);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM1, CNL_LPGPPDbase, CNL_LPGPPDPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM1, CNL_LPGPPDbase, CNL_LPGPPDPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM1, CNL_LPGPPFbase, CNL_LPGPPFPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM1, CNL_LPGPPFbase, CNL_LPGPPFPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM1, CNL_LPGPPHbase, CNL_LPGPPHPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM1, CNL_LPGPPHbase, CNL_LPGPPHPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM2, CNL_LPGPDbase,  CNL_LPGPDPadLockbase, GroupSize12);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM2, CNL_LPGPDbase,  CNL_LPGPDPadTxLockbase, GroupSize12);

   //ParseAndPrintLockStatus(CNL_PID_GPIOCOM3, CNL_LPGPPAudbase, CNL_LPGPPGPadLockbase, GroupSize8);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM4, CNL_LPGPPCbase, CNL_LPGPPCPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM4, CNL_LPGPPCbase, CNL_LPGPPCPadTxLockbase, GroupSize24);

   ParseAndPrintLockStatus(CNL_PID_GPIOCOM4, CNL_LPGPPEbase, CNL_LPGPPEPadLockbase, GroupSize24);
   ParseAndPrintLockStatus(CNL_PID_GPIOCOM4, CNL_LPGPPEbase, CNL_LPGPPEPadTxLockbase, GroupSize24);
}
*/