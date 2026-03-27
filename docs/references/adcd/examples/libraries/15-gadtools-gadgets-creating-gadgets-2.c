/* Source: ADCD 2.1
 * Section: 15-gadtools-gadgets-creating-gadgets
 * Library: libraries
 * ADCD reference: libraries/15-gadtools-gadgets-creating-gadgets.md
 */

    slidergad = CreateGadget(SLIDER_KIND, newgadget, prevgad,
        GTSL_Min, 0,
        GTSL_Max, 15,
        GTSL_Level, 11,
        GTSL_LevelFormat, "%2ld" /* printf()-style formatting string */
        GTSL_MaxLevelLen, 2,     /* maximum length of string         */
        TAG_END);
