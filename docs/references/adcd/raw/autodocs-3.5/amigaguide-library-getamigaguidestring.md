# amigaguide.library/GetAmigaGuideString



   NAME
```c
        GetAmigaGuideString - Get an AmigaGuide string.
                                                               (V34)
```
   SYNOPSIS

```c
        txt = GetAmigaGuideString (id);
        d0                         d0

        [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) GetAmigaGuideString (ULONG);
```
   FUNCTION

        This function is used to obtain a localized string given the
        ID.
   INPUTS

        ID -- Valid AmigaGuide string id.
   RETURNS

        A pointer to the string.   NULL for an invalid string.
   SEE ALSO

