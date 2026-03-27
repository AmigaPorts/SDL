# 35 / FFP Mathematics Conversion Library / Math Support Functions


[afp()](../Includes_and_Autodocs_2._guide/node013B.html)    FLOAT afp( BYTE *string );

    Convert ASCII string into FFP equivalent.
[arnd()](../Includes_and_Autodocs_2._guide/node0140.html)   VOID arnd( LONG place, LONG exp, BYTE *string);

    Round ASCII representation of FFP number.
[dbf()](../Includes_and_Autodocs_2._guide/node0151.html)    FLOAT dbf( ULONG exp, ULONG mant);

    Convert FFP dual-binary number to FFP equivalent.
[fpa()](../Includes_and_Autodocs_2._guide/node015B.html)    LONG fpa( FLOAT fnum, BYTE *string);

    Convert FFP variable into ASCII equivalent.
Be sure to include proper data type definitions, as shown in the example
below.  Print statements have been included to help clarify the format of
the math conversion function calls.


```c
     [mathffp.c](../Libraries_Manual_guide/node05FE.html) 
```
