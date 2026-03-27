/* Source: ADCD 2.1
 * Section: where-do-the-x-and-y-dpi-values-come-from
 * Library: amiga-mail
 * ADCD reference: amiga-mail/where-do-the-x-and-y-dpi-values-come-from.md
 */

     if (myfont = OpenDiskFont(&mytta))
     {
        dpivalue = GetTagData(TA_DeviceDPI,
           0L,
           ((struct TextFontExtension *)(myfont->tf_Extension))->tfe_Tags);
        if (dpivalue) printf("XDPI = %d    YDPI = %d\n",
                        ((dpivalue & 0xFFFF0000)>>16),
                        (dpivalue & 0x0000FFFF));
        /* blah, blah, render some text, blah, blah */
        ...

       CloseFont(myfont);
