---
title: 34 Keymap Library / Keymap Functions
manual: libraries
chapter: libraries
section: 34-keymap-library-keymap-functions
functions: [AskKeyMapDefault, MapANSI, MapRawKey, SetKeyMapDefault]
libraries: [keymap.library]
---

# 34 Keymap Library / Keymap Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                   Table 34-1: Keymap Library Functions
  ________________________________________________________________________
 |                       |                                                |
 | [AskKeyMapDefault()](libraries/34-keymap-functions-asking-for-the-default-keymap.md)    | Ask for a pointer to current default keymap    |
 |-----------------------|------------------------------------------------|
 | [MapANSI()](libraries/34-keymap-functions-mapping-ansi-strings-to-key-codes.md)             | Encode an ANSI string into key codes           |
 |-----------------------|------------------------------------------------|
 | [MapRawKey()](libraries/34-keymap-functions-mapping-key-codes-to-ansi-strings.md)           | Decode a raw key input event to an ANSI string |
 |-----------------------|------------------------------------------------|
 | [SetKeyMapDefault()](libraries/34-keymap-functions-setting-the-default-keymap.md)    | Set the current default keymap for the system  |
 |_______________________|________________________________________________|


                Table 34-2: Console Device Keymap Commands
  ________________________________________________________________________
 |                       |                                                |
 | [CD_ASKKEYMAP](autodocs-2.0/includes-devices-console-h.md)          | Ask for the current console's keymap           |
 |-----------------------|------------------------------------------------|
 | [CD_SETKEYMAP](autodocs-2.0/includes-devices-console-h.md)          | Set the current console's keymap               |
 |-----------------------|------------------------------------------------|
 | [CD_ASKDEFAULTKEYMAP](autodocs-2.0/includes-devices-console-h.md)*  | Set the current default keymap                 |
 |-----------------------|------------------------------------------------|
 | [CD_SETDEFAULTKEYMAP](autodocs-2.0/includes-devices-console-h.md)** | Ask for a pointer to current default keymap    |
 |-----------------------|------------------------------------------------|
 | *  Obsolete - use [AskKeyMapDefault()](libraries/34-keymap-functions-asking-for-the-default-keymap.md)                                   |
 | ** Obsolete - use [SetKeyMapDefault()](libraries/34-keymap-functions-setting-the-default-keymap.md)                                   |
 |________________________________________________________________________|


All of these commands deal with a set of pointers to key translation
arrays, known as a [KeyMap](libraries/34-keymap-functions-details-of-the-keymap-structure.md) structure.  The KeyMap structure is defined in
<devices/[keymap.h](autodocs-2.0/includes-devices-keymap-h.md)> and is shown below.


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
The [KeyMap](libraries/34-keymap-functions-details-of-the-keymap-structure.md) structure contains pointers to arrays which define the ANSI
character or string that should be produced when a key or a combination of
keys are pressed.  For example, a keymap might specify that the key with
raw value hex 20 should produce the ANSI character "a", and if the Shift
key is being held it should produce the character "A".

 [Asking For the Default Keymap](libraries/34-keymap-functions-asking-for-the-default-keymap.md) 
 [Setting the Default Keymap](libraries/34-keymap-functions-setting-the-default-keymap.md) 
 [Accessing the Keymap For the Current Console](libraries/34-keymap-functions-accessing-the-keymap-for-the-current.md) 
 [Mapping Key Codes To ANSI Strings](libraries/34-keymap-functions-mapping-key-codes-to-ansi-strings.md) 
 [Mapping ANSI Strings To Key Codes](libraries/34-keymap-functions-mapping-ansi-strings-to-key-codes.md) 
 [Details Of the Keymap Structure](libraries/34-keymap-functions-details-of-the-keymap-structure.md) 
 [Key Map Standards](libraries/34-keymap-functions-key-map-standards.md) 
 [Dead-Class Keys](libraries/34-keymap-functions-dead-class-keys.md) 
 [Double-Dead Keys](libraries/34-keymap-functions-double-dead-keys.md) 

---

## See Also

- [AskKeyMapDefault — keymap.library](../autodocs/keymap.library.md#askkeymapdefault)
- [MapANSI — keymap.library](../autodocs/keymap.library.md#mapansi)
- [MapRawKey — keymap.library](../autodocs/keymap.library.md#maprawkey)
- [SetKeyMapDefault — keymap.library](../autodocs/keymap.library.md#setkeymapdefault)
