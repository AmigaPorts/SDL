---
title: B / icclass / Attributes: ICSPECIAL_CODE ()
manual: libraries
chapter: libraries
section: b-icclass-attributes-icspecial-code
functions: []
libraries: []
---

# B / icclass / Attributes: ICSPECIAL_CODE ()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is a dummy attribute for the [ICA_MAP](libraries/b-icclass-attributes-ica-map-is.md).  If any attribute maps to
ICSPECIAL_CODE and [ICA_TARGET](libraries/b-icclass-attributes-ica-target-is.md) is ICTARGET_IDCMP, then the value of the
mapped attribute will be copied into the [IntuiMessage.Code](libraries/9-using-the-idcmp-intuimessages.md) field of the
[IDCMP_IDCMPUPDATE](libraries/9-event-message-classes-and-flags-other-flags.md) message (just the lower sixteen bits of the attribute
value will fit).

