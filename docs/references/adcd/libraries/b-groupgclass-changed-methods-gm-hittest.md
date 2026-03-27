---
title: B / groupgclass / Changed Methods: GM_HITTEST
manual: libraries
chapter: libraries
section: b-groupgclass-changed-methods-gm-hittest
functions: []
libraries: []
---

# B / groupgclass / Changed Methods: GM_HITTEST

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method works its way through the list of group members, sending each
a [GM_HITTEST](libraries/b-gadgetclass-new-methods-gm-hittest.md) message, looking for the first member in the list that says
it has been hit.  This member gadget becomes the active member.

