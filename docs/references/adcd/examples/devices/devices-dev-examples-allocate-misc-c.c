/* Source: ADCD 2.1
 * Section: devices-dev-examples-allocate-misc-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-allocate-misc-c.md
 */

    /* Allocate both pieces of the serial hardware */
    if ((owner = AllocMiscResource(MR_SERIALPORT,"Serial Port Hog")) == NULL)
        {
        if ((owner = AllocMiscResource(MR_SERIALBITS,"Serial Port Hog")) == NULL)
            {
            /* Wait for CTRL-C to be pressed */
            printf("\nWaiting for CTRL-C...\n");
            Wait(SIGBREAKF_CTRL_C);

            /* We're back */

            /* Deallocate the serial port register */
            FreeMiscResource(MR_SERIALBITS);
            }
        else
            printf("\nUnable to allocate MR_SERIALBITS because %s owns it\n",owner);

        /* Deallocate the serial port */
        FreeMiscResource(MR_SERIALPORT);
       }
    else
       printf("\nUnable to allocate MR_SERIALPORT because %s owns it\n",owner);
