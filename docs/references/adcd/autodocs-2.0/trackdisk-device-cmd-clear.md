---
title: trackdisk.device/CMD_CLEAR
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-cmd-clear
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/CMD_CLEAR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_CLEAR/ETD_CLEAR -- mark the track buffer as containing invalid
                           data.
FUNCTION

```c
    These commands mark the track buffer as invalid, forcing a
    reread of the disk on the next operation. ETD_UPDATE or [CMD_UPDATE](autodocs-2.0/trackdisk-device-cmd-update.md)
    would be used to force data out to the disk before turning the motor
    off. ETD_CLEAR or CMD_CLEAR are usually used after having locked out
    the trackdisk.device via the use of the disk resource, when you
    wish to prevent the track from being updated, or when you wish to
    force the track to be re-read. ETD_CLEAR or CMD_CLEAR will not do an
    update, nor will an update command do a clear.
```
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      CMD_CLEAR or ETD_CLEAR
    io_Flags        0 or IOF_QUICK
    iotd_Count      (ETD_CLEAR only) maximum allowable change counter
                    value.
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
```
SEE ALSO

```c
    [CMD_WRITE](autodocs-2.0/trackdisk-device-cmd-write.md), [CMD_UPDATE](autodocs-2.0/trackdisk-device-cmd-update.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
