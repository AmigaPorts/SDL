/* Source: ADCD 2.1
 * Section: lib-examples-rgbboxes-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rgbboxes-c.md
 */

    /* Make a ViewPortExtra and get ready to attach it */
    if( vpextra = GfxNew(VIEWPORT_EXTRA_TYPE) )
        {
        vcTags[1].ti_Data = (ULONG) vpextra;

        /* Initialize the DisplayClip field of the ViewPortExtra */
        if( GetDisplayInfoData( NULL , (UBYTE *) &dimquery ,
                                sizeof(dimquery) , DTAG_DIMS, modeID) )
            {
            vpextra->DisplayClip = dimquery.Nominal;

            /* Make a DisplayInfo and get ready to attach it */
            if( !(vcTags[2].ti_Data = (ULONG) FindDisplayInfo(modeID)) )
                fail("Could not get DisplayInfo\n");
             }
        else fail("Could not get DimensionInfo \n");
        }
    else fail("Could not get ViewPortExtra\n");

    /* This is for backwards compatibility with, for example,   */
    /* a 1.3 screen saver utility that looks at the Modes field */
    viewPort.Modes = (UWORD) (modeID & 0x0000ffff);
    }
