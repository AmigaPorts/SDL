---
title: 5 / / Stringinfo Structure / Gadget Key Mapping
manual: libraries
chapter: libraries
section: 5-stringinfo-structure-gadget-key-mapping
functions: []
libraries: []
---

# 5 / / Stringinfo Structure / Gadget Key Mapping

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

By default, screen characters appear using simple ASCII key translations.
If desired, the application can set up alternate key mapping.  A pointer
to the [KeyMap](libraries/34-keymap-library-keymap-functions.md) structure is placed into the AltKeyMap field of the
[StringInfo](libraries/5-string-gadget-type-stringinfo-structure.md) structure.  The [GACT_ALTKEYMAP](libraries/5-gadget-structure-gadget-activation-flags.md) bit in the [Activation](libraries/5-intuition-gadgets-gadget-structure.md) flags of
the gadget must also be set.

See the "[Console Device](devices/4-console-device.md)" chapter in the Amiga ROM Kernel Reference Manual:
Devices, and the "[Keymap Library](libraries/34-keymap-library.md)" chapter in this manual for more
information about the console device and key mapping.

