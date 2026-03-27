---
title: icon.library/DeleteDiskObject
manual: autodocs-2.0
chapter: autodocs-2.0
section: icon-library-deletediskobject
functions: [FreeDiskObject, GetDiskObject, IoErr, PutDiskObject]
libraries: [dos.library, icon.library]
---

# icon.library/DeleteDiskObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DeleteDiskObject - Delete a Workbench disk object from disk.     (V37)
```
SYNOPSIS

```c
    result = DeleteDiskObject(name)
      D0                      A0

    BOOL DeleteDiskObject(char *);
```
FUNCTION

```c
    This routine will try to delete a Workbench disk object from disk.
    The name parameter will have a ".info" postpended to it, and the
    info file of that name will be deleted.  If the call fails,
    it will return zero.  The reason for the failure may be obtained
    via [IoErr()](autodocs-2.0/dos-library-ioerr.md).

    This call also updates the Workbench screen if needed.

    Using this routine protects you from any future changes to
    the way icons are stored within the system.
```
INPUTS

```c
    name -- name of the object (char *)
```
RESULTS

    result -- TRUE if it worked, false if not.
EXAMPLE

```c
    error=NULL;

    *Check if you have the right library version*

    if (((struct [Library](autodocs-2.0/includes-exec-libraries-h.md) *)IconBase)->lib_Version > 36)
    {
            if (!DeleteDiskObject(name)) error=IoErr();
    }
    else
    {
            * Delete name plus ".info" *
    }

    if (error)
    {
            * Do error routine...*
    }
```
SEE ALSO

```c
    [PutDiskObject()](autodocs-2.0/icon-library-putdiskobject.md), [GetDiskObject()](autodocs-2.0/icon-library-getdiskobject.md), [FreeDiskObject()](autodocs-2.0/icon-library-freediskobject.md)
```
BUGS

    None

---

## See Also

- [FreeDiskObject — icon.library](../autodocs/icon.library.md#freediskobject)
- [GetDiskObject — icon.library](../autodocs/icon.library.md#getdiskobject)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [PutDiskObject — icon.library](../autodocs/icon.library.md#putdiskobject)
