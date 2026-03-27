/* Source: ADCD 2.1
 * Section: 24-messages-waiting-for-a-message
 * Library: libraries
 * ADCD reference: libraries/24-messages-waiting-for-a-message.md
 */

    struct XYMessage *xy_msg;
    struct MsgPort   *xyport;

    xyport = CreatePort("xyport", 0);
    if (xyport == 0)
    {
        printf("Couldn't create xyport\n");
        exit(31);
    }

    xy_msg = WaitPort(xyport);     /* go to sleep until message arrives */
