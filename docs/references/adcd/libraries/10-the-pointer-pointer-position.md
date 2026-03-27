---
title: 10 / The Pointer / Pointer Position
manual: libraries
chapter: libraries
section: 10-the-pointer-pointer-position
functions: [Forbid, Permit, ReportMouse]
libraries: [exec.library, intuition.library]
---

# 10 / The Pointer / Pointer Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are two ways to determine the position of the pointer: by direct
examination of variables in the window structure at any time, and by
examining messages sent by Intuition which inform the application of
pointer movement.  The pointer coordinates are relative to the upper left
corner of the window and are reported in the resolution of the screen,
even though the pointer's visible resolution is always in low-resolution
pixels (note that the pointer is actually a sprite).

The [MouseX](libraries/4-intuition-windows-the-window-structure.md) and [MouseY](libraries/4-intuition-windows-the-window-structure.md) fields of the [Window](libraries/4-intuition-windows-the-window-structure.md) structure always contain the
current pointer x and y coordinates, whether or not the window is the
active one.  If the window is a [GimmeZeroZero](libraries/4-window-types-gimmezerozero-window-type.md) window, the variables
[GZZMouseX](libraries/4-intuition-windows-the-window-structure.md) and [GZZMouseY](libraries/4-intuition-windows-the-window-structure.md) in the Window structure contain the position of
the mouse relative to the upper left corner of the inner window.

If the window is receiving mouse move messages, it will get a set of x,y
coordinates each time the pointer moves.  To receive messages about
pointer movements, the [WFLG_REPORTMOUSE](libraries/4-window-attributes-boolean-window-attribute-tags.md) flag must be set in the [Window](libraries/4-intuition-windows-the-window-structure.md)
structure.  This flag can be set when the window is opened.  The flag can
also be modified after the window is open by calling [ReportMouse()](autodocs-2.0/intuition-library-reportmouse.md),
however C programmers should avoid this function.  ReportMouse() has
problems due to historic confusion about the ordering of its C language
arguments.  Do not use ReportMouse() unless you are programming in
assembler.  C programmers should set the flag directly in the Window
structure using an atomic operation.

Most compilers generate atomic code for operations such as mywindow->flags
|= [WFLG_REPORTMOUSE](libraries/4-window-attributes-boolean-window-attribute-tags.md) or mywindow->flags &= ~WFLG_REPORTMOUSE.  If you are
unsure of getting an atomic operation from your compiler, you may wish to
do this operation in assembler, or bracket the code with a
[Forbid()/Permit()](libraries/21-exec-tasks-function-reference.md) pair.

After the [WFLG_REPORTMOUSE](libraries/4-window-attributes-boolean-window-attribute-tags.md) flag is set, whenever the window is active it
will be sent an [IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md) messages each time the pointer position
changes. The window must have the IDCMP flag IDCMP_MOUSEMOVE set to
receive these messages.

Mouse movements can cause a very large number of messages to be sent to
the IDCMP, the application should be prepared to handle them efficiently.

Messages about pointer movements may also be activated by setting the flag
[GACT_FOLLOWMOUSE](libraries/5-gadget-structure-gadget-activation-flags.md) in an application [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure. When this flag is set
in a gadget, changes in the pointer position are reported as long as the
gadget is selected by the user. These messages are also sent as
[IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md) messages.

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [ReportMouse — intuition.library](../autodocs/intuition.library.md#reportmouse)
