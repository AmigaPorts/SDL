# utility.library/UMult32



NAME

```c
    UMult32 -- Unsigned 32 by 32 bit multiply with 32 bit result. (V36)
```
SYNOPSIS

```c
    Result = UMult32( Arg1, Arg2 )
    D0                D0    D1

    ULONG UMult32( ULONG, ULONG );
```
FUNCTION

    Returns the unsigned 32 bit result of multiplying Arg1 by Arg2.
INPUTS

    Arg1, Arg2              - unsigned multiplicands.
RESULTS

    Result                  - the unsigned 32 bit result of
                              multiplying Arg1 by Arg2.
NOTES

SEE ALSO

```c
    [SDivMod32()](../Includes_and_Autodocs_2._guide/node03DD.html), [SMult32()](../Includes_and_Autodocs_2._guide/node03DE.html), [UDivMod32()](../Includes_and_Autodocs_2._guide/node03E4.html)
```
BUGS

