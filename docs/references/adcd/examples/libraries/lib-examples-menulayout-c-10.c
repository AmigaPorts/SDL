/* Source: ADCD 2.1
 * Section: lib-examples-menulayout-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-menulayout-c.md
 */

    {
    SetFont(&textrp, font);       /* Put font into temporary RastPort */

    char_size = TextLength(&textrp, "n", 1);    /* Get the Width of the Font */

    /* To prevent crowding of the Amiga key when using COMMSEQ, don't allow the items to be less
    ** than 8 pixels high.  Also, add an extra pixel for inter-line spacing.
    */
    if (font->tf_YSize > 8)
        height = 1 + font->tf_YSize;
    else
        height = 1 + 8;

    start = 2;      /* Set Starting Pixel */

    /* Step thru the menu structure and adjust it */
    for (cur_menu = first_menu; cur_menu != NULL; cur_menu = cur_menu->NextMenu)
        {
        cur_menu->LeftEdge = start;
        cur_menu->Width = char_size +
            TextLength(&textrp, cur_menu->MenuName, strlen(cur_menu->MenuName));
        adjustItems(&textrp, cur_menu->FirstItem, textAttr, char_size, height, 0, 0);
        start += cur_menu->Width + char_size + char_size;
        }
    CloseFont(font);              /* Close the Font */
    returnValue = TRUE;
    }
