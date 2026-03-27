---
title: 34 / Keymap Functions / Mapping Key Codes To ANSI Strings
manual: libraries
chapter: libraries
section: 34-keymap-functions-mapping-key-codes-to-ansi-strings
functions: [MapRawKey]
libraries: [keymap.library]
---

# 34 / Keymap Functions / Mapping Key Codes To ANSI Strings

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[MapRawKey()](autodocs-2.0/keymap-library-maprawkey.md) is converts raw key codes to ANSI characters based on a
default or supplied keymap.


```c
    WORD MapRawKey(struct InputEvent *inputevent, UBYTE *buffer,
                   WORD bufferlength, struct Keymap *keymap);
```
[MapRawKey()](autodocs-2.0/keymap-library-maprawkey.md) takes an [IECLASS_RAWKEY](libraries/31-commodities-exchange-filter-objects-and-input.md) inputevent, which may be chained, and
converts the key codes to ANSI characters which are placed in the
specified buffer. If the buffer would overflow, for example because a
longer string is attached to a key, -1 will be returned. If no error
occurred, MapRawKey() will return the number of bytes written in the
buffer.  The keymap argument can be set to NULL if the default keymap is
to be used for translation, or can be a pointer to a specific [KeyMap](libraries/34-keymap-functions-details-of-the-keymap-structure.md)
structure.

The following example shows how to implement the [MapRawKey()](autodocs-2.0/keymap-library-maprawkey.md) function.


```c
     [maprawkey.c](libraries/lib-examples-maprawkey-c.md) 
```

---

## See Also

- [MapRawKey — keymap.library](../autodocs/keymap.library.md#maprawkey)
