---
title: 5 / / Custom String Editing / Actions with SGH_KEY
manual: libraries
chapter: libraries
section: 5-custom-string-editing-actions-with-sgh-key
functions: [DisplayBeep]
libraries: [intuition.library]
---

# 5 / / Custom String Editing / Actions with SGH_KEY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If [SGA_USE](libraries/5-custom-string-editing-actions-definitions.md) is set in the [SGWork](libraries/5-custom-string-editing-sgwork-structure.md) structure [Actions](libraries/5-custom-string-editing-sgwork-structure.md) field when the hook
returns, Intuition will use the values in the SGWork fields [WorkBuffer](libraries/5-custom-string-editing-sgwork-structure.md),
[NumChars](libraries/5-custom-string-editing-sgwork-structure.md), [BufferPos](libraries/5-custom-string-editing-sgwork-structure.md), and [LongInt](libraries/5-custom-string-editing-sgwork-structure.md); copying the WorkBuffer to the [StringInfo](libraries/5-string-gadget-type-stringinfo-structure.md)
[Buffer](libraries/5-string-gadget-type-stringinfo-structure.md).  SGA_USE is set by Intuition prior to calling the hook, and must
be cleared by the hook if the changes are to be ignored.  If SGA_USE is
cleared when the hook returns, the [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget will be unchanged.

If [SGA_END](libraries/5-custom-string-editing-actions-definitions.md) is set when the hook returns, Intuition will deactivate the
[string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget.  In this case, Intuition will place the value found in
[SGWork](libraries/5-custom-string-editing-sgwork-structure.md) structure [Code](libraries/5-custom-string-editing-sgwork-structure.md) field into the [IntuiMessage.Code](libraries/9-using-the-idcmp-intuimessages.md) field of the
[IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) message it sends to the application.

If [SGA_REUSE](libraries/5-custom-string-editing-actions-definitions.md) and [SGA_END](libraries/5-custom-string-editing-actions-definitions.md) are set when the hook returns, Intuition will
reuse the input event after it deactivates the gadget.

Starting in V37, the hook may set [SGA_PREVACTIVE](libraries/5-custom-string-editing-actions-definitions.md) or [SGA_NEXTACTIVE](libraries/5-custom-string-editing-actions-definitions.md) with
[SGA_END](libraries/5-custom-string-editing-actions-definitions.md).  This tells Intuition to activate the next or previous gadget
that has the [GFLG_TABCYCLE](libraries/5-gadget-structure-gadget-flags.md) flag set.

If [SGA_BEEP](libraries/5-custom-string-editing-actions-definitions.md) is set when the hook returns, Intuition will call
[DisplayBeep()](libraries/3-other-screen-functions-miscellaneous-screen-functions.md).  Use this if the user has typed in error, or buffer is full.

Set [SGA_REDISPLAY](libraries/5-custom-string-editing-actions-definitions.md) if the changes to the gadget warrant a gadget redisplay.
Changes to the cursor position require redisplay.

---

## See Also

- [DisplayBeep — intuition.library](../autodocs/intuition.library.md#displaybeep)
