/* Source: ADCD 2.1
 * Section: lib-examples-vsprite-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-vsprite-c.md
 */

        /* Image data, sprite color array word width (must be 1 for true VSprite) */
        vsprite_data1, mySpriteColors,1,
        /* Line height, image depth (must be 2 for true VSprite), x, y position   */                                                           */
        GEL_SIZE, 2, 160, 100,
        /* Flags (VSPRITE == true VSprite), hit mask and me mask                  */
        VSPRITE, 1 << BORDERHIT, 0
        };
