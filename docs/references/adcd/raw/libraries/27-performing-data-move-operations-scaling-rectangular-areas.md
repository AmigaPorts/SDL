# 27 / / Performing Data Move Operations / Scaling Rectangular Areas


[BitMapScale()](../Includes_and_Autodocs_2._guide/node041E.html) will scale a single bitmap any integral size up to 16,383
times its original size.  This function is available only in Release 2 and
later versions of the OS.  It is called with the address of a BitScaleArgs
structure (see <graphics/[scale.h](../Includes_and_Autodocs_2._guide/node00BF.html#line18)>).


```c
    void BitMapScale(struct BitScaleArgs *bsa)
```
The bsa argument specifies the [BitMap](../Libraries_Manual_guide/node032B.html#line74)s to use, the source and destination
rectangles, as well as the scaling factor.  The source and destination may
not overlap.  The caller must ensure that the destination BitMap is large
enough to receive the scaled-up copy of the source rectangle.  The
function [ScalerDiv()](../Includes_and_Autodocs_2._guide/node0472.html) is provided to help in the calculation of the
destination BitMap's size.

