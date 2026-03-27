---
title: 10 Printer Device / Example Printer Driver Source Code
manual: devices
chapter: devices
section: 10-printer-device-example-printer-driver-source-code
functions: []
libraries: []
---

# 10 Printer Device / Example Printer Driver Source Code

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As an aid in writing printer drivers, source code for two different
classes of printers is supplied. Both drivers have been successfully
generated with Lattice C 5.10 and Lattice Assembler 5.10. The example
drivers are:

   EpsonX       A YMCB, 8 pin, multi-density interleaved printer.
   HP_Laserjet  A black&white, multi-density, page-oriented printer.

All printer drivers use the following include file macros.i for init.asm.


```c
     [macros.i](devices/devices-dev-examples-macros-i.md) 
```
 [EpsonX](devices/10-example-printer-driver-source-code-epsonx.md) 
 [HP_Laserjet](devices/10-example-printer-driver-source-code-hp-laserjet.md) 

