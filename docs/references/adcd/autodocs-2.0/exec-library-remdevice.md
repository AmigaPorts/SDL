---
title: exec.library/RemDevice
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-remdevice
functions: [Forbid, Permit]
libraries: [exec.library]
---

# exec.library/RemDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RemDevice -- remove a device from the system
SYNOPSIS

```c
    RemDevice(device)
              A1

    void RemDevice(struct [Device](autodocs-2.0/includes-exec-devices-h.md) *);
```
FUNCTION

```c
    This function calls the device's EXPUNGE vector, which requests
    that a device delete itself.  The device may refuse to do this if
    it is busy or currently open. This is not typically called by user
    code.

    There are certain, limited circumstances where it may be
    appropriate to attempt to specifically flush a certain device.
    Example:

     /* Attempts to flush the named device out of memory. */
     #include [<exec/types.h>](autodocs-2.0/includes-exec-types-h.md)
     #include [<exec/execbase.h>](autodocs-2.0/includes-exec-execbase-h.md)

     void FlushDevice(name)
     STRPTR name;
     {
     struct [Device](autodocs-2.0/includes-exec-devices-h.md) *result;

        Forbid();
        if(result=(struct [Device](autodocs-2.0/includes-exec-devices-h.md) *)FindName(&SysBase->DeviceList,name))
            RemDevice(result);
        Permit();
     }
```
INPUTS

    device - pointer to a device node
SEE ALSO

```c
    [AddLibrary](autodocs-2.0/exec-library-addlibrary.md)
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
