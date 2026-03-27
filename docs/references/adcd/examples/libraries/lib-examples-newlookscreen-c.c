/* Source: ADCD 2.1
 * Section: lib-examples-newlookscreen-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-newlookscreen-c.md
 */

    {
    if (IntuitionBase->lib_Version >= 37)
        {
        /* The screen is opened two bitplanes deep so that the
        ** new look will show-up better.
        */
        if (NULL != (my_screen = OpenScreenTags(NULL,
                                     SA_Pens, (ULONG)pens,
                                     SA_Depth, 2,
                                     TAG_DONE)))
            {
            /* screen successfully opened */
            Delay(30L);  /* normally the program would be here */

            CloseScreen(my_screen);
            }
        }
    CloseLibrary(IntuitionBase);
    }
