---
title: B / rootclass / New Methods: OM_REMMEMBER
manual: libraries
chapter: libraries
section: b-rootclass-new-methods-om-remmember
functions: []
libraries: []
---

# B / rootclass / New Methods: OM_REMMEMBER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Tells an object to remove a member object from its personal list.  The
member object should have already been added with [OM_ADDMEMBER](libraries/b-rootclass-new-methods-om-addmember.md).  This
method uses the same custom message as OM_ADDMEMBER.  Normally a
dispatcher implements OM_REMMEMBER by sending the [OM_REMOVE](libraries/b-rootclass-new-methods-om-remove.md) message to the
opam_Object object.  The return value for this method is not explicitly
defined.

