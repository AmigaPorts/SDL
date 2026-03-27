# 34 / Keymap Functions / Details Of the Keymap Structure


A [KeyMap](../Includes_and_Autodocs_2._guide/node003A.html#line22) structure contains pointers to arrays which determine the
translation from raw key codes to ANSI characters.


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
 [LoKeyMap and HighKeyMap](../Libraries_Manual_guide/node0470.html)            [String Output Keys](../Libraries_Manual_guide/node0473.html) 
 [LoKeyMapTypes and HiKeyMapTypes](../Libraries_Manual_guide/node0471.html)    [Capsable Bit Tables](../Libraries_Manual_guide/node0474.html) 
 [More About Qualifiers](../Libraries_Manual_guide/node0472.html)              [Repeatable Bit Tables](../Libraries_Manual_guide/node0475.html) 

