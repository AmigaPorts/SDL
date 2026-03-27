# 34 / Keymap Functions / Mapping Key Codes To ANSI Strings


[MapRawKey()](../Includes_and_Autodocs_2._guide/node0315.html) is converts raw key codes to ANSI characters based on a
default or supplied keymap.


```c
    WORD MapRawKey(struct InputEvent *inputevent, UBYTE *buffer,
                   WORD bufferlength, struct Keymap *keymap);
```
[MapRawKey()](../Includes_and_Autodocs_2._guide/node0315.html) takes an [IECLASS_RAWKEY](../Libraries_Manual_guide/node0407.html#line16) inputevent, which may be chained, and
converts the key codes to ANSI characters which are placed in the
specified buffer. If the buffer would overflow, for example because a
longer string is attached to a key, -1 will be returned. If no error
occurred, MapRawKey() will return the number of bytes written in the
buffer.  The keymap argument can be set to NULL if the default keymap is
to be used for translation, or can be a pointer to a specific [KeyMap](../Libraries_Manual_guide/node046F.html)
structure.

The following example shows how to implement the [MapRawKey()](../Includes_and_Autodocs_2._guide/node0315.html) function.


```c
     [maprawkey.c](../Libraries_Manual_guide/node05AD.html) 
```
