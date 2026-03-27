---
title: dos.library/RemSegment
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-remsegment
functions: [AddSegment, FindSegment]
libraries: [dos.library]
---

# dos.library/RemSegment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RemSegment - Removes a resident segment from the resident list (V36)
```
SYNOPSIS

```c
    success = RemSegment(segment)
    D0                      D1

    BOOL RemSegment(struct [Segment](autodocs-2.0/includes-dos-dosextens-h.md) *)
```
FUNCTION

```c
    Removes a resident segment from the Dos resident segment list,
    unloads it, and does any other cleanup required.  Will only succeed
    if the seg_UC (usecount) is 0.
```
INPUTS

    segment - the segment to be removed
RESULT

    success - success or failure.
SEE ALSO

```c
    [FindSegment()](autodocs-2.0/dos-library-findsegment.md), [AddSegment()](autodocs-2.0/dos-library-addsegment.md)
```

---

## See Also

- [AddSegment — dos.library](../autodocs/dos.library.md#addsegment)
- [FindSegment — dos.library](../autodocs/dos.library.md#findsegment)
