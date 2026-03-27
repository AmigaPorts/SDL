---
title: B / strgclass / Attributes: STRINGA_MaxChars - STRINGA_WorkBuffer (I)
manual: libraries
chapter: libraries
section: b-strgclass-attributes-stringa-maxchars-stringa-workbuffer-i
functions: []
libraries: []
---

# B / strgclass / Attributes: STRINGA_MaxChars - STRINGA_WorkBuffer (I)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

STRINGA_MaxChars, STRINGA_Buffer, STRINGA_UndoBuffer, STRINGA_WorkBuffer
(I) - Specify various buffers defined for string gadgets and extended
string gadgets.  If your value of STRINGA_MaxChars is less than
SG_DEFAULTMAXCHARS (128 for now), then this class can provide all these
buffers for you.  Note that [UndoBuffer](libraries/5-string-gadget-type-stringinfo-structure.md) and [WorkBuffer](libraries/5-string-gadget-type-extended-string-gadgets.md) can be shared by
many separate gadgets, providing they are as large as the largest [MaxChars](libraries/5-string-gadget-type-stringinfo-structure.md)
they will encounter.

