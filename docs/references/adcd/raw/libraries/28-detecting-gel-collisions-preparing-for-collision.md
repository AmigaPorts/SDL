# 28 / / Detecting Gel Collisions / Preparing for Collision Detection


Before you can use the system to detect collisions between GELS, you must
allocate and initialize a table of collision-detection routines and place
the address of the table in the [GelsInfo.CollHandler](../Libraries_Manual_guide/node03AE.html) field.  This table is
an array of pointers to the actual routines that you have provided for
your collision types.  You must also prepare some members of the [VSprite](../Libraries_Manual_guide/node0381.html)
structure: [CollMask](../Libraries_Manual_guide/node03AF.html), [BorderLine](../Libraries_Manual_guide/node03B0.html), [HitMask](../Libraries_Manual_guide/node03B2.html), and [MeMask](../Libraries_Manual_guide/node03B2.html).

