/* Source: ADCD 2.1
 * Section: devices-dev-examples-clipdemo-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-clipdemo-c.md
 */

    {

    /* Open clipboard.device unit 0 */

    if (ior = CBOpen(0L))
        {
        mustwrite = FALSE;

        /* Notify clipboard we have data */

        ior->io_Data    = (STRPTR)satisfy;
        ior->io_ClipID  = 0L;
        ior->io_Command = CBD_POST;
        DoIO( (struct IORequest *) ior);

        postID = ior->io_ClipID;

        printf("\nClipID = %ld\n",postID);

        /* Wait for CTRL-C break, or message from clipboard */
        Wait(SIGBREAKF_CTRL_C|(1L << satisfy->mp_SigBit));

        /* see if we got a message, or a break */
        puts("Woke up");


        if (sm = (struct SatisfyMsg *)GetMsg(satisfy))
            {
            puts("Got a message from the clipboard\n");

            /* We got a message - we MUST write some data */
            mustwrite = TRUE;
            }
        else
            {
            /* Determine if we must write before exiting by
             * checking to see if our POST is still valid
             */

            ior->io_Command = CBD_CURRENTWRITEID;
            DoIO( (struct IORequest *) ior);

            printf("CURRENTWRITEID = %ld\n",ior->io_ClipID);

            if (postID >= ior->io_ClipID)
                mustwrite = TRUE;

            }

        /* Write the string of text */

        if (mustwrite)
            {
            if (!(CBWriteFTXT(ior,string)))
                puts("Error writing to clipboard");
            }
        else
            {
            puts("No need to write to clipboard");
            }

        CBClose(ior);
        }
    else
        {
        puts("Error opening clipboard.device");
        }

    DeletePort(satisfy);
    }
