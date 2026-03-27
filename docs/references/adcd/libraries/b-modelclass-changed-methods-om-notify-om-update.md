---
title: B / modelclass / Changed Methods: OM_NOTIFY/OM_UPDATE
manual: libraries
chapter: libraries
section: b-modelclass-changed-methods-om-notify-om-update
functions: []
libraries: []
---

# B / modelclass / Changed Methods: OM_NOTIFY/OM_UPDATE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method tells an object to forward the message in the form of an
OM_UPDATE message to all the objects in its broadcast list.  The
[modelclass](libraries/b-boopsi-class-reference-modelclass.md) does not map the attributes in these OM_UPDATE messages.
Because modelclass inherits behavior from [icclass](libraries/b-boopsi-class-reference-icclass.md), if the model has an
[ICA_TARGET](libraries/b-icclass-attributes-ica-target-is.md) and [ICA_MAP](libraries/b-icclass-attributes-ica-map-is.md), it will also send a mapped OM_UPDATE message to
its ICA_TARGET.  The return values for these methods are not explicitly
defined.  See the [rootclass](libraries/b-boopsi-class-reference-rootclass.md) [OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md)/[OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) and icclass
[OM_NOTIFY/OM_UPDATE](libraries/b-icclass-changed-methods-om-update-om-notify.md) descriptions for more information.

