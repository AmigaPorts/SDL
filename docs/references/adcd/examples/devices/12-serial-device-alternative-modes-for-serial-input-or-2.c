/* Source: ADCD 2.1
 * Section: 12-serial-device-alternative-modes-for-serial-input-or
 * Library: devices
 * ADCD reference: devices/12-serial-device-alternative-modes-for-serial-input-or.md
 */

    /* Precalculate a wait mask for the CTRL-C, CTRL-F and message
     * port signals.  When one or more signals are received,
     * Wait() will return.  Press CTRL-C to exit the example.
     * Press CTRL-F to wake up the example without doing anything.
     * NOTE: A signal may show up without an associated message!
     */

    WaitMask = SIGBREAKF_CTRL_C|
                SIGBREAKF_CTRL_F|
                 1L << SerialMP->mp_SigBit;

    SerialIO->IOSer.io_Command  = CMD_READ;
    SerialIO->IOSer.io_Length   = READ_BUFFER_SIZE;
    SerialIO->IOSer.io_Data     = (APTR)&SerialReadBuffer[0];
    SendIO(SerialIO);

    printf("Sleeping until CTRL-C, CTRL-F, or serial input\n");

    while (1)
           {
           Temp = Wait(WaitMask);
           printf("Just woke up (YAWN!)\n");

           if (SIGBREAKF_CTRL_C & Temp)
               break;

           if (CheckIO(SerialIO) ) /* If request is complete... */
               {
               WaitIO(SerialIO);   /* clean up and remove reply */
               printf("%ld bytes received\n",SerialIO->IOSer.io_Actual);
               break;
               }
           }
    AbortIO(SerialIO);  /* Ask device to abort request, if pending */
    WaitIO(SerialIO);   /* Wait for abort, then clean up */
