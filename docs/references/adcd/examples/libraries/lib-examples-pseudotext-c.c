/* Source: ADCD 2.1
 * Section: lib-examples-pseudotext-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-pseudotext-c.md
 */

    struct TextAttr myta = {
        "topaz.font"
        11,
        FSF_ITALIC | FSF_BOLD,
        NULL
    };

    struct TextFont *myfont, *oldfont;
    struct RastPort *myrp;
    struct Window   *mywin;

    . . .

    /* open the graphics and diskfont libraries and whatever else you may need */
    . . .

    if (myfont = OpenDiskFont(&myta))
    {
        /* you would probably set the font of the rastport you are going to use */
        myrp    = mywin->RPort
        oldfont = myrp->Font;
        SetFont(myrp, myfont);

        . . .

        /* perform whatever drawing you need to do */

        . . .

        /* time to clean up.  If the rastport is not exclusively yours,
           you may need to restore the original font or other Rasport values */
        SetFont(myrp, oldfont);
        CloseFont(myfont);
    }

    /* close whatever libraries and other resources you allocated */
