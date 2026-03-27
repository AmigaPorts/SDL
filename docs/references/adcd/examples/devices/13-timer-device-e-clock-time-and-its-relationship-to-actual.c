/* Source: ADCD 2.1
 * Section: 13-timer-device-e-clock-time-and-its-relationship-to-actual
 * Library: devices
 * ADCD reference: devices/13-timer-device-e-clock-time-and-its-relationship-to-actual.md
 */

              (struct IORequest *)TimerIO,0L)) )
    {
    TimerBase = (struct Library *)TimerIO->tr_node.io_Device;
    E_Freq =  ReadEClock((struct EClockVal *) time1); /* Get initial */
                                                      /*   reading   */

       /*  place operation to be measured here */

    E_Freq =  ReadEClock((struct EClockVal *) time2); /* Get 2nd reading */
    printf("\nThe operation took: %f fractions of a second\n",
            (time2->ev_lo-time1->ev_lo)/(double)E_Freq);

    CloseDevice( (struct IORequest *) TimerIO );
    }
