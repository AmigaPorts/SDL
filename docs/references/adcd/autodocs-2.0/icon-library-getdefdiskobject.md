---
title: icon.library/GetDefDiskObject
manual: autodocs-2.0
chapter: autodocs-2.0
section: icon-library-getdefdiskobject
functions: [IoErr]
libraries: [dos.library]
---

# icon.library/GetDefDiskObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetDefDiskObject - read default wb disk object from disk.       (V36)
```
SYNOPSIS

```c
    diskobj = GetDefDiskObject(def_type)
     D0                          D0

    struct [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md) *GetDefDiskObject(LONG);
```
FUNCTION

```c
    This routine reads in a default Workbench disk object from disk.
    The valid def_types can be found in [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md) and
    currently include WBDISK thru WBGARBAGE.  If the call fails,
    it will return zero.  The reason for the failure may be obtained
    via [IoErr()](autodocs-2.0/dos-library-ioerr.md).

    Using this routine protects you from any future changes to
    the way default icons are stored within the system.
```
INPUTS

```c
    def_type - default icon type (WBDISK thru WBKICK).  Note that the
               define 'WBDEVICE' is not currently supported.
```
RESULTS

    diskobj -- the default Workbench disk object in question
SEE ALSO

```c
    [PutDefDiskObject](autodocs-2.0/icon-library-putdefdiskobject.md)
```
BUGS

    None

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
