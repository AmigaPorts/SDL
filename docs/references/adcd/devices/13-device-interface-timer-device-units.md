---
title: 13 / Device Interface / Timer Device Units
manual: devices
chapter: devices
section: 13-device-interface-timer-device-units
functions: []
libraries: []
---

# 13 / Device Interface / Timer Device Units

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are five units in the timer device.



                           TIMER DEVICE UNITS

                   Unit                        Use
                ------------            ---------------
                UNIT_MICROHZ            Interval Timing
                UNIT_VBLANK             Interval Timing
                UNIT_ECLOCK             Interval Timing
                UNIT_WAITUNTIL          Time Event Occurrence
                UNIT_WAITECLOCK         Time Event Occurrence
   *  The VBLANK timer unit is very stable and has a granularity comparable

      to the vertical blanking time.  When you make a timing request, such
      as "signal me in 21 seconds," the reply will come at the next
      vertical blank after 21 seconds have elapsed.  This timer has very
      low overhead and may be more accurate then the MICROHZ and ECLOCK
      units for long time periods. Keep in mind that the vertical blanking
      time varies depending on the display mode.
   *  The MICROHZ timer unit uses the built-in precision hardware timers to

      create the timing interval you request. It accepts the same type of
      command - "signal me in so many seconds and microseconds." The
      microhertz timer has the advantage of greater resolution than the
      vertical blank timer, but it may have less accuracy over long periods
      of time.  The microhertz timer also has much more system overhead,
      which means accuracy is reduced as the system load increases. It is
      primarily useful for short-burst timing for which critical accuracy
      is not required.
   *  The ECLOCK timer unit uses the Amiga E-Clock to measure the time

      interval you request.  This is the most precise time measure
      available through the timer device.
   *  The WAITUNTIL timer unit acts as an alarm clock for time requests.

      It will signal the task when systime is greater than or equal to a
      specified time value.  It has the same granularity as the VBLANK
      timer unit.
   *  The WAITECLOCK timer unit acts as an alarm clock for time requests.

      It will signal the task when the E-Clock value is greater than or
      equal to a specified time value.  It has the same granularity as the
      ECLOCK timer unit.
   Granularity vs. Accuracy.
   -------------------------
   Granularity is the sampling frequency used to check the timers.
   Accuracy is the precision of a measured time interval with respect to
   the same time interval in real-time.  We speak only of granularity
   because the sampling frequency directly affects how accurate the
   timers appear to be.

