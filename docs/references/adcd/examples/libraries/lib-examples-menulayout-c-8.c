/* Source: ADCD 2.1
 * Section: lib-examples-menulayout-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-menulayout-c.md
 */

    {
    itext = (struct IntuiText *)cur_item->ItemFill;
    total_textlen = extra_width + itext->LeftEdge +
          TextLength(textRPort, itext->IText, strlen(itext->IText));

    /* returns the greater of the two */
    if (total_textlen > maxLength)
        maxLength = total_textlen;
    }
