---
title: FD/keymap_lib.fd
manual: autodocs-2.0
chapter: autodocs-2.0
section: fd-keymap-lib-fd
functions: [AskKeyMapDefault]
libraries: [keymap.library]
---

# FD/keymap_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* "keymap.library"
##base _KeymapBase
##bias 30
##public
*--- functions in V36 or higher (distributed as Release 2.0) ---
SetKeyMapDefault(keyMap)(a0)
AskKeyMapDefault()()
MapRawKey(event,buffer,length,keyMap)(a0/a1,d1/a2)
MapANSI(string,count,buffer,length,keyMap)(a0,d0/a1,d1/a2)
##end

---

## See Also

- [AskKeyMapDefault — keymap.library](../autodocs/keymap.library.md#askkeymapdefault)
