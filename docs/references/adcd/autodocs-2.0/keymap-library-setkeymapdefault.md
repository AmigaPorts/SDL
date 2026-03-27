---
title: keymap.library/SetKeyMapDefault
manual: autodocs-2.0
chapter: autodocs-2.0
section: keymap-library-setkeymapdefault
functions: [AskKeyMapDefault]
libraries: [keymap.library]
---

# keymap.library/SetKeyMapDefault

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetKeyMapDefault -- Set the current default keymap. (V36)
```
SYNOPSIS

```c
    SetKeyMapDefault(keyMap)

    void SetKeyMapDefault( struct [KeyMap](autodocs-2.0/includes-devices-keymap-h.md) * );
```
FUNCTION

```c
    A pointer to key map specified is cached by the keymap library
    for use by [MapRawKey](autodocs-2.0/keymap-library-maprawkey.md) and [MapANSI](autodocs-2.0/keymap-library-mapansi.md) when a keymap is not specified.
```
INPUTS

    keyMap - a pointer to a keyMap structure.  This key map must be
        permanently allocated: it must remain in memory till the
        machine is reset.  It is appropriate that this keyMap be a
        node on the keymap.resource list.
BUGS

    The keymap.h include file should be in the libraries/ or perhaps
    resources/ directory, but is in the devices/ directory for
    compatability reasons.
SEE ALSO

```c
    [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md), [keymap.library/AskKeyMapDefault()](autodocs-2.0/keymap-library-askkeymapdefault.md),
    console.device ...KEYMAP functions
```

---

## See Also

- [AskKeyMapDefault — keymap.library](../autodocs/keymap.library.md#askkeymapdefault)
