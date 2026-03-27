---
title: timer.device/TR_SETSYSTIME
manual: autodocs-3.5
chapter: autodocs-3.5
section: timer-device-tr-setsystime-2
functions: [GetSysTime]
libraries: [timer.device]
---

# timer.device/TR_SETSYSTIME

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	TR_SETSYSTIME -- Set the system time.

   FUNCTION
	Set the system idea of what time it is.  The system starts out
	at time "zero" so it is safe to set it forward to the real
	time.  However, care should be taken when setting the time
	backwards.  System time is generally expected to monotonically
	increasing.

   TIMER REQUEST
	io_Message      mn_ReplyPort initialized
	io_Device       preset by timer in [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit         preset by timer in [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command      [TR_GETSYSTIME](autodocs-3.5/timer-device-tr-getsystime-2.md)
	io_Flags        IOF_QUICK permitted
	tr_time         a [timeval](autodocs-3.5/include-devices-timer-h.md) structure with the current system
	                    time

   RESULTS
	tr_time         will contain junk

   NOTES
	This function may be called from interrupts.

   SEE ALSO
	[timer.device/TR_GETSYSTIME](autodocs-3.5/timer-device-tr-getsystime-2.md),
	[timer.device/GetSysTime()](autodocs-3.5/timer-device-getsystime-2.md),

   BUGS

---

## See Also

- [GetSysTime — timer.device](../autodocs/timer.device.md#getsystime)
