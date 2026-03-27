# 34 / Keymap Functions / Mapping ANSI Strings To Key Codes


The [MapANSI()](../Includes_and_Autodocs_2._guide/node0314.html) function translates ANSI strings into raw key codes,
complete with qualifiers and (double) dead keys, based on a default or
supplied keymap.


```c
    LONG MapANSI(UBYTE *string, LONG stringlength, UBYTE *buffer,
                 LONG bufferlength, struct KeyMap *keymap);
```
The string argument is a pointer to an ANSI string, of length
stringlength. The buffer argument is a pointer to the memory block where
the translated key codes will be placed.  The length of this buffer must
be indicated in WORDs since each translation will occupy one byte for the
key code and one for the qualifier. Since one ANSI character can be
translated to two dead keys and one key, the buffer must be at least 3
WORDs per character in the string to be translated. The keymap argument
can be set to NULL if the default keymap is to be used, or can be a
pointer to a [KeyMap](../Libraries_Manual_guide/node046F.html) structure.  Upon return, the function will indicate
how many key code/qualifier combinations are placed in the buffer or a
negative number in case an error occurred. If zero is returned, the
character could not be translated.

The following example shows the usage of [MapANSI()](../Includes_and_Autodocs_2._guide/node0314.html) and demonstrates how
returned key codes can be processed.


```c
     [mapansi.c](../Libraries_Manual_guide/node05AE.html) 
```
