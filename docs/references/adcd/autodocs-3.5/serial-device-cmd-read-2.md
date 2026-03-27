---
title: serial.device/CMD_READ
manual: autodocs-3.5
chapter: autodocs-3.5
section: serial-device-cmd-read-2
functions: [AbortIO, WaitIO]
libraries: [exec.library, timer.device]
---

# serial.device/CMD_READ

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       [Read](autodocs-3.5/dos-library-read-2.md) -- read input from serial port
```
   FUNCTION
	This command causes a stream of characters to be read in from
	the serial port buffer.  The number of characters is specified
	in io_Length.

	The Query function can be used to check how many characters
	are currently waiting in the serial port buffer.  If more characters
	are requested than are currently available, the ioRequest
	will be queued until it can be satisfied.


	The best way to handle reads is to first Query to get the number
	of characters currently in the buffer.  Then post a read request
	for that number of characters (or the maximum size of your buffer).

	If zero characters are in the buffer, post a request
	for 1 character.  When at least one is ready, the device will return
	it.  Now start over with another Query.

	Before the program exits, it must be sure to [AbortIO()](autodocs-3.5/serial-device-abortio-2.md) then [WaitIO()](autodocs-3.5/exec-library-waitio-2.md)
	any outstanding ioRequests.

   IO REQUEST
```c
       io_Message      A mn_ReplyPort is required
       io_Device       set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
       io_Unit         set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
       io_Command      CMD_READ
       io_Flags        If the IOB_QUICK bit is set, read will try
```
			to complete the IO quickly

       io_Length       number of characters to receive.
       io_Data         pointer to buffer
   RESULTS
```c
       Error -- if the [Read](autodocs-3.5/dos-library-read-2.md) succeded, then io_Error will be null.
           If the [Read](autodocs-3.5/dos-library-read-2.md) failed, then io_Error will be non-zero.
```
	     io_Error will indicate problems such as parity mismatch,
	     break, and buffer overrun.

   SEE ALSO
	[serial.device/SDCMD_QUERY](autodocs-3.5/serial-device-sdcmd-query-2.md)
	[serial.device/SDCMD_SETPARAMS](autodocs-3.5/serial-device-sdcmd-setparams-2.md)

   BUGS
	Having multiple outstanding read IORequests at any one time will
	probably fail.

	Old documentation mentioned a mode where io_Length was set to -1.
	If you want a NULL terminated read, use the io_TermArray instead.

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
