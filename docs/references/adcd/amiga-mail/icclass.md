---
title: icclass
manual: amiga-mail
chapter: amiga-mail
section: icclass
functions: []
libraries: []
---

# icclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  icclass
Superclass:             rootclass
Description:            Base class of simple forwarding interconnection.
Include File:           <intuition/icclass.h>


New Methods:
------------

ICM_SETLOOP
ICM_CLEARLOOP
ICM_CHECKLOOP - All of these methods are used internally by subclasses
to manage a loop inhibition for broadcasted messages.  They increment,
decrement, and return the value of that counter.


Changed Methods:
----------------

OM_SET - Sets attributes and returns 0.  Note that this is not the same
behavior as OM_NOTIFY.


OM_NOTIFY - Issues an OM_UPDATE message to the object indicated by
attribute ICA_Target, first converting the attribute tags according to
the ICA_Map attribute.  The internal loop count is incremented until the
OM_UPDATE method it invokes on ICA_Target returns.  Also, it will do
nothing at all if that loop count was non-zero to begin with, preventing
itself from participating in an infinite loop.


OM_UPDATE - Receive update notices from others.  This base IC class just
passes the message along, treating it exactly like an OM_NOTIFY message.
Subclasses will probably redefine this method to perform a calculation,
the result of which they might forward to others by issuing themselves
an OM_NOTIFY message.  Unfortunately, this class converts the OM_SET and
OM_NOTIFY messages to an OM_NOTIFY by changing their MethodID field, and
does not restore it to what it originally was.


Attributes:
-----------

ICA_Target                      (IS)

Target object for OM_UPDATE messages.  If this attribute is given the
value ICTARGET_IDCMP, then the notification will consist of sending an
IDCMPUPDATE IntuiMessage to a window.  The window is determined by the
GadgetInfo structure passed around when the object is connected to
gadgets.


ICA_Map                         (IS)

Attribute mapping list.


ICSPECIAL_CODE                  (*)

This is a magic dummy attribute: if it occurs as a target in the ICA_Map
mapping list, and ICA_Target is ICTARGET_IDCMP, then the new value of
the corresponding attribute will be copied into the IntuiMessage.Code
field of the IDCMPUPDATE message (just the lower sixteen bits of the
attribute value will fit).  This sometimes makes it particularly simple
to process IDCMPUPDATE messages with a single item of interest.

