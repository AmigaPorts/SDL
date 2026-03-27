---
title: dos.library/AddSegment
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-addsegment
functions: [FindSegment, LoadSeg, RemSegment]
libraries: [dos.library]
---

# dos.library/AddSegment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AddSegment - Adds a resident segment to the resident list (V36)
```
SYNOPSIS

```c
    success = AddSegment(name, seglist, type)
    D0                    D1     D2      D3

    BOOL AddSegment(STRPTR, BPTR, LONG)
```
FUNCTION

```c
    Adds a segment to the Dos resident list, with the specified Seglist
    and type (stored in seg_UC - normally 0).  NOTE: currently unused
    types may cause it to interpret other registers (d4-?) as additional
    parameters in the future.

    Do NOT build [Segment](autodocs-2.0/includes-dos-dosextens-h.md) structures yourself!
```
INPUTS

    name    - name for the segment
    seglist - Dos seglist of code for segment
    type    - initial usecount, normally 0
RESULT

    success - success or failure
SEE ALSO

```c
    [FindSegment()](autodocs-2.0/dos-library-findsegment.md), [RemSegment()](autodocs-2.0/dos-library-remsegment.md), [LoadSeg()](autodocs-2.0/dos-library-loadseg.md)
```

---

## See Also

- [FindSegment — dos.library](../autodocs/dos.library.md#findsegment)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [RemSegment — dos.library](../autodocs/dos.library.md#remsegment)
