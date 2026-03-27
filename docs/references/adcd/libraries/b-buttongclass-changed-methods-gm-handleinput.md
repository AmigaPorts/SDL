---
title: B / buttongclass / Changed Methods: GM_HANDLEINPUT
manual: libraries
chapter: libraries
section: b-buttongclass-changed-methods-gm-handleinput
functions: []
libraries: []
---

# B / buttongclass / Changed Methods: GM_HANDLEINPUT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method continuously issues [OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md) messages for each IECLASS_TIMER
event it gets.  The OM_NOTIFY message's OPUF_INTERIM flag (from
[opUpdate.opu_Flags](libraries/b-rootclass-new-methods-om-update.md)) is set for all but the final OM_NOTIFY.

The [OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md) message contains one attribute/value pair, GA_ID.  If the
pointer is currently over the gadget image, the value of this
attribute/value pair is the gadget's actual GA_ID (from the
[Gadget.GadgetID](libraries/5-intuition-gadgets-gadget-structure.md) field).  If the pointer isn't over the image, the value is
the negative of the gadget's actual GA_ID.

