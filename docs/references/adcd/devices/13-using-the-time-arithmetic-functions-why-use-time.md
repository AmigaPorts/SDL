---
title: 13 / Using the Time Arithmetic Functions / Why Use Time Arithmetic?
manual: devices
chapter: devices
section: 13-using-the-time-arithmetic-functions-why-use-time
functions: []
libraries: []
---

# 13 / Using the Time Arithmetic Functions / Why Use Time Arithmetic?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As mentioned earlier in this section, because of the multitasking
capability of the Amiga, the timer device can provide timings that are at
least as long as the specified amount of time. If you need more precision
than this, using the system timer along with the time arithmetic routines
can at least, in the long run, let you synchronize your software with this
precision timer after a selected period of time.

Say, for example, that you select timer intervals so that you get 161
signals within each 3-minute span. Therefore, the  [timeval](devices/13-timer-device-device-interface.md) you would have
selected would be 180/161, which comes out to 1 second and 118,012
microseconds per interval.  Considering the time it takes to set up a call
to set the timer and delays due to task-switching (especially if the
system is very busy), it is possible that after 161 timing intervals, you
may be somewhat beyond the 3-minute time. Here is a method you can use to
keep in sync with system time:

   1. Begin.

   2. Read system time; save it.

   3. Perform your loop however many times in your selected interval.

   4. Read system time again, and compare it to the old value you saved.

```c
      (For this example, it will be more or less than 3 minutes as a total
      time elapsed.)
```
   5. Calculate a new value for the time interval ( [timeval](devices/13-timer-device-device-interface.md)); that is, one

```c
      that (if precise) would put you exactly in sync with system time the
      next time around. Timeval will be a lower value if the loops took too
      long, and a higher value if the loops didn't take long enough.
```
   6. Repeat the cycle.

Over the long run, then, your average number of operations within a
specified period of time can become precisely what you have designed.

   You Can't Do 1+1 on E-Clock Values.
   -----------------------------------
   The arithmetic functions are not designed to operate on [EClockVal](devices/13-timer-device-device-interface.md)s.

