# mathieeesingbas.library/IEEESPCeil



NAME

    IEEESPCeil -- compute Ceil function of IEEE single precision number
SYNOPSIS

```c
      x   = IEEESPCeil(  y  );
     d0                  d0

    float   x,y;
```
FUNCTION

```c
    Calculate the least integer greater than or equal to x and return it.
    This identity is true.  Ceil(x) = -Floor(-x).
```
INPUTS

    y -- IEEE single precision floating point value
RESULT

    x -- IEEE single precision floating point value
BUGS

SEE ALSO

```c
    [IEEESPFloor](../Includes_and_Autodocs_2._guide/node0196.html)
```
