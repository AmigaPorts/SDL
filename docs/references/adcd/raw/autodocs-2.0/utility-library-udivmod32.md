# utility.library/UDivMod32



NAME

```c
    UDivMod32 -- Unsigned 32 by 32 bit division and modulus. (V36)
```
SYNOPSIS

```c
    Quotient:Remainder = UDivMod32( Dividend, Divisor )
    D0       D1                     D0        D1

    ULONG UDivMod32( ULONG, ULONG );
```
FUNCTION

    Divides the unsigned 32 bit dividend by the unsigned 32 bit divisor
    and returns a unsigned 32 bit quotient and remainder.
INPUTS

    Dividend        - unsigned 32 bit dividend.
    Divisor         - unsigned 32 bit divisor.
RESULTS

    Quotient        - unsigned 32 quotient of the division.
    Remainder       - unsigned 32 remainder of the division.
NOTES

SEE ALSO

```c
    [SDivMod32()](../Includes_and_Autodocs_2._guide/node03DD.html), [SMult32()](../Includes_and_Autodocs_2._guide/node03DE.html), [UMult32()](../Includes_and_Autodocs_2._guide/node03E5.html)
```
BUGS

