---
title: Translate CxObjects
manual: amiga-mail
chapter: amiga-mail
section: translate-cxobjects
functions: []
libraries: []
---

# Translate CxObjects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Normally, after a commodity processes a hot key input event, it needs
to eliminate the input event.  Other commodities may need to replace
an input event with a different one.  The translate CxObject can be
used for these purposes.


```c
    translateCxObj = CxObj *CxTranslate(struct InputEvent *newinputevent);
```
The macro CxTranslate() creates a new translate CxObject.
CxTranslate()'s only argument is a pointer to a chain of one or more
InputEvent structures.  When a translate CxObject receives a
CxMessage, it eliminates the CxMessage and its corresponding input
event from the system.  The translator introduces a new input event,
which Commodities Exchange copies from the InputEvent structure passed
to CxTranlate() (newinputevent from the function prototype above), in
place of the deleted input event.  The trans lator introduces the new
input event after the Commodities Exchange input handler in the
input.device's input stream.  Any CxObjects that follow the translator
in the Commodities network will see neither the deleted CxMessage nor
the new input event.

A translator is normally attached to some kind of filtering CxObject.
If it wasn't, it would translate all input events into the same exact
input event.  Like the sender CxObject, a translator does not divert
CxMessages down its personal list, so it does n't serve any purpose to
add any to it.

HotKey utilizes a special kind of translator.  Instead of supplying a
new input event, HotKey passes a NULL to CxTranslate().  If a
translator has a NULL new input event pointer, it does not introduce a
new input event, but still eliminates any CxMessages and corresponding
input events it receives.

