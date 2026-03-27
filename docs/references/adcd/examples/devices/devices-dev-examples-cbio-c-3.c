/* Source: ADCD 2.1
 * Section: devices-dev-examples-cbio-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-cbio-c.md
 */

    {
    /* Check to see if it starts with "FORM" */
    if (cbuff[0] == ID_FORM)
        {
        /* Check to see if its "FTXT" */
        if (cbuff[2] == ID_FTXT)
            return(TRUE);
        }

    /* It's not "FORM[size]FTXT", so tell clipboard we are done */
    }
