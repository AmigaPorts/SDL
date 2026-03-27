---
title: timer.device/TR_ADDREQUEST
manual: autodocs-3.5
chapter: autodocs-3.5
section: timer-device-tr-addrequest-2
functions: [AbortIO, WaitIO]
libraries: [exec.library, timer.device]
---

# timer.device/TR_ADDREQUEST

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	TR_ADDREQUEST -- Submit a request to wait a period of time.

   FUNCTION
	Ask the timer to wait a specified amount of time before
	replying the [timerequest](autodocs-3.5/include-devices-timer-h.md).

	The message may be forced to finish early with an
	[AbortIO()/WaitIO()](autodocs-3.5/exec-library-waitio-2.md) pair.

   TIMER REQUEST
	io_Message      mn_ReplyPort initialized
	io_Device       preset by timer in [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit         preset by timer in [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command      TR_ADDREQUEST
	io_Flags        IOF_QUICK permitted (but ignored)
	tr_time         a [timeval](autodocs-3.5/include-devices-timer-h.md) structure specifying how long the
	                    device will wait before replying

   RESULTS
	tr_time         will be zeroed

   NOTES
	This function may be called from interrupts.

	Previous to 2.0, the tr_time field was documented as containing
	junk when the [timerequest](autodocs-3.5/include-devices-timer-h.md) was returned.

   SEE ALSO
	[timer.device/AbortIO()](autodocs-3.5/timer-device-abortio-2.md),
	[timer.device/TimeDelay()](autodocs-3.5/amiga-lib-timedelay-2.md),

   BUGS

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
