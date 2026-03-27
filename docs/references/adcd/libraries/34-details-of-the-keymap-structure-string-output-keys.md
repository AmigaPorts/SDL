---
title: 34 / / Details Of the Keymap Structure / String Output Keys
manual: libraries
chapter: libraries
section: 34-details-of-the-keymap-structure-string-output-keys
functions: []
libraries: []
---

# 34 / / Details Of the Keymap Structure / String Output Keys

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When a key is to output a string, the keymap table contains the address of
a string descriptor in place of a 4-byte mapping of a key. Here is a
partial table for a new high keymap table that contains only three entries
thus far. The first two are for the space bar and the backspace key; the
third is for the tab key, which is to output a string that says "[TAB]".
An alternate string, "[SHIFTED-TAB]", is also to be output when a shifted
TAB key is pressed.


```c
    newHiMapTypes:
      DC.B  KCF_ALT,KC_NOQUAL,    ;key 41
      DC.B  KCF_STRING+KCF_SHIFT, ;key 42
          ...  ;(more)
    newHiMap:
      DC.B  0,0,$A0,$20  ;key 40: space bar, and Alt-space bar
      DC.B  0,0,0,$08    ;key 41: Back Space key only
      DC.L  newkey42     ;key 42: new string definition to output for Tab
          ...  ;(more)
    newkey42:
      DC.B  new42ue - new42us   ;length of the unshifted string
      DC.B  new42us - newkey42  ;number of bytes from start of
                                ;string descriptor to start of this string
      DC.B  new42se - new42ss   ;length of the shifted string
      DC.B  new42ss - newkey42  ;number of bytes from start of
                                ;string descriptor to start of this string
    new42us:  DC.B        '[TAB]'
    new42ue:
    new42ss:  DC.B        '[SHIFTED-TAB]'
    new42se:
```
The new high map table points to the string descriptor at address
newkey42. The new high map types table says that there is one qualifier,
which means that there are two strings in the key string descriptor.

Each string in the descriptor takes two bytes in this part of the table:
the first byte is the length of the string, and the second byte is the
distance from the start of the descriptor to the start of the string.
Therefore, a single string ([KCF_STRING](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md) + [KC_NOQUAL](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)) takes 2 bytes of
string descriptor. If there is one qualifier, 4 bytes of descriptor are
used. If there are two qualifiers, 8 bytes of descriptor are used. If
there are 3 qualifiers, 16 bytes of descriptor are used. All strings start
immediately following the string descriptor in that they are accessed as
single-byte offsets from the start of the descriptor itself. Therefore,
the distance from the start of the descriptor to the last string in the
set (the one that uses the entire set of specified qualifiers) must start
within 255 bytes of the descriptor address.

Because the length of the string is contained in a single byte, the length
of any single string must be 255 bytes or less while also meeting the
"reach" requirement. However, the console input buffer size limits the
string output from any individual key to 32 bytes maximum.

The length of a keymap containing string descriptors and strings is
variable and depends on the number and size of the strings that you
provide.

