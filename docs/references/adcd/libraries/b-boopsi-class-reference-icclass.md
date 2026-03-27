---
title: B Boopsi Class Reference / icclass
manual: libraries
chapter: libraries
section: b-boopsi-class-reference-icclass
functions: []
libraries: []
---

# B Boopsi Class Reference / icclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  icclass (interconnection class)
Superclass:             [rootclass](libraries/b-boopsi-class-reference-rootclass.md)
Include File:           <intuition/[icclass.h](autodocs-2.0/includes-intuition-icclass-h.md)>

Base class of simple OM_UPDATE forwarding objects.  When an icclass object
gets an [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) message, it maps the attributes in the OM_UPDATE message
according to its mapping list (its [ICA_MAP](libraries/b-icclass-attributes-ica-map-is.md) attribute) and forwards the
[OM_UPDATE](libraries/b-icclass-changed-methods-om-update-om-notify.md) to its target (its [ICA_TARGET](libraries/b-icclass-attributes-ica-target-is.md) attribute).

New Methods:
------------
None.

Changed Methods:
----------------
 [OM_SET](libraries/b-icclass-changed-methods-om-set.md)    [OM_UPDATE/OM_NOTIFY](libraries/b-icclass-changed-methods-om-update-om-notify.md) 

Attributes:
-----------
 [ICA_TARGET (IS)](libraries/b-icclass-attributes-ica-target-is.md)    [ICA_MAP (IS)](libraries/b-icclass-attributes-ica-map-is.md)    [ICSPECIAL_CODE (*)](libraries/b-icclass-attributes-icspecial-code.md) 

