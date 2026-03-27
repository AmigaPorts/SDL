---
title: 10 Printer Device / Obtaining Printer Specific Data
manual: devices
chapter: devices
section: 10-printer-device-obtaining-printer-specific-data
functions: []
libraries: []
---

# 10 Printer Device / Obtaining Printer Specific Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Information about the printer in use can be obtained by reading the
[PrinterData](autodocs-2.0/includes-devices-prtbase-h.md) and [PrinterExtendedData](autodocs-2.0/includes-devices-prtbase-h.md) structures.  The values found in these
structures are determined by the printer driver selected through
Preferences.  The data structures are defined in devices/[prtbase.h](autodocs-2.0/includes-devices-prtbase-h.md).

Printer specific data is returned in [printerIO](devices/10-printer-device-device-interface.md) when the printer device is
opened.  To read the structures, you must first set the [PrinterData](autodocs-2.0/includes-devices-prtbase-h.md)
structure to point to iodrp.io_Device of the [printerIO](devices/10-printer-device-device-interface.md) used to open the
device and then set [PrinterExtendedData](autodocs-2.0/includes-devices-prtbase-h.md) to point to the extended data
portion of [PrinterData](autodocs-2.0/includes-devices-prtbase-h.md).


```c
     [Printer_Data.c](devices/devices-dev-examples-printer-data-c.md) 
```
