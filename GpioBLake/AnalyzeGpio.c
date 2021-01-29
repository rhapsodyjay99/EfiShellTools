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


UINT32 BITn[] = {
                   0x00000001, 0x00000002, 0x00000004, 0x00000008, 
                   0x00000010, 0x00000020, 0x00000040, 0x00000080, 
                   0x00000100, 0x00000200, 0x00000400, 0x00000800, 
                   0x00001000, 0x00002000, 0x00004000, 0x00008000, 
                   0x00010000, 0x00020000, 0x00040000, 0x00080000, 
                   0x00100000, 0x00200000, 0x00400000, 0x00800000, 
                   0x01000000, 0x02000000, 0x04000000, 0x08000000,
                   0x10000000, 0x20000000, 0x40000000, 0x80000000 
                };


UINT32 GetPadValue ( UINT32 Community,
                     UINT32 Offset)
{
  return MmioRead32 (PCH_PCR_BASE_ADDRESS + (Community << 16) + Offset);
}

VOID ParseAndPrintPadStatus( 
   UINT32 Community,
   UINT32 GroupOffset,
   UINT8  GroupSize
   )
{
  UINT32        GpioPadValue;
  UINT8         i;
  UINT8         NatMode;

  PrintCommunityGroupHeader(Community, GroupOffset);

  for (i = 0; i < GroupSize; i++)
  {

    //GpioPadValue = GetPadValue (Community, GroupOffset + \
    //((PchSeries == CnlPchH || PchSeries == CnlPchLp || PchSeries == CmlPchH ||  PchSeries == CmlPchLp || PchSeries == IclPchLp || PchSeries == TglPchLp || PchSeries == TglPchH)? i*16 : i*8));
    GpioPadValue = GetPadValue (Community, GroupOffset + \
    ((PchSeries == SklKblPchLp || PchSeries == SklKblCmlvPchH)? i*8 : i*16));

    if(GpioPadValue == 0xffffffff)
    { 
       Print(L" %02d: NotOwned   %s",i, CRLF(i, NItemsARow));
    }
    else if (GpioPadValue == 0)
    {
       Print(L"Error!!!");
    }
    else
    {

       if((GpioPadValue & PadModeMask) >> PadModeOffset == PadModeGPIO) //GPIO
       {
          if((GpioPadValue & TXRXMask) >> TxRxModeOffset == Pad_Disable) //Disabled
          {
             Print(L" %02d: GPIO Dis   %s",i, CRLF(i, NItemsARow));
          }
          if((GpioPadValue & TXRXMask) >> TxRxModeOffset == Pad_OUT)  //GPO
          {
             Print(L" %02d: GPO %s   %s",i, (GpioPadValue & GPOHiLoMask) ? L"High":L"Low ", CRLF(i, NItemsARow));
          }
          if((GpioPadValue & TXRXMask) >> TxRxModeOffset == Pad_IN)  //GPI
          {
             Print(L" %02d: GPI %s   %s",i, (GpioPadValue & GPIHiLoMask) ? L"High":L"Low ", CRLF(i, NItemsARow));
          }
       }
       else                                                          //Native
       {
          NatMode = (GpioPadValue & PadModeMask) >> PadModeOffset;

          if((GpioPadValue & TXRXMask) >> TxRxModeOffset == Pad_Disable) //Disabled
          {
             Print(L" %02d: Nat%d Dis   %s",i, NatMode, CRLF(i, NItemsARow));
          }
          else if((GpioPadValue & TXRXMask) >> TxRxModeOffset == Pad_INOUT) // In & Out
          {
             Print(L" %02d: Nat%d In Out%s",i, NatMode, CRLF(i, NItemsARow));
          }
          if((GpioPadValue & TXRXMask) >> TxRxModeOffset == Pad_OUT)  //Out
          {
             Print(L" %02d: Nat%d Out %s %s",i, NatMode, (GpioPadValue & GPOHiLoMask) ? L"H" : L"L", CRLF(i, NItemsARow));
          }
          if((GpioPadValue & TXRXMask) >> TxRxModeOffset == Pad_IN)  //In
          {
             Print(L" %02d: Nat%d In %s  %s",i, NatMode,(GpioPadValue & GPOHiLoMask) ? L"H" : L"L",  CRLF(i, NItemsARow));
          }
       }
    }
  }
}

VOID ParseAndPrintLockStatus( 
   UINT32 Community,
   UINT32 GroupOffset,
   UINT32 LockOffset,
   UINT8  GroupSize
   )
{
   UINT32        GpioLockPadValue;
   UINT8         i;

  if (!(LockOffset & BIT2))
  {
     PrintCommunityGroupHeader(Community, GroupOffset);
  }
  GpioLockPadValue = GetPadValue (Community, LockOffset);

  if (!(LockOffset & BIT2))
  {
     Print(L"PadLock: ");
     for(i=0; i < GroupSize; i++)
     {
        if(GpioLockPadValue & BITn[i])
        {
          Print(L"%d ", i);
        }
     }
     Print(L"\n");
  }
  else
  {
     Print(L"TxLock:  ");
     for(i=0; i < GroupSize; i++)
     {
        if(GpioLockPadValue & BITn[i])
        {
          Print(L"%d ", i);
        }
     }
     Print(L"\n");
  }
}

VOID PrintAdlHGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  )
{
   if ((Community == ADL_PID_GPIOCOM0) && (GroupOffset == ADL_GPPIbase))
   {
      Print(L"Community 0:GPP_I\n");
   }
   else if ((Community == ADL_PID_GPIOCOM0) && (GroupOffset == ADL_GPPRbase))
   {
      Print(L"Community 0:GPP_R\n");
   }
   else if ((Community == ADL_PID_GPIOCOM0) && (GroupOffset == ADL_GPPJbase))
   {
      Print(L"Community 0:GPP_J\n");
   }
   else if (Community == ADL_PID_GPIOCOM1 && GroupOffset == ADL_GPPBbase)
   {
      Print(L"Community 1:GPP_B\n");
   }
   else if (Community == ADL_PID_GPIOCOM1 && GroupOffset == ADL_GPPGbase)
   {
      Print(L"Community 1:GPP_G\n");
   }
   else if (Community == ADL_PID_GPIOCOM1 && GroupOffset == ADL_GPPHbase)
   {
      Print(L"Community 1:GPP_H\n");
   }
   else if (Community == ADL_PID_GPIOCOM2 && GroupOffset == ADL_GPDbase)
   {
      Print(L"Community 2:GPD\n");
   }
   else if (Community == ADL_PID_GPIOCOM3 && GroupOffset == ADL_GPPAbase)
   {
      Print(L"Community 3:GPP_A\n");
   }
   else if (Community == ADL_PID_GPIOCOM3 && GroupOffset == ADL_GPPCbase)
   {
      Print(L"Community 3:GPP_C\n");
   }
   else if (Community == ADL_PID_GPIOCOM4 && GroupOffset == ADL_GPPSbase)
   {
      Print(L"Community 4:GPP_S\n");
   }
   else if (Community == ADL_PID_GPIOCOM4 && GroupOffset == ADL_GPPEbase)
   {
      Print(L"Community 4:GPP_E\n");
   }
   else if(Community == ADL_PID_GPIOCOM4 && GroupOffset == ADL_GPPKbase)
   {
      Print(L"Community 4:GPP_K\n");
   }
   else if(Community == ADL_PID_GPIOCOM4 && GroupOffset == ADL_GPPFbase)
   {
      Print(L"Community 4:GPP_F\n");
   }
   else if(Community == ADL_PID_GPIOCOM5 && GroupOffset == ADL_GPPDbase)
   {
      Print(L"Community 5:GPP_D\n");
   }
}

VOID PrintTglHGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  )
{
   if ((Community == TGL_PID_GPIOCOM0) && (GroupOffset == TGL_GPPAbase))
   {
      Print(L"Community 0:GPP_A\n");
   }
   else if ((Community == TGL_PID_GPIOCOM0) && (GroupOffset == TGL_GPPRbase))
   {
      Print(L"Community 0:GPP_R\n");
   }
   else if ((Community == TGL_PID_GPIOCOM0) && (GroupOffset == TGL_GPPBbase))
   {
      Print(L"Community 0:GPP_B\n");
   }
   else if (Community == TGL_PID_GPIOCOM1 && GroupOffset == TGL_GPPDbase)
   {
      Print(L"Community 1:GPP_D\n");
   }
   else if (Community == TGL_PID_GPIOCOM1 && GroupOffset == TGL_GPPCbase)
   {
      Print(L"Community 1:GPP_C\n");
   }
   else if (Community == TGL_PID_GPIOCOM1 && GroupOffset == TGL_GPPSbase)
   {
      Print(L"Community 1:GPP_S\n");
   }
   else if (Community == TGL_PID_GPIOCOM1 && GroupOffset == TGL_GPPGbase)
   {
      Print(L"Community 1:GPP_G\n");
   }
   else if (Community == TGL_PID_GPIOCOM2 && GroupOffset == TGL_GPDbase)
   {
      Print(L"Community 2:GPD\n");
   }
   else if (Community == TGL_PID_GPIOCOM3 && GroupOffset == TGL_GPPEbase)
   {
      Print(L"Community 3:GPP_E\n");
   }
   else if (Community == TGL_PID_GPIOCOM3 && GroupOffset == TGL_GPPFbase)
   {
      Print(L"Community 3:GPP_F\n");
   }
   else if (Community == TGL_PID_GPIOCOM4 && GroupOffset == TGL_GPPHbase)
   {
      Print(L"Community 4:GPP_H\n");
   }
   else if (Community == TGL_PID_GPIOCOM4 && GroupOffset == TGL_GPPJbase)
   {
      Print(L"Community 4:GPP_J\n");
   }
   else if(Community == TGL_PID_GPIOCOM4 && GroupOffset == TGL_GPPKbase)
   {
      Print(L"Community 4:GPP_K\n");
   }
   else if(Community == TGL_PID_GPIOCOM5 && GroupOffset == TGL_GPPIbase)
   {
      Print(L"Community 5:GPP_I\n");
   }
}


VOID PrintTglLpGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  )
{
   if ((Community == TGL_PID_GPIOCOM0) && (GroupOffset == TGL_LPGPPBbase))
   {
      Print(L"Community 0:GPP_B\n");
   }
   else if ((Community == TGL_PID_GPIOCOM0) && (GroupOffset == TGL_LPGPPTbase))
   {
      Print(L"Community 0:GPP_T\n");
   }
   else if (Community == TGL_PID_GPIOCOM0 && GroupOffset == TGL_LPGPPAbase)
   {
      Print(L"Community 0:GPP_A\n");
   }
   else if (Community == TGL_PID_GPIOCOM1 && GroupOffset == TGL_LPGPPSbase)
   {
      Print(L"Community 1:GPP_S\n");
   }
   else if (Community == TGL_PID_GPIOCOM1 && GroupOffset == TGL_LPGPPHbase)
   {
      Print(L"Community 1:GPP_H\n");
   }
   else if (Community == TGL_PID_GPIOCOM1 && GroupOffset == TGL_LPGPPDbase)
   {
      Print(L"Community 1:GPP_D\n");
   }
   else if (Community == TGL_PID_GPIOCOM1 && GroupOffset == TGL_LPGPPUbase)
   {
      Print(L"Community 1:GPP_U\n");
   }
   else if (Community == TGL_PID_GPIOCOM2 && GroupOffset == TGL_LPGPDbase)
   {
      Print(L"Community 2:GPD\n");
   }
   else if (Community == TGL_PID_GPIOCOM4 && GroupOffset == TGL_LPGPPCbase)
   {
      Print(L"Community 4:GPP_C\n");
   }
   else if (Community == TGL_PID_GPIOCOM4 && GroupOffset == TGL_LPGPPFbase)
   {
      Print(L"Community 4:GPP_F\n");
   }
   else if(Community == TGL_PID_GPIOCOM4 && GroupOffset == TGL_LPGPPEbase)
   {
      Print(L"Community 4:GPP_E\n");
   }
   else if(Community == TGL_PID_GPIOCOM5 && GroupOffset == TGL_LPGPPRbase)
   {
      Print(L"Community 5:GPP_R\n");
   }
}

VOID PrintIclLpGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  )
{
   if ((Community == ICL_PID_GPIOCOM0) && (GroupOffset == ICL_LPGPPGbase))
   {
      Print(L"Community 0:GPP_G\n");
   }
   else if ((Community == ICL_PID_GPIOCOM0) && (GroupOffset == ICL_LPGPPBbase))
   {
      Print(L"Community 0:GPP_B\n");
   }
   else if (Community == ICL_PID_GPIOCOM0 && GroupOffset == ICL_LPGPPAbase)
   {
      Print(L"Community 0:GPP_A\n");
   }
   else if (Community == ICL_PID_GPIOCOM1 && GroupOffset == ICL_LPGPPHbase)
   {
      Print(L"Community 1:GPP_H\n");
   }
   else if (Community == ICL_PID_GPIOCOM1 && GroupOffset == ICL_LPGPPDbase)
   {
      Print(L"Community 1:GPP_D\n");
   }
   else if (Community == ICL_PID_GPIOCOM1 && GroupOffset == ICL_LPGPPFbase)
   {
      Print(L"Community 1:GPP_F\n");
   }
   else if (Community == ICL_PID_GPIOCOM1 && GroupOffset == ICL_LPGPPv39base)
   {
      Print(L"Community 1:GPP_v39\n");
   }
   else if (Community == ICL_PID_GPIOCOM2 && GroupOffset == ICL_LPGPDbase)
   {
      Print(L"Community 2:GPD\n");
   }
   else if (Community == ICL_PID_GPIOCOM4 && GroupOffset == ICL_LPGPPCbase)
   {
      Print(L"Community 4:GPP_C\n");
   }
   else if(Community == ICL_PID_GPIOCOM4 && GroupOffset == ICL_LPGPPEbase)
   {
      Print(L"Community 4:GPP_E\n");
   }
   else if(Community == ICL_PID_GPIOCOM5 && GroupOffset == TGL_LPGPPRbase)
   {
      Print(L"Community 5:GPP_R\n");
   }
   else if(Community == ICL_PID_GPIOCOM5 && GroupOffset == ICL_LPGPPSbase)
   {
      Print(L"Community 5:GPP_S\n");
   }
}


VOID PrintCnlHGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  )
{
   if ((Community == CNL_PID_GPIOCOM0) && (GroupOffset == CNL_GPPAbase))
   {
      Print(L"Community 0:GPP_A\n");
   }
   else if ((Community == CNL_PID_GPIOCOM0) && (GroupOffset == CNL_GPPBbase))
   {
      Print(L"Community 0:GPP_B\n");
   }
   else if (Community == CNL_PID_GPIOCOM1 && GroupOffset == CNL_GPPCbase)
   {
      Print(L"Community 1:GPP_C\n");
   }
   else if (Community == CNL_PID_GPIOCOM1 && GroupOffset == CNL_GPPDbase)
   {
      Print(L"Community 1:GPP_D\n");
   }
   else if (Community == CNL_PID_GPIOCOM1 && GroupOffset == CNL_GPPGbase)
   {
      Print(L"Community 1:GPP_G\n");
   }
   else if (Community == CNL_PID_GPIOCOM2 && GroupOffset == CNL_GPDbase)
   {
      Print(L"Community 2:GPD\n");
   }
   else if (Community == CNL_PID_GPIOCOM3 && GroupOffset == CNL_GPPKbase)
   {
      Print(L"Community 3:GPP_K\n");
   }
   else if (Community == CNL_PID_GPIOCOM3 && GroupOffset == CNL_GPPHbase)
   {
      Print(L"Community 3:GPP_H\n");
   }
   else if (Community == CNL_PID_GPIOCOM3 && GroupOffset == CNL_GPPEbase)
   {
      Print(L"Community 3:GPP_E\n");
   }
   else if (Community == CNL_PID_GPIOCOM3 && GroupOffset == CNL_GPPFbase)
   {
      Print(L"Community 3:GPP_F\n");
   }
   else if (Community == CNL_PID_GPIOCOM4 && GroupOffset == CNL_GPPIbase)
   {
      Print(L"Community 4:GPP_I\n");
   }
   else if(Community == CNL_PID_GPIOCOM4 && GroupOffset == CNL_GPPJbase)
   {
      Print(L"Community 4:GPP_J\n");
   }
}

VOID PrintCnlLpGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  )
{
   if ((Community == CNL_PID_GPIOCOM0) && (GroupOffset == CNL_LPGPPAbase))
   {
      Print(L"Community 0:GPP_A\n");
   }
   else if ((Community == CNL_PID_GPIOCOM0) && (GroupOffset == CNL_LPGPPBbase))
   {
      Print(L"Community 0:GPP_B\n");
   }
   else if (Community == CNL_PID_GPIOCOM0 && GroupOffset == CNL_LPGPPGbase)
   {
      Print(L"Community 0:GPP_G\n");
   }
   else if (Community == CNL_PID_GPIOCOM1 && GroupOffset == CNL_LPGPPDbase)
   {
      Print(L"Community 1:GPP_D\n");
   }
   else if (Community == CNL_PID_GPIOCOM1 && GroupOffset == CNL_LPGPPFbase)
   {
      Print(L"Community 1:GPP_F\n");
   }
   else if (Community == CNL_PID_GPIOCOM1 && GroupOffset == CNL_LPGPPHbase)
   {
      Print(L"Community 1:GPP_H\n");
   }
   else if (Community == CNL_PID_GPIOCOM2 && GroupOffset == CNL_LPGPDbase)
   {
      Print(L"Community 2:GPD\n");
   }
   else if (Community == CNL_PID_GPIOCOM3 && GroupOffset == CNL_LPGPPAudbase)
   {
      Print(L"Community 3:GPPAud\n");
   }
   else if (Community == CNL_PID_GPIOCOM4 && GroupOffset == CNL_LPGPPCbase)
   {
      Print(L"Community 4:GPP_C\n");
   }
   else if(Community == CNL_PID_GPIOCOM4 && GroupOffset == CNL_LPGPPEbase)
   {
      Print(L"Community 4:GPP_E\n");
   }
}

VOID PrintSklHGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  )
{
   if ((Community == SKL_PID_GPIOCOM0) && (GroupOffset == SKL_GPPAbase))
   {
      Print(L"Community 0:GPP_A\n");
   }
   else if ((Community == SKL_PID_GPIOCOM0) && (GroupOffset == SKL_GPPBbase))
   {
      Print(L"Community 0:GPP_B\n");
   }
   else if (Community == SKL_PID_GPIOCOM1 && GroupOffset == SKL_GPPCbase)
   {
      Print(L"Community 1:GPP_C\n");
   }
   else if (Community == SKL_PID_GPIOCOM1 && GroupOffset == SKL_GPPDbase)
   {
      Print(L"Community 1:GPP_D\n");
   }
   else if (Community == SKL_PID_GPIOCOM1 && GroupOffset == SKL_GPPEbase)
   {
      Print(L"Community 1:GPP_E\n");
   }
   else if (Community == SKL_PID_GPIOCOM1 && GroupOffset == SKL_GPPFbase)
   {
      Print(L"Community 1:GPP_F\n");
   }
   else if (Community == SKL_PID_GPIOCOM1 && GroupOffset == SKL_GPPGbase)
   {
      Print(L"Community 1:GPP_G\n");
   }
   else if (Community == SKL_PID_GPIOCOM1 && GroupOffset == SKL_GPPHbase)
   {
      Print(L"Community 1:GPP_H\n");
   }
   else if (Community == SKL_PID_GPIOCOM2 && GroupOffset == SKL_GPDbase)
   {
      Print(L"Community 2:GPD\n");
   }
   else if (Community == SKL_PID_GPIOCOM3 && GroupOffset == SKL_GPPIbase)
   {
      Print(L"Community 3:GPP_I\n");
   }
}

VOID PrintSklLpGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  )
{
   if ((Community == SKL_PID_GPIOCOM0) && (GroupOffset == SKL_LPGPPAbase))
   {
      Print(L"Community 0:GPP_A\n");
   }
   else if ((Community == SKL_PID_GPIOCOM0) && (GroupOffset == SKL_LPGPPBbase))
   {
      Print(L"Community 0:GPP_B\n");
   }
   else if (Community == SKL_PID_GPIOCOM1 && GroupOffset == SKL_LPGPPCbase)
   {
      Print(L"Community 1:GPP_C\n");
   }
   else if (Community == SKL_PID_GPIOCOM1 && GroupOffset == SKL_LPGPPDbase)
   {
      Print(L"Community 1:GPP_D\n");
   }
   else if (Community == SKL_PID_GPIOCOM1 && GroupOffset == SKL_LPGPPEbase)
   {
      Print(L"Community 1:GPP_E\n");
   }
   else if (Community == SKL_PID_GPIOCOM2 && GroupOffset == SKL_GPDbase)
   {
      Print(L"Community 2:GPD\n");
   }
   else if (Community == SKL_PID_GPIOCOM3 && GroupOffset == SKL_LPGPPFbase)
   {
      Print(L"Community 3:GPP_F\n");
   }
   else if (Community == SKL_PID_GPIOCOM3 && GroupOffset == SKL_LPGPPGbase)
   {
      Print(L"Community 3:GPP_G\n");
   }
}

VOID
PrintCommunityGroupHeader(
   UINT32 Community,
   UINT32 GroupOffset
   )
{
  SetColor(EFI_YELLOW);

  switch (PchSeries)
  {
     case TglPchH:
        PrintTglHGroupName(Community, GroupOffset);
        break;

     case TglPchLp:
        PrintTglLpGroupName(Community, GroupOffset);
        break;

     case IclPchLp:
        PrintIclLpGroupName(Community, GroupOffset);
        break;

     case CnlPchH:
     case CmlPchH:
        PrintCnlHGroupName(Community, GroupOffset);
        break;

     case CnlPchLp:
     case CmlPchLp:
        PrintCnlLpGroupName(Community, GroupOffset);
        break;

     case SklKblCmlvPchH:
        PrintSklHGroupName(Community, GroupOffset);
        break;

     case SklKblPchLp:
        PrintSklLpGroupName(Community, GroupOffset);
        break;

     default:
        break;
  }

  SetColor(EFI_WHITE);
}

VOID SetColor(UINT8 Color)
{
   gST->ConOut->SetAttribute(gST->ConOut, EFI_TEXT_ATTR(Color, EFI_BLACK));
}
