/** @file
    A simple, basic, EDK II native, "hello" application to verify that
    we can build applications without LibC.

    Copyright (c) 2010 - 2011, Intel Corporation. All rights reserved.<BR>
    This program and the accompanying materials
    are licensed and made available under the terms and conditions of the BSD License
    which accompanies this distribution. The full text of the license may be found at
    http://opensource.org/licenses/bsd-license.

    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
**/
#include  <Uefi.h>
#include  <Library/UefiLib.h>
#include  <Library/ShellCEntryLib.h>
#include  <Library/UefiBootServicesTableLib.h>
#include  <Protocol/LoadedImage.h>
#include  <Library/PeCoffGetEntryPointLib.h>
#include  <Library/BaseLib.h>
#include  <Library/BaseMemoryLib.h>
#include  <Library/MemoryAllocationLib.h>
#include  <Protocol/DevicePath.h>

#define EFI_PERF_PDBFILENAME_LENGTH 36
/***
  Print a welcoming message.

  Establishes the main structure of the application.

  @retval  0         The application exited normally.
  @retval  Other     An error occurred.
***/
VOID
GetShortPdbFileName (
  IN  CHAR8     *PdbFileName,
  OUT CHAR8    *UnicodeBuffer
  );

INTN
EFIAPI
ShellAppMain (
  IN UINTN Argc,
  IN CHAR16 **Argv
  )
{
  EFI_STATUS                            Status;
  UINTN                                 HandleCount = 0;
  EFI_HANDLE                            *LoadedImageHandleBuffer = NULL;
  UINTN                                 Ndx;
  EFI_LOADED_IMAGE_PROTOCOL             *LoadedImageProtocol = NULL;
  MEDIA_FW_VOL_FILEPATH_DEVICE_PATH     *FvFilePath;
  VOID                                  *EntryPoint;

  Status = gBS->LocateHandleBuffer(
                   ByProtocol,
                   &gEfiLoadedImageProtocolGuid,
                   NULL,
                   &HandleCount,
                   &LoadedImageHandleBuffer);
  
  //Print(L"Handle Address, Size     ,PdbOffset       ,Driver Name,File,Guid,                     \n");
  if (EFI_SUCCESS == Status)
  {
     for (Ndx=0; Ndx < HandleCount; Ndx++)
     {
          Status = gBS->HandleProtocol(LoadedImageHandleBuffer[Ndx],
                                     &gEfiLoadedImageProtocolGuid,
                                     (VOID**)&LoadedImageProtocol
                                     );
          if (EFI_SUCCESS == Status)
          {
             Print(L"Handle%03d = %08x, Size = % 7x, ", Ndx, LoadedImageProtocol->ImageBase, LoadedImageProtocol->ImageSize);
             {
                CHAR8   *PdbPointer;
                CHAR8   *PdbFileNameOnly;

                PdbFileNameOnly = AllocateZeroPool(0x25);

                PdbPointer = PeCoffLoaderGetPdbPointer (LoadedImageProtocol->ImageBase);
                Status = PeCoffLoaderGetEntryPoint (LoadedImageProtocol->ImageBase, &EntryPoint);
                Print(L"EntryPoint=%08X,", EntryPoint);
                GetShortPdbFileName(PdbPointer, PdbFileNameOnly);
                if (PdbPointer != NULL) {
                   Print(L"PdbOffset:% 6x,%a,", PdbPointer - (CHAR8*)LoadedImageProtocol->ImageBase, PdbFileNameOnly);
                }
                else
                {
                   Print(L"PdbOffset:000000,No Debug Info,");
                }
             }
             if(LoadedImageProtocol->FilePath->Type == MEDIA_DEVICE_PATH && LoadedImageProtocol->FilePath->SubType == MEDIA_PIWG_FW_FILE_DP)
             {
                FvFilePath      = (MEDIA_FW_VOL_FILEPATH_DEVICE_PATH *) LoadedImageProtocol->FilePath;
                Print(L" File,%g\n", FvFilePath->FvFileName);
             }
             else
             {
                Print(L"File,00000000-0000-0000-0000-000000000000\n");
             }
          }
     }

  }

  return(0);
}

VOID
GetShortPdbFileName (
  CHAR8  *PdbFileName,
  CHAR8  *GaugeString
  )
/*++

Routine Description:
  
Arguments:

Returns:

--*/
{
  UINTN Index;
  UINTN Index1;
  UINTN StartIndex;
  UINTN EndIndex;

  if (PdbFileName == NULL) {
    AsciiStrCpy (GaugeString, (CHAR8 *)" ");
  } else {
    StartIndex = 0;
    for (EndIndex = 0; PdbFileName[EndIndex] != 0; EndIndex++)
      ;

    for (Index = 0; PdbFileName[Index] != 0; Index++) {
      if (PdbFileName[Index] == '\\') {
        StartIndex = Index + 1;
      }

      if (PdbFileName[Index] == '.') {
        EndIndex = Index;
      }
    }

    Index1 = 0;
    for (Index = StartIndex; Index < EndIndex; Index++) {
      GaugeString[Index1] = PdbFileName[Index];
      Index1++;
      if (Index1 == EFI_PERF_PDBFILENAME_LENGTH - 1) {
        break;
      }
    }

    GaugeString[Index1] = 0;
  }

  return ;
}