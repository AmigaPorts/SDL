---
title: serial.device/CMD_WRITE
manual: autodocs-2.0
chapter: autodocs-2.0
section: serial-device-cmd-write
functions: []
libraries: []
---

# serial.device/CMD_WRITE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Write -- send output to serial port
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
    io_Device       set by [OpenDevice](autodocs-2.0/serial-device-opendevice.md)
    io_Unit         set by [OpenDevice](autodocs-2.0/serial-device-opendevice.md)
    io_Command      CMD_WRITE
    io_Flags        Set IOF_QUICK to try quick I/O
    io_Length       number of characters to transmit, or if set
                    to -1 transmit until null encountered in buffer
    io_Data         pointer to block of data to transmit
```
RESULTS

    Error -- if the Write succeded, then io_Error will be null.
        If the Write failed, then the io_Error will be non-zero.
SEE ALSO

```c
    [serial.device/SDCMD_SETPARAMS](autodocs-2.0/serial-device-sdcmd-setparams.md)
```
