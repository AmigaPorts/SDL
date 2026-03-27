---
title: 13 Timer Device
manual: devices
chapter: devices
section: 13-timer-device
functions: [ReadEClock]
libraries: [timer.device]
---

# 13 Timer Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga timer device provides a general interface to the Amiga's
internal clocks.  Through the timer device, time intervals can be
measured, time delays can be effected, system time can be set and
retrieved, and arithmetic operations can be performed on time values.


```c
                  NEW TIMER FEATURES FOR VERSION 2.0

               Feature                 Description
               --------                -----------
               [UNIT_ECLOCK](devices/13-device-interface-timer-device-units.md)             New timer device unit
               [UNIT_WAITUNTIL](devices/13-device-interface-timer-device-units.md)          New timer device unit
               [UNIT_WAITECLOCK](devices/13-device-interface-timer-device-units.md)         New timer device unit
               [ReadEClock()](devices/13-timer-device-timer-device-commands-and-functions.md)            New function
```
   Compatibility Warning:
   ----------------------
   The new features for 2.0 are not backwards compatible.

 [Timer Device Commands and Functions](devices/13-timer-device-timer-device-commands-and-functions.md) 
 [Device Interface](devices/13-timer-device-device-interface.md) 
 [System Time](devices/13-timer-device-system-time.md) 
 [Adding a Time Request](devices/13-timer-device-adding-a-time-request.md) 
 [Using the Time Arithmetic Functions](devices/13-timer-device-using-the-time-arithmetic-functions.md) 
 [E-Clock Time and Its Relationship to Actual Time](devices/13-timer-device-e-clock-time-and-its-relationship-to-actual.md) 
 [Example Timer Program](devices/devices-dev-examples-simple-timer-c.md) 
 [Additional Information on the Timer Device](devices/13-timer-device-additional-information-on-the-timer-device.md) 

---

## See Also

- [ReadEClock — timer.device](../autodocs/timer.device.md#readeclock)
