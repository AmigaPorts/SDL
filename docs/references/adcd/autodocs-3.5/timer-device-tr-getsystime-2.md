---
title: timer.device/TR_GETSYSTIME
manual: autodocs-3.5
chapter: autodocs-3.5
section: timer-device-tr-getsystime-2
functions: [GetSysTime]
libraries: [timer.device]
---

# timer.device/TR_GETSYSTIME

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	TR_GETSYSTIME -- get the system time.

   FUNCTION
	Ask the system what time it is.  The system time starts off at
	zero at power on, but may be initialized via the [TR_SETSYSTIME](autodocs-3.5/timer-device-tr-setsystime-2.md)
	call.

	System time is monotonically increasing, and guaranteed to be
	unique (except when the system time is set backwards).

   TIMER REQUEST
	io_Message      mn_ReplyPort initialized
	io_Device       preset by timer in [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit         preset by timer in [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command      TR_GETSYSTIME
	io_Flags        IOF_QUICK permitted

   RESULTS
	tr_time         a [timeval](autodocs-3.5/include-devices-timer-h.md) structure with the current system
	                    time

   NOTES
	This function may be called from interrupts.

   SEE ALSO
	[timer.device/TR_SETSYSTIME](autodocs-3.5/timer-device-tr-setsystime-2.md),
	[timer.device/GetSysTime()](autodocs-3.5/timer-device-getsystime-2.md),

   BUGS

---

## See Also

- [GetSysTime — timer.device](../autodocs/timer.device.md#getsystime)
