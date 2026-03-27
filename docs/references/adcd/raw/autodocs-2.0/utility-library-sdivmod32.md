# utility.library/SDivMod32



NAME

```c
    SDivMod32 -- Signed 32 by 32 bit division and modulus. (V36)
```
SYNOPSIS

```c
    Quotient:Remainder = SDivMod32( Dividend, Divisor )
    D0       D1                     D0        D1

    LONG SDivMod32( LONG, LONG );
```
FUNCTION

    Divides the signed 32 bit dividend by the signed 32 bit divisor
       and returns a signed 32 bit quotient and remainder.
INPUTS

    Dividend        - signed 32 bit dividend.
    Divisor         - signed 32 bit divisor.
RESULTS

    Quotient        - signed 32 quotient of the division.
    Remainder       - signed 32 remainder of the division.
NOTES

SEE ALSO

```c
    [SMult32()](../Includes_and_Autodocs_2._guide/node03DE.html), [UDivMod32()](../Includes_and_Autodocs_2._guide/node03E4.html), [UMult32()](../Includes_and_Autodocs_2._guide/node03E5.html)
```
BUGS

