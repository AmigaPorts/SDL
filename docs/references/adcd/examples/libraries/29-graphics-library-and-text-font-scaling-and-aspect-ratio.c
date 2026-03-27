/* Source: ADCD 2.1
 * Section: 29-graphics-library-and-text-font-scaling-and-aspect-ratio
 * Library: libraries
 * ADCD reference: libraries/29-graphics-library-and-text-font-scaling-and-aspect-ratio.md
 */

    #define MYXDPI (75L << 16)
    #define MYYDPI (50L)

    struct TTextAttr mytta = {
        "topaz.font", 9,
        FSF_TAGGED,   0, NULL
    };

    struct TagItem tagitem[2];
    struct TextFont *myfont;
    ULONG dpivalue;

     . . .

    tagitem[0].ti_tag = TA_DeviceDPI;
    tagitem[0].ti_Data = MYXDPI | MYYDPI;
    tagitem[1].ti_tag = TAG_END;
    mytta.tta_tags = tagitem;

     . . .

    if (myfont = OpenDiskFont(&mytta))
    {
        dpi = GetTagData(TA_DeviceDPI,
                         OL,
                         ((struct TextFontExtension *)
                          (myfont->tf_Extension))->tfe_Tags);
        if (dpi) printf("XDPI = %d    YDPI = %d\n",
                        ((dpi & 0xFFFF0000)>>16),
                        (dpi & 0x0000FFFF));
              . . .                             /* Blah Blah print blah */

        CloseFont(myfont);
    }
