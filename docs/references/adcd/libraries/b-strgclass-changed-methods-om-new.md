---
title: B / strgclass / Changed Methods: OM_NEW
manual: libraries
chapter: libraries
section: b-strgclass-changed-methods-om-new
functions: []
libraries: []
---

# B / strgclass / Changed Methods: OM_NEW

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method sets up the string gadget's [StringInfo](libraries/5-string-gadget-type-stringinfo-structure.md) and [StringExtend](libraries/5-string-gadget-type-extended-string-gadgets.md)
structures.  It allocates a buffer if needed and will use shared data
buffers for [UndoBuffer](libraries/5-string-gadget-type-stringinfo-structure.md) and [WorkBuffer](libraries/5-string-gadget-type-extended-string-gadgets.md) if the [MaxChars](libraries/5-string-gadget-type-stringinfo-structure.md) is less than
SG_DEFAULTMAXCHARS (128).  Default text pens are: Foreground = 1,
Background = 0.  See the [rootclass](libraries/b-boopsi-class-reference-rootclass.md) description of the [OM_NEW](libraries/b-rootclass-new-methods-om-new.md) method for
more details.

