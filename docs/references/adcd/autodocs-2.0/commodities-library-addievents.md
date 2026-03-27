---
title: commodities.library/AddIEvents
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-addievents
functions: []
libraries: []
---

# commodities.library/AddIEvents

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AddIEvents -- add input events to commodities' input stream. (V36)
```
SYNOPSIS

```c
    AddIEvents(events)
               A0

    VOID AddIEvents(struct [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) *);
```
FUNCTION

```c
    This function adds a null-terminated linked list of input events to
    the input stream of commodities. It is a touch easier than using the
    input device directly.

    The contents of the input events are copied into commodity
    messages, so they may be disposed of as soon as this call returns.

    The messages are initially routed to the first broker in the
    Commodities Object [List](autodocs-2.0/includes-exec-lists-h.md).
```
INPUTS

    events - the list of input events to add
SEE ALSO

```c
    [cx_lib/FreeIEvents()](autodocs-2.0/amiga-lib-freeievents.md)
```
