---
title: 34 / Keymap Functions / Asking For the Default Keymap
manual: libraries
chapter: libraries
section: 34-keymap-functions-asking-for-the-default-keymap
functions: [AskKeyMapDefault]
libraries: [keymap.library]
---

# 34 / Keymap Functions / Asking For the Default Keymap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [AskKeyMapDefault()](autodocs-2.0/keymap-library-askkeymapdefault.md) returns a pointer to the current default keymap.
To use the mapping functions in keymap.library it is normally not
necessary to call this function. They accept NULL as equivalent to 'use
default keymap' and will call this function for you. You can use this
pointer for example to cache the system default in order to temporarily
change the keymap your applications uses, or find the keymap in the
keymap.resource list of loaded keymaps.  You should never change the
system wide default keymap unless the user asks you to do so; since the
Amiga is a multitasking system, changing the keymap could interfere with
the behaviour of other applications.

---

## See Also

- [AskKeyMapDefault — keymap.library](../autodocs/keymap.library.md#askkeymapdefault)
