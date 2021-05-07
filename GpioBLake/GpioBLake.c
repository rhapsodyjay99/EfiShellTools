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

/***
  Demonstrates basic workings of the main() function by displaying a
  welcoming message.

  Note that the UEFI command line is composed of 16-bit UCS2 wide characters.
  The easiest way to access the command line parameters is to cast Argv as:
      wchar_t **wArgv = (wchar_t **)Argv;

  @param[in]  Argc    Number of argument tokens pointed to by Argv.
  @param[in]  Argv    Array of Argc pointers to command line tokens.

  @retval  0         The application exited normally.
  @retval  Other     An error occurred.
***/
#include "GpioBLake.h"

int
EFIAPI
main (
  IN int Argc,
  IN char **Argv
  )
{
  UINT8         PchSeries = GetPchSeries();
  
  if(Argv[1][0] == 'h' || Argv[1][0] == '?')
  {
     PrintHelpMsg();
  }
  if (PchSeries == AdlPchH)
  {
     if(Argv[1][0] == 'a' || Argv[1][0] == 'A') //Show All
     {
        ADL_DumpAllPCH_H();
     }

     if(Argv[1][0] == 'd' || Argv[1][0] == 'D')
     {
        if(Argv[2][0] == '0') //show community 0
        {
           ADL_DumpCommunity0PCH_H();
        }
        else if(Argv[2][0] == '1') //show community 1
        {
           ADL_DumpCommunity1PCH_H();
        }
        else if(Argv[2][0] == '2') //show community 2
        {
           ADL_DumpCommunity2PCH_H();
        }
        else if(Argv[2][0] == '3') //show community 3
        {
           ADL_DumpCommunity3PCH_H();
        }
        else if(Argv[2][0] == '4') //show community 4
        {
           ADL_DumpCommunity4PCH_H();
        }
        else if(Argv[2][0] == '5') //show community 5
        {
           ADL_DumpCommunity5PCH_H();
        }
     }

     if(Argv[1][0] == 'l' || Argv[1][0] == 'L') //Show Lock status
     {
        //CNL_DumpLockStatusPCH_H();
        Print(L"Not Porting yet");
     }
  }
  else if (PchSeries == AdlPchLp)
  {
     if(Argv[1][0] == 'a' || Argv[1][0] == 'A') //Show All
     {
        ADL_DumpAllPCH_LP();
     }

     if(Argv[1][0] == 'd' || Argv[1][0] == 'D')
     {
        if(Argv[2][0] == '0') //show community 0
        {
           ADL_DumpCommunity0PCH_LP();
        }
        else if(Argv[2][0] == '1') //show community 1
        {
           ADL_DumpCommunity1PCH_LP();
        }
        else if(Argv[2][0] == '2') //show community 2
        {
           ADL_DumpCommunity2_LP();
        }
        else if(Argv[2][0] == '3') //show community 3
        {
           ADL_DumpCommunity3PCH_LP();
        }
        else if(Argv[2][0] == '4') //show community 4
        {
           ADL_DumpCommunity4PCH_LP();
        }
        else if(Argv[2][0] == '5') //show community 5
        {
           ADL_DumpCommunity5PCH_LP();
        }
     }

     if(Argv[1][0] == 'l' || Argv[1][0] == 'L') //Show Lock status
     {
        //CNL_DumpLockStatusPCH_H();
        Print(L"Not Porting yet");
     }
  }
  else if (PchSeries == TglPchLp)
  {
     if(Argv[1][0] == 'a' || Argv[1][0] == 'A') //Show All
     {
        TGL_DumpAllPCH_LP();
     }

     if(Argv[1][0] == 'd' || Argv[1][0] == 'D')
     {
        if(Argv[2][0] == '0') //show community 0
        {
           TGL_DumpCommunity0PCH_LP();
        }
        else if(Argv[2][0] == '1') //show community 1
        {
           TGL_DumpCommunity1PCH_LP();
        }
        else if(Argv[2][0] == '2') //show community 2
        {
           TGL_DumpCommunity2_LP();
        }
        else if(Argv[2][0] == '3') //show community 3
        {
           TGL_DumpCommunity3PCH_LP();
        }
        else if(Argv[2][0] == '4') //show community 4
        {
           TGL_DumpCommunity4PCH_LP();
        }
        else if(Argv[2][0] == '5') //show community 5
        {
           TGL_DumpCommunity5PCH_LP();
        }
     }

     if(Argv[1][0] == 'l' || Argv[1][0] == 'L') //Show Lock status
     {
        //CNL_DumpLockStatusPCH_H();
        Print(L"Not Porting yet");
     }
  }
  else if (PchSeries == TglPchH)
  {
     if(Argv[1][0] == 'a' || Argv[1][0] == 'A') //Show All
     {
        TGL_DumpAllPCH_H();
     }

     if(Argv[1][0] == 'd' || Argv[1][0] == 'D')
     {
        if(Argv[2][0] == '0') //show community 0
        {
           TGL_DumpCommunity0PCH_H();
        }
        else if(Argv[2][0] == '1') //show community 1
        {
           TGL_DumpCommunity1PCH_H();
        }
        else if(Argv[2][0] == '2') //show community 2
        {
           TGL_DumpCommunity2();
        }
        else if(Argv[2][0] == '3') //show community 3
        {
           TGL_DumpCommunity3PCH_H();
        }
        else if(Argv[2][0] == '4') //show community 4
        {
           TGL_DumpCommunity4PCH_H();
        }
        else if(Argv[2][0] == '5') //show community 5
        {
           TGL_DumpCommunity5PCH_H();
        }
     }

     if(Argv[1][0] == 'l' || Argv[1][0] == 'L') //Show Lock status
     {
        //CNL_DumpLockStatusPCH_H();
        Print(L"Not Porting yet");
     }
  }
  else if (PchSeries == IclPchLp)
  {
     if(Argv[1][0] == 'a' || Argv[1][0] == 'A') //Show All
     {
        ICL_DumpAllPCH_LP();
     }

     if(Argv[1][0] == 'd' || Argv[1][0] == 'D')
     {
        if(Argv[2][0] == '0') //show community 0
        {
           ICL_DumpCommunity0PCH_LP();
        }
        else if(Argv[2][0] == '1') //show community 1
        {
           ICL_DumpCommunity1PCH_LP();
        }
        else if(Argv[2][0] == '2') //show community 2
        {
           ICL_DumpCommunity2();
        }
        else if(Argv[2][0] == '3') //show community 3
        {
           ICL_DumpCommunity3PCH_LP();
        }
        else if(Argv[2][0] == '4') //show community 4
        {
           ICL_DumpCommunity4PCH_LP();
        }
        else if(Argv[2][0] == '5') //show community 5
        {
           ICL_DumpCommunity5PCH_LP();
        }
     }

     if(Argv[1][0] == 'l' || Argv[1][0] == 'L') //Show Lock status
     {
        //CNL_DumpLockStatusPCH_H();
        Print(L"Not Porting yet");
     }
  }
  else if ((PchSeries == CnlPchH) || (PchSeries == CmlPchH))
  {
     if(Argv[1][0] == 'a' || Argv[1][0] == 'A') //Show All
     {
        CNL_DumpAllPCH_H();
     }

     if(Argv[1][0] == 'd' || Argv[1][0] == 'D')
     {
        if(Argv[2][0] == '0') //show community 0
        {
           CNL_DumpCommunity0PCH_H();
        }
        else if(Argv[2][0] == '1') //show community 1
        {
           CNL_DumpCommunity1PCH_H();
        }
        else if(Argv[2][0] == '2') //show community 2
        {
           CNL_DumpCommunity2();
        }
        else if(Argv[2][0] == '3') //show community 3
        {
           CNL_DumpCommunity3PCH_H();
        }
        else if(Argv[2][0] == '4') //show community 4
        {
           CNL_DumpCommunity4PCH_H();
        }
     }

     if(Argv[1][0] == 'l' || Argv[1][0] == 'L') //Show Lock status
     {
        CNL_DumpLockStatusPCH_H();
     }
  }
  else if(PchSeries == SklKblCmlvPchH)
  {
     if(Argv[1][0] == 'a' || Argv[1][0] == 'A') //Show All
     {
        SKL_DumpAllPCH_H();
     }

     if(Argv[1][0] == 'd' || Argv[1][0] == 'D')
     {
        if(Argv[2][0] == '0') //show community 0
        {
           SKL_DumpCommunity0();
        }
        else if(Argv[2][0] == '1') //show community 1
        {
           SKL_DumpCommunity1PCH_H();
        }
        else if(Argv[2][0] == '2') //show community 2
        {
           SKL_DumpCommunity2();
        }
        else if(Argv[2][0] == '3') //show community 3
        {
           SKL_DumpCommunity3PCH_H();
        }
        else if(Argv[2][0] == '4') //show community 4
        {
           Print(L"Group 4 Not Supported on SKL/KBL!!\n");
        }
     }
     if(Argv[1][0] == 'l' || Argv[1][0] == 'L') //Show Lock status
     {
        SKL_DumpLockStatusPCH_H();
     }
  }
  else if((PchSeries == CnlPchLp) || (PchSeries == CmlPchLp))
  {
     if(Argv[1][0] == 'a' || Argv[1][0] == 'A') //Show All
     {
        CNL_DumpAllPCH_LP();
     }

     if(Argv[1][0] == 'd' || Argv[1][0] == 'D')
     {
        if(Argv[2][0] == '0') //show community 0
        {
          CNL_DumpCommunity0PCH_LP();
        }
        else if(Argv[2][0] == '1') //show community 1
        {
          CNL_DumpCommunity1PCH_LP();
        }
        else if(Argv[2][0] == '2') //show community 2
        {
          CNL_DumpCommunity2();
        }
        else if(Argv[2][0] == '3') //show community 3
        {
          CNL_DumpCommunity3PCH_LP();
        }
        else if(Argv[2][0] == '4') //show community 4
        {
          CNL_DumpCommunity4PCH_LP();
        }
     }
     if(Argv[1][0] == 'l' || Argv[1][0] == 'L') //Show Lock status
     {
        CNL_DumpLockStatusPCH_LP();
     }
  }
  else if(PchSeries == SklKblPchLp)
  {
     if(Argv[1][0] == 'a' || Argv[1][0] == 'A') //Show All
     {
        SKL_DumpAllPCH_LP();
     }

     if(Argv[1][0] == 'd' || Argv[1][0] == 'D')
     {
        if(Argv[2][0] == '0') //show community 0
        {
          SKL_DumpCommunity0();
        }
        else if(Argv[2][0] == '1') //show community 1
        {
          SKL_DumpCommunity1PCH_LP();
        }
        else if(Argv[2][0] == '2') //show community 2
        {
          SKL_DumpCommunity2();
        }
        else if(Argv[2][0] == '3') //show community 3
        {
          SKL_DumpCommunity3PCH_LP();
        }
        else if(Argv[2][0] == '4') //show community 4
        {
          Print(L"Group 4 Not Supported on SKL/KBL!!\n");
        }
     }
     if(Argv[1][0] == 'l' || Argv[1][0] == 'L') //Show Lock status
     {
        SKL_DumpLockStatusPCH_LP();
     }
  }
  else
  {
    Print(L"Not Defined!!\n");
  }
  return 0;
}
 
UINT8 GetPchSeries ()
{
   UINT32  PchDevIdBase = PCI_LIB_ADDRESS(0,31,0,2);
   UINT16  PchDevId  = PciRead16(PchDevIdBase);

   switch (PchDevId & B_LPC_CFG_DID)
   {
      case V_LPC_CFG_DID_ADL_S:
         Print(L"PCH: AdlS\n");
         PchSeries = AdlPchH;
         break;

      case V_LPC_CFG_DID_ADL_P:
         Print(L"PCH: AdlP\n");
         PchSeries = AdlPchLp;
         break;

      case V_LPC_CFG_DID_TGL_LP:
         Print(L"PCH: TglLp\n");
         PchSeries = TglPchLp;
         break;
      
      case V_LPC_CFG_DID_TGL_H:
         Print(L"PCH: TglH\n");
         PchSeries = TglPchH;
         break;

      case V_LPC_CFG_DID_ICL_LP:
         Print(L"PCH: IclLp\n");
         PchSeries = IclPchLp;
         break;

      case V_LPC_CFG_DID_CML_H:
         Print(L"PCH: CmlH\n");
         PchSeries = CmlPchH;
         break;

      case V_LPC_CFG_DID_CML_LP:
         Print(L"PCH: CmlLp\n");
         PchSeries = CmlPchLp;
         break;

      case V_LPC_CFG_DID_CNL_LP:
         Print(L"PCH: CnlLp\n");
         PchSeries = CnlPchLp;
         break;
   
      case V_LPC_CFG_DID_CNL_H:
         Print(L"PCH: CnlH\n");
         PchSeries = CnlPchH;
         break;
   
      case V_LPC_CFG_DID_SKL_LP:
         Print(L"PCH: SklLp/KblLp\n");
         PchSeries = SklKblPchLp;
         break;
   
      case V_LPC_CFG_DID_SKL_H:
      case V_LPC_CFG_DID_KBL_H:
      case V_LPC_CFG_DID_CMLV_H:

         Print(L"PCH: SklH/KblH/CMLv\n");
         PchSeries = SklKblCmlvPchH;
         break;
   
      default:
         Print(L"PCH: Unknown\n");
         PchSeries = CnlPchLp;
         break;
   }

   return PchSeries;

}

VOID PrintHelpMsg()
{
   Print(L"GPIO tool Ver. 4.3\n\n");
   Print(L"To show help menu:\n");
   Print(L"fs#:\\>GpioBLake.efi ? or fs#:\\GpioBLake.efi h\n");
   Print(L"To Dump all Gpios:\n");
   Print(L"fs#:\\>GpioBLake.efi a\n");
   Print(L"To Dump Community x:\n");
   Print(L"fs#:\\>GpioBLake.efi d x<x = 0, 1, 2, 3, 4>\n");
   Print(L"To show Pad/Tx Lock status:\n");
   Print(L"fs#:\\>GpioBLake.efi L\n");
}
