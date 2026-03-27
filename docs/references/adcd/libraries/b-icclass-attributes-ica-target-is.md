---
title: B / icclass / Attributes: ICA_TARGET (IS)
manual: libraries
chapter: libraries
section: b-icclass-attributes-ica-target-is
functions: []
libraries: []
---

# B / icclass / Attributes: ICA_TARGET (IS)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This attribute stores the address of the [icclass](libraries/b-boopsi-class-reference-icclass.md) object's target object.
Whenever the icclass object receives an [OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md) or [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) message, it
forwards that message to its target in the form of an OM_UPDATE message.
If the icclass object has an attribute mapping list (see the [ICA_MAP](libraries/b-icclass-attributes-ica-map-is.md)
attribute below), it also maps the [OM_NOTIFY/OM_UPDATE](libraries/b-icclass-changed-methods-om-update-om-notify.md) message's attribute
IDs to new ones before forwarding the message.

If the value of ICA_TARGET is ICTARGET_IDCMP, the [icclass](libraries/b-boopsi-class-reference-icclass.md) object sends an
[IDCMP_IDCMPUPDATE](libraries/9-event-message-classes-and-flags-other-flags.md) [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) to its window instead of forwarding an
OM_UPDATE message.  See the [rootclass](libraries/b-boopsi-class-reference-rootclass.md) description of [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) for more
information.

