---
title: B / rootclass / New Methods: OM_UPDATE
manual: libraries
chapter: libraries
section: b-rootclass-new-methods-om-update
functions: []
libraries: []
---

# B / rootclass / New Methods: OM_UPDATE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method tells an object to update one or more of its attributes.  No
application should call this method.  Only Boopsi objects send OM_UPDATE
messages.  The return value for this method is not explicitly defined.

A Boopsi object uses an OM_UPDATE message to notify another Boopsi object
about transitory changes to one or more attributes.

From the point of view of most objects, an OM_UPDATE message is almost
identical to [OM_SET](libraries/b-rootclass-new-methods-om-set.md).  Because the methods are so similar, When a typical
dispatcher receives an OM_UPDATE message, it processes the OM_UPDATE the
same way it would process an OM_SET message, usually using the same code.

There are actually two kinds of OM_UPDATE, an interim and final one.
While a Boopsi object's attribute is in a transient state, it can send out
interim OM_UPDATE messages to its target(s).  For example, while the user
is sliding a Boopsi prop gadget, the prop gadget sends interim OM_UPDATE
message about changes to its [PGA_Top](libraries/b-propgclass-pga-top-isgnu-pga-visible-pga-total-isu.md) value (the integer value of the prop
gadget is the PGA_Top attribute) to some target object.  When the user
lets go of the prop gadget, the gadget is no longer in a transient state,
so the gadget sends out a final OM_UPDATE about its PGA_Top attribute.
The target object can choose to change one of its attributes based on the
OM_UPDATE messages it receives.

The layout of the OM_UPDATE message is almost identical to the OM_SET
message:


```c
    struct opUpdate {  /* the OM_NOTIFY method also uses this structure */
        ULONG             MethodID;           /* OM_UPDATE              */
        struct TagItem    *opu_AttrList;      /* tag list of attributes */
        struct GadgetInfo *opu_GInfo;         /*   that changed.        */
        ULONG             opu_Flags;          /* The extra field        */
    };

    #define OPUF_INTERIM    (1<<0)
```
Some dispatchers need to know the difference between an interim and final
OM_UPDATE.  A dispatcher can tell the difference between an interim and
final OM_UPDATE message because the OM_UPDATE message has an extra field
for flags.  If the low order bit (the OPUF_INTERIM bit) is set, this is an
interim OM_UPDATE message.  The interim flag is useful to a class that
wants to ignore any interim messages, processing only final attribute
values.

