# graphics.library/PolyDraw



NAME

```c
    PolyDraw -- Draw lines from table of (x,y) values.
```
SYNOPSIS

```c
    PolyDraw( rp, count , array )
              a1   d0      a0

    void PolyDraw( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, WORD, WORD * );
```
FUNCTION

    starting with the first pair in the array, draw connected lines to
    it and every successive pair.
INPUTS

```c
    rp - pointer to [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
    count -  number of (x,y) pairs in the array
    array - pointer to first (x,y) pair
```
BUGS

SEE ALSO

```c
    [Draw()](../Includes_and_Autodocs_2._guide/node0436.html) [Move()](../Includes_and_Autodocs_2._guide/node045D.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
