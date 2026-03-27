# graphics.library/ScrollVPort



NAME

```c
    ScrollVPort -- Reinterpret RasInfo information in [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) to reflect
                    the current Offset values.
```
SYNOPSIS

```c
    ScrollVPort( vp )
                 a0

    void ScrollVPort(struct [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) *);
```
FUNCTION

```c
    After the programmer has adjusted the Offset values in
    the RasInfo structures of [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40), change the
    the copper lists to reflect the the Scroll positions.
    Changing the [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) ptr in RasInfo and not changing the
    the Offsets will effect a double buffering affect.
```
INPUTS
```c
    vp - pointer to a [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) structure
         that is currently be displayed.
```
RESULTS

    modifies hardware and intermediate copperlists to reflect
    new RasInfo
BUGS
   pokes not fast enough to avoid some visible hashing of display

SEE ALSO

```c
    [MakeVPort()](../Includes_and_Autodocs_2._guide/node045B.html) [MrgCop()](../Includes_and_Autodocs_2._guide/node045F.html) [LoadView()](../Includes_and_Autodocs_2._guide/node0459.html)  [graphics/view.h](../Includes_and_Autodocs_2._guide/node00B8.html)
```
