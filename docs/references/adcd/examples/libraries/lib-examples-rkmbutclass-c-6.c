/* Source: ADCD 2.1
 * Section: lib-examples-rkmbutclass-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rkmbutclass-c.md
 */

    struct TagItem tt[3];

    tt[0].ti_Tag = RKMBUT_Pulse;
    tt[0].ti_Data = mid - ((gpi->gpi_Mouse).X + ((struct Gadget *)o)->LeftEdge);

    tt[1].ti_Tag = GA_ID;
    tt[1].ti_Data = ((struct Gadget *)o)->GadgetID;

    tt[2].ti_Tag = TAG_DONE;

    DoSuperMethod(cl, o, OM_NOTIFY, tt, gpi->gpi_GInfo, flags);
