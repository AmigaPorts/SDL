---
title: 10 / Creating a Printer Driver / Writing Alphanumeric Printer Drivers
manual: devices
chapter: devices
section: 10-creating-a-printer-driver-writing-alphanumeric-printer
functions: []
libraries: []
---

# 10 / Creating a Printer Driver / Writing Alphanumeric Printer Drivers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The alphanumeric portion of the printer driver is designed to convert ANSI
x3.64 style commands into the specific escape codes required by each
individual printer.  For example, the ANSI code for underline-on is
ESC[4m.  The Commodore MPS-1250 printer would like a ESC[-1 to set
underline-on. The HP LaserJet accepts ESC[&dD as a start underline
command. By using the printer driver, all printers may be handled in a
similar manner.

There are two parts to the alphanumeric portion of the printer driver: the
Command Table data table and the DoSpecial() routine.

 [Command Table](devices/10-writing-an-alphanumeric-printer-driver-command-table.md) 
 [DoSpecial()](devices/10-writing-an-alphanumeric-printer-driver-dospecial.md) 
 [Printertag.asm](devices/10-writing-an-alphanumeric-printer-driver-printertag-asm.md) 
 [Extended Character Table](devices/10-writing-an-alphanumeric-printer-driver-extended.md) 
 [Character Conversion Routine](devices/10-writing-an-alphanumeric-printer-driver-character.md) 

