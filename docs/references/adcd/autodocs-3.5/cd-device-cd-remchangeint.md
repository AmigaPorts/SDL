---
title: cd.device/CD_REMCHANGEINT
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-remchangeint
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_REMCHANGEINT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_REMCHANGEINT -- remove a disk change software interrupt handler.
   FUNCTION

```c
       This command removes a disk change software interrupt added
       by a previous use of [CD_ADDCHANGEINT](autodocs-3.5/cd-device-cd-addchangeint.md).
```
   IO REQUEST INPUT

```c
       The same IO request used for [CD_ADDCHANGEINT](autodocs-3.5/cd-device-cd-addchangeint.md).

       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_REMCHANGEINT
       io_Length       sizeof(struct Interrupt)
       io_Data         pointer to [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) structure
```
   IO REQUEST RESULT

```c
       io_Error - 0 for success, or an error code as defined in
                  [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
```
   SEE ALSO

```c
       [CD_ADDCHANGEINT](autodocs-3.5/cd-device-cd-addchangeint.md), [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
