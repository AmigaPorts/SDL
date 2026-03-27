---
title: B / groupgclass / Changed Methods: OM_ADDMEMBER
manual: libraries
chapter: libraries
section: b-groupgclass-changed-methods-om-addmember
functions: []
libraries: []
---

# B / groupgclass / Changed Methods: OM_ADDMEMBER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method adds a gadget to the group object's list.  The group object
will increase the size of its select box to include the new gadget's
select box.  The group object moves the new member to an absolute location
(by changing the new member's [GA_Left](libraries/b-gadgetclass-attributes-ga-left-ga-top-ga-width-ga-height.md) and [GA_Top](libraries/b-gadgetclass-attributes-ga-left-ga-top-ga-width-ga-height.md) attributes) relative to
the group object's upper-left corner.  Note that all members of the
[groupgclass](libraries/b-boopsi-class-reference-groupgclass.md) object will be deleted by [OM_DISPOSE](libraries/b-groupgclass-changed-methods-om-dispose.md).

