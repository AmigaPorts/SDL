# 28 / / Sprite Functions / Changing The Appearance Of A Simple Sprite


The [ChangeSprite()](../Includes_and_Autodocs_2._guide/node0427.html) function can be used to alter the appearance of a
Simple Sprite.  ChangeSprite() substitutes new image data for the data
currently used to display a Simple Sprite.  It is called by the following
sequence:


```c
    struct ViewPort     *vp;
    struct SimpleSprite *sprite;
    APTR                newdata;

    ChangeSprite(vp, sprite, newdata);
```
The vp input to this function is a pointer to the [ViewPort](../Libraries_Manual_guide/node00F1.html#line4) for this Sprite
or 0 if this Sprite is relative only to the current [View](../Libraries_Manual_guide/node00F1.html#line4).  The sprite
argument is a pointer to a [SimpleSprite](../Libraries_Manual_guide/node0379.html#line6) data structure.  (You must
allocate an actual SimpleSprite structure for sprite to point to.)  Set
newdata to the address of an image data structure containing the new
image.  The data must reside in Chip ([MEMF_CHIP](../Libraries_Manual_guide/node02A8.html#line11)) memory.

The structure for the new sprite image data is shown below.  It is not a
system structure, so it will not be found in the system includes, but it
is described in the documentation for the [ChangeSprite()](../Includes_and_Autodocs_2._guide/node0427.html) call.


```c
    struct spriteimage
        {
        UWORD posctl[2];  /* position and control data for this Sprite */

        /* Two words per line of Sprite height, first of the two words
         *  contains the MSB for color selection, second word contains
         * LSB (colors 0,1,2,3 from allowable color register selection
         *  set). Color '0' for any Sprite pixel makes it transparent.
         */
        UWORD data[height][2];  /* actual Sprite image */

        UWORD reserved[2];  /* reserved, initialize to 0, 0 */
        };
```
