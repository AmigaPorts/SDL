---
title: Callback Hooks
manual: amiga-mail
chapter: amiga-mail
section: callback-hooks
functions: []
libraries: []
---

# Callback Hooks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When you present a custom image to Intuition, you provide a pointer to a
Hook structure that Intuition uses to find functions needed by various
image operations.  Without going into great detail, a hook provides a
pointer to a function that the system calls using Amiga register parameter
conventions.  The hook supplies enough information to conveniently
transfer control to a High-Level Language (HLL) entry point.  Boopsi
imageclass objects provide Intuition with a hook to a method dispatcher
function.

The Hook structure is defined as follows (from <utility/hooks.h>):


```c
    /* new standard hook structure */
    struct Hook
    {
        struct MinNode  h_MinNode;
        ULONG       (*h_Entry)();   /* stub function entry point */
        ULONG       (*h_SubEntry)();/* the custom function entry point */
        VOID        *h_Data;        /* owner specific */
    };
```
The assembly language stub for C parameter conventions that boopsi classes (and custom gadgets) require is:


```c
    _hookEntry:
        move.l  a1,-(sp)                ; push message packet pointer
        move.l  a2,-(sp)                ; push object pointer
        move.l  a0,-(sp)                ; push hook pointer
        move.l  h_SubEntry(a0),a0       ; fetch C entry point ...
        jsr     (a0)                    ; ... and call it
        lea     12(sp),sp               ; fix stack
        rts
```
The C language stub, for C compilers that support registerized parameters
is:


```c
    /* This function converts register-parameter hook calling
     * convention into standard C conventions.  It requires a C
     * compiler that supports registerized parameters, such as
     * SAS/C 5.xx or greater.
     */
    ULONG __asm hookEntry(
        register __a0 struct Hook *h,
        register __a2 VOID *o,
        register __a1 VOID *msg)
    {
        return ((*h->h_SubEntry)(h, o, msg));
    }
```
