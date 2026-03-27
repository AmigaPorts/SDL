# 28 / / Types Of GELs / VSprites


The VSprite, or virtual sprite, is the simplest type of GEL.  The [VSprite](../Libraries_Manual_guide/node0381.html)
data structure contains just a bit more information than is needed to
define a hardware sprite.  VSprites take advantage of the system's ability
to reuse sprite DMA channels--each VSprite can be temporarily assigned to
a hardware sprite, as needed.  This makes it appear to an application
program that it has a virtually unlimited supply of VSprites.

Since VSprites are based on hardware sprites, rules that apply to hardware
sprites apply to VSprites too.  VSprites are not rendered into the
underlying [BitMap](../Libraries_Manual_guide/node00F1.html#line4) of the playfield and so do not affect any bits in the
BitMap.  Because they are hardware based, they are positioned at absolute
display coordinates and are not affected by the movement of screens.  The
starting position of a sprite must not occur before scanline 20, because
of certain hardware DMA time constraints.  VSprites have the same size
limitations as hardware sprites, they are 16-bits wide and arbitrarily
tall.

The [VSprite](../Libraries_Manual_guide/node0381.html) data structure also serves as the root structure of more
complex GEL types--Bobs and AnimComps.

