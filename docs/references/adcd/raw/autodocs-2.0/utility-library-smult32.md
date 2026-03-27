# utility.library/SMult32



NAME

```c
    SMult32 -- Signed 32 by 32 bit multiply with 32 bit result. (V36)
```
SYNOPSIS

```c
    Result = SMult32( Arg1, Arg2 )
    D0                D0    D1

    LONG SMult32( LONG, LONG );
```
FUNCTION

    Returns the signed 32 bit result of multiplying Arg1 by Arg2.
INPUTS

    Arg1, Arg2      - signed multiplicands.
RESULTS

    Result          - the signed 32 bit result of multiplying
                      Arg1 by Arg2.
NOTES

SEE ALSO

```c
    [SDivMod32()](../Includes_and_Autodocs_2._guide/node03DD.html), [UDivMod32()](../Includes_and_Autodocs_2._guide/node03E4.html), [UMult32()](../Includes_and_Autodocs_2._guide/node03E5.html)
```
BUGS

