/* Source: ADCD 2.1
 * Section: lib-examples-openwindowtags-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-openwindowtags-c.md
 */

    {
    win = OpenWindowTagList(NULL,win_tags);
    if (win==NULL)
        {
        /* window failed to open */
        }
    else
        {
        /* window successfully opened here */
        handle_window_events(win);

        CloseWindow(win);
        }
    CloseLibrary((struct Library *)IntuitionBase);
    }
