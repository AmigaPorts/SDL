/* Source: ADCD 2.1
 * Section: 15-gadtools-gadgets-creating-gadget-lists
 * Library: libraries
 * ADCD reference: libraries/15-gadtools-gadgets-creating-gadget-lists.md
 */

    /* Assume that the NewGadget structure 'ng' is fully
     * initialized here for a button labelled "OK"
     */
    gad = CreateGadget(BUTTON_KIND, gad, &ng,
        TAG_END);

    /* Modify only those fields that need to change: */
    ng.ng_GadgetID++;
    ng.ng_LeftEdge += 80;
    ng.ng_GadgetText = "Cancel";
    gad = CreateGadget(BUTTON_KIND, gad, &ng,
                            TAG_END);

    Warning:
    --------
    All gadgets created by GadTools currently have the GADTOOL_TYPE bit
    set in their [GadgetType](../Libraries_Manual_guide/node0149.html#line58) field.  It is not correct to check for,
    set, clear or otherwise rely on this since it is subject to change.
