/* Source: ADCD 2.1
 * Section: 15-gadtools-gadgets-creating-gadget-lists
 * Library: libraries
 * ADCD reference: libraries/15-gadtools-gadgets-creating-gadget-lists.md
 */

    gad = CreateGadget(STRING_KIND, gad, &ng,
                            GTST_String, "Hello World",
                            TAG_END);
    if (gad)
        {
        stringbuffer = ((struct StringInfo *)(gad->SpecialInfo))->Buffer;
        }

    /* Creation can continue here: */
    gad = CreateGadget(..._KIND, gad, &ng2,
        ...
        TAG_END);
