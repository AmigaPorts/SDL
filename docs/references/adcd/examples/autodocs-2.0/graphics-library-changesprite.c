/* Source: ADCD 2.1
 * Section: graphics-library-changesprite
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/graphics-library-changesprite.md
 */

    vp - pointer to [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) structure that this sprite is
              relative to,  or 0 if relative only top of [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57)
    s - pointer to [SimpleSprite](../Includes_and_Autodocs_2._guide/node00C5.html#line20) structure
    newdata - pointer to data structure of the following form.
            struct spriteimage
            {
                UWORD    posctl[2]; /* used by simple sprite machine*/
                UWORD    data[height][2];   /* actual sprite image */
                UWORD    reserved[2];       /* initialized to */
                                                 /*  0x0,0x0 */
            };
    The programmer must initialize reserved[2].  Spriteimage must be
    in CHIP memory. The height subfield of the [SimpleSprite](../Includes_and_Autodocs_2._guide/node00C5.html#line20) structure
    must be set to reflect the height of the new spriteimage BEFORE
    calling ChangeSprite(). The programmer may allocate two sprites to
    handle a single attached sprite.  After [GetSprite()](../Includes_and_Autodocs_2._guide/node0449.html), ChangeSprite(),
    the programmer can set the SPRITE_ATTACHED bit in posctl[1] of the
    odd numbered sprite.
    If you need more than 8 sprites, look up VSprites in the
    graphics documentation.
