/* Source: ADCD 2.1
 * Section: 19-exec-device-i-o-devices-with-functions
 * Library: libraries
 * ADCD reference: libraries/19-exec-device-i-o-devices-with-functions.md
 */

    /* Create the I/O request.  */
    if ( TimerIO = (struct timerequest *)
         CreateExtIO(TimerMP,sizeof(struct timerequest)) )
    {
        /* Open the timer device.  */
        if ( !(OpenDevice(TIMERNAME,UNIT_MICROHZ,TimerIO,0)) )
        {
            /* Set up pointer for timer functions.  */
            TimerBase = (struct Library *)TimerIO->tr_node.io_Device;

            /* Use timer device library-style functions such as /*
            /* CmpTime() ...*/

            CloseDevice(TimerIO);     /* Close the timer device. */
        }
        else
            printf("Error: Could not open %s\n",TIMERNAME);
    }
    else
        printf("Error: Could not create I/O request\n");
