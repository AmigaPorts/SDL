---
title: buttongclass
manual: amiga-mail
chapter: amiga-mail
section: buttongclass
functions: []
libraries: []
---

# buttongclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  buttongclass
Superclass:             gadgetclass
Description:            A (repeatable) command button gadget.
Include File:           <intuition/gadgetclass.h>


New Methods:
------------

None.


Changed Methods:
----------------

GM_HITTEST - Delegates this question to its GA_Image attribute.


GM_HANDLEINPUT - Will behave like a button, but continuously issues
OM_NOTIFY messages for each IECLASS_TIMER event.

Flag OPUF_INTERIM will be set for all but the last notification.

The notified attribute is GA_ID, with a twist: the value sent will be
the negative of GadgetID if the pointer is not currently over the gadget
image.


GM_RENDER - All rendering is passed along to the GadgetRender Image.
The state provided is  IDS_INACTIVESELECTED, IDS_INACTIVENORMAL,
IDS_SELECTED, or IDS_NORMAL.


Attributes:
-----------

GA_Image                        (IS)

Changing the image will cause the gadget to refresh itself.

