---
title: commodities.library/CxMsgType
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-cxmsgtype
functions: []
libraries: []
---

# commodities.library/CxMsgType

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CxMsgType -- obtain the type of a commodity message. (V36)
```
SYNOPSIS

```c
    type = CxMsgType(cxm);
                     A0

    ULONG CxMsgType(struct CxMsg *);
```
FUNCTION

```c
    This function returns the type of a commodity message. Possible values
    of 'type' are defined in [<libraries/commodities.h>](autodocs-2.0/includes-libraries-commodities-h.md). Most commodity
    messages are of type CXM_IEVENT.
```
INPUTS

    cxm - the commodity message to inquire about
RESULTS

```c
    type - the type of the commodity message, possible values are defined
           in [<libraries/commodities.h>](autodocs-2.0/includes-libraries-commodities-h.md)
```
