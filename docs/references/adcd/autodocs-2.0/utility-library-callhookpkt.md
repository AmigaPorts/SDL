---
title: utility.library/CallHookPkt
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-callhookpkt
functions: []
libraries: []
---

# utility.library/CallHookPkt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CallHookPkt -- Invoke a [Hook](autodocs-2.0/includes-utility-hooks-h.md) function callback. (V36)
```
SYNOPSIS

```c
    return = CallHookPkt( hook, object, paramPkt )
    D0                    A0    A2      A1

    ULONG CallHookPkt( struct [Hook](autodocs-2.0/includes-utility-hooks-h.md) *hook, VOID *object, VOID *paramPkt );
```
FUNCTION

```c
    Performs the callback standard defined by a [Hook](autodocs-2.0/includes-utility-hooks-h.md) structure.
    This function is really very simple; it effectively performs
    a JMP to Hook->h_Entry.

    It is probably just as well to do this operation in an
    assembly language function linked in to your program, possibly
    from a compiler supplied library or a builtin function.

    It is anticipated that C programs will often call a 'varargs'
    variant of this function which will be named [CallHook](autodocs-2.0/amiga-lib-callhook.md).  This
    function must be provided in a compiler specific library, but
    an example of use would be:

    returnval = CallHook( hook, dataobject, COMMAND_ID, param1, param2 );

    This function [CallHook](autodocs-2.0/amiga-lib-callhook.md) can be implemented in many C compilers
    like this:
    CallHook( hook, object, command, ... )
    struct [Hook](autodocs-2.0/includes-utility-hooks-h.md)    *hook;
    VOID            *object;
    ULONG           command;
    {
            return ( CallHookPkt( hook, object, (VOID *) &command ) );
    }
```
INPUTS

```c
    [Hook](autodocs-2.0/includes-utility-hooks-h.md)           - pointer to [Hook](autodocs-2.0/includes-utility-hooks-h.md) structure as defined in
                      [utility/hooks.h](autodocs-2.0/includes-utility-hooks-h.md)
    Object          - useful data structure in the particular context the
                      hook is being used for.
    ParamPkt        - pointer to a parameter packet (often built on the
                      stack); by convention this packet should start off
                      with a longword command code, and the remaining
                      data in the packet depends on that command.
```
RESULT

```c
    return          - The meaning of the value returned in D0 depends on
                      the context in which the [Hook](autodocs-2.0/includes-utility-hooks-h.md) is being used.
```
NOTES

```c
    The functions called through this function should follow normal
    register conventions unless EXPLICITLY documented otherwise (and
    they have a good reason too).
```
BUGS

SEE ALSO

```c
    [utility/hooks.h](autodocs-2.0/includes-utility-hooks-h.md)
```
