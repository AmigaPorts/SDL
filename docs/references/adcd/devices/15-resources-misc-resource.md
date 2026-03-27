---
title: 15 Resources / Misc Resource
manual: devices
chapter: devices
section: 15-resources-misc-resource
functions: []
libraries: []
---

# 15 Resources / Misc Resource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The misc resource oversees usage of the serial data port, the serial
communication bits, the parallel data and handshake port, and the parallel
communication bits.  Before using serial or parallel port hardware, it
first must be acquired from the misc resource.

The misc resource provides two functions for allocating and freeing the
serial and parallel hardware.


```c
                             Misc Resource Functions
                             ------------------------
     [AllocMiscResource()](autodocs-2.0/misc-resource-allocmiscresource.md)     Allocate one of the serial or parallel
                             misc resources.

     [FreeMiscResource()](autodocs-2.0/misc-resource-freemiscresource.md)      Deallocate one of the serial or
                             parallel misc resources.
```
Once you've successfully allocated one of the misc resources, you are free
to write directly to its hardware locations.  Information on the serial
and parallel hardware can be found in the Amiga [Hardware Reference Manual](hardware/amiga-hardware-reference-manual-8-interface-hardware.md)
and the hardware/[custom.h](autodocs-2.0/includes-hardware-custom-h.md) include file.

The two examples below are assembly and C versions of the same code for
locking the serial misc resources and waiting for CTRL-C to be pressed
before releasing them.


```c
     [Assembly Example Of Allocating Misc Resources](devices/devices-dev-examples-alloc-misc-a.md) 
     [C Example Of Allocating Misc Resources](devices/15-misc-resource-c-example-of-allocating-misc-resources.md) 
```
