---
title: B Boopsi Class Reference / rootclass
manual: libraries
chapter: libraries
section: b-boopsi-class-reference-rootclass
functions: []
libraries: []
---

# B Boopsi Class Reference / rootclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  rootclass
Superclass:             None
Include File:           <intuition/[classusr.h](autodocs-2.0/includes-intuition-classusr-h.md)>

This is the universal base class for all other classes.

New Methods:
------------
 [OM_NEW](libraries/b-rootclass-new-methods-om-new.md)        [OM_ADDTAIL](libraries/b-rootclass-new-methods-om-addtail.md) 
 [OM_DISPOSE](libraries/b-rootclass-new-methods-om-dispose.md)    [OM_REMOVE](libraries/b-rootclass-new-methods-om-remove.md) 

The following methods are described at the rootclass level although its up
to the subclasses to actually implement them.  If a class does not
implement these methods, it should either return zero, indicating that
this class does not support the method, or defer processing on to its
superclass.

 [OM_ADDMEMBER](libraries/b-rootclass-new-methods-om-addmember.md)    [OM_GET](libraries/b-rootclass-new-methods-om-get.md)    [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) 
 [OM_REMMEMBER](libraries/b-rootclass-new-methods-om-remmember.md)    [OM_SET](libraries/b-rootclass-new-methods-om-set.md)    [OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md) 

Changed Methods:
----------------
Not applicable.

Attributes:
-----------
None.

