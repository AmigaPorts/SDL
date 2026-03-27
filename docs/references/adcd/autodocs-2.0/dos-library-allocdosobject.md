---
title: dos.library/AllocDosObject
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-allocdosobject
functions: [FreeDosObject]
libraries: [dos.library]
---

# dos.library/AllocDosObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AllocDosObject -- Creates a dos object (V36)
```
SYNOPSIS

```c
    ptr = AllocDosObject(type, tags)
    D0                    D1    D2

    void *AllocDosObject(ULONG, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *)

    ptr = AllocDosObjectTagList(type, tags)
    D0                           D1    D2

    void *AllocDosObjectTagList(ULONG, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *)

    ptr = AllocDosObjectTags(type, Tag1, ...)

    void *AllocDosObjectTags(ULONG, ULONG, ...)
```
FUNCTION

    Create one of several dos objects, initializes it, and returns it
    to you.  Note the DOS_STDPKT returns a pointer to the sp_Pkt of the
    structure.
INPUTS

    type - type of object requested
    tags - pointer to taglist with additional information
RESULT

    packet - pointer to the object or NULL
SEE ALSO

```c
    [FreeDosObject()](autodocs-2.0/dos-library-freedosobject.md), [<dos/dostags.h>](autodocs-2.0/includes-dos-dostags-h.md), [<dos/dos.h>](autodocs-2.0/includes-dos-dos-h.md)
```

---

## See Also

- [FreeDosObject — dos.library](../autodocs/dos.library.md#freedosobject)
