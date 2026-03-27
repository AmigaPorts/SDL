---
title: Keymap Index
manual: libraries
chapter: libraries
section: keymap-index
functions: [AskKeyMapDefault, MapANSI, MapRawKey, SetKeyMapDefault]
libraries: [keymap.library]
---

# Keymap Index

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Keymap, [811](libraries/34-keymap-library.md)
  alternate key maps, [821](libraries/34-details-of-the-keymap-structure-string-output-keys.md)
  AskKeyMap(), [813](libraries/34-keymap-functions-accessing-the-keymap-for-the-current.md)
  AskKeyMapDefault(), [812](libraries/34-keymap-functions-asking-for-the-default-keymap.md)
  capsable keys, [822](libraries/34-details-of-the-keymap-structure-capsable-bit-tables.md)
  caveats - key numbers over hex 67, [818](libraries/34-details-of-the-keymap-structure-lokeymap-and-highkeymap.md)
  dead-class keys, [823](libraries/34-keymap-functions-dead-class-keys.md)
  double-dead keys, [826](libraries/34-keymap-functions-double-dead-keys.md)
  Examples
```c
    AskKeyMap(), [813](libraries/34-keymap-functions-accessing-the-keymap-for-the-current.md)
    German keymap excerpt, [824](libraries/34-keymap-functions-dead-class-keys.md)
    mapping RAWKEY events to character sequences, [814](libraries/lib-examples-maprawkey-c.md)
    mapping text to keypresses, [816](libraries/lib-examples-mapansi-c.md)
    SetKeyMap(), [813](libraries/34-keymap-functions-accessing-the-keymap-for-the-current.md)
```
  high key map, [818](libraries/34-details-of-the-keymap-structure-lokeymap-and-highkeymap.md)
  KCF_ALT, [820-821](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)
  KCF_CONTROL, [820-821](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)
  KCF_DOWNUP, [820](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)
  KCF_SHIFT, [820-821](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)
  KCF_STRING, [820](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)
  KC_NOQUAL, [820-821](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)
  KC_VANILLA, [820-821](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)
  key map standards, [823](libraries/34-keymap-functions-key-map-standards.md)
  keymapping, [829](libraries/34-keymap-library-keyboard-layout.md)
  keymapping qualifiers, [819](libraries/34-details-of-the-keymap-structure-lokeymap-and-highkeymap.md), [820](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)
  keytype table, [820](libraries/34-details-of-keymap-structure-lokeymaptypes-and.md)
  low key map, [818](libraries/34-details-of-the-keymap-structure-lokeymap-and-highkeymap.md)
  MapANSI(), [816](libraries/34-keymap-functions-mapping-ansi-strings-to-key-codes.md)
  MapRawKey(), [814](libraries/34-keymap-functions-mapping-key-codes-to-ansi-strings.md)
  mouse button events, [831](libraries/34-keymap-library-keyboard-layout.md)
  qualifiers, [820](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md)
  repeatable keys, [822](libraries/34-details-of-the-keymap-structure-repeatable-bit-tables.md)
  SetKeyMap(), [813](libraries/34-keymap-functions-accessing-the-keymap-for-the-current.md)
  SetKeyMapDefault(), [813](libraries/34-keymap-functions-setting-the-default-keymap.md)
  string output keys, [821](libraries/34-details-of-the-keymap-structure-string-output-keys.md)
  struct KeyMap, [812](libraries/34-keymap-library-keymap-functions.md)

---

## See Also

- [AskKeyMapDefault — keymap.library](../autodocs/keymap.library.md#askkeymapdefault)
- [MapANSI — keymap.library](../autodocs/keymap.library.md#mapansi)
- [MapRawKey — keymap.library](../autodocs/keymap.library.md#maprawkey)
- [SetKeyMapDefault — keymap.library](../autodocs/keymap.library.md#setkeymapdefault)
