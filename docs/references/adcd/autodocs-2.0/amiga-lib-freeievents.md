---
title: amiga.lib/FreeIEvents
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-freeievents
functions: []
libraries: []
---

# amiga.lib/FreeIEvents

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeIEvents -- free a chain of input events allocated by
                   [InvertString()](autodocs-2.0/amiga-lib-invertstring.md). (V36)
```
SYNOPSIS

```c
    FreeIEvents(events)

    VOID FreeIEvents(struct [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) *);
```
FUNCTION

```c
    This function frees a linked list of input events as obtained from
    [InvertString()](autodocs-2.0/amiga-lib-invertstring.md).
```
INPUTS
   events - the list of input events to free, may be NULL.

SEE ALSO

```c
    [InvertString()](autodocs-2.0/amiga-lib-invertstring.md)
```
