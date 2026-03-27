# 28 / Collisions and GEL Structure Extensions / Detecting Gel Collisions


All GELs, including VSprites, can participate in the software collision
detection features of the graphics library.  Simple Sprites must use
hardware collision detection.  See the Amiga [Hardware](../Hardware_Manual_guide/node015A.html) Reference Manual for
information about hardware collision detection.

Two kinds of collisions are handled by the system routines:
GEL-to-boundary hits and GEL-to-GEL hits.  You can set up as many as 16
different routines to handle different collision combinations; one routine
to handle the boundary hits, and up to fifteen more to handle different
inter-GEL hits.

You supply the actual collision handling routines, and provide their
addresses to the system so that it can call them as needed (when the hits
are detected).  These addresses are kept in a collision handler table
pointed to by the [CollHandler](../Libraries_Manual_guide/node03AE.html) field of the [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) list.  Which routine
is called depends on the 16-bit [MeMask](../Includes_and_Autodocs_2._guide/node00C3.html#line106) and [HitMask](../Includes_and_Autodocs_2._guide/node00C3.html#line106) members of the [VSprite](../Libraries_Manual_guide/node0381.html)
structures involved in the collision.

When you call [DoCollision()](../Libraries_Manual_guide/node03D1.html#line16), the system goes through the [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) list
which, is constantly kept sorted by x, y position.  If a GEL intersects
the display boundaries and the GELs [HitMask](../Includes_and_Autodocs_2._guide/node00C3.html#line106) indicates it is appropriate,
the boundary collision routine is called.  When DoCollision() finds that
two GELs overlap, it compares the [MeMask](../Includes_and_Autodocs_2._guide/node00C3.html#line106) of one with the HitMask of the
other.  If corresponding bits are set in both, it calls the appropriate
inter-GEL collision routine at the table position corresponding to the
bits in the HitMask and MeMask, as outlined below.

 [Preparing for Collision Detection](../Libraries_Manual_guide/node03AD.html)         [VSprite BorderLine](../Libraries_Manual_guide/node03B0.html) 
 [Building a Table of Collision Routines](../Libraries_Manual_guide/node03AE.html)    [VSprite HitMask and MeMask](../Libraries_Manual_guide/node03B1.html) 
 [VSprite Collision Mask](../Libraries_Manual_guide/node03AF.html)                    [Using HitMask and MeMask](../Libraries_Manual_guide/node03B2.html) 

