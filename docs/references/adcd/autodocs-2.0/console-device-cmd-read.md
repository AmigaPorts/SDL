---
title: console.device/CMD_READ
manual: autodocs-2.0
chapter: autodocs-2.0
section: console-device-cmd-read
functions: []
libraries: []
---

# console.device/CMD_READ

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_READ -- return the next input from the keyboard
FUNCTION

```c
    Read the next input, generally from the keyboard.  The form of
    this input is as an ANSI byte stream: i.e. either ASCII text
    or control sequences.  Raw input events received by the
    console device can be selectively filtered via the aSRE and aRRE
    control sequences (see the write command).  Keys are converted
    via the keymap associated with the unit, which is modified
    with AskKeyMap and SetKeyMap

    If, for example, raw keycodes had been enabled by writing
    <CSI>1{ to the console (where <CSI> is $9B or Esc[), keys
    would return raw keycode reports with the information from
    the input event itself, in the form:
    <CSI>1;0;<keycode>;<qualifiers>;0;0;<seconds>;<microseconds>q

    If there is no pending input, this command will not be
    satisfied, but if there is some input, but not as much as can
    fill io_Length, the request will be satisfied with the input
    currently available.
```
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](autodocs-2.0/console-device-opendevice.md)
    io_Unit         preset by the call to [OpenDevice](autodocs-2.0/console-device-opendevice.md)
    io_Command      CMD_READ
    io_Flags        IOF_QUICK if quick I/O possible, else zero
    io_Length       sizeof(*buffer)
    io_Data         char buffer[]
                    a pointer to the destination for the characters to read
                    from the keyboard.
```
RESULTS

```c
    This function sets the error field in the [IOStdReq](autodocs-2.0/includes-exec-io-h.md), and fills
        in the io_Data area with the next input, and io_Actual with
        the number of bytes read.
```
BUGS

SEE ALSO

```c
    [exec/io.h](autodocs-2.0/includes-exec-io-h.md), [devices/console.h](autodocs-2.0/includes-devices-console-h.md)
```
