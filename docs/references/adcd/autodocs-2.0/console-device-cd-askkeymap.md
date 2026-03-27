---
title: console.device/CD_ASKKEYMAP
manual: autodocs-2.0
chapter: autodocs-2.0
section: console-device-cd-askkeymap
functions: []
libraries: []
---

# console.device/CD_ASKKEYMAP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CD_ASKKEYMAP -- Get the current key map structure for this console.
FUNCTION

```c
    Fill the io_Data buffer with the current [KeyMap](autodocs-2.0/includes-devices-keymap-h.md) structure in
    use by this console unit.
```
IO REQUEST INPUT

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](autodocs-2.0/console-device-opendevice.md)
    io_Unit         preset by the call to [OpenDevice](autodocs-2.0/console-device-opendevice.md)
    io_Command      CD_ASKKEYMAP
    io_Flags        IOF_QUICK if quick I/O possible, else zero
    io_Length       sizeof(*keyMap)
    io_Data         struct [KeyMap](autodocs-2.0/includes-devices-keymap-h.md) *keyMap
                    pointer to a structure that describes
                    the raw keycode to byte stream conversion.
```
IO REQUEST RESULT

```c
    This function sets the io_Error field in the [IOStdReq](autodocs-2.0/includes-exec-io-h.md), and fills
    the structure the structure pointed to by io_Data with the current
     key map.
```
SEE ALSO

```c
    [exec/io.h](autodocs-2.0/includes-exec-io-h.md), [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md), [devices/console.h](autodocs-2.0/includes-devices-console-h.md)
```
