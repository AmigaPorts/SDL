---
title: 10 / / Writing An Alphanumeric Printer Driver / DoSpecial()
manual: devices
chapter: devices
section: 10-writing-an-alphanumeric-printer-driver-dospecial
functions: [Close]
libraries: [dos.library]
---

# 10 / / Writing An Alphanumeric Printer Driver / DoSpecial()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The DoSpecial() function is meant to implement all the ANSI functions that
cannot be done by simple substitution, but can be handled by a more
complex sequence of control characters sent to the printer. These are
functions that need parameter conversion, read values from Preferences,
and so on. Complete routines can also be placed in dospecial.c. For
instance, in a driver for a page oriented-printer such as the HP LaserJet,
the dummy [Close()](autodocs-2.0/dos-library-close.md) routine from the init.asm file would be replaced by a
real Close() routine in dospecial.c. This close routine would handle
ejecting the paper after text has been sent to the printer and the printer
has been closed.

The DoSpecial() function is set up as follows:

   #include "exec/types.h"
   #include "devices/printer.h"
   #include "devices/prtbase.h"

   extern struct PrinterData *PD;

   DoSpecial(command,outputBuffer,vline,currentVMI,crlfFlag,Parms)
   UBYTE outputBuffer[];
   UWORD *command;
   BYTE *vline;
   BYTE *currentVMI;
   BYTE *crlfFlag;
   UBYTE Parms[];
   {                /* code begins here... */

   where

   command

```c
      points to the command number. The devices/[printer.h](autodocs-2.0/includes-devices-printer-h.md) file contains the
      definitions for the routines to use (aRIN is initialize, and so on).
```
   vline

      points to the value for the current line position.
   currentVMI

      points to the value for the current line spacing.
   crlfFlag

      points to the setting of the "add line feed after carriage return"
      flag.
   Parms

      contain whatever parameters were given with the ANSI command.
   outputBuffer

      points to the memory buffer into which the converted command is
      returned.
Almost every printer will require an aRIN (initialize) command in
DoSpecial(). This command reads the printer settings from Preferences and
creates the proper control sequence for the specific printer.  It also
returns the character set to normal (not italicized, not bold, and so on).
Other functions depend on the printer.

Certain functions are implemented both in the [CommandTable](devices/10-writing-an-alphanumeric-printer-driver-command-table.md) and in the
DoSpecial() routine. These are functions such as superscript, subscript,
PLU (partial line up), and PLD (partial line down), which can often be
handled by a simple conversion. However, some of these functions must also
adjust the printer device's line-position variable.

   Save the Data!
   --------------
   Some printers lose data when sent their own reset command. For this
   reason, it is recommended that if the printer's own reset command is
   going to be used, PD->pd_PWaitEnabled should be defined to be a
   character that the printer will not print. This character should be
   put in the reset string before and after the reset character(s) in
   the command table.

In the EpsonX[CBM_MPS-1250] DoSpecial() function you'll see

   if (*command == aRIS)
```c
       {        /* reset command */
       PD->pd_PWaitEnabled = \375; /* preserve that data! */
```
   }

while in the command table the string for reset is defined as
"\\375\\033@\\375". This means that when the printer device outputs the
reset string "\\033@", it will first see the "\\375", wait a second and
output the reset string. While the printer is resetting, the printer
device gets the second "\\375" and waits another second. This ensures that
no data will be lost if a reset command is embedded in a string.

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
