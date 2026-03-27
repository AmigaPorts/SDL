---
title: 5 / / Custom String Editing / The SGH_KEY Command
manual: libraries
chapter: libraries
section: 5-custom-string-editing-the-sgh-key-command
functions: []
libraries: []
---

# 5 / / Custom String Editing / The SGH_KEY Command

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The SGH_KEY command indicates that the user has pressed a key while the
gadget is active.  This may be any key, including non-character keys such
as Shift, Ctrl and Alt.  Repeat keys (one call per repeat) and the Amiga
keys also cause the hook to be called with the SGH_KEY command.  The hook
is not called for "key up" events.

The SGH_KEY command must be supported by any custom string editing hook.
There are no parameters following the SGH_KEY command longword.  All
information on the event must be derived from the [SGWork](libraries/5-custom-string-editing-sgwork-structure.md) structure.

Intuition has already processed the event and filled-in the [SGWork](libraries/5-custom-string-editing-sgwork-structure.md)
structure before calling the hook.  The information included in this
structure includes the type of action taken ([EditOp](libraries/5-custom-string-editing-sgwork-structure.md)), the new cursor
position ([BufferPos](libraries/5-custom-string-editing-sgwork-structure.md)), the new value in the buffer ([WorkBuffer](libraries/5-custom-string-editing-sgwork-structure.md)),  the
previous value in the buffer ([PrevBuffer](libraries/5-custom-string-editing-sgwork-structure.md)), the input event that caused
this call ([IEvent](libraries/5-custom-string-editing-sgwork-structure.md)) and more.

