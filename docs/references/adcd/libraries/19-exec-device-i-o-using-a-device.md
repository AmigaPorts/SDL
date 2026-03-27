---
title: 19 Exec Device I/O / Using a Device
manual: libraries
chapter: libraries
section: 19-exec-device-i-o-using-a-device
functions: [DoIO, GetMsg, SendIO]
libraries: [exec.library]
---

# 19 Exec Device I/O / Using a Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once a device has been opened, you use it by passing the I/O request to
it.  When the device processes the I/O request, it acts on the information
the I/O request contains and returns a reply message, i.e., the I/O
request, to the message port when it is finished.  The I/O request is
passed to a device using one of three functions, [DoIO()](autodocs-2.0/exec-library-doio.md), [SendIO()](autodocs-2.0/exec-library-sendio.md) and
[BeginIO()](autodocs-2.0/amiga-lib-beginio.md).  They take only one argument: the I/O request you wish to pass
to the device.

  * [DoIO()](autodocs-2.0/exec-library-doio.md) is a synchronous function.  It will not return until the

```c
    device has finished with the I/O request.  DoIO() will wait, if
    necessary, for the request to complete, and will remove ([GetMsg()](libraries/24-messages-getting-a-message.md))
    any reply message from the message port.
```
  * [SendIO()](autodocs-2.0/exec-library-sendio.md) is an asynchronous function.  It can return immediately, but

```c
    the I/O operation it initiates may take a short or long time. SendIO
    is normally used when your application has other work to do while the
    I/O request is being acted upon, or if your application wishes to
    allow the user to cancel the I/O. Using SendIO() requires that you
    wait on or check for completion of the request, and remove the
    completed request from the message port with [GetMsg()](libraries/24-messages-getting-a-message.md).
```
  * [BeginIO()](autodocs-2.0/amiga-lib-beginio.md) is commonly used to control the QuickIO bit when sending an

```c
    I/O request to a device.  When the QuickIO flag ([IOF_QUICK](autodocs-2.0/includes-exec-io-h.md)) is set in
    the I/O request, a device is allowed to take certain shortcuts in
    performing and completing a request.  If the request can complete
    immediately, the device will not return a reply message and the
    QuickIO flag will remain set.  If the request cannot be completed
    immediately, the QUICK_IO flag will be clear.  [DoIO()](autodocs-2.0/exec-library-doio.md) normally
    requests QuickIO; [SendIO()](autodocs-2.0/exec-library-sendio.md) does not.
```
An I/O request typically has three fields set for every command sent to a
device.  You set the command itself in the [io_Command](autodocs-2.0/includes-exec-io-h.md) field, a pointer to
the data for the command in the [io_Data](autodocs-2.0/includes-exec-io-h.md) field, and the length of the data
in the [io_Length](autodocs-2.0/includes-exec-io-h.md) field.


```c
    SerialIO->IOSer.io_Length   = sizeof(ReadBuffer);
    SerialIO->IOSer.io_Data     = ReadBuffer;
    SerialIO->IOSer.io_Command  = CMD_READ;
    SendIO((struct IORequest *)SerialIO);
```
Commands consist of two parts (separated by an underscore, all in upper
case): a prefix and the command word.  The prefix indicates whether the
command is an Exec or device specific command.  All Exec standard commands
have "CMD" as the prefix.  They are defined in the include file
<exec/[io.h](autodocs-2.0/includes-exec-io-h.md)>.



             Table 19-2: Standard Exec Device Commands

            CMD_READ   CMD_START  CMD_UPDATE  CMD_CLEAR
            CMD_WRITE  CMD_STOP   CMD_FLUSH   CMD_RESET
You should not assume that a device supports all standard Exec device
commands.  Always check the documentation before attempting to use one of
them.  Device-specific command prefixes vary with the device.




```c
             Table 19-3: System Device Command Prefixes

        Device     Prefix                       Example
        ------     ------                       -------
        [Audio](devices/2-audio-device.md)      [ADCMD](autodocs-2.0/includes-devices-audio-h.md)                        ADCMD_ALLOCATE
        [Clipboard](devices/3-clipboard-device.md)  [CBD](autodocs-2.0/includes-devices-clipboard-h.md)                          CBD_POST
        [Console](devices/4-console-device.md)    [CD](autodocs-2.0/includes-devices-console-h.md)                           CD_ASKKEYMAP
        [Gameport](devices/5-gameport-device.md)   [GPD](autodocs-2.0/includes-devices-gameport-h.md)                          GPD_SETCTYPE
        [Input](devices/6-input-device.md)      [IND](autodocs-2.0/includes-devices-input-h.md)                          IND_SETMPORT
        [Keyboard](devices/7-keyboard-device.md)   [KBD](autodocs-2.0/includes-devices-keyboard-h.md)                          KBD_READMATRIX
        [Narrator](devices/8-narrator-device.md)   no device specific commands  -
        [Parallel](devices/9-parallel-device.md)   [PDCMD](autodocs-2.0/includes-devices-parallel-h.md)                        PDCMD_QUERY
        [Printer](devices/10-printer-device.md)    [PRD](autodocs-2.0/includes-devices-printer-h.md)                          PRD_PRTCOMMAND
        [SCSI](devices/11-scsi-device.md)       [HD](autodocs-2.0/includes-devices-scsidisk-h.md)                           HD_SCSICMD
        [Serial](devices/12-serial-device.md)     [SDCMD](autodocs-2.0/includes-devices-serial-h.md)                        SDCMD_BREAK
        [Timer](devices/13-timer-device.md)      [TR](autodocs-2.0/includes-devices-timer-h.md)                           TR_ADDREQUEST
        [Trackdisk](devices/14-trackdisk-device.md)  [TD](autodocs-2.0/includes-devices-trackdisk-h.md) and [ETD](autodocs-2.0/includes-devices-trackdisk-h.md)                   TD_MOTOR/ETD_MOTOR
```
Each device maintains its own I/O request queue.  When a device receives
an I/O request, it either processes the request immediately or puts it in
the queue because one is already being processed. After an I/O request is
completely processed, the device checks its queue and if it finds another
I/O request, begins to process that request.

 [Synchronous Vs. Asynchronous Requests](libraries/19-using-a-device-synchronous-vs-asynchronous-requests.md)    [I/O Request Completion](libraries/19-using-a-device-i-o-request-completion.md) 

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
