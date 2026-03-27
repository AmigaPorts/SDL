---
title: B / propgclass / Changed Methods: GM_HANDLEINPUT
manual: libraries
chapter: libraries
section: b-propgclass-changed-methods-gm-handleinput
functions: []
libraries: []
---

# B / propgclass / Changed Methods: GM_HANDLEINPUT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If the knob position changes sufficiently to change a [propgclass](libraries/b-boopsi-class-reference-propgclass.md) object's
[PGA_Top](libraries/b-propgclass-pga-top-isgnu-pga-visible-pga-total-isu.md) attribute, the gadget will send an [OM_NOTIFY](libraries/b-gadgetclass-changed-methods-om-notify.md) message to itself,
which the propgclass dispatcher passes on to the [gadgetclass](libraries/b-boopsi-class-reference-gadgetclass.md) dispatcher
for processing (see the [rootclass](libraries/b-boopsi-class-reference-rootclass.md) description of [OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md) and [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md)
for more information).

The [OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md) message will contain two attribute/value pairs, [PGA_Top](libraries/b-propgclass-pga-top-isgnu-pga-visible-pga-total-isu.md) and
GA_ID.  While the prop gadget's PGA_Top is in a transitory state (while it
is active and the user is moving the prop gadget's knob), the gadget sends
interim [OM_NOTIFY](libraries/b-gadgetclass-changed-methods-om-notify.md) messages.  The interim OM_NOTIFY messages have the
OPUF_INTERIM flag of the [opUpdate.opu_Flags](libraries/b-rootclass-new-methods-om-update.md) field set.  When the user
finishes manipulating the gadget (by letting go of the knob), the gadget
sends a final OM_NOTIFY message, which has a cleared OPUF_INTERIM flag.

