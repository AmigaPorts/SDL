---
title: 5 / / Custom String Editing / The SGH_CLICK Command
manual: libraries
chapter: libraries
section: 5-custom-string-editing-the-sgh-click-command
functions: []
libraries: []
---

# 5 / / Custom String Editing / The SGH_CLICK Command

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The SGH_CLICK command indicates that the user has clicked the select
button of the mouse within the gadget select box.  There are no parameters
following the SGH_CLICK command longword.

Intuition will have already calculated the mouse position character cell
and placed that value in [SGWork.BufferPos](libraries/5-custom-string-editing-sgwork-structure.md).  The previous BufferPos value
remains in the [SGWork](libraries/5-custom-string-editing-sgwork-structure.md).[StringInfo.BufferPos](libraries/5-string-gadget-type-stringinfo-structure.md).

Intuition will again use the [SGWork](libraries/5-custom-string-editing-sgwork-structure.md) fields listed above for [SGH_KEY](libraries/5-custom-string-editing-actions-with-sgh-key.md).  That
is, the [WorkBuffer](libraries/5-custom-string-editing-sgwork-structure.md), [NumChars](libraries/5-custom-string-editing-sgwork-structure.md), [BufferPos](libraries/5-custom-string-editing-sgwork-structure.md) and [LongInt](libraries/5-custom-string-editing-sgwork-structure.md) fields values may be
modified by the hook and are used by Intuition if [SGA_USE](libraries/5-custom-string-editing-actions-definitions.md) is set when the
hook returns.

