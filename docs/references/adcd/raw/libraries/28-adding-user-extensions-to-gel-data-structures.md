# 28 / / Adding User Extensions To Gel Data Structures


This section describes how to expand the size and scope of the [VSprite](../Libraries_Manual_guide/node0381.html),
[Bob](../Libraries_Manual_guide/node0398.html) and [AnimOb](../Libraries_Manual_guide/node03B9.html#line34) data structures.  In the definition for these structures,
there is an item called UserExt at the end of each.  If you want to expand
these structures (to hold your own special data), you define the UserExt
member before the <graphics/[gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)> file is included.  If this member has
already been defined when the <graphics/gels.h> file is parsed,  the
compiler preprocessor will extend the structure definition automatically.
If these members have not been defined, the system will make them SHORTs,
and you may still consider these as being reserved for your private use.

To show the kind of use you can make of this feature, the example below
adds speed and acceleration figures to each GEL by extending the [VSprite](../Libraries_Manual_guide/node0381.html)
structure.  When your collision routine is called, it could use these
values to transfer energy between the two colliding objects (say, billiard
balls).  You would have to set up additional routines, executed between
calls to [DoCollision()](../Libraries_Manual_guide/node03D1.html#line16), that would add the values to the GELs position
appropriately.  You could do this with code similar o the following:


```c
     struct myInfo
         {
         short xvelocity;
         short yvelocity;
         short xaccel;
         short yaccel;
         };
```
These members are for example only.  You may use any definition for your
user extensions.  You would then also provide the following line, to
extend the [VSprites](../Libraries_Manual_guide/node0381.html) structure, use:


     /* Redefine VUserStuff for my own use. */
     #define VUserStuff struct myInfo
To extend the [Bob](../Libraries_Manual_guide/node0398.html)s structure, use:


     #define BUserStuff struct myInfo
To extend the [AnimOb](../Libraries_Manual_guide/node03B9.html#line34)s structure, use:


     #define AUserStuff struct myInfo
When the system is compiling the <graphics/[gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)> file with your program,
the compiler preprocessor substitutes "struct myInfo" everywhere that
UserExt is used in the header. The structure is thereby customized to
include the items you wish to associate with it.


    Typedef Cannot Be Used.
    -----------------------
    You cannot use the C-language construct typedef for the above
    statements.  If you want to substitute your own data type for one of
    the UserStuff variables, you must use a #define.
