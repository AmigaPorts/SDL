---
title: trackdisk.device/CMD_UPDATE
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-cmd-update
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/CMD_UPDATE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_UPDATE/ETD_UPDATE -- write out the track buffer if it is dirty.
FUNCTION

```c
    The trackdisk device does not write data sectors unless it is
    necessary (you request that a different track be used) or until the
    user requests that an update be performed. This improves system speed
    by caching disk operations. These commands ensure that any
    buffered data is flushed out to the disk. If the track buffer has not
    been changed since the track was read in, these commands do nothing.
    ETD_UPDATE command checks for diskchange.
```
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      CMD_UPDATE or ETD_UPDATE
    io_Flags        0 or IOF_QUICK
    iotd_Count      (ETD_UPDATE only) maximum allowable change counter
                    value.
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
```
SEE ALSO

```c
    [CMD_WRITE](autodocs-2.0/trackdisk-device-cmd-write.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
