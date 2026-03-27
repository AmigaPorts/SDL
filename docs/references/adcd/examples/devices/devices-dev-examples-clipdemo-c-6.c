/* Source: ADCD 2.1
 * Section: devices-dev-examples-clipdemo-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-clipdemo-c.md
 */

    {
    sig_rcvd = Wait ((SIGBREAKF_CTRL_C | SIGBREAKF_CTRL_E));

    if (sig_rcvd & SIGBREAKF_CTRL_C)
        printf ("^C received\n");

    if (sig_rcvd & SIGBREAKF_CTRL_E)
        printf ("clipboard change, current ID is %ld\n", ch.ch_ClipID);

    CloseCB(clipIO);
    }
