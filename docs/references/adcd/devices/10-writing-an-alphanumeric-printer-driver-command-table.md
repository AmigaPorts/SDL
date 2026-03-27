---
title: 10 / / Writing An Alphanumeric Printer Driver / Command Table
manual: devices
chapter: devices
section: 10-writing-an-alphanumeric-printer-driver-command-table
functions: []
libraries: []
---

# 10 / / Writing An Alphanumeric Printer Driver / Command Table

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The CommandTable is used to convert all escape codes that can be handled
by simple substitution. It has one entry per ANSI command supported by the
printer driver. When you are creating a custom CommandTable, you must
maintain the order of the commands in the same sequence as that shown in
devices/[printer.h](autodocs-2.0/includes-devices-printer-h.md). By placing the specific codes for your printer in the
proper positions, the conversion takes place automatically.

   Octal knows NULL.
   -----------------
   If the code for your printer requires a decimal 0 (an ASCII NULL
   character), you enter this NULL into the CommandTable as octal 376
   (decimal 254).

Placing an octal value of 377 (255 decimal) in a position in the command
table indicates to the printer device that no simple conversion is
available on this printer for this ANSI command.  For example, if a
daisy-wheel printer does not have a foreign character set, 377 octal (255
decimal) is placed in that position in the command table. However, 377 in
a position can also mean that the ANSI command is to be handled by code
located in the DoSpecial() function. For future compatibility all printer
commands should be present in the command table, and those not supported
by the printer filled with the dummy entry 377 octal.

