/* Source: ADCD 2.1
 * Section: lib-examples-menulayout-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-menulayout-c.md
 */

    {
    if (cur_item->Flags & COMMSEQ)
        {
        commCharWidth = TextLength(textRPort,&(cur_item->Command),1);
        if (commCharWidth > maxCommCharWidth)
            maxCommCharWidth = commCharWidth;
        }
    }
