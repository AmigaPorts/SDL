/* Source: ADCD 2.1
 * Section: 29-the-text-function-setting-the-font-style
 * Library: libraries
 * ADCD reference: libraries/29-the-text-function-setting-the-font-style.md
 */

    /* Set the font and add software styling to the text if I asked for
       a style in OpenFont() and didn't get it.  Because most Amiga fonts
       do not have styling built into them (with the exception of the CG
       outline fonts), if the user selected some kind of styling for the
       text, it will have to be added algorithmically by calling
       SetSoftStyle().
    */
    if (myfont = OpenDiskFont(mytextattr))
    {
            SetFont(myrastport, myfont);
            SetSoftStyle(myrastport,
                         mytextattr.ta_Style ^ myfont->tf_Style,
                         (FSF_BOLD | FSF_UNDERLINED | FSF_ITALIC));
    ...
    ...
            CloseFont(myfont);
    }
