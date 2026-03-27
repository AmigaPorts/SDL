---
title: keymap.library (basename: _KeymapBase)
manual: amiga-mail
chapter: amiga-mail
section: keymap-library-basename-keymapbase
functions: [AskKeyMapDefault]
libraries: [keymap.library]
---

# keymap.library (basename: _KeymapBase)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

AskKeyMapDefault()()                    - Ask for a pointer to the current
                                          default
MapANSI(string,count,buffer,length,keyMap)(a0,d0/a1,d1/a2)
```c
                                        - Encode an ANSI string into
                                          keycodes. (V36)
```
MapRawKey(event,buffer,length,keyMap)(a0/a1,d1/a2)
                                        - Decode single raw key input
                                          event to an ANSI
SetKeyMapDefault(keyMap)(a0)            - Set the current default keymap.

```c
                                          (V36)
```

---

## See Also

- [AskKeyMapDefault — keymap.library](../autodocs/keymap.library.md#askkeymapdefault)
