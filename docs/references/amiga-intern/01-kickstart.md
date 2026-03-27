# Kickstart 2.04

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 1.1.1 Reset Capabilities

Begin with a  "cold start" by switching on the 3000. Press both mouse 

buttons at once, and you will be moved to the Operating System Menu. Here you can select the operating system you want to work with and specify the source from which it should be loaded. For example, an old version of the operating system can be loaded from the (hard) drive into a RAM storage area. The 68030's integrated MMU logically shifts this area to the normal operating system address and protects it against overwrite. Now the current operating system's normal reset routine, which can also be invoked by the sequence <ctrQ,lft-Amiga,rt-Amiga>, is initiated. Under
AmigaOS 2.x, any external or internal expansions are immediately 

recognized and incorporated into the system (this was not the case with earlier versions). The operating system checks hardware and memory and builds the tables for routines (error handling) and interrupts. All base data structures containing variable values are then set up.

Pressing both mouse buttons again will take you to the Boot Menu. This 

screen allows you to select the logical or physical drive from which booting will take place. This drive will be referred to as SYS (system directory). For other Amigas, even before the start of DOS, all logical drives are recognized and drive names established. The execution of the
Startup sequence can also be disabled. This can be an advantage for CLI 

users, since the InitialCLI itself is now a  complete shell, providing a convenient and easy-to-use platform for the Command Line Interface. Now the Device Operating System (DOS) is started and the work shell initialized. To save time and avoid problems selecting the right monitor driver, the windows aren't opened until the Workbench is activated or output in an InitialCLI window requires it.

## 1.1 Inside AmigaOS 2  jc

### 1.1.2 The Main Units of AmigaOS 2.x

The Amiga Operating system is designed in modules. Considering the size of the entire system and that the Amiga is a  multitasking device, this is a  great advantage. The modular design makes the system more flexible and easier to change. The main units can be divided into four groups:
Libraries, Devices, Resources and Special. Libraries are simply collections 

of routines of a  certain type or application. Devices serve as logical device drivers and may perform one or more tasks. Resources include base routines which usually manage access to certain resources and exclude them from or reserve them for other programs. The modules are initialized according to their priorities. The following modules are found in AmigaOS 2.4 ROM in the order of their initialization:

/. Kickstart 2.04 

Address 

Pri 

Typ 

Name 

Vers. 

Date 

$00f83cc0 

+110 

Library 

expansion

37.23 

(3/15/91) 

$00f800b6 

+105 

Library 

exec

37.52 

(3/15/91) 

$00f83cda 

+105 

Special 

diag init

$00fbb09a 

+103 

Library 

utility

37.3 

(2/13/91) 

$00faba14 

+100 

Resource 

potgo

37.4 

(1/28/91) 

$00f889e0 

+80 

Resource 

da

37.4 

(3/15/91) 

$00f98dac 

+80 

Resource 

filesysres

37.1 

(1/12/91) 

$00f8f3bc 

+70 

Resource 

disk

37.1 

(1/9/91) 

$00fab964 

+70 

Resource 

misc

37.1 

(1/8/91) 

(3/14/91) 

$00fbbb50 

+65 

Library 

graphics

37.20 

$00faebd8 

+60 

Device 

gameport

37.8 

(1/28/91) 

$00fb8540 

+50 

Device 

timer

37.57 

(3/14/91) 

$00f85890 

+45 

Resource 

battclock

37.3 

(3/11/91) 

$00faec02 

+45 

Device 

keyboard

37.8 

(1/28/91) 

$00f862d0 

+44 

Resource 

battmem

37.3 

(3/4/91) 

$00»a6984 

+40 

Library 

keymap

37.2 

(1/8/91) 

$00faec2c 

+40 

Device 

input

37.8 

(1/28/91) 

$00fa76c4 

+31 

Library 

layers

37.7 

(3/13/91) 

$00fae054 

+25 

Device 

ramdrive

37.3 

(1/9/91) 

$00fb936c 

+20 

Device 

trackdisk

37.3 

(3/13/91) 

$00fb0298 

+10 

Device 

scsidisk

37.4 

(2/26/1) 

$00fd3f6c 

+10 

Library 

intuition

37.220 

(3/14/91) 

$00f83ca4 

+5 

Special 

alerthook

$00f8b358 

+5 

Device 

console

37.85 

(3/13/91) 

$00fab5f4 

+0 

Library 

mathieeesingbas

37.2 

(2/7/91) 

$00f86508 

-35 

Special 

syscheck

37.2 

(1/15/91) 

$00fb7620 

-40 

Special 

romboot

37.23 

(3/15/91) 

$00fff46c 

-45 

Special 

Magic 

36.7 

(3/16/90) 

$00f864c8 

-50 

Special 

bootmenu

37.2 

(1/15/91) 

$00fb763a 

-60 

Special 

strap

37.23 

(3/15/91) 

$00f98f3e 

-81 

Special 

fs

37.11 

(3/13/91) 

$00fae70c 

-100 

Special 

ramlib

37.13 

(3/14/91) 

$00f847f0 

-120 

Device 

audio

37.7 

(3/13/91) 

$00f90390 

-120 

Library 

dos

37.22 

(3/15/91) 

$00f9e4d0 

-120 

Library 

gadtools

37.82 

(3/14/91) 

$00fa445c 

-120 

Library 

icon

37.6 

(3/2/91) 

$00fab110 

-120 

Library 

mathffp

37.1 

(1/13/91) 

$00fbba7a 

-120 

Task 

Pre-2.0 LoadWB stub 

$00feccd4 

-120 

Library 

wb

37.108 

(3/14/91) 

$00f88d8e 

-121 

Special 

con-handler

37.39 

(3/13/91) 

$00fb2ed4 

-122 

Special 

shell

37.37 

(3/13/91) 

$00fabbb8 

-123 

Special 

ram

37.9 

(3/15/91) 

Some modules are only included for backward compatibility. For 

example, the workbench-task module and the "mathffp.library" are used. All other modules contained in ROM are used frequently or are required by other modules.

/ ./ Inside AmigaOS 2.x 

1.1.3 

Disk Libraries and Devices 

Modules are found in ROM, on the Workbench disk or in the system 

directory of the hard drive. These programs are loaded as they are used:

Name 

Version 

Directory 

asl. library

37.25 

"LIBS

commodities.library

37.5 

diskfontlibrary

36.50 

iffparse.library

37.1 

mathieeedoubbas.library

37.1 

mathieeedoubtrans.library

37.1 

mathieeesingtrans.library

37.1 

mathtrans.library

37.1 

translator.library

37.1 

version.library

37.33 

rexxsyslib. library

36.19 

rexxsupport.library

34.9 

clipboard.device

37.4 

"DEVS

narrator.device

37.5 

parallel.device

37.1 

printer.device

35.603 

serial .device

37.1 

aux-handler

"L

port-handler speak-handler queue-handler

## 1.2 AmigaOS 2.x Compatibility

The addresses of routines in ROM will vary from version to version. They should not be called directly, since they are always subject to change. In short, do not rely on a  specific value for anything that Commodore has not declared a  constant. A  disadvantage with compatibility is the memory requirements of programs. The new operating system uses more memory than earlier versions to accommodate its many new features. The same is true for program stack requirements. System routines have become much more complex, with a  corresponding increase in their stack storage needs.

Many values whose contents are made up of flag bits have been 

expanded, and failure to handle them accordingly can lead to problems. Also, this can happen to the 68030's expanded status register.
Unfortunately, some system data not defined as PUBLIC has found its 

way into circulation. These values are not to be trusted and changes in their definitions can most likely happen. The programmer can always rely on the address $00000004. This is the base address of the "exec .library for all versions of the operating system. All other values are uncertain. The color and proportions of the system font can also change. Processor speed has increased dramatically. As a  rule, a  program will have to be synchronized with clock impulses or the monitor's electron beam. The main and co-processors' instructions doesn't allow interval storage of values, bits in addresses or instruction codes.

Many extensions of AmigaOS 1.3 have been removed and integrated 

into the base module in a  large expanded form. For example, the
"romboot.library" was removed and the boot routine completely 

reprogrammed. Autobooting from devices other than the internal disks is now standard and fully supported by the system. Like the SCSI-devices, all disks come bootable from the supplier. Drives DF0 through DF3 are assigned priorities of +5, -10, -20, and -30.

Early in the reset-routine the new operating system's enhancements 

become apparent. Calling of the ColdCapture vector is delayed. At any time the Exception/Interrupt Table can be placed over the Vector Base
Register (VBR). 

## 1.2 AmigaOS 2jc Compatibility

There are allowances for changing the size and type of MemHeader structures, and the use of ResetWindows has been revised. The base structure of the Expansion-library is declared as PRIVATE and may not be accessed. Any expansions are incorporated in two passes accompanied by the sorting of address slots. The "dos.library" is greatly expanded and, like many other modules, programmed with the SAS C-compiler Version 5. Its base structure now conforms to that of the other libraries. However, for compatibility reasons, some addresses still exist as BCPL-pointers. New types of
DosPackets and new locks have been implemented. The process 

structure has grown substantially, so that auto-creation, for example with the popular "arp.library," results in a  system crash. The Workbench, which has changed in appearance and color, can now be nearly any desired size, shade and resolution. Window frames and gadgets adjust automatically to changes in resolution and fonts.
Workbench windows can be transferred to other screens. Screens, which 

can consist of up to 16368*16384 pixels, are capable of new display modes, overscan into the unseen border area, and several styles of horizontal and vertical scrolling. All data necessary to duplicate a  screen can no longer be determined from the screen structure. Screen handling is greatly improved and, even with SimpleRefresh windows, a  message is sent only when refresh is necessary. Different color borders indicate which windows are active and special effects create a  3-dimensional appearance. There are new IDCMP-flags for this, and both keyboard flags now transmit raw data for special keys. The Layer system is improved. SimpleRefresh layers are saved and refreshed to the fullest possible extent. The routines FattenLayerlnfo,
ThinLayerlnfo, and InitLayers should no longer be used NewLayerlnfo 

accomplishes all these functions.

Computing of Copper lists has been optimized. The video-hardware does 

not like programming errors, such as switching off the display mode in mid-display. GetColorMapO must be used to manipulate ColorMap structures, which have increased in size. Row/cols values in the GfxBase no longer relate to the Workbench. Although the font structures have a  new format, the old one continues to be supported. The system-area of "font" files has been changed.
Character set sizes that are not present are now simply calculated. The 

topaz font is still in ROM, but now as a  sans-serif variant for increased legibility at high resolutions. Size and proportions of the system font can be specified as desired.

Many CLI/Shell commands are stored in ROM, and several CLI/Shell 

processes can run simultaneously. Windows are now equipped with close gadgets that, when activated, cause an EOF code to be sent. The missing cursor error in SuperBitmap Console windows has been corrected. The Audio device no longer is initialized until its first use, which can result in errors because of insufficient memory.

Several serial interfaces (expansion cards) are possible. However, this can 

lead to problems with the adjustment of certain parameters through the
Serial device. 

Trackdisk device buffers can be released, but a  subsequent attempt to 

use a  buffer may result in an error if insufficient memory is available.

Both CIAB timers are now accessible. 

The current maximum for chip RAM is 2  Meg. Fast RAM is configured down from the upper boundary of memory (in full 32 bit addresses) and can be as high as 8  Gigabytes. This configuration will make it easier for a future release to break the 2  Meg chip RAM barrier, probably reaching as high as 8  Meg. The ECS has more hardware registers, which reside in between those familiar to the previous system and can cause problems for programmers of clockcycle-optimized programs. Some old registers contain important new bits. The accubuffered truetime clock is not compatible with earlier clock chips.

## 2.1 The Workbench

