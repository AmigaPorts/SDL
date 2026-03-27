---
title: dos.library/FreeDosObject
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-freedosobject
functions: [AllocDosObject]
libraries: [dos.library]
---

# dos.library/FreeDosObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeDosObject -- Frees an object allocated by [AllocDosObject()](autodocs-2.0/dos-library-allocdosobject.md) (V36)
```
SYNOPSIS

```c
    FreeDosObject(type, ptr)
                   D1   D2

    void FreeDosObject(ULONG, void *)
```
FUNCTION

```c
    Frees an object allocated by [AllocDosObject()](autodocs-2.0/dos-library-allocdosobject.md).  Do NOT call for
    objects allocated in any other way.
```
INPUTS

```c
    type - type passed to [AllocDosObject()](autodocs-2.0/dos-library-allocdosobject.md)
    ptr  - ptr returned by [AllocDosObject()](autodocs-2.0/dos-library-allocdosobject.md)
```
SEE ALSO

```c
    [AllocDosObject()](autodocs-2.0/dos-library-allocdosobject.md), [<dos/dos.h>](autodocs-2.0/includes-dos-dos-h.md)
```

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
