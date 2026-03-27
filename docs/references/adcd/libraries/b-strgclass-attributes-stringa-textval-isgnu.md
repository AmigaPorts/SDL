---
title: B / strgclass / Attributes: STRINGA_TextVal (ISGNU)
manual: libraries
chapter: libraries
section: b-strgclass-attributes-stringa-textval-isgnu
functions: []
libraries: []
---

# B / strgclass / Attributes: STRINGA_TextVal (ISGNU)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This attribute tells [strgclass](libraries/b-boopsi-class-reference-strgclass.md) that this gadget is a plain string gadget.
The attribute points to a string which the object copies into the string
gadget's current string value buffer.

When a [strgclass](libraries/b-boopsi-class-reference-strgclass.md) gadget's internal [STRINGA_LongVal](libraries/b-strgclass-attributes-stringa-longval-isgnu.md) or STRINGA_TextVal
value changes (usually because the user manipulated the gadget), it sends
itself an [OM_NOTIFY](libraries/b-gadgetclass-changed-methods-om-notify.md) message.  The OM_NOTIFY message will contain two
attribute/value pairs, GA_ID and either STRINGA_LongVal or STRINGA_TextVal
(depending on what kind of strgclass gadget it is).  Strgclass gadgets
only send a final OM_NOTIFY message (one's with the OPUF_INTERIM flag of
the [opUpdate.opu_Flags](libraries/b-rootclass-new-methods-om-update.md) field cleared).

