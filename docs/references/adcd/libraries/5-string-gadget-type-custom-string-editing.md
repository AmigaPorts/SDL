---
title: 5 / String Gadget Type / Custom String Editing
manual: libraries
chapter: libraries
section: 5-string-gadget-type-custom-string-editing
functions: [Wait]
libraries: [exec.library]
---

# 5 / String Gadget Type / Custom String Editing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The application may choose to control the editing features provided in
[string](libraries/5-intuition-gadgets-string-gadget-type.md) gadgets used within the application.  To locally install the custom
string editing features, the application provides a hook in the
[StringExtend](libraries/5-string-gadget-type-extended-string-gadgets.md) structure [EditHook](libraries/5-string-gadget-type-extended-string-gadgets.md) field.

A hook is a well defined calling interface for a user provided subroutine
or function.  Hooks are more fully described in the "[Utility Library](libraries/37-utility-library-callback-hooks.md)"
chapter.  A [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget hook is called in the standard way, where the
hook object is a pointer to a [SGWork](libraries/5-custom-string-editing-sgwork-structure.md) structure, and the hook message is a
pointer to a command block.  However, unlike a function callback hook, a
string gadget editing hook is called on Intuition's task context, not on
the application's own context.  Therefore, a string gadget editing hook
must not use dos.library, and may not [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md) on application signals or
message ports, and may not call any Intuition function which might wait
for Intuition.

The command block starts with either (longword) [SGH_KEY](libraries/5-custom-string-editing-the-sgh-key-command.md) or [SGH_CLICK](libraries/5-custom-string-editing-the-sgh-click-command.md).
There may be new commands added in the future, so the application should
not assume that these are the only possible commands. The hook should
return zero if it doesn't understand the command and non-zero if the
command is supported.

The [SGWork](libraries/5-custom-string-editing-sgwork-structure.md) structure, defined in <intuition/[sghooks.h](autodocs-2.0/includes-intuition-sghooks-h.md)>, is listed on the
next page.  Use this structure as the hook object for custom string
editing hooks.

 [SGWork Structure](libraries/5-custom-string-editing-sgwork-structure.md)       [Actions with SGH_KEY](libraries/5-custom-string-editing-actions-with-sgh-key.md) 
 [EditOp Definitions](libraries/5-custom-string-editing-editop-definitions.md)     [The SGH_CLICK Command](libraries/5-custom-string-editing-the-sgh-click-command.md) 
 [Actions Definitions](libraries/5-custom-string-editing-actions-definitions.md)    [Actions with SGH_CLICK](libraries/5-custom-string-editing-actions-with-sgh-click.md) 
 [The SGH_KEY Command](libraries/5-custom-string-editing-the-sgh-key-command.md)    [Example String Gadget Editing Hook](libraries/lib-examples-strhooks-c.md) 

---

## See Also

- [Wait — exec.library](../autodocs/exec.library.md#wait)
