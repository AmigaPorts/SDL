/* Source: ADCD 2.1
 * Section: lib-examples-bob-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-bob-c.md
 */

        {
        if (NULL == (myBob = makeBob(&myNewBob)))
                return_code = RETURN_WARN;
        else
                {
                AddBob(myBob, win->RPort);
                bobDrawGList(win->RPort, ViewPortAddress(win));
                process_window(win, myBob);
                RemBob(myBob);
                bobDrawGList(win->RPort, ViewPortAddress(win));
                freeBob(myBob, myNewBob.nb_RasDepth);
                }
        cleanupGelSys(my_ginfo,win->RPort);
        }
