---
title: A / Amiga.lib / Commodities
manual: libraries
chapter: libraries
section: a-amiga-lib-commodities
functions: [FindToolType, SetFilter]
libraries: [commodities.library, icon.library]
---

# A / Amiga.lib / Commodities

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md) and [ArgArrayDone()](autodocs-2.0/amiga-lib-argarraydone.md)

```c
    ArgArrayInit() returns an array of strings suitable for sending to
    icon.library/[FindToolType()](autodocs-2.0/icon-library-findtooltype.md). This array will be the ToolTypes array
    of the program's icon, if it was started from Workbench. It will just
    be 'argv' if the program was started from a shell. ArgArrayDone()
    frees memory and does cleanup required after a call to ArgArrayInit().
```
[ArgInt()](autodocs-2.0/amiga-lib-argint.md) and [ArgString()](autodocs-2.0/amiga-lib-argstring.md)

```c
    These functions look for a particular entry in a ToolType array
    returned by ArgArrayInit() and return the integer (ArgInt()) or
    string (ArgString()) associated with that entry.  A default value can
    be passed to each function which will be returned in the event that
    the requested entry could not be found in the ToolType array.
```
[CxCustom()](autodocs-2.0/amiga-lib-cxcustom.md)

    This function creates a custom commodity object. The action of this
    object on receiving a commodity message is to call a function of the
    application programmer's choice.
[CxDebug()](autodocs-2.0/amiga-lib-cxdebug.md)

```c
    This function creates a Commodities debug object. The action of this
    object on receiving a Commodities message is to print out information
    about the message through the serial port (using the
    debug.lib/[KprintF()](libraries/a-appendix-a-linker-libraries-debug-lib.md) routine). A specified 'id' will also be displayed.
```
[CxFilter()](autodocs-2.0/amiga-lib-cxfilter.md)

```c
    Creates a Commodities input event filter object that matches a
    description string. The description string is in the same format as
    strings expected by commodities.library/[SetFilter()](autodocs-2.0/commodities-library-setfilter.md). If the
    description string is NULL, the filter will not match any messages.
```
[CxSender()](autodocs-2.0/amiga-lib-cxsender.md)

    This function creates a Commodities sender object. The action of this
    object on receiving a Commodities message is to copy the Commodities
    message into a standard Exec Message, to put a supplied id in the
    message as well, and to send the message off to the message port.
[CxSignal()](autodocs-2.0/amiga-lib-cxsignal.md)

    This function creates a Commodities signal object. The action of this
    object on receiving a Commodities message is to send a signal to a
    task.  The caller is responsible for allocating the signal and
    determining the proper task ID.
[CxTranslate()](autodocs-2.0/amiga-lib-cxtranslate.md)

    This function creates a Commodities translator object. The action of
    this object on receiving a Commodities message is to replace that
    message in the commodities network with a chain of Commodities input
    messages.
[HotKey()](autodocs-2.0/amiga-lib-hotkey.md)

```c
    This function creates a triad of commodity objects to accomplish a
    high-level function.

    The three objects are a filter, which is created to match by
    CxFilter(), a sender created by CxSender(), and a translator which is
    created by CxTranslate(), so that it swallows any commodity input
    event messages that are passed down by the filter.

    This is the simple way to get a message sent to your program when the
    user performs a particular input action.
```
[InvertString()](autodocs-2.0/amiga-lib-invertstring.md)

```c
    This function returns a linked list of input events which would
    translate into the string using the supplied keymap (or the system
    default keymap if the supplied keymap is NULL).

    This chain should eventually be freed using FreeIEvents().
```
[FreeIEvents()](autodocs-2.0/amiga-lib-freeievents.md)

```c
    This function frees a linked list of input events as obtained from
    InvertString().
```

---

## See Also

- [FindToolType — icon.library](../autodocs/icon.library.md#findtooltype)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
