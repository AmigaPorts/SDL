---
title: 31 Commodities Exchange Library / Debug CxObjects
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-debug-cxobjects
functions: []
libraries: []
---

# 31 Commodities Exchange Library / Debug CxObjects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The final [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) is the debug CxObject.  When a debug CxObject receives
a [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md), it sends debugging information to the serial port using
[KPrintF()](autodocs-2.0/debug-lib-kprintf.md).


```c
    debugCxObj  = CxObj  *CxDebug(LONG ID);
```
The debug [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) will [KPrintF()](autodocs-2.0/debug-lib-kprintf.md) the following information about itself,
the [CxMsg](autodocs-2.0/includes-libraries-commodities-h.md), and the corresponding [InputEvent](libraries/9-intuition-input-and-output-methods-intuition-input.md) structure:


    DEBUG NODE: 7CB5AB0, ID: 2
     CxMsg: 7CA6EF2, type: 0, data 2007CA destination 6F1E07CB
    dump IE: 7CA6F1E
     Class 1
     Code 40
     Qualifier 8000
     EventAddress 40001802
There has to be a terminal connected to the Amiga's serial port to receive
this information.  See the [KPrintF()](autodocs-2.0/debug-lib-kprintf.md) Autodoc (debug.lib) for more details.
Note that the debug [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) did not work before V37.

