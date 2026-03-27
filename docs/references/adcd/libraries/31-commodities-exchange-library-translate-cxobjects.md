---
title: 31 Commodities Exchange Library / Translate CxObjects
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-translate-cxobjects
functions: [SetTranslate]
libraries: [commodities.library]
---

# 31 Commodities Exchange Library / Translate CxObjects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Normally, after a commodity processes a hot key input event, it needs to
eliminate that input event.  Other commodities may need to replace an
input event with a different one.  The translate [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) can be used for
these purposes.


```c
    translateCxObj = CxObj  *CxTranslate(struct InputEvent *newinputevent);
```
The macro [CxTranslate()](autodocs-2.0/amiga-lib-cxtranslate.md) creates a new translate [CxObject](libraries/31-commodities-exchange-library-cxobjects.md).  CxTranslate()'s
only argument is a pointer to a chain of one or more [InputEvent](libraries/9-intuition-input-and-output-methods-intuition-input.md) structures.

When a translate [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) receives a [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md), it eliminates the
CxMessage and its corresponding input event from the system.  The
translator introduces a new input event, which Commodities Exchange copies
from the [InputEvent](libraries/9-intuition-input-and-output-methods-intuition-input.md) structure passed to [CxTranslate()](autodocs-2.0/amiga-lib-cxtranslate.md) (newinputevent from
the function prototype above), in place of the deleted input event.

A translator is normally attached to some kind of [filtering CxObject](libraries/31-commodities-exchange-filter-objects-and-input.md).  If
it wasn't, it would translate all input events into the same exact input
event.  Like the [sender CxObject](libraries/31-commodities-exchange-library-sender-cxobjects.md), a translator does not divert [CxMessages](libraries/31-commodities-exchange-library-cxmessages.md)
down its personal list, so it doesn't serve any purpose to add any to it.


```c
    void SetTranslate( CxObj *translator, struct InputEvent *ie );
```
It is possible to change the [InputEvent](libraries/9-intuition-input-and-output-methods-intuition-input.md) structure that a translator looks
at when it creates and introduces new input events into the input stream.
The function [SetTranslate()](autodocs-2.0/commodities-library-settranslate.md) accepts a pointer to the new InputEvent
structure, which the translator will duplicate and introduce when it
receives a [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md).

HotKey utilizes a special kind of translator.  Instead of supplying a new
input event, HotKey passes a NULL to [CxTranslate()](autodocs-2.0/amiga-lib-cxtranslate.md).  If a translator has a
NULL new input event pointer, it does not introduce a new input event, but
still eliminates any [CxMessages](libraries/31-commodities-exchange-library-cxmessages.md) and corresponding input events it receives.

---

## See Also

- [SetTranslate — commodities.library](../autodocs/commodities.library.md#settranslate)
