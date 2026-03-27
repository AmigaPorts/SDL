---
title: 37 / / Hook Structure And Function / Simple Callback Hook Usage
manual: libraries
chapter: libraries
section: 37-hook-structure-and-function-simple-callback-hook-usage
functions: []
libraries: []
---

# 37 / / Hook Structure And Function / Simple Callback Hook Usage

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A [Hook](libraries/37-callback-hooks-callback-hook-structure-and-function.md) function must accept the following three parameters in these
specific registers:




```c
      A0 - Pointer to the [Hook](libraries/37-callback-hooks-callback-hook-structure-and-function.md) structure.
      A2 - Pointer to an object to manipulate. The object is
           context specific.
      A1 - Pointer to a message packet. This is also context
           specific.
```
For a callback function written in C, the parameters should appear in this
order:


```c
    myCallbackFunction(Pointer to Hook (A0),
                       Pointer to Object (A2),
                       Pointer to message (A1));
```
This is because the standard C stub pushes the parameters onto the stack
in the following order: A1, A2, A0.  The following assembly language
routine is a callback stub for C:


```c
    INCLUDE 'exec/types.i'
    INCLUDE 'utility/hooks.i'

    xdef        _hookEntry

    _hookEntry:
        move.l  a1,-(sp)                ; push message packet pointer
        move.l  a2,-(sp)                ; push object pointer
        move.l  a0,-(sp)                ; push hook pointer
        move.l  h_SubEntry(a0),a0       ; fetch actual Hook entry point ...
        jsr     (a0)                    ; and call it
        lea     12(sp),sp               ; fix stack
        rts
```
If your C compiler supports registerized parameters, your callback
functions can get the parameters directly from the CPU registers instead
of having to use a stub to push them on the stack.  The following C
language routine uses registerized parameters to put parameters in the
right registers.  This routine requires a C compiler that supports
registerized parameters.


```c
    #include <exec/types.h>
    #include <utility/hooks.h>

    #define     ASM     __asm
    #define     REG(x)  register __ ## x

    /* This function converts register-parameter hook calling
     * convention into standard C conventions.  It requires a C
     * compiler that supports registerized parameters, such as
     * SAS/C 5.xx or greater.
     */
    ULONG ASM
    hookEntry(REG(a0) struct Hook *h, REG(a2) VOID *o, REG(a1) VOID *msg)
    {
        return ((*h->h_SubEntry)(h, o, msg));
    }
```
A callback function is executed on the context of the module that invoked
it.  This usually means that callback functions cannot call functions that
need to look at environment specific data.  For example, [printf()](autodocs-2.0/amiga-lib-printf.md) needs to
look at the current process's input and output stream.  Entities like
Intuition have no input and output stream.  This also means that in order
for the function to access any of its global data, it needs to make sure
the CPU can find the function's data segment.  It does this by forcing the
function to load the offset for the program's data segment into CPU
register A4.  See your compiler documentation for details.

The following is a simple function that can be used in a callback hook.


```c
    ULONG MyFunction (struct Hook *h, VOID *o, VOID *msg)
    {
        /* A SASC and Manx function that obtains access to the global
           data segment */
        geta4();

        /* Debugging function to send a string to the serial port */
        KPrintF("Inside MyFunction()\n");

        return (1);
    }
```
The next step is to initialize the [Hook](libraries/37-callback-hooks-callback-hook-structure-and-function.md) for use.  This basically means
that the fields of the Hook structure must be filled with appropriate
values.

The following simple function initializes a [Hook](libraries/37-callback-hooks-callback-hook-structure-and-function.md) structure.


```c
    /* This simple function is used to initialize a Hook */
    VOID InitHook (struct Hook *h, ULONG (*func)(), VOID *data)
    {
        /* Make sure a pointer was passed */
        if (h)
        {
            /* Fill in the hook fields */
            h->h_Entry = (ULONG (*)()) hookEntry;
            h->h_SubEntry = func;
            h->h_Data = data;
        }
    }
```
The following is a simple example of a callback hook function.


```c
     [hooks1.c](libraries/lib-examples-hooks1-c.md) 
```
