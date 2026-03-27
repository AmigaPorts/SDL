# 28 / / / Parameters To Your Boundary Collision Routine


During the operation of the [DoCollision()](../Libraries_Manual_guide/node03D1.html#line16) routine, if you have enabled
boundary collisions for a GEL (by setting the least significant bit of its
[HitMask](../Libraries_Manual_guide/node03B2.html)) and it has crossed a boundary, the system calls the boundary
routine you have defined.  The system will call the routine once for every
GEL that has hit, or gone outside of the boundary.  The system will call
your routine with the following two arguments:

  * A pointer to the [VSprite](../Libraries_Manual_guide/node0381.html) structure of the GEL that hit the boundary

  * A flag word containing one to four bits set, representing top,

    bottom, left and right boundaries, telling you which of the
    boundaries it has hit or exceeded. To test these bits, compare to the
    constants TOPHIT, BOTTOMHIT, LEFTHIT, and RIGHTHIT.
See the [VSprite example](../Libraries_Manual_guide/node05F2.html#line73) given earlier for an example of using boundary
collision.

