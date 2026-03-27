---
title: serial.device/CMD_WRITE
manual: autodocs-3.5
chapter: autodocs-3.5
section: serial-device-cmd-write-2
functions: []
libraries: []
---

# serial.device/CMD_WRITE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       [Write](autodocs-3.5/dos-library-write-2.md) -- send output to serial port
```
   FUNCTION

```c
       This command causes a stream of characters to be written out
       the serial port. The number of characters is specified in
       io_Length, unless -1 is used, in which case output is sent until
       a null(0x00) is encountered.
```
   IO REQUEST

```c
       io_Message      must have mn_ReplyPort initialized
       io_Device       set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
       io_Unit         set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
       io_Command      CMD_WRITE
       io_Flags        Set IOF_QUICK to try quick I/O
       io_Length       number of characters to transmit, or if set
                       to -1 transmit until null encountered in buffer
       io_Data         pointer to block of data to transmit
```
   RESULTS

```c
       Error -- if the [Write](autodocs-3.5/dos-library-write-2.md) succeded, then io_Error will be null.
           If the [Write](autodocs-3.5/dos-library-write-2.md) failed, then the io_Error will be non-zero.
```
   SEE ALSO
	[serial.device/SDCMD_SETPARAMS](autodocs-3.5/serial-device-sdcmd-setparams-2.md)

