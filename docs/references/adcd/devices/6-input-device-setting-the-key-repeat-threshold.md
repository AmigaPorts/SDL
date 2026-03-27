---
title: 6 Input Device / Setting the Key Repeat Threshold
manual: devices
chapter: devices
section: 6-input-device-setting-the-key-repeat-threshold
functions: []
libraries: []
---

# 6 Input Device / Setting the Key Repeat Threshold

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The key repeat threshold is the number of seconds and microseconds a user
must hold down a key before it begins to repeat. This delay is normally
set by the Preferences tool or by Intuition when it notices that the
Preferences have been changed, but you can also do it directly through the
input device.

You set the key repeat threshold by passing a [timerequest](devices/6-input-device-device-interface.md) with
[IND_SETTHRESH](autodocs-2.0/input-device-ind-setthresh.md) set in io_Command and the number of seconds to delay set in
tv_secs and the number of microseconds to delay set in tv_micro.

   #include <devices/timer.h>

   struct timerequest *InputTime;/* Init with CreateExtIO() before using */

   InputTime->tr_time.tv_secs=1;         /* 1 second */
   InputTime->tr_time.tv_micro=500000;   /* 500000 microseconds */
   InputTime->tr_node.io_Command=IND_SETTHRESH;
   DoIO((struct IORequest *)InputTime);

The code above will set the key repeat threshold to 1.5 seconds.

