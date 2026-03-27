/* Source: ADCD 2.1
 * Section: devices-dev-examples-clipdemo-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-clipdemo-c.md
 */

    {
    ULONG hookEntry ();

    /* Fill out the IORequest */
    clipIO->io_Data = (char *) &hook;
    clipIO->io_Length = 1;
    clipIO->io_Command = CBD_CHANGEHOOK;

    /* Set up the hook data */
    ch.ch_Task = FindTask (NULL);

    /* Prepare the hook */
    hook.h_Entry = hookEntry;
    hook.h_SubEntry = clipHook;
    hook.h_Data = &ch;

    /* Start the hook */
    if (DoIO (clipIO))
        printf ("unable to set hook\n");
    else
        printf ("hook set\n");

    /* Return success */
    return ( clipIO );
    }
