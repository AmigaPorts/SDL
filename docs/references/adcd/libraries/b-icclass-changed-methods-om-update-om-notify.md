---
title: B / icclass / Changed Methods: OM_UPDATE/OM_NOTIFY
manual: libraries
chapter: libraries
section: b-icclass-changed-methods-om-update-om-notify
functions: []
libraries: []
---

# B / icclass / Changed Methods: OM_UPDATE/OM_NOTIFY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These methods tell the object to notify its [ICA_TARGET](libraries/b-icclass-attributes-ica-target-is.md) of attribute
changes by sending the target an OM_UPDATE message.  If the object has an
[ICA_MAP](libraries/b-icclass-attributes-ica-map-is.md), it maps the attribute IDs it finds to new attribute IDs.  See the
[rootclass](libraries/b-boopsi-class-reference-rootclass.md) descriptions of [OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md) and [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) for more information.
The return value for this method is not explicitly defined.

