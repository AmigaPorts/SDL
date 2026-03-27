---
title: 10 / The Keyboard / Amiga Qualifiers
manual: libraries
chapter: libraries
section: 10-the-keyboard-amiga-qualifiers
functions: []
libraries: []
---

# 10 / The Keyboard / Amiga Qualifiers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga keyboard has several special qualifiers which are listed in the
next table.  Most of these qualifiers are associated with special keys on
the keyboard such as the Shift or Ctrl key.  These keys are used to modify
the meaning of other keys.  Other qualifiers are associated with mouse
button status.  For a complete list of all the qualifiers, see the include
file <devices/[inputevent.h](autodocs-2.0/includes-devices-inputevent-h.md)>.

The [Qualifier](libraries/9-using-the-idcmp-intuimessages.md) field of each [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) contains the status of all the
qualifiers.  An individual application should never attempt to track the
state of any of the qualifier keys or mouse buttons even though key-down
and key-up information may be available.  Instead use the information
available in the Qualifier field of the IntuiMessage structure.



```c
                 Table 10-3: Keyboard Qualifiers

    Qualifier
      Type          Key Label  Explanation
    ---------       ---------  -----------
    Control         Ctrl       The IEQUALIFIER_CONTROL bit indicates
                               that the Control key is depressed.

    Amiga           Fancy A    There are two Amiga keys, one on each
                               side of the space bar.  The left Amiga
                               key is recognized by the [Qualifier](libraries/9-using-the-idcmp-intuimessages.md) bit
                               IEQUALIFIER_LCOMMAND, and the right
                               Amiga key by IEQUALIFIER_RCOMMAND.

    Alternate       Alt        There are two separate Alt keys, one on
                               each side of the space bar, next to the
                               Amiga keys.  These can be treated
                               separately, if desired.  The left Alt
                               key sets the IEQUALIFIER_LALT bit and
                               the right Alt key sets the
                               IEQUALIFIER_RALT bit.

    Shift           Up Arrow   There are two separate Shift keys, one
                               above each Alt key.  These can be
                               treated distinctly, if desired.  The
                               left Shift key sets the
                               IEQUALIFIER_LSHIFT bit and the right
                               Shift key sets the IEQUALIFIER_RSHIFT
                               bit.

    Caps Lock       Caps Lock  The IEQUALIFIER_CAPSLOCK bit is set as
                               long as the Caps Lock light is
                               illuminated.

    Numeric Pad                The IEQUALIFIER_NUMERICPAD bit is set
                               for keys on the numeric keypad.

    Repeat                     Repeat key events are sent with the
                               IEQUALIFIER_REPEAT bit set.

    Mouse Buttons              If mouse buttons are down when the
                               event occurs, one or more of the three
                               bits IEQUALIFIER_LEFTBUTTON,
                               IEQUALIFIER_MIDBUTTON or
                               IEQUALIFIER_RBUTTON will be set.
```
