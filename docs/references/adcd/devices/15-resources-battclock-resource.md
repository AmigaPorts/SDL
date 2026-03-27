---
title: 15 Resources / BattClock Resource
manual: devices
chapter: devices
section: 15-resources-battclock-resource
functions: [Amiga2Date]
libraries: [utility.library]
---

# 15 Resources / BattClock Resource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The battery-backed clock (BattClock) keeps Amiga time while the system is
powered off.  The time from the BattClock is loaded into the Amiga system
clock as part of the boot sequence.

The battclock resource provides access to the BattClock.  Three functions
allow you to read the BattClock value, reset it and set it to a value you
desire.


```c
                           BattClock Resource Functions
                           ----------------------------
     [ReadBattClock()](autodocs-2.0/battclock-resource-readbattclock.md)       Read the time from the BattClock and
                           returns it as the number of seconds since
                           12:00 AM, January 1, 1978.

     [ResetBattClock()](autodocs-2.0/battclock-resource-resetbattclock.md)      Reset the BattClock to 12:00 AM, January 1,
                           1978.

     [WriteBattClock()](autodocs-2.0/battclock-resource-writebattclock.md)      Set the BattClock to the number of seconds
                           you pass it relative to 12:00 AM, January
                           1, 1978.
```
The utility.library contains time functions which convert the number of
seconds since 12:00 AM, January 1, 1978 to a date and time we can
understand, and vice versa.  You will find these functions useful when
dealing with the BattClock.  The example program below uses the
[Amiga2Date()](autodocs-2.0/utility-library-amiga2date.md) utility function to convert  the value returned by
[ReadBattClock()](autodocs-2.0/battclock-resource-readbattclock.md).  See the "[Utility Library](libraries/37-utility-library.md)" chapter of the Amiga ROM
Kernel Reference Manual: Libraries for a discussion of the utility.library
and the Amiga ROM Kernel Reference Manual: [Includes and Autodocs](autodocs-2.0/utility-doc.md) for a
listing of its functions.

   So, You Want to Be A Time Lord?
   -------------------------------
   This resource will allow you to set the BattClock to any value you
   desire. Keep in mind that this time will endure a reboot and could
   adversely affect your system.


```c
     [Read_BattClock.c](devices/devices-dev-examples-read-battclock-c.md) 
```
Additional programming information on the battclock resource can be found
in the include files and the Autodocs for the battclock resource and the
utility library.

---

## See Also

- [Amiga2Date — utility.library](../autodocs/utility.library.md#amiga2date)
