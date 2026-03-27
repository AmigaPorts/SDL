---
title: 10 Printer Device / Printer Device Access
manual: devices
chapter: devices
section: 10-printer-device-printer-device-access
functions: []
libraries: []
---

# 10 Printer Device / Printer Device Access

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The printer device is totally transparent to an application. It uses
information set up by the Workbench Preferences Printer and PrinterGfx
tools to identify the type of printer connection (serial or parallel),
type of dithering, etc.  It also offers the flexibility to send raw
information to the printer for special non-standard or unsupported
features. Raw data transfer is not recommended for conventional text and
graphics since it will result in applications that will only work with
certain printers. By using the standard printer device interface, an
application can perform device independent output to a printer.

   Don't Hog The Device.
   ---------------------
   The printer device is currently an exclusive access device.  Do not
   tie it up needlessly.

There are two ways of doing output to the printer device:

*  PRT:-the AmigaDOS printer device
   PRT: may be opened just like any other AmigaDOS file. You may send
   standard escape sequences to PRT: to specify the options you want as
   shown in the command table below. The escape sequences are
   interpreted by the printer driver, translated into printer-specific
   escape sequences and forwarded to the printer. When using PRT: the
   escape sequences and data must be sent as a character stream. Using
   PRT: is by far the easiest way of doing text output to a printer.

*  printer.device - to directly access the printer device itself
   By opening the printer device directly, you have full control over
   the printer.  You can either send standard escape sequences as shown
   in the command table below or send raw characters directly to the
   printer with no processing at all. Doing this would be similar to
   sending raw characters to SER: or PAR: from AmigaDOS. (Since this
   interferes with device-independence it is strongly discouraged).
   Direct access to the printer device also allows you to transmit
   device I/O commands, such as reset and flush, and do a raster dump on
   a graphics-capable printer.

   Use A Stream to Escape.
   -----------------------
   All "raw escape sequences" transmitted to the printer through the
   printer device must take the form of a character stream.

 [Opening Prt:](devices/10-printer-device-access-opening-prt.md)        [Writing To Prt:](devices/10-printer-device-access-writing-to-prt.md)        [Closing Prt:](devices/10-printer-device-access-closing-prt.md) 

