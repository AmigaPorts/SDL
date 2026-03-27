---
title: 34 / / Details Of the Keymap Structure / Capsable Bit Tables
manual: libraries
chapter: libraries
section: 34-details-of-the-keymap-structure-capsable-bit-tables
functions: []
libraries: []
---

# 34 / / Details Of the Keymap Structure / Capsable Bit Tables

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The vectors [km_LoCapsable](libraries/34-keymap-functions-details-of-the-keymap-structure.md) and [km_HiCapsable](libraries/34-keymap-functions-details-of-the-keymap-structure.md) each point to an array of 8
bytes that contain more information about the keytable entries.
Specifically, if the Caps Lock key has been pressed (the Caps Lock LED is
on) and if there is a bit on in that position in the capsable map, then
this key will be treated as though the Shift key is now currently pressed.
For example, in the default key mapping, the alphabetic keys are
"capsable" but the punctuation keys are not. This allows you to set the
Caps Lock key, just as on a normal typewriter, and get all capital
letters. However, unlike a normal typewriter, you need not go out of Caps
Lock to correctly type the punctuation symbols or numeric keys.

In the byte array, the bits that control this feature are numbered from
the lowest bit in the byte, and from the lowest memory byte address to the
highest. For example, the bit representing capsable status for the key
that transmits raw code 00 is bit 0 in byte 0; for the key that transmits
raw code 08 it is bit 0 in byte 1, and so on.

There are 64 bits (8 bytes) in each of the two capsable tables.

