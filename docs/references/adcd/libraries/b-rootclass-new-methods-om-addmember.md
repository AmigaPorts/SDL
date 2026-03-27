---
title: B / rootclass / New Methods: OM_ADDMEMBER
manual: libraries
chapter: libraries
section: b-rootclass-new-methods-om-addmember
functions: []
libraries: []
---

# B / rootclass / New Methods: OM_ADDMEMBER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Tells an object to add another object to its personal Exec list.  What the
list is for depends on the class.  The return value for this method is not
explicitly defined.

One class that uses this method is [modelclass](libraries/b-boopsi-class-reference-modelclass.md).  A modelclass object
maintains a broadcast list.  When a modelclass object gets an [OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md)
message, it broadcasts an [OM_UPDATE](libraries/b-modelclass-changed-methods-om-notify-om-update.md) message about the OM_NOTIFY to every
object in its broadcast list.

This method uses a custom message (defined in <intuition/[classusr.h](autodocs-2.0/includes-intuition-classusr-h.md)>):


```c
    #define  opAddMember opMember
    struct opMember {
        ULONG  MethodID;     /* OM_ADDMEMBER (or OM_REMMEMBER) */
        Object *opam_Object; /* add (or remove) this object    */
    };                       /* to (from) personal list.       */
```
opam_Object is the object to add to the list.  A dispatcher typically
implements OM_ADDMEMBER by sending the [OM_ADDTAIL](libraries/b-rootclass-new-methods-om-addtail.md) message to the
opam_Object object.

