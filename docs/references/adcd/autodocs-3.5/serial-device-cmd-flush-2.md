---
title: serial.device/CMD_FLUSH
manual: autodocs-3.5
chapter: autodocs-3.5
section: serial-device-cmd-flush-2
functions: []
libraries: []
---

# serial.device/CMD_FLUSH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       [Flush](autodocs-3.5/dos-library-flush-2.md) -- clear all queued I/O requests for the serial port
```
   FUNCTION

```c
       This command purges the read and write request queues for the
       serial device. [Flush](autodocs-3.5/dos-library-flush-2.md) will not affect active requests.
```
   IO REQUEST

```c
       io_Message      mn_ReplyPort initialized
       io_Device       set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
       io_Unit         set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
       io_Command      CMD_FLUSH
```
   RESULTS

```c
       Error -- if the [Flush](autodocs-3.5/dos-library-flush-2.md) succeded, then io_Error will be null.
           	 If the [Flush](autodocs-3.5/dos-library-flush-2.md) failed, then the io_Error will be non-zero.
```
