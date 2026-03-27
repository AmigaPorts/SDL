---
title: 13 Timer Device / Adding a Time Request
manual: devices
chapter: devices
section: 13-timer-device-adding-a-time-request
functions: [ReplyMsg]
libraries: [exec.library]
---

# 13 Timer Device / Adding a Time Request

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Time delays and time alarms are done by opening the timer device with the
proper unit and submitting a [timerequest](devices/13-timer-device-device-interface.md) to the device with [TR_ADDREQUEST](autodocs-2.0/timer-device-tr-addrequest.md)
set in io_Command and the appropriate values set in tv_secs and tv_micro.

Time delays are used with the [UNIT_MICROHZ](devices/13-device-interface-timer-device-units.md), [UNIT_VBLANK](devices/13-device-interface-timer-device-units.md), and
[UNIT_ECLOCK](devices/13-device-interface-timer-device-units.md) units. The time specified in a time delay [timerequest](devices/13-timer-device-device-interface.md) is a
relative measure from the time the request is posted.  This means that the
tv_secs and tv_micro fields should be set to the amount of delay required.

When the specified amount of time has elapsed, the driver will send the
[timerequest](devices/13-timer-device-device-interface.md) back via [ReplyMsg()](autodocs-2.0/exec-library-replymsg.md).  You must fill in the ReplyPort pointer
of the [timerequest](devices/13-timer-device-device-interface.md) structure if you wish to be signaled. Also, the number
of microseconds must be normalized; it should be a value less than one
million.

For a minute and a half delay, set 60 in tv_secs and 500,000 in tv_micro.


```c
    TimerIO->tr_node.io_Command = TR_ADDREQUEST;
    TimerIO->tr_time.tv_secs  = 60;        /* Delay a minute */
    TimerIO->tr_time.tv_micro = 500000;    /* and a half     */
    DoIO(TimerIO);
```
Time alarms are used with the [UNIT_WAITUNTIL](devices/13-device-interface-timer-device-units.md) and [UNIT_WAITECLOCK](devices/13-device-interface-timer-device-units.md) units.
The tv_secs and tv_micro fields should be set to the absolute time value
of the alarm.  For an alarm at 10:30 tonight, the number of seconds from
midnight, January 1, 1978 till 10:30 tonight should be set in tv_secs.
The timer device will not return until the time is greater than or equal
to the absolute time value.

For our purposes, we will set an alarm for three hours from now by getting
the current system time and adding three hours of seconds to it.

   #define SECSPERHOUR (60*60)
   struct timeval *systime;

   GetSysTime(systime);   /* Get current system time */

   TimerIO->tr_node.io_Command = TR_ADDREQUEST;
   TimerIO->tr_time.tv_secs  = systime.tv_secs+(SECSPERHOUR*3);
   TimerIO->tr_time.tv_micro = systime.tv_micro;
   DoIO(TimerIO);

   Time requests with the E-Clock Units.
   -------------------------------------
   Time requests with the E-Clock units - [UNIT_ECLOCK](devices/13-device-interface-timer-device-units.md) and
   [UNIT_WAITECLOCK](devices/13-device-interface-timer-device-units.md) - work the same as the other units except that the
   values specified in their I/O requests are compared against the value
   of the E-Clock.  See "[E-Clock Time and Its Relationship to Actual Time](devices/13-timer-device-e-clock-time-and-its-relationship-to-actual.md)"
   below.

Remember, you must never reuse a [timerequest](devices/13-timer-device-device-interface.md) until the timer device has
replied to it.  When you submit a timer request, the driver destroys the
values you have provided in the  [timeval](devices/13-timer-device-device-interface.md) structure. This means that you
must reinitialize the time specification before reposting a [timerequest](devices/13-timer-device-device-interface.md).

Keep in mind that the timer device provides a general time-delay
capability. It can signal you when at least a certain amount of time has
passed. The timer device is very accurate under normal system loads, but
because the Amiga is a multitasking system, the timer device cannot
guarantee that exactly the specified amount of time has
elapsed - processing overhead increases as more tasks are run.
High-performance applications (such as MIDI time-stamping) may want to
take over the 16-bit counters of the CIA B timer resource instead of using
the timer device.

   Problems with small time requests in V1.3 and earlier versions.
   ---------------------------------------------------------------
   You must also take care  to avoid posting a [timerequest](devices/13-timer-device-device-interface.md) of less than
   2 microseconds with the [UNIT_MICROHZ](devices/13-device-interface-timer-device-units.md) timer device if you are using
   V1.3 or earlier versions of the system software.  In V1.3 and earlier
   versions of the Amiga system software, sending a [timerequest](devices/13-timer-device-device-interface.md) for 0 or
   1 microseconds can cause a system crash.  Make sure all your timer
   requests are for 2 microseconds or more when you use the [UNIT_MICROHZ](devices/13-device-interface-timer-device-units.md)
   timer with those versions.

 [Multiple Timer Requests](devices/13-adding-a-time-request-multiple-timer-requests.md) 

---

## See Also

- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
