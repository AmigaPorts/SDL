---
title: 34 / / Details Of Keymap Structure / LoKeyMapTypes and HiKeyMapTypes
manual: libraries
chapter: libraries
section: 34-details-of-keymap-structure-lokeymaptypes-and
functions: []
libraries: []
---

# 34 / / Details Of Keymap Structure / LoKeyMapTypes and HiKeyMapTypes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The tables named [km_LoKeyMapTypes](libraries/34-keymap-functions-details-of-the-keymap-structure.md) and [km_HiKeyMapTypes](libraries/34-keymap-functions-details-of-the-keymap-structure.md) each contain one
byte per raw key code. Each byte defines the type of entry that is found
in the keymap table for that raw key code.

Possible key types are:


```c
    * Any of the qualifier groupings [noted below](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)

    * [KCF_STRING](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md) + any combination of [KCF_SHIFT](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md), [KCF_ALT](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md), [KCF_CONTROL](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)
      (or [KC_NOQUAL](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)) if the result of pressing the key is to be a
      stream of bytes (and key-with-one-or-more-qualifiers is to be
      one or more alternate streams of bytes).

      Any key can be made to output up to eight unique byte streams if
      [KCF_STRING](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md) is set in its keytype. The only limitation is that
      the total length of all of the strings assigned to a key must be
      within the "jump range" of a single byte increment. See the
      "[String Output Keys](libraries/34-details-of-the-keymap-structure-string-output-keys.md)" section below for more information.

    * [KCF_DEAD](libraries/34-keymap-functions-dead-class-keys.md) + any combination of [KCF_SHIFT](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md), [KCF_ALT](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md), [KCF_CONTROL](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)
      (or [KC_NOQUAL](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)) if the key is a dead-class key and can thus
      modify or be modified by another dead-class key. See the
      "[Dead-Class Keys](libraries/34-keymap-functions-dead-class-keys.md)" section below for more information.
```
The low keytype table covers the raw key codes from hex 00-3F and contains
one byte per key code. Therefore this table contains 64 (decimal) bytes.
The high keytype table covers the raw key codes from hex 40-7F and
contains 64 (decimal) bytes.

