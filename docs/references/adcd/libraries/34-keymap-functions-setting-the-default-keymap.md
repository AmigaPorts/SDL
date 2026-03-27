---
title: 34 / Keymap Functions / Setting the Default Keymap
manual: libraries
chapter: libraries
section: 34-keymap-functions-setting-the-default-keymap
functions: [SetKeyMapDefault]
libraries: [keymap.library]
---

# 34 / Keymap Functions / Setting the Default Keymap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The system default keymap can be set with the [SetKeyMapDefault()](autodocs-2.0/keymap-library-setkeymapdefault.md) function.
This function takes a pointer to a loaded keymap. In general, this
function should never be used by an application unless the application is
a system Preferences editor, or an application that takes over the system.
Normal applications should instead attach a console.device unit to their
own Intuition window (see the [Devices](devices/4-console-device.md) volume), and use the console.device
command [CD_SETKEYMAP](libraries/34-keymap-library-keymap-functions.md) to set a keymap only for their own console.

When making a keymap the system default, first check whether the keymap
has been loaded previously by checking the keymap list of the
keymap.resource.  If it has not been loaded already, it can be loaded from
devs:Keymaps, and added to the keymap list of keymap.resource. This will
ensure that other applications which may want the keymap will not have to
load a second instance. Once made the default, the keymap can never be
safely removed from memory, even after if it is no longer the default,
since other applications may still have and use a pointer to it.

---

## See Also

- [SetKeyMapDefault — keymap.library](../autodocs/keymap.library.md#setkeymapdefault)
