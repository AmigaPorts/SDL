# 28 / Using Bobs / VSprite Flags and Bobs


The bits in the [VSprite.Flags](../Includes_and_Autodocs_2._guide/node00C3.html#line92) field that apply to a Bob are the [VSPRITE](../Libraries_Manual_guide/node0383.html#line6)
flag, the [SAVEBACK](../Includes_and_Autodocs_2._guide/node00C3.html#line19) flag and the [OVERLAY](../Includes_and_Autodocs_2._guide/node00C3.html#line19) flag.  When a [VSprite](../Libraries_Manual_guide/node0381.html) structure is
used to define a Bob, the VSPRITE flag in the VSprite.Flags field must be
set to zero.  This tells the system that this GEL is a Bob type.

To have the GEL routines save the background before the Bob is drawn and
restore the background after the Bob is removed, specify the [SAVEBACK](../Includes_and_Autodocs_2._guide/node00C3.html#line19) flag
(stands for "save the background") in the [VSprite](../Libraries_Manual_guide/node0381.html) structure [Flags](../Includes_and_Autodocs_2._guide/node00C3.html#line92) field.
If this flag is set, the [SaveBuffer](../Libraries_Manual_guide/node0398.html#line5) must have been allocated, which is
where the system puts this saved background area.  The buffer must be
large enough to save all the background bitplanes, regardless of how many
planes the Bob has.  The size in words can be calculated as follows:


```c
    /* Note that Bob.Width is in units of words. */
    size = Bob.Width * Bob.Height * RastPort.BitMap.Depth;
```
To allocate this space, the graphics function [AllocRaster()](../Libraries_Manual_guide/node032E.html) can be used.
AllocRaster() takes the width in bits, so it is a convenient way to
allocate the space needed.  The [makeBob()](../Libraries_Manual_guide/node059C.html#line129) routine below shows another way
to correctly allocate this buffer. For example:


```c
    /* space for 16 bits times 5 lines times 5 bitplanes */
    myBob.SaveBuffer = AllocRaster( (UWORD) 16, (UWORD) (5 * 5) );


    Warning:
    --------
    The [SaveBuffer](../Libraries_Manual_guide/node0398.html#line5) must be allocated from Chip memory and contain an
    even number of word-aligned bytes.  The [AllocRaster()](../Libraries_Manual_guide/node032E.html) function
    does this for you.  The AllocRaster() function rounds the width
    value up to the next integer multiple of 16 bits which is greater
    than or equal to the current value an it obtains memory from the Chip
    memory pool.
```
[OVERLAY](../Includes_and_Autodocs_2._guide/node00C3.html#line19) is the other [VSprite.Flags](../Includes_and_Autodocs_2._guide/node00C3.html#line92) item that applies to Bobs. If this flag
is set, it means that the background's original pixels show through in any
area where there are 0 bits in the Bob's shadow mask ([ImageShadow](../Libraries_Manual_guide/node039F.html),
explained later).  The space for the ImageShadow shadow mask must have
been allocated and initialized.  The ImageShadow mask must be allocated
from Chip memory.

If the [OVERLAY](../Includes_and_Autodocs_2._guide/node00C3.html#line19) bit is cleared, the system uses the entire rectangle of
words that define the Bob image to replace the playfield area at the
specified x,y coordinates.  See the paragraphs below called "[ImageShadow](../Libraries_Manual_guide/node039F.html)".

