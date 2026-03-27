# 28 / / Setting Up For Boundary Collisions


To specify the region in the playfield that the system will use to define
the outermost limits of the GEL boundaries, you use these [GelsInfo](../Libraries_Manual_guide/node0377.html#line6)
members: [topmost, bottommost, leftmost, and rightmost](../Includes_and_Autodocs_2._guide/node00AF.html#line50). The [DoCollision()](../Libraries_Manual_guide/node03D1.html#line16)
routine tests these boundaries when determining boundary collisions within
this [RastPort](../Libraries_Manual_guide/node034A.html).  They have nothing whatsoever to do with graphical
clipping.  Graphical clipping makes use of the RastPort's clipping
rectangle.

Here is a typical program segment that assigns the members correctly (for
boundaries 50, 100, 80, 240).  It assumes that you already have a [RastPort](../Libraries_Manual_guide/node034A.html)
structure pointer named myRastPort.


```c
    myRastPort->GelsInfo->topmost    = 50;
    myRastPort->GelsInfo->bottommost = 100;
    myRastPort->GelsInfo->leftmost   = 80;
    myRastPort->GelsInfo->rightmost  = 240;
```
 [Parameters To Your Boundary Collision Routine](../Libraries_Manual_guide/node03B4.html) 
 [Parameters To Your Inter-GEL Collision Routines](../Libraries_Manual_guide/node03B5.html) 
 [Handling Multiple Collisions](../Libraries_Manual_guide/node03B6.html) 

