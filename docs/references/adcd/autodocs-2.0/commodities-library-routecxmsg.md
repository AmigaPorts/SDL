---
title: commodities.library/RouteCxMsg
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-routecxmsg
functions: [DivertCxMsg]
libraries: [commodities.library]
---

# commodities.library/RouteCxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RouteCxMsg -- set the next destination of a commodity message. (V36)
```
SYNOPSIS

```c
    RouteCxMsg(cxm,co);
               A0  A1

    VOID RouteCxMsg(struct CxMsg *,CxObj *);
```
FUNCTION

```c
    Establishes the next destination of a commodity message
    to be 'co', which must be a valid commodity object, and
    must be linked in ultimately to the Commodities Object [List](autodocs-2.0/includes-exec-lists-h.md).

    Routing of an object is analogous to a 'goto' in a program.
    There is no effect on the message's routing stack.
```
INPUTS

    cxm - the commodity message to route
    co - the commodity object to route the message to
SEE ALSO

```c
    [DivertCxMsg()](autodocs-2.0/commodities-library-divertcxmsg.md)
```

---

## See Also

- [DivertCxMsg — commodities.library](../autodocs/commodities.library.md#divertcxmsg)
