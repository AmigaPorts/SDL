---
title: 4 Console Device / Input Event Reports
manual: devices
chapter: devices
section: 4-console-device-input-event-reports
functions: []
libraries: []
---

# 4 Console Device / Input Event Reports

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If you select any of these events you will start to get information about
the events in the following form:

<CSI><class>;<subclass>;<keycode>;<qualifiers>;<x>;<y>;<secs>;<microsecs>|

<CSI>
   is a one-byte field.  It is the "control sequence introducer," 0x9B
   in hex.

<class>
   is the RAW input event type, from the above table.

<subclass>
   is usually 0. If the mouse is moved to the right controller, this
   would be 1.

<keycode>
   indicates which raw key number was pressed. This field can also be
   used for mouse information.

   The Raw Key Might Be The Wrong Key.
   -----------------------------------
   National keyboards often have different keyboard arrangements. This
   means that a particular raw key number may represent different
   characters on different national keyboards. The normal console read
   stream (as opposed to raw events) will contain the proper ASCII
   character for the keypress as translated according to the user's
   keymap.

<qualifiers>
   indicates the state of the keyboard and system.

The qualifiers are defined as follows:


                         INPUT EVENT QUALIFIERS
   Bit  Mask   Key
   ---  ----   ---

```c
    0   0001   Left shift
    1   0002   Right shift
    2   0004   Caps Lock Associated keycode is special; see below.
    3   0008   Ctrl
    4   0010   Left Alt
    5   0020   Right Alt
    6   0040   Left Amiga key pressed
    7   0080   Right Amiga key pressed
    8   0100   Numeric pad
    9   0200   Repeat
    10  0400   Interrupt Not currently used.
    11  0800   Multibroadcast This window (active one) or all windows.
    12  1000   Middle mouse button (Not available on standard mouse)
    13  2000   Right mouse button
    14  4000   Left mouse button
    15  8000   Relative mouse Mouse coordinates are relative, not absolute.
```
The Caps Lock key is handled in a special manner. It generates a keycode
only when it is pressed, not when it is released. However, the up/down bit
(80 hex) is still used and reported. If pressing the Caps Lock key causes
the LED to light, keycode 62 (Caps Lock pressed) is sent. If pressing the
Caps Lock key extinguishes the LED, keycode 190 (Caps Lock released) is
sent. In effect, the keyboard reports this key as held down until it is
struck again.

The <x> and <y> fields are filled by some classes with an Intuition
address:  x<<16+y.

The <seconds> and <microseconds> fields contain the system time stamp
taken at the time the event occurred.  These values are stored as
longwords by the system.

With RAW keyboard input selected, keys will no longer return a simple
one-character "A" to "Z" but will instead return raw keycode reports
of the form:

  <CSI>1;0;<keycode>;<qualifiers>;<prev1>;<prev2>;<seconds>;<microseconds>|

For example, if the user pressed and released the A key with the left
Shift and right Amiga keys also pressed, you might receive the following
data:

  <CSI>1;0;32;32769;14593;5889;421939940;316673|

  <CSI>1;0;160;32769;0;0;421939991;816683|

The <keycode> field is an ASCII decimal value representing the key pressed
or released.  Adding 128 to the pressed key code will result in the
released keycode.

The <prev1> and <prev2> fields are relevant for the interpretation of keys
which are modifiable by dead-keys (see "[Dead-Class Keys](libraries/34-keymap-functions-dead-class-keys.md)" section). The
<prev1> field shows the previous key pressed.  The lower byte shows the
qualifier, the upper byte shows the key code. The <prev2> field shows the
key pressed before the previous key.  The lower byte shows the qualifier,
the upper byte shows the key code.

