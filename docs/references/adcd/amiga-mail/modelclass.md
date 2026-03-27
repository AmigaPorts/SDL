---
title: modelclass
manual: amiga-mail
chapter: amiga-mail
section: modelclass
functions: []
libraries: []
---

# modelclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  modelclass
Superclass:             icclass
Description:            Provides "broadcast" interconnection.
Include File:           <intuition/icclass.h>


New Methods:
------------

None.


Changed Methods:
----------------

OM_ADDMEMBER - Adds an object to the the Model's internally maintained
broadcast list.  Anything on this list will be DISPOSED when the model
object is disposed.


OM_REMMEMBER - Removes objects added by OM_ADDMEMBER.


OM_DISPOSE - Disposes members of the broadcast list as well as itself.


OM_NOTIFY, OM_UPDATE - these behave like the icclass methods, but first
an OM_UPDATE message is sent to all members of the object's broadcast
list, un-mapped.  The members of the broadcast list are typically
icclass objects, which have gadgets as their targets and appropriate
mapping lists.  If you are creating a useful subclass, you will probably
want to intercept OM_UPDATE, but pass OM_NOTIFY to modelclass, your
superclass.


Attributes:
-----------

ICA_Map, ICA_Target -  Same as for the superclass (icclass).

