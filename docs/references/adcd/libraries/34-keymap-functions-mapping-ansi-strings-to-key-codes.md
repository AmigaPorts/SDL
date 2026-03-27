---
title: 34 / Keymap Functions / Mapping ANSI Strings To Key Codes
manual: libraries
chapter: libraries
section: 34-keymap-functions-mapping-ansi-strings-to-key-codes
functions: [MapANSI]
libraries: [keymap.library]
---

# 34 / Keymap Functions / Mapping ANSI Strings To Key Codes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [MapANSI()](autodocs-2.0/keymap-library-mapansi.md) function translates ANSI strings into raw key codes,
complete with qualifiers and (double) dead keys, based on a default or
supplied keymap.


```c
    LONG MapANSI(UBYTE *string, LONG stringlength, UBYTE *buffer,
                 LONG bufferlength, struct KeyMap *keymap);
```
The string argument is a pointer to an ANSI string, of length
stringlength. The buffer argument is a pointer to the memory block where
the translated key codes will be placed.  The length of this buffer must
be indicated in WORDs since each translation will occupy one byte for the
key code and one for the qualifier. Since one ANSI character can be
translated to two dead keys and one key, the buffer must be at least 3
WORDs per character in the string to be translated. The keymap argument
can be set to NULL if the default keymap is to be used, or can be a
pointer to a [KeyMap](libraries/34-keymap-functions-details-of-the-keymap-structure.md) structure.  Upon return, the function will indicate
how many key code/qualifier combinations are placed in the buffer or a
negative number in case an error occurred. If zero is returned, the
character could not be translated.

The following example shows the usage of [MapANSI()](autodocs-2.0/keymap-library-mapansi.md) and demonstrates how
returned key codes can be processed.


```c
     [mapansi.c](libraries/lib-examples-mapansi-c.md) 
```

---

## See Also

- [MapANSI — keymap.library](../autodocs/keymap.library.md#mapansi)
