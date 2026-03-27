---
title: The 'A' and 'B' Buttons
manual: amiga-mail
chapter: amiga-mail
section: the-a-and-b-buttons
functions: []
libraries: []
---

# The 'A' and 'B' Buttons

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The A and B buttons on the remote correspond to the left and right
buttons on the mouse.  If the user prefers to use a keyboard for input,
he can use any of the following:


```c
    The left Alt/left Amiga combination for the 'A' button and right
    Alt/right Amiga for the 'B' button.

    The left Amiga key (raw keycode 66 hex) alone for 'A', and right Amiga
    key (raw keycode 67 hex) alone for 'B'.

    The F9 function key (rawkey code 58 hex) for 'A' and F10 function key
    (rawkey code 59 hex) for 'B'.

    the A (for left) and B (for right) keys on the keyboard.
```
By offering a keyboard equivalent to the 'A' and 'B' button, users with
keyboards will not have to move their hands from the keyboard to the
mouse in order to confirm a selection.  It also avoids accidental
movements of the mouse when pressing the rodent's left or right button.

The F9 and F10 function keys were selected because of their convenient
location near the directional arrow keys on the keyboard.

Supporting the 'A' and 'B' keys on the keyboard is more complicated.
The 'A' or 'B' key on the keyboard cannot be equivalents for the
remote's A and B buttons during the input of a text string.  In other
situations, however, this mapping can be helpful to the neophyte user.

If a title uses the console device, it should support both uppercase
and lowercase ('A' and 'a').  Furthermore, the raw keycodes for the 'A'
and 'B' keys must always be translated via the active keymap to
determine the actual ASCII value.  The rawkeyconvert.c routines in the
ROM Kernel manual give an example of this translation process.

If your title reads raw keycodes directly, beware of using raw keycodes
for the 'A' and 'B' keys on the keyboard, as the raw keycodes may
change if the user has a French keyboard.  The French keyboard has
reversed the position of the 'A' and the 'Q' keys.  If you choose to
have raw keycode support, you should accept both the 'A' (raw keycode
20 hex) and 'Q' (raw keycode 10 hex) for the 'A' button, and 'B' (raw
keycode 35 hex) for the 'B' button.

