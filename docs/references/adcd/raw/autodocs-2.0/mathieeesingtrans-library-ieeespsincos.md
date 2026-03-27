# mathieeesingtrans.library/IEEESPSincos



NAME

    IEEESPSincos -- compute the arc tangent of a floating point number
SYNOPSIS

```c
      x   = IEEESPSincos( z ,  y  );
    d0                   a0  d0

    float   x,y,*z;
```
FUNCTION

    Compute sin and cosine of y in IEEE single precision.
    Store the cosine in *z. Return the sine of y.
INPUTS

    y - IEEE single precision floating point value
    z - pointer to IEEE single precision floating point number
RESULT

    x - IEEE single precision floating point value
BUGS

SEE ALSO

```c
    [IEEESPSin()](../Includes_and_Autodocs_2._guide/node01EB.html), [IEEESPCos()](../Includes_and_Autodocs_2._guide/node01E4.html)
```
