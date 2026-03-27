/* Source: ADCD 2.1
 * Section: v-15-fta-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/v-15-fta-c.md
 */

    tagitem[0].ti_Tag = TA_DeviceDPI;
    tagitem[0].ti_Data = MYXDPI | MYYDPI;
    tagitem[1].ti_Tag = TAG_END;


    if (DiskfontBase = OpenLibrary("diskfont.library", 36L))
    {
        if (UtilityBase = OpenLibrary("utility.library", 36L))
        {
            if (GfxBase = OpenLibrary("graphics.library", 36L))
            {
            	if (myfont = OpenDiskFont(&mytta))
                {
                    dpivalue = GetTagData(TA_DeviceDPI,
                                     0L,
                                     ((struct TextFontExtension *)(myfont->tf_Extension))->tfe_Tags);
                    if (dpivalue) printf("XDPI = %d    YDPI = %d\n",
                                    ((dpivalue & 0xFFFF0000)>>16),
                                    (dpivalue & 0x0000FFFF));
                    CloseFont(myfont);
                }
