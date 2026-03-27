---
title: trackdisk.device/TD_ADDCHANGEINT
manual: autodocs-2.0
chapter: autodocs-2.0
section: trackdisk-device-td-addchangeint
functions: [Cause, OpenDevice, SendIO]
libraries: [exec.library]
---

# trackdisk.device/TD_ADDCHANGEINT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TD_ADDCHANGEINT -- add a disk change software interrupt handler.
FUNCTION

```c
    This command lets you add a software interrupt handler to the
    disk device that gets invoked whenever a disk insertion or removal
    occurs.

    You must pass in a properly initialized Exec [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) structure
    and be prepared to deal with disk insertions/removals
    immediately. From within the interrupt handler, you may only call the
    status commands that can use IOF_QUICK.

    To set up the handler, an [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) structure must be initialized.
    This structure is supplied as the io_Data to the TD_ADDCHANGEINT
    command. The handler then gets linked into the handler chain and
    gets invoked whenever a disk change happens. You must eventually
    remove the handler before you exit.

    This command only returns when the handler is removed. That is,
    the device holds onto the IO request until the [TD_REMCHANGEINT](autodocs-2.0/trackdisk-device-td-remchangeint.md) command
    is executed with that same IO request. Hence, you must use [SendIO()](autodocs-2.0/exec-library-sendio.md)
    with this command.
```
IO REQUEST INPUT

```c
    io_Device       preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by the call to [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)
    io_Command      TD_ADDCHANGEINT
    io_Flags        0
    io_Length       sizeof(struct Interrupt)
    io_Data         pointer to [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) structure
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md)
```
SEE ALSO

```c
    [TD_REMCHANGEINT](autodocs-2.0/trackdisk-device-td-remchangeint.md), [<devices/trackdisk.h>](autodocs-2.0/includes-devices-trackdisk-h.md), [<exec/interrupts.h>](autodocs-2.0/includes-exec-interrupts-h.md),
    [exec.library/Cause()](autodocs-2.0/exec-library-cause.md)
```

---

## See Also

- [Cause — exec.library](../autodocs/exec.library.md#cause)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
