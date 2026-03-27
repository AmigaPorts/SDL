---
title: 5 / / Custom String Editing / SGWork Structure
manual: libraries
chapter: libraries
section: 5-custom-string-editing-sgwork-structure
functions: []
libraries: []
---

# 5 / / Custom String Editing / SGWork Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    struct SGWork" link Includes/intuition/sghooks.h/MAIN 32}
        {
        struct Gadget       *Gadget;
        struct StringInfo   *StringInfo;
        UBYTE               *WorkBuffer;
        UBYTE               *PrevBuffer;
        ULONG               Modes;
        struct InputEvent   *IEvent;
        UWORD               Code;
        WORD                BufferPos;
        WORD                NumChars;
        ULONG               Actions;
        LONG                LongInt;
        struct GadgetInfo   *GadgetInfo;
        UWORD               EditOp;
        };
```
The local (application) hook may only change the Code, Actions,
WorkBuffer, NumChars, BufferPos and LongInt fields.  None of the other
fields in the SGWork structure may be modified.

Gadget and StringInfo

```c
    The values in the [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget before any modification are available
    through the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) and [StringInfo](libraries/5-string-gadget-type-stringinfo-structure.md) pointers.
```
PrevBuffer

    The PrevBuffer provides a shortcut to the old, unmodified string
    buffer.
WorkBuffer, BufferPos, NumChars and LongInt

```c
    WorkBuffer, BufferPos, NumChars and LongInt contain the values that
    the [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget will take if the edits are accepted.  If the edit
    hook updates these values, the gadget will take on the updated values.
```
IEvent

    IEvent contains the input event that caused this call to the hook.
    This input event is not keymapped.  Only use this event for action
    keys, like the Return key, function keys or the Esc key.
Code

```c
    If the input event maps to a single character, the keymapped value
    will be in the Code field.  The Code field may also be modified, and
    the value placed in it will be passed back to the application in the
    [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) message when [SGA_END](libraries/5-custom-string-editing-actions-definitions.md) is specified in the Actions field.
```
GadgetInfo

```c
    A structure of information defined in <intuition/[cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md)>.  This
    structure is read only.  See the "[BOOPSI](libraries/12-boopsi-gadgets-the-boopsi-gadget-methods.md)" chapter for more
    information.
```
Modes

    The modes of the gadget such as insert mode, defined below.
Actions

```c
    The action taken by the edit hook, [defined below](libraries/5-custom-string-editing-actions-definitions.md).
```
EditOp

```c
    The type of edit operation done by the global hook, [defined below](libraries/5-custom-string-editing-editop-definitions.md).
```
