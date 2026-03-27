---
title: 10 / Creating a Printer Driver / Writing A Graphics Printer Driver
manual: devices
chapter: devices
section: 10-creating-a-printer-driver-writing-a-graphics-printer
functions: []
libraries: []
---

# 10 / Creating a Printer Driver / Writing A Graphics Printer Driver

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Designing the graphics portion of a custom printer driver consists of two
steps: writing the printer-specific [Render()](devices/10-writing-a-graphics-printer-driver-render.md), [Transfer()](devices/10-writing-a-graphics-printer-driver-transfer.md) and [SetDensity()](devices/10-writing-a-graphics-printer-driver-setdensity.md)
functions, and replacing the printer-specific values in printertag.asm.
Render(), Transfer() and SetDensity() comprise render.c, transfer.c, and
density.c modules, respectively.

A printer that does not support graphics has a very simple form of
Render(); it returns an error. Here is sample code for Render() for a
non-graphics printer (such as an Alphacom or Diablo 630):

   #include "exec/types.h"
   #include "devices/printer.h"
   int Render()
   {
```c
       return(PDERR_NOTGRAPHICS);
```
   }

The following section describes the contents of a typical driver for a
printer that does support graphics.

 [Render()](devices/10-writing-a-graphics-printer-driver-render.md)      [Transfer()](devices/10-writing-a-graphics-printer-driver-transfer.md)      [SetDensity()](devices/10-writing-a-graphics-printer-driver-setdensity.md)      [Printertag.asm](devices/10-writing-a-graphics-printer-driver-printertag-asm.md) 

