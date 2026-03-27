# 28 / Using Bobs / The Bob Structure


The Bob structure is defined in the include file <graphics/[gels.h](../Includes_and_Autodocs_2._guide/node00C3.html#line140)> as
follows:

struct Bob
  {
  WORD               Flags;     /* general purpose flags                 */
  WORD              *SaveBuffer;/* buffer for background save            */
  WORD              *ImageShadow; /* shadow mask of image                */
  struct Bob        *Before;   /* draw this Bob before Bobs on this list */
  struct Bob        *After;     /* draw this Bob after Bobs on this list */
  struct VSprite    *BobVSprite;/* this Bob's VSprite definition         */
  struct AnimComp   *BobComp;   /* pointer to this Bob's AnimComp def    */
  struct DBufPacket *DBuffer;   /* pointer to this Bob's dBuf packet     */
  BUserStuff         BUserExt;  /* Bob user extension                    */
  };

The Bob structure itself does not need to be in Chip memory. The (global)
static declaration of a Bob structure could be done like so:


```c
    struct Bob myBob =
        {
        0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0
        };
```
However, since most of the Bob structure members are pointers, it is more
common to allocate and set the Bob up dynamically. Refer to the [makeBob()](../Libraries_Manual_guide/node059C.html#line129)
and [freeBob()](../Libraries_Manual_guide/node059C.html#line302) functions in the "[animtools.c](../Libraries_Manual_guide/node059C.html)" example at the end of the
chapter for an example of allocating, initializing and freeing a Bob
structure.

 [Linking Bob and VSprite Structures](../Libraries_Manual_guide/node0399.html) 

