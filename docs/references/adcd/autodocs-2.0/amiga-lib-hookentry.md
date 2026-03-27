---
title: amiga.lib/HookEntry
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-hookentry
functions: []
libraries: []
---

# amiga.lib/HookEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    HookEntry -- Assembler to HLL conversion stub for hook entry.  (V36)
```
SYNOPSIS

```c
    result = HookEntry( struct [Hook](autodocs-2.0/includes-utility-hooks-h.md) *, Object *, APTR )
    D0                  A0             A2        A1
```
FUNCTION

```c
    By definition, a standard hook entry-point must receive the
    hook in A0, the object in A2, and the message in A1.  If your
    hook entry-point is written in a high-level language and is
    expecting its parameters on the stack, then HookEntry() will
    put the three parameters on the stack and invoke the function
    stored in the hook h_SubEntry field.

    This function is only useful to hook implementers, and is
    never called from C.
```
INPUTS

    hook - pointer to hook being invoked
    object - pointer to hook-specific data
    msg - pointer to hook-specific message
RESULT

    result - a hook-specific result.
NOTES

    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
EXAMPLE

```c
    If your hook dispatcher is this:

    dispatch( struct [Hook](autodocs-2.0/includes-utility-hooks-h.md) *hookPtr, Object *obj, APTR msg )
    {
        ...
    }

    Then when you initialize your hook, you would say:

    myhook.h_Entry = HookEntry;     /* amiga.lib stub */
    myhook.h_SubEntry = dispatch;   /* HLL entry */
```
SEE ALSO

```c
    [CallHook()](autodocs-2.0/amiga-lib-callhook.md), [CallHookA()](autodocs-2.0/amiga-lib-callhooka.md), [<utility/hooks.h>](autodocs-2.0/includes-utility-hooks-h.md)
```
