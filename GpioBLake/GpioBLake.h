#ifndef _GPIOBLAKE_H_
#define _GPIOBLAKE_H_

#include  <stdio.h>
#include  <Library/UefiLib.h>
#include  <Library/UefiBootServicesTableLib.h>
#include  <Library/UefiRuntimeServicesTableLib.h>
#include  <Library/IoLib.h>
#include  <Library/PciLib.h>

#define PCI_LIB_ADDRESS(Bus,Device,Function,Register)   \
  (((Register) & 0xfff) | (((Function) & 0x07) << 12) | (((Device) & 0x1f) << 15) | (((Bus) & 0xff) << 20))

#define PCH_PCR_BASE_ADDRESS            0xFD000000     ///< SBREG MMIO base address
#define PCH_PCR_ADDRESS(Pid, Offset)    (PCH_PCR_BASE_ADDRESS | ((UINT8)(Pid) << 16) | (UINT16)(Offset))

#define CRLF(Index, n) ((Index % n) == (n-1)) ? L"\r\n" : L""
#define NItemsARow  4

enum
{
   SklKblPchLp = 0,
   SklKblCmlvPchH = 1, 
   CnlPchLp = 2,
   CnlPchH = 3,
   CmlPchLp = 4,
   CmlPchH = 5,
   IclPchH = 6,
   IclPchLp = 7,
   TglPchLp = 8,
   TglPchH = 9
};

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

//Function declaration
UINT8  GetPchSeries (void);
UINT8  PchSeries;

UINT32 
GetPadValue(
   UINT32 Community,
   UINT32 Offset
   );

VOID 
ParseAndPrintPadStatus(
   UINT32 Community,
   UINT32 GroupOffset,
   UINT8  GroupSize
   );

VOID 
ParseAndPrintLockStatus( 
   UINT32 Community,
   UINT32 GroupOffset,
   UINT32 LockOffset,
   UINT8  GroupSize
   );
//TGL dump functions
//Dump PCH-H
VOID TGL_DumpAllPCH_H (void);
VOID TGL_DumpCommunity0PCH_H (void);
VOID TGL_DumpCommunity2 (void);
VOID TGL_DumpCommunity1PCH_H (void);
VOID TGL_DumpCommunity3PCH_H (void);
VOID TGL_DumpCommunity4PCH_H (void);
VOID TGL_DumpCommunity5PCH_H (void);
VOID TGL_DumpLockStatusPCH_H(void);
//Dump PCH-LP
VOID TGL_DumpAllPCH_LP (void);
VOID TGL_DumpCommunity0PCH_LP (void);
VOID TGL_DumpCommunity1PCH_LP (void);
VOID TGL_DumpCommunity2_LP (void);
VOID TGL_DumpCommunity3PCH_LP (void);
VOID TGL_DumpCommunity4PCH_LP (void);
VOID TGL_DumpCommunity5PCH_LP (void);
VOID TGL_DumpLockStatusPCH_LP(void);
//ICL dump functions
//Dump PCH-H
VOID ICL_DumpAllPCH_H (void);
VOID ICL_DumpCommunity0PCH_H (void);
VOID ICL_DumpCommunity2 (void);
VOID ICL_DumpCommunity1PCH_H (void);
VOID ICL_DumpCommunity3PCH_H (void);
VOID ICL_DumpCommunity4PCH_H (void);
VOID ICL_DumpLockStatusPCH_H(void);
//Dump PCH-LP
VOID ICL_DumpAllPCH_LP (void);
VOID ICL_DumpCommunity0PCH_LP (void);
VOID ICL_DumpCommunity1PCH_LP (void);
VOID ICL_DumpCommunity3PCH_LP (void);
VOID ICL_DumpCommunity4PCH_LP (void);
VOID ICL_DumpCommunity5PCH_LP (void);
VOID ICL_DumpLockStatusPCH_LP(void);
//CNL dump functions
//Dump PCH-H
VOID CNL_DumpAllPCH_H (void);
VOID CNL_DumpCommunity0PCH_H (void);
VOID CNL_DumpCommunity2 (void);
VOID CNL_DumpCommunity1PCH_H (void);
VOID CNL_DumpCommunity3PCH_H (void);
VOID CNL_DumpCommunity4PCH_H (void);
VOID CNL_DumpLockStatusPCH_H(void);
//Dump PCH-LP
VOID CNL_DumpAllPCH_LP (void);
VOID CNL_DumpCommunity0PCH_LP (void);
VOID CNL_DumpCommunity1PCH_LP (void);
VOID CNL_DumpCommunity3PCH_LP (void);
VOID CNL_DumpCommunity4PCH_LP (void);
VOID CNL_DumpLockStatusPCH_LP(void);
//SKL & KBL dump functions
//Dump PCH-H
VOID SKL_DumpAllPCH_H (void);
VOID SKL_DumpCommunity0 (void);
VOID SKL_DumpCommunity2 (void);
VOID SKL_DumpCommunity1PCH_H (void);
VOID SKL_DumpCommunity3PCH_H (void);
VOID SKL_DumpLockStatusPCH_H(void);
//Dump PCH-LP
VOID SKL_DumpAllPCH_LP (void);
VOID SKL_DumpCommunity1PCH_LP (void);
VOID SKL_DumpCommunity3PCH_LP (void);
VOID SKL_DumpLockStatusPCH_LP(void);

VOID SetColor(UINT8 Color);
VOID PrintHelpMsg (void);

VOID PrintTglLpGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  );

VOID PrintTglHGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  );

VOID PrintIclLpGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  );

VOID PrintCnlHGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  );

VOID PrintCnlLpGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  );

VOID PrintSklHGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  );

VOID PrintSklLpGroupName (
   UINT32 Community,
   UINT32 GroupOffset
  );

VOID PrintCommunityGroupHeader(
   UINT32 Community,
   UINT32 GroupOffset
   );
//GPIO DW0 definitions
#define   PadModeMask      0x00000C00  //BIT[11:10] Mode: 0: GPIO 1:NativeFunction1 2:NativeFunction2 3:NativeFunction3
#define   TXRXMask         0x00000300  //Bit8: GPIO TX disable  Bit9: GPIO RX disable
#define   GPIHiLoMask      0x00000002  
#define   GPOHiLoMask      0x00000001
#define   PadModeOffset    10
#define   TxRxModeOffset   8
#define   PadModeGPIO      0
#define   Pad_Disable      3
#define   Pad_OUT          2
#define   Pad_IN           1
#define   Pad_INOUT        0
// TGL
#define   TGL_PID_GPIOCOM0 0x0000006E
#define   TGL_PID_GPIOCOM1 0x0000006D
#define   TGL_PID_GPIOCOM2 0x0000006C
#define   TGL_PID_GPIOCOM3 0x0000006B
#define   TGL_PID_GPIOCOM4 0x0000006A
#define   TGL_PID_GPIOCOM5 0x00000069
// ICL
#define   ICL_PID_GPIOCOM0 0x0000006E
#define   ICL_PID_GPIOCOM1 0x0000006D
#define   ICL_PID_GPIOCOM2 0x0000006C
#define   ICL_PID_GPIOCOM3 0x0000006B
#define   ICL_PID_GPIOCOM4 0x0000006A
#define   ICL_PID_GPIOCOM5 0x00000069
// CNL
#define   CNL_PID_GPIOCOM0 0x0000006E
#define   CNL_PID_GPIOCOM1 0x0000006D
#define   CNL_PID_GPIOCOM2 0x0000006C
#define   CNL_PID_GPIOCOM3 0x0000006B
#define   CNL_PID_GPIOCOM4 0x0000006A
// SKL & KBL
#define   SKL_PID_GPIOCOM0 0x000000AF
#define   SKL_PID_GPIOCOM1 0x000000AE
#define   SKL_PID_GPIOCOM2 0x000000AD
#define   SKL_PID_GPIOCOM3 0x000000AC

//TGL Group Base definition
//PCH-H
//PCH-H Community 0
#define  TGL_GPPAbase               0x00000680
#define  TGL_GPPRbase               0x00000790
#define  TGL_GPPBbase               0x000008D0
//PCH-H Community 1
#define  TGL_GPPDbase               0x00000600
#define  TGL_GPPCbase               0x000007A0
#define  TGL_GPPSbase               0x00000920
#define  TGL_GPPGbase               0x000009A0
//PCH-H Community 2
#define  TGL_GPDbase                0x00000600
//PCH-H Community 3
#define  TGL_GPPEbase               0x00000600
#define  TGL_GPPFbase               0x000006D0
//PCH-H Community 4
#define  TGL_GPPHbase               0x00000600
#define  TGL_GPPJbase               0x00000780
#define  TGL_GPPKbase               0x00000820
//PCH-H Community 5
#define  TGL_GPPIbase               0x00000600
//PCH-LP Community 0
#define   TGL_LPGPPBbase            0x00000700
#define   TGL_LPGPPTbase            0x000008C0
#define   TGL_LPGPPAbase            0x000009A0
//PCH-LP Community 1
#define   TGL_LPGPPSbase            0x00000700
#define   TGL_LPGPPHbase            0x00000780
#define   TGL_LPGPPDbase            0x00000900
#define   TGL_LPGPPUbase            0x00000A90
//PCH-LP Community 2
#define   TGL_LPGPDbase             0x00000700
//PCH-LP Community 3
//reserved
//PCH-LP Community 4
#define   TGL_LPGPPCbase            0x00000700
#define   TGL_LPGPPFbase            0x00000880
#define   TGL_LPGPPEbase            0x00000A70
//PCH-LP Community 5
#define   TGL_LPGPPRbase            0x00000700
//ICL Group Base definition
//PCH-H
//Reserved
//PCH-LP Community 0
#define   ICL_LPGPPGbase            0x00000600
#define   ICL_LPGPPBbase            0x00000680
#define   ICL_LPGPPAbase            0x00000820
//PCH-LP Community 1
#define   ICL_LPGPPHbase            0x00000600
#define   ICL_LPGPPDbase            0x00000780
#define   ICL_LPGPPFbase            0x000008D0
#define   ICL_LPGPPv39base          0x00000BD0
//PCH-LP Community 2
#define   ICL_LPGPDbase             0x00000600
//PCH-LP Community 3
//reserved
//PCH-LP Community 4
#define   ICL_LPGPPCbase            0x00000600
#define   ICL_LPGPPEbase            0x000007E0
//PCH-LP Community 5
#define   ICL_LPGPPRbase            0x00000600
#define   ICL_LPGPPSbase            0x00000680
//CNL Group Base definition
//CNL Group Base definition
//PCH-H Community 0
#define   CNL_GPPAPadLockbase       0x00000080
#define   CNL_GPPAPadTxLockbase     0x00000084
#define   CNL_GPPBPadLockbase       0x00000088
#define   CNL_GPPBPadTxLockbase     0x0000008C
#define   CNL_GPPAbase              0x00000600
#define   CNL_GPPBbase              0x00000790
//PCH-H Community 1
#define   CNL_GPPCPadLockbase       0x00000080
#define   CNL_GPPCPadTxLockbase     0x00000084
#define   CNL_GPPDPadLockbase       0x00000088
#define   CNL_GPPDPadTxLockbase     0x0000008C
#define   CNL_GPPGPadLockbase       0x00000090
#define   CNL_GPPGPadTxLockbase     0x00000094
#define   CNL_GPPCbase              0x00000600
#define   CNL_GPPDbase              0x00000780  
#define   CNL_GPPGbase              0x00000900
//PCH-H Community 2
#define   CNL_GPDPadLockbase        0x00000080
#define   CNL_GPDPadTxLockbase      0x00000084
#define   CNL_GPDbase               0x00000600
//PCH-H Community 3
#define   CNL_GPPKPadLockbase       0x00000080
#define   CNL_GPPKPadTxLockbase     0x00000084
#define   CNL_GPPHPadLockbase       0x00000088
#define   CNL_GPPHPadTxLockbase     0x0000008C
#define   CNL_GPPEPadLockbase       0x00000090
#define   CNL_GPPEPadTxLockbase     0x00000094
#define   CNL_GPPFPadLockbase       0x00000098
#define   CNL_GPPFPadTxLockbase     0x0000009C
#define   CNL_GPPKbase              0x00000600
#define   CNL_GPPHbase              0x00000780
#define   CNL_GPPEbase              0x00000900
#define   CNL_GPPFbase              0x000009D0
//PCH-H Community 4
#define   CNL_GPPIPadLockbase       0x00000090
#define   CNL_GPPIPadTxLockbase     0x00000094
#define   CNL_GPPJPadLockbase       0x00000098
#define   CNL_GPPJPadTxLockbase     0x0000009C
#define   CNL_GPPIbase              0x00000740
#define   CNL_GPPJbase              0x00000860
//PCH-LP Community 0
#define   CNL_LPGPPAPadLockbase     0x00000080
#define   CNL_LPGPPAPadTxLockbase   0x00000084
#define   CNL_LPGPPBPadLockbase     0x00000088
#define   CNL_LPGPPBPadTxLockbase   0x0000008C
#define   CNL_LPGPPGPadLockbase     0x00000090
#define   CNL_LPGPPGPadTxLockbase   0x00000094
#define   CNL_LPGPPAbase            0x00000600
#define   CNL_LPGPPBbase            0x00000790
#define   CNL_LPGPPGbase            0x00000930
//PCH-LP Community 1
#define   CNL_LPGPPDPadLockbase     0x00000080
#define   CNL_LPGPPDPadTxLockbase   0x00000084
#define   CNL_LPGPPFPadLockbase     0x00000088
#define   CNL_LPGPPFPadTxLockbase   0x0000008C
#define   CNL_LPGPPHPadLockbase     0x00000090
#define   CNL_LPGPPHPadTxLockbase   0x00000094
#define   CNL_LPGPPDbase            0x00000600
#define   CNL_LPGPPFbase            0x00000790  
#define   CNL_LPGPPHbase            0x00000910
//PCH-LP Community 2
#define   CNL_LPGPDPadLockbase      0x00000080
#define   CNL_LPGPDPadTxLockbase    0x00000084
#define   CNL_LPGPDbase             0x00000600
//PCH-LP Community 3 - Muxed Audio signals
#define   CNL_LPGPPAudbase          0x00000600
//PCH-LP Community 4
#define   CNL_LPGPPCPadLockbase     0x00000080
#define   CNL_LPGPPCPadTxLockbase   0x00000084
#define   CNL_LPGPPEPadLockbase     0x00000088
#define   CNL_LPGPPEPadTxLockbase   0x0000008C
#define   CNL_LPGPPCbase            0x00000600
#define   CNL_LPGPPEbase            0x00000780
// SKL & KBL Group Base definition
//PCH-H Community 0
#define   SKL_GPPAPadLockbase       0x000000A0
#define   SKL_GPPAPadTxLockbase     0x000000A4
#define   SKL_GPPBPadLockbase       0x000000A8
#define   SKL_GPPBPadTxLockbase     0x000000AC
#define   SKL_GPPAbase              0x00000400
#define   SKL_GPPBbase              0x000004C0
//PCH-H Community 1
#define   SKL_GPPCPadLockbase       0x00000090
#define   SKL_GPPCPadTxLockbase     0x00000094
#define   SKL_GPPDPadLockbase       0x00000098
#define   SKL_GPPDPadTxLockbase     0x0000009C
#define   SKL_GPPEPadLockbase       0x000000A0
#define   SKL_GPPEPadTxLockbase     0x000000A4
#define   SKL_GPPFPadLockbase       0x000000A8
#define   SKL_GPPFPadTxLockbase     0x000000AC
#define   SKL_GPPGPadLockbase       0x000000B0
#define   SKL_GPPGPadTxLockbase     0x000000B4
#define   SKL_GPPHPadLockbase       0x000000B8
#define   SKL_GPPHPadTxLockbase     0x000000BC
#define   SKL_GPPCbase              0x00000400
#define   SKL_GPPDbase              0x000004C0  
#define   SKL_GPPEbase              0x00000580
#define   SKL_GPPFbase              0x000005E8
#define   SKL_GPPGbase              0x000006A8
#define   SKL_GPPHbase              0x00000768
//PCH-H Community 2
#define   SKL_GPDPadLockbase         0x00000090
#define   SKL_GPDPadTxLockbase      0x00000094
#define   SKL_GPDbase               0x00000400
//PCH-H Community 3
#define   SKL_GPPIPadLockbase       0x00000090
#define   SKL_GPPIPadTxLockbase     0x00000094
#define   SKL_GPPIbase              0x00000400
//PCH-LP Community 0
#define   SKL_LPGPPAPadLockbase     0x000000A0
#define   SKL_LPGPPAPadTxLockbase   0x000000A4
#define   SKL_LPGPPBPadLockbase     0x000000A8
#define   SKL_LPGPPBPadTxLockbase   0x000000AC
#define   SKL_LPGPPAbase            0x00000400
#define   SKL_LPGPPBbase            0x000004C0
//PCH-LP Community 1
#define   SKL_LPGPPCPadLockbase     0x000000A0
#define   SKL_LPGPPCPadTxLockbase   0x000000A4
#define   SKL_LPGPPDPadLockbase     0x000000A8
#define   SKL_LPGPPDPadTxLockbase   0x000000AC
#define   SKL_LPGPPEPadLockbase     0x000000B0
#define   SKL_LPGPPEPadTxLockbase   0x000000B4
#define   SKL_LPGPPCbase            0x00000400
#define   SKL_LPGPPDbase            0x000004C0  
#define   SKL_LPGPPEbase            0x00000580
//PCH-LP Community 2
#define   SKL_LPGPDPadLockbase      0x000000A0
#define   SKL_LPGPDPadTxLockbase    0x000000A4
#define   SKL_LPGPDbase             0x00000400
//PCH-LP Community 3
#define   SKL_LPGPPFPadLockbase     0x000000A0
#define   SKL_LPGPPFPadTxLockbase   0x000000A4
#define   SKL_LPGPPGPadLockbase     0x000000A8
#define   SKL_LPGPPGPadTxLockbase   0x000000AC
#define   SKL_LPGPPFbase            0x00000400
#define   SKL_LPGPPGbase            0x000004C0
//Group Size
#define   GroupSize24      24
#define   GroupSize20      20
#define   GroupSize16      16
#define   GroupSize15      15
#define   GroupSize13      13
#define   GroupSize12      12
#define   GroupSize11      11
#define   GroupSize10      10
#define   GroupSize8        8
#define   GroupSize2        2
#define   GroupSize1        1

#define   B_LPC_CFG_DID             0xFFE0
#define   V_LPC_CFG_DID_SKL_H       0xA140
#define   V_LPC_CFG_DID_SKL_LP      0x9D40
#define   V_LPC_CFG_DID_KBL_H       0xA2C0
#define   V_LPC_CFG_DID_KBL_LP      0x9D40
#define   V_LPC_CFG_DID_CNL_H       0xA300
#define   V_LPC_CFG_DID_CNL_LP      0x9D80
#define   V_LPC_CFG_DID_CML_H       0x0680
#define   V_LPC_CFG_DID_CML_LP      0x0280
#define   V_LPC_CFG_DID_CMLV_H      0xA3C0
#define   V_LPC_CFG_DID_ICL_LP      0x3480
#define   V_LPC_CFG_DID_TGL_LP      0xA080
#define   V_LPC_CFG_DID_TGL_H       0x4380
//#define   V_LPC_CFG_DID_TGL_LP_UP3  0xA081  ///< PCH LP Mobile U Super SKU (SSKU)
//#define   V_LPC_CFG_DID_TGL_LP_UP4  0xA086  ///< PCH LP Mobile U Premium
//#define   V_LPC_CFG_DID_TGL_PR_UP3  0xA082  ///< PCH LP Mobile Y Super SKU (SSKU)v
//#define   V_LPC_CFG_DID_TGL_PR_UP4  0xA087  ///< PCH LP Mobile Y Premium

//#define V_TGL_PCH_LP_LPC_CFG_DEVICE_ID_MB_0           0xA080        ///< PCH LP Mobile SKU
//#define V_TGL_PCH_LP_LPC_CFG_DEVICE_ID_MB_1           0xA081        ///< PCH LP Mobile U Super SKU (SSKU)
//#define V_TGL_PCH_LP_LPC_CFG_DEVICE_ID_MB_2           0xA082        ///< PCH LP Mobile U Premium
//#define V_TGL_PCH_LP_LPC_CFG_DEVICE_ID_MB_6           0xA086        ///< PCH LP Mobile Y Super SKU (SSKU)
//#define V_TGL_PCH_LP_LPC_CFG_DEVICE_ID_MB_7           0xA087        ///< PCH LP Mobile Y Premium

#endif


