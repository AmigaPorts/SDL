---
title: 34 / Keymap Functions / Details Of the Keymap Structure
manual: libraries
chapter: libraries
section: 34-keymap-functions-details-of-the-keymap-structure
functions: []
libraries: []
---

# 34 / Keymap Functions / Details Of the Keymap Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A [KeyMap](autodocs-2.0/includes-devices-keymap-h.md) structure contains pointers to arrays which determine the
translation from raw key codes to ANSI characters.


```c
    struct KeyMap
        {
        UBYTE *km_LoKeyMapTypes;
        ULONG *km_LoKeyMap;
        UBYTE *km_LoCapsable;
        UBYTE *km_LoRepeatable;
        UBYTE *km_HiKeyMapTypes;
        ULONG *km_HiKeyMap;
        UBYTE *km_HiCapsable;
        UBYTE *km_HiRepeatable;
        };
```
 [LoKeyMap and HighKeyMap](libraries/34-details-of-the-keymap-structure-lokeymap-and-highkeymap.md)            [String Output Keys](libraries/34-details-of-the-keymap-structure-string-output-keys.md) 
 [LoKeyMapTypes and HiKeyMapTypes](libraries/34-details-of-keymap-structure-lokeymaptypes-and.md)    [Capsable Bit Tables](libraries/34-details-of-the-keymap-structure-capsable-bit-tables.md) 
 [More About Qualifiers](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)              [Repeatable Bit Tables](libraries/34-details-of-the-keymap-structure-repeatable-bit-tables.md) 

