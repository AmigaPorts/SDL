---
title: B / gadgetclass / Attributes: ICA_TARGET (IS)
manual: libraries
chapter: libraries
section: b-gadgetclass-attributes-ica-target-is
functions: []
libraries: []
---

# B / gadgetclass / Attributes: ICA_TARGET (IS)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This attribute stores the address of the gadget's target object.  Whenever
the gadget receives an [OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md) message, it sends an [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) message to
its target.  If the gadget has an attribute mapping list (see the [ICA_MAP](libraries/b-gadgetclass-attributes-ica-map-is.md)
attribute below), it also maps the IDs from the OM_NOTIFY message.

If the value of ICA_TARGET is ICTARGET_IDCMP, the gadget sends an
[IDCMP_IDCMPUPDATE](libraries/9-event-message-classes-and-flags-other-flags.md) [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) to its window.  See the [rootclass](libraries/b-boopsi-class-reference-rootclass.md)
description of [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) for more information.

