# keymap.library (basename: _KeymapBase)


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
