/* Source: ADCD 2.1
 * Section: 15-gadtools-gadgets-modifying-gadgets
 * Library: libraries
 * ADCD reference: libraries/15-gadtools-gadgets-modifying-gadgets.md
 */

    /* Disable a button gadget */
    GT_SetGadgetAttrs(buttongad, win, NULL,
                            GA_Disabled, TRUE,
                            TAG_END);

    /* Change a slider's range to be 1 to 100, currently at 50 */
    GT_SetGadgetAttrs(slidergad, win, NULL,
                            GTSL_Min, 1,
                            GTSL_Max, 100,
                            GTSL_Level, 50,
                            TAG_END);

    /* Add a node to the head of listview's list, and make it */
    /* the selected one */
    GT_SetGadgetAttrs(listviewgad, win, NULL,
                            /* detach list before modifying */
                            GTLV_Labels, ~0,
                            TAG_END);
    AddHead(&lvlabels, &newnode);
    GT_SetGadgetAttrs(listviewgad, win, NULL,
                            /* re-attach list */
                            GTLV_Labels, &lvlabels,
                            GTLV_Selected, 0,
                            TAG_END);
