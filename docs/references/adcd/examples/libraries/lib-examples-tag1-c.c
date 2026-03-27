/* Source: ADCD 2.1
 * Section: lib-examples-tag1-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-tag1-c.md
 */

    struct TagItem *tags;
    struct Window  *win;

    /* For this example we need Version 2.0 */
    if (IntuitionBase = OpenLibrary ("intuition.library", 37))
    {
        /* We need the utility library for this example */
        if (UtilityBase = OpenLibrary ("utility.library", 37))
        {

        /****************************************************************/
        /* This section allocates a tag array, fills it in with values, */
        /* and then uses it.                                            */
        /****************************************************************/

            /* Allocate a tag array */
            if (tags = AllocateTagItems (7))
            {
                /* Fill in our tag array */
                tags[0].ti_Tag = WA_Width;
                tags[0].ti_Data = 320;
                tags[1].ti_Tag = WA_Height;
                tags[1].ti_Data = 50;
                tags[2].ti_Tag = WA_Title;
                tags[2].ti_Data = (ULONG) "RKM Tag Example 1";
                tags[3].ti_Tag = WA_IDCMP;
                tags[3].ti_Data = IDCMP_CLOSEWINDOW;
                tags[4].ti_Tag = WA_CloseGadget;
                tags[4].ti_Data = TRUE;
                tags[5].ti_Tag = WA_DragBar;
                tags[5].ti_Data = TRUE;
                tags[6].ti_Tag = TAG_DONE;

                /* Open the window, using the tag attributes as the
                 * only description. */
                if (win = OpenWindowTagList (NULL, tags))
                {
                    /* Wait for an event to occur */
                    WaitPort (win->UserPort);

                    /* Close the window now that we're done with it */
                    CloseWindow (win);
                }

                /* Free the tag list now that we're done with it */
                FreeTagItems(tags);
            }

        /****************************************************************/
        /* This section builds the tag array on the stack, and passes   */
        /* the array to a function.                                     */
        /****************************************************************/

            /* Now use the VarArgs (or stack based) version. */
            if (win = OpenWindowTags ( NULL,
                                       WA_Width, 320,
                                       WA_Height, 50,
                                       WA_Title, (ULONG)"RKM Tag Example 1",
                                       WA_IDCMP, IDCMP_CLOSEWINDOW,
                                       WA_CloseGadget, TRUE,
                                       WA_DragBar, TRUE,
                                       TAG_DONE))
            {
                /* Wait for an event to occur */
                WaitPort (win->UserPort);

                /* Close the window now that we're done with it */
                CloseWindow (win);
            }

            /* Close the library now */
            CloseLibrary (UtilityBase);
        }

        /* Close the library now that we're done with it */
        CloseLibrary (IntuitionBase);
    }
