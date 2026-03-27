# 28 / / Other Items Influencing Bob Colors / PlaneOnOff


What happens to the background planes that aren't picked?  The shadow mask
is used to either set or clear the bits in those planes in the exact shape
of the Bob if [OVERLAY](../Libraries_Manual_guide/node0397.html#line34) is set, otherwise the entire rectangle containing
the Bob is used.  The [PlaneOnOff](../Includes_and_Autodocs_2._guide/node00C3.html#line123) member tells the system whether to put
down the shadow mask as zeros or ones for each plane.  The relationship
between bit positions in PlaneOnOff and background plane numbers is
identical to [PlanePick](../Libraries_Manual_guide/node03A0.html): the least significant bit position indicates the
lowest-numbered bitplane.  A zero bit clears the shadow mask shape in the
corresponding plane, while a one bit sets the shadow mask shape.  The
planes Picked by PlanePick have image data - not shadow mask - blitted in.

This provides a great deal of color versatility.  One image definition can
be used for many Bobs.  By having different [PlanePick](../Libraries_Manual_guide/node03A0.html) / [PlaneOnOff](../Includes_and_Autodocs_2._guide/node00C3.html#line123)
combinations, each Bob can use a different subset of the background color
set.

There is a member in the [VSprite](../Libraries_Manual_guide/node0381.html) structure called [CollMask](../Libraries_Manual_guide/node03AF.html) (the collision
mask, covered under "[Detecting GEL Collisions](../Libraries_Manual_guide/node03AC.html)") for which the application
may also reserve some memory space.  The [ImageShadow](../Libraries_Manual_guide/node039F.html) and CollMask pointers
usually, but not necessarily, point to the same data, which must be
located in Chip memory.  If they point to the same location, obviously,
the memory only need be allocated once.

An example of the kinds of statements that accomplish these actions (see
the [makeVSprite()](../Libraries_Manual_guide/node059C.html#line89) and [makeBob()](../Libraries_Manual_guide/node059C.html#line129) examples for more details):


#define BOBW 1
#define BOBH 5
#define BOBD 2

/* Data definition from example layout */
WORD chip BobData[]=

```c
    {
    0xFFFF, 0x300C, 0x0FF0, 0x03C0, 0x0180,
    0xFFFF, 0x3E7C, 0x0C30, 0x03C0, 0x0180
    };
```
/* Reserve space for the collision mask for this Bob */
WORD chip BobCollision[BOBW * BOBH];

myVSprite.Width  = BOBW;     /* Image is 16 pixels wide (1 word) */
myVSprite.Height = BOBH;    /* 5 lines for each plane of the Bob */
myVSprite.Depth  = BOBD;     /* 2 Planes are in ImageData */

/* Show the system where it can find the data image of the Bob */
myVSprite.ImageData = BobData;

/* binary 0101, render image data into bitplanes 0 and 2 */
myVSprite.PlanePick = 0x05;

/* binary 0000, means colors 1, 4, and 5 will be used.
*  binary 0010 would mean colors 3, 6, and 7.
*    "    1000   "    "     "    9, C, and D.
*    "    1010   "    "     "    B, E, and F.
*/
myVSprite.PlaneOnOff = 0x00;

/* Where to put collision mask */
myVSprite.CollMask = BobCollision;

/* Tell the system where it can assemble a GEL shadow */
/* Point to same area as CollMask */
myBob.ImageShadow = BobCollision;

/* Create the Sprite collision mask in the VSprite structure */
InitMasks(&myVSprite);

