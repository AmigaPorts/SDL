---
title: 13 / Adding a Time Request / Multiple Timer Requests
manual: devices
chapter: devices
section: 13-adding-a-time-request-multiple-timer-requests
functions: [OpenDevice, SendIO]
libraries: [exec.library]
---

# 13 / Adding a Time Request / Multiple Timer Requests

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Multiple requests may be posted to the timer driver. For example, you can
make three timer requests in a row:


```c
    Signal me in 20 seconds (request 1)
    Signal me in 30 seconds (request 2)
    Signal me in 10 seconds (request 3)
```
As the timer queues these requests, it changes the time values and sorts
the timer requests to service each request at the desired interval,
resulting effectively in the following order:


```c
    (request 3) in now+10 seconds
    (request 1) 10 seconds after request 3 is satisfied
    (request 2) 10 seconds after request 1 is satisfied
```
If you wish to send out multiple timer requests, you have to create
multiple request blocks. You can do this by allocating memory for each
[timerequest](devices/13-timer-device-device-interface.md) you need and filling in the appropriate fields with command
data.  Some fields are initialized by the call to the [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
function.  So, for convenience, you may allocate memory for the
[timerequest](devices/13-timer-device-device-interface.md) you need, call [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) with one of them, and then copy
the initialized fields into all the other [timerequest](devices/13-timer-device-device-interface.md).

It is also permissible to open the timer device multiple times.  In some
cases this may be easier than opening it once and using multiple requests.
When multiple requests are given, [SendIO()](autodocs-2.0/exec-library-sendio.md) should be used to transmit each
one to the timer.


```c
     [Multiple_Timers.c](devices/devices-dev-examples-multiple-timers-c.md) 
```
If all goes according to plan, TimerIO[1] will finish first, TimerIO[2]
will finish next, and TimerIO[0] will finish last.

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
