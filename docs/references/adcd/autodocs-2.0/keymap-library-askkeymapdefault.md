---
title: keymap.library/AskKeyMapDefault
manual: autodocs-2.0
chapter: autodocs-2.0
section: keymap-library-askkeymapdefault
functions: [AskKeyMapDefault, SetKeyMapDefault]
libraries: [keymap.library]
---

# keymap.library/AskKeyMapDefault

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AskKeyMapDefault -- Ask for a pointer to the current default
                        keymap. (V36)
```
SYNOPSIS

```c
    keyMap = AskKeyMapDefault()

    struct [KeyMap](autodocs-2.0/includes-devices-keymap-h.md) *AskKeyMapDefault( VOID );
```
FUNCTION

```c
    Return a pointer to the keymap used by the keymap library for
    [MapRawKey](autodocs-2.0/keymap-library-maprawkey.md) and [MapANSI](autodocs-2.0/keymap-library-mapansi.md) when a keymap is not specified.
```
RESULTS

    keyMap - a pointer to a keyMap structure.  This key map is
        guaranteed to be permanently allocated: it will remain in
        memory till the machine is reset.
BUGS

    The keymap.h include file should be in the libraries/ or perhaps
    resources/ directory, but is in the devices/ directory for
    compatability reasons.
SEE ALSO

```c
    [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md), [keymap.library/SetKeyMapDefault()](autodocs-2.0/keymap-library-setkeymapdefault.md),
    console.device ...KEYMAP functions
```

---

## See Also

- [AskKeyMapDefault — keymap.library](../autodocs/keymap.library.md#askkeymapdefault)
- [SetKeyMapDefault — keymap.library](../autodocs/keymap.library.md#setkeymapdefault)
