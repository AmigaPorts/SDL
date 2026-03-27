---
title: 34 / / Details Of the Keymap Structure / LoKeyMap and HighKeyMap
manual: libraries
chapter: libraries
section: 34-details-of-the-keymap-structure-lokeymap-and-highkeymap
functions: []
libraries: []
---

# 34 / / Details Of the Keymap Structure / LoKeyMap and HighKeyMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The low key map provides translation of the key values from hex 00-3F; the
high key map provides translation of key values from hex 40-7F. Key values
from hex 68-7F are not used by the existing keyboards, but this may change
in the future. A raw key value (hex 00-7F) plus hex 80 is the release of
that key. If you need to check for raw key releases do it like this:


```c
    if (keyvalue & 0x80)     {  /* do key up processing   */  }
    else                     {  /* do key down processing */  }
```
Raw output from the keyboard for the low key map does not include the
space bar, Tab, Alt, Ctrl, arrow keys, and several other keys.




                   Table 34-3: High Key Map Hex Values


     Key    Keycap Legend                Key    Keycap Legend
    Number  or Function                 Number  or Function
    ------  -------------               ------  -------------
      40    Space                       50-59   Function keys F1-F10
      41    Backspace                   5A-5E   Numeric Pad characters
      42    Tab                         5F      Help
      43    Enter                       60      Left Shift
      44    Return                      61      Right Shift
      45    Escape                      62      Caps Lock
      46    Delete                      63      Control
      4A    Numeric Pad character       64      Left Alt
      4C    Cursor Up                   65      Right Alt
      4D    Cursor Down                 66      Left Amiga
      4E    Cursor Right                67      Right Amiga
      4F    Cursor Left
The keymap table for the low and high keymaps consists of 4-byte entries,
one per hex key code. These entries are interpreted in one of three
possible ways:


```c
    * As four separate bytes, specifying how the key is to be
      interpreted when pressed alone, with one qualifier, with another
      qualifier, or with both qualifiers (where a qualifier is one of
      three possible keys:  Ctrl, Alt, or Shift).

    * As a longword containing the address of a string descriptor,
      where a string of characters is to be output when this key is
      pressed. If a string is to be output, any combination of
      qualifiers can affect the string that may be transmitted.

    * As a longword containing the address of a dead-key descriptor,
      where additional data describe the character to be output when
      this key is pressed alone or with another dead key.

    The keymap tables must be word aligned.
    ---------------------------------------
    The keymap tables must begin aligned on a word boundary.  Each
    entry is four bytes long, thereby maintaining word alignment
    throughout the table.  This is necessary because some of the entries
    may be longword addresses and must be aligned properly for the
    68000.
```
