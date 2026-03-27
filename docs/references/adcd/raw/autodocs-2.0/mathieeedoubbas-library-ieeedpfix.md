# mathieeedoubbas.library/IEEEDPFix



NAME

    IEEEDPFix -- convert IEEE double float to integer
SYNOPSIS

```c
    x   = IEEEDPFix(  y  );
    d0              d0/d1

    long    x;
    double  y;
```
FUNCTION

    Convert IEEE double precision argument to a 32 bit signed integer
    and return result.
INPUTS

    y -- IEEE double precision floating point value
RESULT

    if no overflow occured then return
            x -- 32 bit signed integer
    if overflow return largest +- integer
            For round to zero
BUGS

SEE ALSO

```c
    [IEEEDPFlt](../Includes_and_Autodocs_2._guide/node0401.html)
```
