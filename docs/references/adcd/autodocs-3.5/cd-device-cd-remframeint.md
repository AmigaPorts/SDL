---
title: cd.device/CD_REMFRAMEINT
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-remframeint
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_REMFRAMEINT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_REMFRAMEINT -- remove a CD-frame interrupt handler.
   IO REQUEST

```c
       The same IO request used for [CD_ADDFRAMEINT](autodocs-3.5/cd-device-cd-addframeint.md).

       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_REMFRAMEINT
       io_Length       sizeof(struct Interrupt)
       io_Data         pointer to [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) structure
```
   RESULTS

```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
```
   FUNCTION

```c
       This command removes a CD-frame software interrupt added
       by a previous use of [CD_ADDFRAMEINT](autodocs-3.5/cd-device-cd-addframeint.md).
```
   BUGS

   SEE ALSO

```c
       [CD_ADDFRAMEINT](autodocs-3.5/cd-device-cd-addframeint.md), [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
