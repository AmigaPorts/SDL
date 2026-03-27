# 28 / About the GELs System / The GELs System


Before you can use the GELs system, you must set up a playfield.  The GELs
system requires access to a [View](../Libraries_Manual_guide/node00F1.html#line4), [ViewPort](../Libraries_Manual_guide/node00F1.html#line4), and [RastPort](../Libraries_Manual_guide/node034A.html) structure.  These
structures may be set up through the grapics library or Intuition.  For
most examples in this chapter, the Intuition library is used for this
purpose.

All GELs have a [VSprite](../Libraries_Manual_guide/node0381.html) structure at their core.  The system keeps track
of all the GELs that it will display (the active GELs) by using a standard
Exec list structure to link the VSprites.  This list is accessed via the
GelsInfo data structure, which in turn is associated with the [RastPort](../Libraries_Manual_guide/node034A.html).
The GelsInfo structure is defined in the file <graphics/[rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html#line39)>. When
a new GEL is introduced to the system, the new GEL is added immediately
ahead of the first existing GEL whose x, y value is greater than or equal
to that of the new GEL, always trying to keep the list sorted.

As GELs are moved about the screen, their x, y values are constantly
changing.  [SortGList()](../Libraries_Manual_guide/node038B.html#line7) re-sorts this list by the x, y values. (Although
this is a list of [VSprite](../Libraries_Manual_guide/node0381.html) structures, bear in mind that some or all may
really be Bobs or AnimComps.)

The basic set up of the [GelsInfo](../Includes_and_Autodocs_2._guide/node00AF.html#line39) structure requires three important
fields:  [sprRsrvd](../Libraries_Manual_guide/node0392.html),  gelHead and gelTail.  The sprRsrvd field tells the
system which hardware sprites not to use when managing true VSprites.  For
instance, Intuition uses sprite 0 for the mouse pointer so this hardware
sprite is not available for assignment to a VSprite.  The gelHead and
gelTail are [VSprite](../Libraries_Manual_guide/node0381.html) structures that are used to manage the list of GELs.
They are never displayed.  To activate or deactivate a GEL, a system call
is made to add it to or delete it from this list.

Other fields must be set up to provide for collision detection, color
optimization, and other features.  A complete example for setting up the
[GelsInfo](../Includes_and_Autodocs_2._guide/node00AF.html#line39) structure is shown in the [animtools.c](../Libraries_Manual_guide/node059C.html#line22) lisitng at the end of this
chapter.

 [Initializing the GEL System](../Libraries_Manual_guide/node0378.html) 

