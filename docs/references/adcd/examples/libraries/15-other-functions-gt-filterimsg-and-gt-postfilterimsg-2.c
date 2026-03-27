/* Source: ADCD 2.1
 * Section: 15-other-functions-gt-filterimsg-and-gt-postfilterimsg
 * Library: libraries
 * ADCD reference: libraries/15-other-functions-gt-filterimsg-and-gt-postfilterimsg.md
 */

    /* port is a message port receiving different messages */
    /* gtwindow is the window that contains GadTools gadgets */

    imsg = GetMsg(port);

    /* Is this the window with GadTools gadgets? */
    if (imsg->IDCMPWindow == gtwindow)
        {
        /* Filter the message and see if action is needed */
        if (gtimsg = GT_FilterIMsg(imsg))
            {
            switch (gtimsg->Class)
                {
                /* Act depending on the message */
                ...
                }
            /* Clean up the filtered message.  The return value is not */
            /* needed since we already have a pointer to the original  */
            /* message.                                                */
            GT_PostFilterIMsg(gtimsg);
            }
        }
    /* other stuff can go here */
    ReplyMsg(imsg);
