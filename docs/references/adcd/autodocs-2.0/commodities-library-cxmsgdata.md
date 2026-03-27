---
title: commodities.library/CxMsgData
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-cxmsgdata
functions: []
libraries: []
---

# commodities.library/CxMsgData

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CxMsgData -- obtain a pointer to a commodity message's data area. (V36)
```
SYNOPSIS

```c
    data = CxMsgData(cxm);
                     A0

    UBYTE *CxMsgData(struct CxMsg *);
```
FUNCTION

```c
    Most commodity messages contain meaningful data, such as an [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md)
    structure. This function returns a pointer to this data.

    You may get a commodity message from a synchronous (custom object) or
    asynchronous (sender object) source. In the second case, 'data' is
    not valid after you have replied to the message.
```
INPUTS

    cxm - the commodity message to get the data pointer from
RESULTS

    data - a pointer to the message's data, or NULL if 'cxm' is NULL.
SEE ALSO

```c
    [cx_lib/CxSender()](autodocs-2.0/amiga-lib-cxsender.md), [cx_lib/CxCustom()](autodocs-2.0/amiga-lib-cxcustom.md)
```
