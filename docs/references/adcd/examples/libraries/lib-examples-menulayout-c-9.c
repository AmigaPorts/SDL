/* Source: ADCD 2.1
 * Section: lib-examples-menulayout-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-menulayout-c.md
 */

    {
    cur_item->TopEdge  = (item_num * height) - level;
    cur_item->LeftEdge = left_edge;
    cur_item->Width    = strip_width;
    cur_item->Height   = height;

    /* place the sub_item 3/4 of the way over on the item. */
    subitem_edge = strip_width - (strip_width >> 2);

    setITextAttr((struct IntuiText *)cur_item->ItemFill, textAttr);
    adjustItems(textRPort,cur_item->SubItem,textAttr,char_size,height,1,subitem_edge);
    }
