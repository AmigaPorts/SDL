---
title: 13 Timer Device / Device Interface
manual: devices
chapter: devices
section: 13-timer-device-device-interface
functions: []
libraries: []
---

# 13 Timer Device / Device Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The timer device operates in a similar manner to the other Amiga devices.
To use it, you must first open it, then send I/O requests to it, and then
close it when finished. See the [Introduction to Amiga System Devices](devices/1-introduction-to-amiga-system-devices-using-a-device.md)
chapter for general information on device usage.

The timer device also provides timer functions in addition to the usual
I/O request protocol.  These functions still require the device to be
opened with the proper timer device unit, but do not require a message
port. However, the base address of the timer library must be obtained in
order to use the timer functions.

The two modes of timer device operation are not mutually exclusive.  You
may use them both within the same application.

The I/O request used by the timer device is called timerequest.

   struct timerequest
   {
```c
       struct IORequest tr_node;
       struct timeval tr_time;
```
   };

The timer device functions are passed a time structure, either timeval for
non E-Clock units or EClockVal for E-Clock units.

   struct timeval
   {
```c
        ULONG tv_secs;   /* seconds */
        ULONG tv_micro;  /* microseconds */
```
   };

   struct EClockVal
   {
```c
       ULONG ev_hi;   /* Upper longword of E-Clock time */
       ULONG ev_lo;   /* Lower longword of E-Clock time */
```
   };

See the include file devices/[timer.h](autodocs-2.0/includes-devices-timer-h.md) for the complete structure
definitions. Time requests fall into three categories:

   *  Time delay - wait a specified period of time.  A time delay causes an

      application to wait a certain length of time. When a time delay is
      requested, the number of seconds and microseconds to delay are
      specified in the I/O request.
   *  Time measure - how long something takes to complete.  A time measure

      is a three-step procedure where the system or E-Clock time is
      retrieved, an operation or series of operations is performed, and
      then another time retrieval is done.  The difference between the two
      time values is the measure of the duration of the operation.
   *  Time alarm - wait till a specific time.  A time alarm is a request to

      be notified when a specific time value has occurred.  It is similar
      to a time delay except that the absolute time value is specified in
      the I/O request.
   What is an E-Clock?
   -------------------
   The E-Clock is the clock used by the Motorola 68000 processor family
   to communicate with other Motorola 8-bit chips.  The E-Clock returns
   two distinct values - the E-Clock value in the form of two longwords
   and the count rate (tics/second) of the E-Clock.  The count rate is
   related to the master frequency of the machine and is different
   between PAL and NTSC machines.

 [Timer Device Units](devices/13-device-interface-timer-device-units.md) 
 [Opening The Timer Device](devices/13-device-interface-opening-the-timer-device.md) 
 [Closing The Timer Device](devices/13-device-interface-closing-the-timer-device.md) 

