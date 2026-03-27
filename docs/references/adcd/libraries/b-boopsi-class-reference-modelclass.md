---
title: B Boopsi Class Reference / modelclass
manual: libraries
chapter: libraries
section: b-boopsi-class-reference-modelclass
functions: []
libraries: []
---

# B Boopsi Class Reference / modelclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  modelclass
Superclass:             [icclass](libraries/b-boopsi-class-reference-icclass.md)
Include File:           <intuition/[icclass.h](autodocs-2.0/includes-intuition-icclass-h.md)>

A class of OM_UPDATE forwarding objects that have multiple targets.  In
addition to the features the modelclass object inherits from [icclass](libraries/b-boopsi-class-reference-icclass.md), when
a modelclass object gets an [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) message, it forwards that [OM_UPDATE](libraries/b-modelclass-changed-methods-om-notify-om-update.md)
message to all of the objects in its broadcast list.

New Methods:
------------
None.

Changed Methods:
----------------
 [OM_ADDMEMBER](libraries/b-modelclass-changed-methods-om-addmember.md)    [OM_REMMEMBER](libraries/b-modelclass-changed-methods-om-remmember.md)    [OM_DISPOSE](libraries/b-modelclass-changed-methods-om-dispose.md)    [OM_NOTIFY/OM_UPDATE](libraries/b-modelclass-changed-methods-om-notify-om-update.md) 

Attributes:
-----------
None.

