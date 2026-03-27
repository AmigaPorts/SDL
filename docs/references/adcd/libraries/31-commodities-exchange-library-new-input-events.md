---
title: 31 Commodities Exchange Library / New Input Events
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-new-input-events
functions: [AddIEvents]
libraries: [commodities.library]
---

# 31 Commodities Exchange Library / New Input Events

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Commodities Exchange also has functions used to introduce new input events
to the input stream.


```c
    struct InputEvent *InvertString( UBYTE *string, ULONG *keymap );
    void               FreeIEvents( struct InputEvent *ie );
    void               AddIEvents( struct InputEvent *ie );
```
[InvertString()](autodocs-2.0/amiga-lib-invertstring.md) is an amiga.lib function that accepts an ASCII string and
creates a linked list of input events that translate into the string using
the supplied keymap (or the system default if the key map is NULL).  The
NULL terminated string may contain ANSI character codes, an input
description enclosed in angle (<>) brackets, or one of the following
backslash escape characters:


    \r -- return
    \t -- tab
    \\ -- backslash
For example:


    abc<alt f1>\rhi there.
[FreeIEvents()](autodocs-2.0/amiga-lib-freeievents.md) frees a list of input events allocated by [InvertString()](autodocs-2.0/amiga-lib-invertstring.md).
[AddIEvents()](autodocs-2.0/commodities-library-addievents.md) is a commodities.library function that adds a linked list of
input events at the the top of the Commodities network.  Each input event
in the list is made into an individual [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md).  Note that if passed a
linked list of input events created by InvertString(), the order the
events appear in the string will be reversed.


```c
     [PopShell.c](libraries/lib-examples-popshell-c.md) 
```

---

## See Also

- [AddIEvents — commodities.library](../autodocs/commodities.library.md#addievents)
