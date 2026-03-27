# mathieeesingbas.library/IEEESPFix



NAME

    IEEESPFix -- convert IEEE single float to integer
SYNOPSIS

```c
    x   = IEEESPFix(  y  );
    d0               d0

    long    x;
    float   y;
```
FUNCTION

    Convert IEEE single precision argument to a 32 bit signed integer
    and return result.
INPUTS

    y -- IEEE single precision floating point value
RESULT

    if no overflow occured then return
            x -- 32 bit signed integer
    if overflow return largest +- integer
            For round to zero
BUGS

SEE ALSO

```c
    [IEEESPFlt](../Includes_and_Autodocs_2._guide/node0197.html)
```
