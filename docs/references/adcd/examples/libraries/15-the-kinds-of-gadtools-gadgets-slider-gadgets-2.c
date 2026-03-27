/* Source: ADCD 2.1
 * Section: 15-the-kinds-of-gadtools-gadgets-slider-gadgets
 * Library: libraries
 * ADCD reference: libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md
 */

    /* NewGadget initialized here. Note the three spaces
     * after "Slider:", to allow a blank plus the two digits
     * of the level display
     */
    ng.ng_Flags = PLACETEXT_LEFT;
    ng.ng_GadgetText = "Slider:   ";

    LONG DepthToColors(struct Gadget *gad, WORD level)
    {
    return ((WORD)(1 << level));
    }

    ...

    gad = CreateGadget(SLIDER_KIND, gad, &ng,
        GTSL_Min, 1,
        GTSL_Max, 5,
        GTSL_Level, current_depth,
        GTSL_MaxLevelLen, 2,
        GTSL_LevelFormat, "%2ld",
        GTSL_DispFunc, DepthToColors,
        TAG_END);
