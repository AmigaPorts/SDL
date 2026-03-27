---
title: amiga.lib/HotKey
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-hotkey
functions: [CxObjError, SetFilter]
libraries: [commodities.library]
---

# amiga.lib/HotKey

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    HotKey -- create a commodity triad. (V36)
```
SYNOPSIS

```c
    filterObj = Hotkey(description,port,id);

    CxObj *HotKey(STRPTR,struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *,LONG);
```
FUNCTION

```c
    This function creates a triad of commodity objects to accomplish a
    high-level function.

    The three objects are a filter, which is created to match by the call
    CxFilter(description), a sender created by the call CxSender(port,id),
    and a translator which is created by CxTranslate(NULL), so that it
    swallows any commodity input event messages that are passed down by
    the filter.

    This is the simple way to get a message sent to your program when the
    user performs a particular input action.

    It is strongly recommended that the ToolTypes environment be used to
    allow the user to specify the input descriptions for your application's
    hotkeys.
```
INPUTS

```c
    description - the description string to use for the filter in the same
                  format as accepted by [commodities.library/SetFilter()](autodocs-2.0/commodities-library-setfilter.md)
    port - port for the sender to send messages to.
    id - id of the messages sent by the sender
```
RESULTS

    filterObj - a pointer to a filter object, or NULL if it could
                not be created.
SEE ALSO

```c
    [CxFilter()](autodocs-2.0/amiga-lib-cxfilter.md), [CxSender()](autodocs-2.0/amiga-lib-cxsender.md), [CxTranslate()](autodocs-2.0/amiga-lib-cxtranslate.md),
    [commodities.library/CxObjError()](autodocs-2.0/commodities-library-cxobjerror.md), [commodities.library/SetFilter()](autodocs-2.0/commodities-library-setfilter.md)
```

---

## See Also

- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
