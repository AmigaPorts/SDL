# mathieeesingtrans.library/IEEESPTieee



NAME

    IEEESPTieee -- convert IEEE single to IEEE single
SYNOPSIS

```c
      x   = IEEESPTieee(  y  );
     d0                 d0

    float   y;
    float   x;
```
FUNCTION

    Convert IEEE single precision number to IEEE single precision.
    These are included for completeness although they just
    return the input parameter. A good way to remember how these
    functions work is: They convert to and from the local format
    to Single Precision IEEE. The local format for this library
    happens to also be Single Precision IEEE.
INPUTS

    y - IEEE single precision floating point value
RESULT

    x - IEEE single precision floating point value
BUGS

SEE ALSO

```c
    [IEEESPFieee()](../Includes_and_Autodocs_2._guide/node01E7.html)
```
