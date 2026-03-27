/* Source: ADCD 2.1
 * Section: lib-examples-usercopperexample-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-usercopperexample-c.md
 */

        if (NULL != screen)
        {
                if (NULL != window)
                {
                        viewPort = ViewPortAddress(window);
                        if (NULL != viewPort->UCopIns)
                        {
                                /*  Free the memory allocated for the Copper.  */
                                FreeVPortCopLists(viewPort);
                                RemakeDisplay();
                        }
                        CloseWindow(window);
                }
                CloseScreen(screen);
        }
        CloseLibrary((struct Library *)IntuitionBase);
