# layers.library/SwapBitsRastPortClipRect



NAME

```c
    SwapBitsRastPortClipRect -- Swap bits between common bitmap
                                and obscured [ClipRect](../Includes_and_Autodocs_2._guide/node00A1.html#line63)
```
SYNOPSIS

```c
    SwapBitsRastPortClipRect( rp, cr )
                              a0  a1

    void SwapBitsRastPortClipRect( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, struct [ClipRect](../Includes_and_Autodocs_2._guide/node00A1.html#line63) *);
```
FUNCTION

```c
    Support routine useful for those that need to do some
    operations not done by the layer library.  Allows programmer
    to swap the contents of a small [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) with a subsection of
    the display. This is accomplished without using extra memory.
    The bits in the display [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) are exchanged with the
    bits in the ClipRect's [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47).

    Note: the [ClipRect](../Includes_and_Autodocs_2._guide/node00A1.html#line63) structures which the layer library allocates are
    actually a little bigger than those described in the [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)
    include file.  So be warned that it is not a good idea to have
    instances of cliprects in your code.
```
INPUTS

    rp - pointer to rastport
    cr - pointer to cliprect to swap bits with
NOTE

```c
    Because the blit operation started by this function is done
    asynchronously, it is imperative that a [WaitBlit()](../Includes_and_Autodocs_2._guide/node0489.html) be performed before
    releasing or using the processor to modify any of the associated
    structures.
```
BUGS

SEE ALSO

```c
    [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html), [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html), [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)
```
