---
title: 6 Input Device / Setting the Key Repeat Interval
manual: devices
chapter: devices
section: 6-input-device-setting-the-key-repeat-interval
functions: []
libraries: []
---

# 6 Input Device / Setting the Key Repeat Interval

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The key repeat interval is the time period, in seconds and microseconds,
between key repeat events once the initial key repeat threshold has
elapsed. (See [Setting the Key Repeat Threshold](devices/6-input-device-setting-the-key-repeat-threshold.md).)  Like the key
repeat threshold, this is normally issued by Intuition and preset by the
Preferences tool.

You set the key repeat interval by passing a [timerequest](devices/6-input-device-device-interface.md) with
[IND_SETPERIOD](autodocs-2.0/input-device-ind-setperiod.md) set in io_Command and the number of seconds set in tv_secs
and the number of microseconds set in tv_micro. struct timerequest
*InputTime; /* Initialize with CreateExtIO() before using */

   InputTime->tr_time.tv_secs=0;
   InputTime->tr_time.tv_micro=12000;  /* .012 seconds */
   InputTime->tr_node.io_Command=IND_SETPERIOD;
   DoIO((struct IORequest *)InputTime);

The code above sets the key repeat interval to .012 seconds.

   The Right Tool For The Right Job.
   ---------------------------------
   As previously stated, you must use a [timerequest](devices/6-input-device-device-interface.md) structure with
   [IND_SETTHRESH](autodocs-2.0/input-device-ind-setthresh.md) and [IND_SETPERIOD](autodocs-2.0/input-device-ind-setperiod.md).

