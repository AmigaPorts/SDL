/* Source: ADCD 2.1
 * Section: 3-clipboard-device-monitoring-clipboard-changes
 * Library: devices
 * ADCD reference: devices/3-clipboard-device-monitoring-clipboard-changes.md
 */

    ULONG HookEntry ();            /* Declare the hook assembly function */
    struct IOClipReq *ClipIO;      /* Declare the IOClipReq */
    struct Hook *ClipHook;         /* Declare the Hook */

    /* Prepare the hook */
    ClipHook->h_Entry = HookEntry; /* C intrfce in asmbly rout. HookEntry*/
    ClipHook->h_SubEntry = HookFunc;/* Call function when Hook activated */
    ClipHook->h_Data = FindTask(NULL);/* Set pointer to current task */

    ClipIO->io_Data = (char *) ClipHook;/* Point to hook struct */
    ClipIO->io_Length = 1;              /* Add hook to clipboard */
    ClipIO->io_Command = CBD_CHANGEHOOK;
    DoIO(clipIO);
