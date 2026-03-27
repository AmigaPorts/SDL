---
title: B / gadgetclass / Changed Methods: OM_NOTIFY
manual: libraries
chapter: libraries
section: b-gadgetclass-changed-methods-om-notify
functions: []
libraries: []
---

# B / gadgetclass / Changed Methods: OM_NOTIFY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method tells a gadget to send an [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) message to its target
object.  Boopsi gadgets have a function similar to [icclass](libraries/b-boopsi-class-reference-icclass.md) objects--each
gadget can have an [ICA_TARGET](libraries/b-gadgetclass-attributes-ica-target-is.md) and [ICA_MAP](libraries/b-gadgetclass-attributes-ica-map-is.md) in order to notify some target
object of attribute changes.  When a Boopsi gadget sends an OM_NOTIFY
message, it always includes its GA_ID.  This makes it easy for an
application to tell which gadget initially sent the OM_NOTIFY.  See the
description of icclass's [OM_NOTIFY](libraries/b-icclass-changed-methods-om-update-om-notify.md) and [OM_UPDATE](libraries/b-icclass-changed-methods-om-update-om-notify.md) and the [rootclass](libraries/b-boopsi-class-reference-rootclass.md)'s
[OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md) and [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) methods for more details.

