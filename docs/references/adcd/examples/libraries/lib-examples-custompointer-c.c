/* Source: ADCD 2.1
 * Section: lib-examples-custompointer-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-custompointer-c.md
 */

    {
    /* the window is opened as active (WA_Activate) so that the busy
    ** pointer will be visible.  If the window was not active, the
    ** user would have to activate it to see the change in the pointer.
    */
    if (win = OpenWindowTags(NULL,
                             WA_Activate, TRUE,
                             TAG_END))
        {
        /* a NULL requester can be used to block input
        ** in a window without any imagery provided.
        */
        InitRequester(&null_request);

        Delay(50);  /* simulate activity in the program. */

        /* Put up the requester to block user input in the window,
        ** and set the pointer to the busy pointer.
        */
        if (Request(&null_request, win))
            {
            SetPointer(win, waitPointer, 16, 16, -6, 0);

            Delay(100);  /* simulate activity in the program. */

            /* clear the pointer (which resets the window to the default
            ** pointer) and remove the requester.
            */
            ClearPointer(win);
            EndRequest(&null_request, win);
            }

        Delay(100);  /* simulate activity in the program. */

        CloseWindow(win);
        }
    CloseLibrary(IntuitionBase);
    }
