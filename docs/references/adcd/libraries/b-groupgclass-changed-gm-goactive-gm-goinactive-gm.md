---
title: B / groupgclass / Changed: GM_GOACTIVE/GM_GOINACTIVE/GM_HANDLEINPUT
manual: libraries
chapter: libraries
section: b-groupgclass-changed-gm-goactive-gm-goinactive-gm
functions: []
libraries: []
---

# B / groupgclass / Changed: GM_GOACTIVE/GM_GOINACTIVE/GM_HANDLEINPUT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method passes the message to the active member's dispatcher for
processing.   For GM_GOINACTIVE and GM_HANDLEINPUT, the coordinates passed
to the member's dispatcher in the message's [gpi_Mouse.X and gpi_Mouse.Y](libraries/b-gadgetclass-new-methods-gm-goactive.md)
fields are translated so that they are relative to the gadget's upper-left
corner.

