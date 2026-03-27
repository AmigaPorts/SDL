---
title: commodities.library/CxMsgID
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-cxmsgid
functions: []
libraries: []
---

# commodities.library/CxMsgID

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CxMsgID -- obtain the ID of a commodity message. (V36)
```
SYNOPSIS

```c
    id = CxMsgID(cxm);
                 A0

    LONG CxMsgID(struct CxMsg *);
```
FUNCTION

    This function returns the value associated with the cause or source
    of the commodity message 'cxm'. Values are provided by the application
    when a sender or custom object is created.
INPUTS

    cxm - the commodity message to inquire about
RESULTS

    id - if not specified by the application, the ID value of a
        commodity message will be 0. It is suggested that using
         non-zero values in your program as a rule may identify some
         possible errors.
SEE ALSO

```c
    [cx_lib/CxSender()](autodocs-2.0/amiga-lib-cxsender.md), [cx_lib/CxCustom()](autodocs-2.0/amiga-lib-cxcustom.md)
```
