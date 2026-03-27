---
title: 31 Commodities Exchange Library / CxObjects
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-cxobjects
functions: []
libraries: []
---

# 31 Commodities Exchange Library / CxObjects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

CxObjects are the basic building blocks used to construct a commodity.  A
commodity uses CxObjects to take care of all manipulations of [CxMessages](libraries/31-commodities-exchange-library-cxmessages.md).
When a CxMessage "arrives" at a CxObject, that CxObject carries out its
primitive action and then, if it has not deleted the CxMessage, it passes
the CxMessage on to the next CxObject.  A commodity links together
CxObjects into a tree, organizing these simple action objects to perform
some higher function.

A CxObject is in one of two states, active or inactive.  An active
CxObject performs its primitive action every time it receives a [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md).
If a CxObject is inactive, CxMessages bypass it, continuing to the
CxObject that follows the inactive one.  By default, all CxObjects except
the type called brokers are created in the active state.

Currently, there are seven types of CxObjects (Table 31-1).


   Object Type   Purpose
   -----------   -------

```c
    [Broker](libraries/31-commodities-exchange-library-installing-a-broker-object.md)       Registers a new commodity with the commodity network
    [Filter](libraries/31-commodities-exchange-filter-objects-and-input.md)       Accepts or rejects input events based on criteria set
                 up by the application
    [Sender](libraries/31-commodities-exchange-library-sender-cxobjects.md)       Sends a message to a message port
    [Translate](libraries/31-commodities-exchange-library-translate-cxobjects.md)    Replaces the input event with a different one
    [Signal](libraries/31-commodities-exchange-library-signal-cxobjects.md)       Signals a task
    [Custom](libraries/31-commodities-exchange-library-custom-cxobjects.md)       Calls a custom function provided by the commodity
    [Debug](libraries/31-commodities-exchange-library-debug-cxobjects.md)        Sends debug information out the serial port


                 Table 31-1: Commodities Exchange Object Types
```
