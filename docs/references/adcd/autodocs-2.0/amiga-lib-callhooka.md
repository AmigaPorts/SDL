---
title: amiga.lib/CallHookA
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-callhooka
functions: [CallHookPkt]
libraries: [utility.library]
---

# amiga.lib/CallHookA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CallHookA -- Invoke a hook given a pointer to a message.  (V36)
```
SYNOPSIS

```c
    result = CallHookA( hookPtr, obj, message )

    ULONG CallHook( struct [Hook](autodocs-2.0/includes-utility-hooks-h.md) *, Object *, APTR );
```
FUNCTION

```c
    Invoke a hook on the supplied hook-specific data (an "object")
    and a parameter packet ("message").  This function is equivalent
    to [utility.library/CallHookPkt()](autodocs-2.0/utility-library-callhookpkt.md).
```
INPUTS

    hookPtr - A system-standard hook
    obj - hook-specific data object
    message - The hook-specific message you wish to send
RESULT

    result - a hook-specific result.
NOTES

    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
SEE ALSO

```c
    [CallHook()](autodocs-2.0/amiga-lib-callhook.md), [utility.library/CallHookPkt()](autodocs-2.0/utility-library-callhookpkt.md), [<utility/hooks.h>](autodocs-2.0/includes-utility-hooks-h.md)
```

---

## See Also

- [CallHookPkt — utility.library](../autodocs/utility.library.md#callhookpkt)
