---
title: amiga.lib/CallHook
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-callhook
functions: [CallHookPkt]
libraries: [utility.library]
---

# amiga.lib/CallHook

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CallHook -- Invoke a hook given a message on the stack.  (V36)
```
SYNOPSIS

```c
    result = CallHook( hookPtr, obj, ... )

    ULONG CallHook( struct [Hook](autodocs-2.0/includes-utility-hooks-h.md) *, Object *, ... );
```
FUNCTION

```c
    Like [CallHookA()](autodocs-2.0/amiga-lib-callhooka.md), CallHook() invoke a hook on the supplied
    hook-specific data (an "object") and a parameter packet ("message").
    However, CallHook() allows you to build the message on your stack.
```
INPUTS

    hookPtr - A system-standard hook
    obj - hook-specific data object
    ... - The hook-specific message you wish to send.  The hook is
        expecting a pointer to the message, so a pointer into your
        stack will be sent.
RESULT

    result - a hook-specific result.
NOTES

    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
EXAMPLE

```c
    If your hook's message was

        struct myMessage
        {
            ULONG mm_FirstGuy;
            ULONG mm_SecondGuy;
            ULONG mm_ThirdGuy;
        };

    You could write:

        result = CallHook( hook, obj, firstguy, secondguy, thirdguy );

    as a shorthand for:

        struct myMessage msg;

        msg.mm_FirstGuy = firstguy;
        msg.mm_SecondGuy = secondguy;
        msg.mm_ThirdGuy = thirdguy;

        result = CallHookA( hook, obj, &msg );
```
SEE ALSO

```c
    [CallHookA()](autodocs-2.0/amiga-lib-callhooka.md), [utility.library/CallHookPkt()](autodocs-2.0/utility-library-callhookpkt.md), [<utility/hooks.h>](autodocs-2.0/includes-utility-hooks-h.md)
```

---

## See Also

- [CallHookPkt — utility.library](../autodocs/utility.library.md#callhookpkt)
