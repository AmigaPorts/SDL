---
title: 13 Timer Device / Using the Time Arithmetic Functions
manual: devices
chapter: devices
section: 13-timer-device-using-the-time-arithmetic-functions
functions: []
libraries: []
---

# 13 Timer Device / Using the Time Arithmetic Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As indicated above, the time arithmetic functions are accessed in the
timer device structure as if they were a routine library. To use them, you
create an [IORequest](autodocs-2.0/includes-exec-io-h.md) block and open the timer.  In the IORequest block is a
pointer to the device's base address. This address is needed to access
each routine as an offset - for example, _LVOAddTime, _LVOSubTime,
_LVOCmpTime - from that base address.


```c
     [Timer_Arithmetic.c](devices/devices-dev-examples-timer-arithmetic-c.md) 
```
 [Why Use Time Arithmetic?](devices/13-using-the-time-arithmetic-functions-why-use-time.md) 

