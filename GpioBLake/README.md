# GpioBLake
Gpio tool for Skylake, Kabylake, CnlLake, Whiskylake, Ice Lake(LP), Tiger Lake(H/LP)

## Requirement:
Intel Big core chipset after Skylake.
## Usage:
      To show help menu:
      fs#:\GpioBLake.efi ? or fs#:\GpioBLake.efi h
      To dump all Gpio.
      fs#:\GpioBLake.efi a
      To dump Gpio community x(x = 0, 1, 2, 3, 4, 5).
      fs#:\GpioBLake.efi d x
      To show Pad/Tx Lock status:
      fs#:\\>GpioBLake.efi L

      To read:
      GPIO Dis :  Pad is GPIO IN/OUT disabled, not used.
      Nat1 In L:  Pad is Native 1, direction IN, level is low.
      Not owned:  Pad is not owned by host/bios.
      GPO High :  Pad is GPIO, direction is out, level is high.