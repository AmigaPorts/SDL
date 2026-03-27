---
title: console.device/CD_ASKDEFAULTKEYMAP
manual: autodocs-2.0
chapter: autodocs-2.0
section: console-device-cd-askdefaultkeymap
functions: []
libraries: []
---

# console.device/CD_ASKDEFAULTKEYMAP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CD_ASKDEFAULTKEYMAP -- get the current default keymap
FUNCTION

```c
    Fill the io_Data buffer with the current console device
    default keymap, which is used to initialize console unit
    keymaps when opened, and by [RawKeyConvert](autodocs-2.0/console-device-rawkeyconvert.md) with a null
    keyMap parameter.
```
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](autodocs-2.0/console-device-opendevice.md)
    io_Unit         preset by the call to [OpenDevice](autodocs-2.0/console-device-opendevice.md)
    io_Command      CD_ASKDEFAULTKEYMAP
    io_Flags        IOF_QUICK if quick I/O possible, else zero
    io_Length       sizeof(*keyMap)
    io_Data         struct [KeyMap](autodocs-2.0/includes-devices-keymap-h.md) *keyMap
                    pointer to a structure that describes
                    the raw keycode to byte stream conversion.
```
RESULTS

```c
    This function sets the io_Error field in the [IOStdReq](autodocs-2.0/includes-exec-io-h.md), and fills
    the structure pointed to by io_Data with the current device
    default key map.
```
BUGS

SEE ALSO

```c
    [exec/io.h](autodocs-2.0/includes-exec-io-h.md), [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md), [devices/console.h](autodocs-2.0/includes-devices-console-h.md)
```
