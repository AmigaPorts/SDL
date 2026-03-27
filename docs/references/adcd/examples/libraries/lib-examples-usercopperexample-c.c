/* Source: ADCD 2.1
 * Section: lib-examples-usercopperexample-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-usercopperexample-c.md
 */

        /*  Open the libraries, a screen and a window.  */
        ret_val = openAll();
        if (RETURN_OK == ret_val)
        {
                /*  Create and attach the user Copper list.  */
                ret_val = loadCopper();
                if (RETURN_OK == ret_val)
                {
                        /*  Wait until the user clicks in the close gadget.  */
                        (VOID) Wait(1<<window->UserPort->mp_SigBit);

                        while (intuiMessage = (struct IntuiMessage *)GetMsg(window->UserPort))
                                ReplyMsg((struct Message *)intuiMessage);
                }
        }
        cleanExit(ret_val);
