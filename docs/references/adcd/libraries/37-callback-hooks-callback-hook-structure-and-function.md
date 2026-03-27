---
title: 37 / Callback Hooks / Callback Hook Structure and Function
manual: libraries
chapter: libraries
section: 37-callback-hooks-callback-hook-structure-and-function
functions: []
libraries: []
---

# 37 / Callback Hooks / Callback Hook Structure and Function

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An application passes a custom function in the form of a callback Hook
(from <utility/[hooks.h](autodocs-2.0/includes-utility-hooks-h.md)>):


```c
    struct Hook
    {
        struct MinNode h_MinNode;
        ULONG (*h_Entry)();     /* stub function entry point */
        ULONG (*h_SubEntry)();  /* the custom function entry point */
        VOID *h_Data;           /* owner specific */
    };
```
h_MinNode

    This field is reserved for use by the module that will call the Hook.
h_Entry

    This is the address of the Hook stub.  When the OS calls a callback
    function, it puts parameters for the callback function in CPU
    registers A0, A1, and A2.  This makes it tough for higher level
    language programmers to use a callback function because most higher
    level languages don't have a way to manipulate CPU registers
    directly.  The solution is a stub function which first copies the
    parameters from the CPU registers to a place where a high level
    language function can get to them.   The stub function then calls the
    callback function.  Typically, the stub pushes the registers onto the
    stack in a specific order and the callback function pops them off the
    stack.
h_SubEntry

    This is the address of the actual callback function that the
    application has defined.  The stub calls this function.
h_Data

    This field is for the application to use.  It could point to a global
    storage structure that the callback function utilizes.
There is only one function defined in utility library that relates to
callback hooks:


```c
    ULONG CallHookPkt(struct Hook *hook, VOID *object, VOID *paramPkt);
```
This function calls a standard callback Hook function.

 [Simple Callback Hook Usage](libraries/37-hook-structure-and-function-simple-callback-hook-usage.md) 

