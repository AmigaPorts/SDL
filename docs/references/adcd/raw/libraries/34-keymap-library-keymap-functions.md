# 34 Keymap Library / Keymap Functions



                   Table 34-1: Keymap Library Functions
  ________________________________________________________________________
 |                       |                                                |
 | [AskKeyMapDefault()](../Libraries_Manual_guide/node046A.html)    | Ask for a pointer to current default keymap    |
 |-----------------------|------------------------------------------------|
 | [MapANSI()](../Libraries_Manual_guide/node046E.html)             | Encode an ANSI string into key codes           |
 |-----------------------|------------------------------------------------|
 | [MapRawKey()](../Libraries_Manual_guide/node046D.html)           | Decode a raw key input event to an ANSI string |
 |-----------------------|------------------------------------------------|
 | [SetKeyMapDefault()](../Libraries_Manual_guide/node046B.html)    | Set the current default keymap for the system  |
 |_______________________|________________________________________________|


                Table 34-2: Console Device Keymap Commands
  ________________________________________________________________________
 |                       |                                                |
 | [CD_ASKKEYMAP](../Includes_and_Autodocs_2._guide/node0050.html#line22)          | Ask for the current console's keymap           |
 |-----------------------|------------------------------------------------|
 | [CD_SETKEYMAP](../Includes_and_Autodocs_2._guide/node0050.html#line22)          | Set the current console's keymap               |
 |-----------------------|------------------------------------------------|
 | [CD_ASKDEFAULTKEYMAP](../Includes_and_Autodocs_2._guide/node0050.html#line22)*  | Set the current default keymap                 |
 |-----------------------|------------------------------------------------|
 | [CD_SETDEFAULTKEYMAP](../Includes_and_Autodocs_2._guide/node0050.html#line22)** | Ask for a pointer to current default keymap    |
 |-----------------------|------------------------------------------------|
 | *  Obsolete - use [AskKeyMapDefault()](../Libraries_Manual_guide/node046A.html)                                   |
 | ** Obsolete - use [SetKeyMapDefault()](../Libraries_Manual_guide/node046B.html)                                   |
 |________________________________________________________________________|


All of these commands deal with a set of pointers to key translation
arrays, known as a [KeyMap](../Libraries_Manual_guide/node046F.html) structure.  The KeyMap structure is defined in
<devices/[keymap.h](../Includes_and_Autodocs_2._guide/node003A.html#line22)> and is shown below.


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
The [KeyMap](../Libraries_Manual_guide/node046F.html) structure contains pointers to arrays which define the ANSI
character or string that should be produced when a key or a combination of
keys are pressed.  For example, a keymap might specify that the key with
raw value hex 20 should produce the ANSI character "a", and if the Shift
key is being held it should produce the character "A".

 [Asking For the Default Keymap](../Libraries_Manual_guide/node046A.html) 
 [Setting the Default Keymap](../Libraries_Manual_guide/node046B.html) 
 [Accessing the Keymap For the Current Console](../Libraries_Manual_guide/node046C.html) 
 [Mapping Key Codes To ANSI Strings](../Libraries_Manual_guide/node046D.html) 
 [Mapping ANSI Strings To Key Codes](../Libraries_Manual_guide/node046E.html) 
 [Details Of the Keymap Structure](../Libraries_Manual_guide/node046F.html) 
 [Key Map Standards](../Libraries_Manual_guide/node0476.html) 
 [Dead-Class Keys](../Libraries_Manual_guide/node0477.html) 
 [Double-Dead Keys](../Libraries_Manual_guide/node0478.html) 

