---
title: trackdisk.device/TD_REMCHANGEINT
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-td-remchangeint
functions: [Forbid, OpenDevice, Permit]
libraries: [exec.library]
---

# trackdisk.device/TD_REMCHANGEINT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TD_REMCHANGEINT -- remove a disk change software interrupt handler.
FUNCTION

```c
    This command removes a disk change software interrupt added
    by a previous use of [TD_ADDCHANGEINT](autodocs-2.0/trackdisk-device-td-addchangeint.md).
```
IO REQUEST INPUT

```c
    The same IO request used for [TD_ADDCHANGEINT](autodocs-2.0/trackdisk-device-td-addchangeint.md).

    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      TD_REMCHANGEINT
    io_Flags        0
    io_Length       sizeof(struct Interrupt)
    io_Data         pointer to [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) structure
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
```
BUGS

```c
    This command did not function properly under versions of Kickstart
    earlier than V36. A valid workaround under these older versions of
    Kickstart is:

            Forbid();
            Remove(ioRequest);
            Permit();

    Do not use this workaround in versions of Kickstart >= V36, use
    TD_REMCHANGEINT instead (for future compatibility with V38+).
```
SEE ALSO

```c
    [TD_ADDCHANGEINT](autodocs-2.0/trackdisk-device-td-addchangeint.md), [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
