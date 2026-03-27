# 28 / / Detecting Gel Collisions / Using HitMask and MeMask


This section illustrates the use of the [HitMask](../Includes_and_Autodocs_2._guide/node00C3.html#line106) and [MeMask](../Includes_and_Autodocs_2._guide/node00C3.html#line106) to define one
type of collision.

Suppose there are two classes of objects that you wish to control on the
display:  ENEMYTANK and MYMISSILE.  Objects of class ENEMYTANK should be
able to pass across one another without registering any collisions.
Objects of class MYMISSILE should also be able to pass across one another
without collisions.  However, when MYMISSILE and ENEMYTANK collide, the
system should generate a call to a collision routine.

Choose a pair of collision detect bits not yet assigned within [MeMask](../Includes_and_Autodocs_2._guide/node00C3.html#line106), one
to represent ENEMYTANK, the other to represent MYMISSILE.  You will use
the same two bits in the corresponding [HitMask](../Includes_and_Autodocs_2._guide/node00C3.html#line106).  In this example, bit 1
represents ENEMYTANK objects and bit 2 represents MYMISSLE objects.


                          MeMask  HitMask
                          ------  -------
              Bit Number   2  1    2  1
              --- ------   -  -    -  -
              ENEMYTANK 1  0  1    1  0
              ENEMYTANK 2  0  1    1  0
              MYMISSILE    1  0    0  1
In the [MeMask](../Includes_and_Autodocs_2._guide/node00C3.html#line106), bit 1 is set to indicate that this object is an ENEMYTANK.
Bit 2 is clear (zero) indicating this object is not a MYMISSILE object.
In the [HitMask](../Includes_and_Autodocs_2._guide/node00C3.html#line106) for ENEMYTANK objects, bit 1 is clear (zero) which means,
"I will not register collisions with other ENEMYTANK objects."  However,
bit 2 is set (one) which means, "I will register collisions with MYMISSILE
objects."

Thus when a call to [DoCollision()](../Libraries_Manual_guide/node03D1.html#line16) occurs, for any objects that appear to
be colliding, the system ANDs the [MeMask](../Includes_and_Autodocs_2._guide/node00C3.html#line106) of one object with the [HitMask](../Includes_and_Autodocs_2._guide/node00C3.html#line106) of
the other object.  If there are non-zero bits present, the system will
call one of your collision routines.

In this example, suppose that the system senses a collision between
ENEMYTANK 1 and ENEMYTANK 2.  Suppose also that ENEMYTANK 1 is the
top/leftmost object of the pair.  Here is the way that the collision
testing routine performs the test to see if the system will call any
collision-handling routines:


              Bit Number             2  1
              --- ------             -  -
              ENEMYTANK 1  MeMask    0  1
              ENEMYTANK 2  HitMask   1  0

              Result of logical-AND  0  0
Therefore, the system does not call a collision routine.  But suppose that
[DoCollision()](../Libraries_Manual_guide/node03D1.html#line16) finds an overlap between ENEMYTANK 1 and MYMISSILE, where
MYMISSILE is the top/leftmost of the pair:


              Bit Number             2  1
              --- ------             -  -
              MYMISSILE MeMask       1  0
              ENEMYTANK 2 HitMask    1  0

              Result of logical-AND  1  0
Therefore, the system calls the collision routine at position 2 in the
table of collision-handling routines.

