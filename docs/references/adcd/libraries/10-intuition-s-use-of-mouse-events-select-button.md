---
title: 10 / / Intuition's Use of Mouse Events / Select Button
manual: libraries
chapter: libraries
section: 10-intuition-s-use-of-mouse-events-select-button
functions: []
libraries: []
---

# 10 / / Intuition's Use of Mouse Events / Select Button

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the user presses the left, or select button, Intuition examines the
state of the system and the position of the pointer.  This information is
used to decide whether or not the user is trying to select some object,
operation, or option.  For example, the user positions the pointer over a
gadget and then presses the left button to select that gadget.
Alternatively, the user can position the pointer over a window and press
the select button to activate the window.  The pointer is said to be over
an object when the pointer's hot spot is positioned within the selection
region of the object.

A number of other common techniques involving the select button are
available.  They include:

Drag Select

```c
    Multiple objects or an extended area may be selected by dragging the
    mouse over a range with the select button held down.  For instance,
    in Release 2, multiple icons can be selected in a Workbench window by
    pressing the select button while the pointer is over the background
    of the window (not an icon or a system gadget) and then moving the
    mouse with the select button held down.  A selection rectangle will
    be displayed and all icons within the rectangle will be selected.
    Similarly, the user may highlight blocks of text in a console window
    by pressing the select button over the first desired character and
    dragging the mouse to the last desired character while holding the
    button down.
```
Multi-Select or Shift Select

```c
    Another way to select multiple objects or an extended area is through
    the shift select technique.  First, select the first member of the
    group of objects in the normal way.  Additional objects can be added
    to the group by holding down the Shift key while the select button is
    pressed.  This technique works with Workbench icons, where icons may
    be added one-at-a-time to the list of selected icons; and with text
    in a console window, where the selected text is extended to include
    the new position.  Note that text need not operate this way, and the
    application may allow multiple discrete blocks to be selected at any
    given time.
```
Cancel Drag Operation

```c
    Both drag select and the dragging of individual objects may often be
    canceled by pressing the right mouse button before completing the
    drag operation (before releasing the select button).  Examples of
    this include window dragging and sizing, and positioning of Workbench
    icons.
```
