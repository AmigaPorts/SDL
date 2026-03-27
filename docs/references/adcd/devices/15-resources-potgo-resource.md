---
title: 15 Resources / Potgo Resource
manual: devices
chapter: devices
section: 15-resources-potgo-resource
functions: []
libraries: []
---

# 15 Resources / Potgo Resource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The potgo resource is used to get control of the hardware POTGO register
connected to the proportional I/O pins on the game controller ports. There
are two registers, POTGO (write-only) and POTINP (read-only). These pins
could also be used for digital I/O.

The potgo resource provides three functions for working with the POTGO
hardware.


```c
                       Potgo Resource Functions
                       ------------------------
     [AllocPotBits()](autodocs-2.0/potgo-resource-allocpotbits.md)    Allocate bits in the POTGO register.

     [FreePotBits()](autodocs-2.0/potgo-resource-freepotbits.md)     Free previously allocated bits in the POTGO
                       register.

     [WritePotgo()](autodocs-2.0/potgo-resource-writepotgo.md)      Set and clear bits in the POTGO register.
                       The bits must have been allocated before
                       calling this function.
```
The example program shown below demonstrates how to use the ptogo resource
to track mouse button presses on port 1.


```c
     [Read_Potinp.c](devices/devices-dev-examples-read-potinp-c.md) 
```
Additional programming information on the potgo resource can be found in
the include files and the Autodocs for the potgo resource.


```c
                         Potgo Resource Information
                      ---------------------------------
                      INCLUDES        resources/[potgo.h](autodocs-2.0/includes-resources-potgo-h.md)
                                      resources/[potgo.i](autodocs-2.0/includes-resources-potgo-i.md)
                                      utility/[hooks.h](autodocs-2.0/includes-utility-hooks-h.md)
                                      utility/[hooks.i](autodocs-2.0/includes-utility-hooks-i.md)

                      AUTODOCS        [potgo.doc](autodocs-2.0/potgo-doc.md)
```
