/* Source: ADCD 2.1
 * Section: devices-dev-examples-read-battclock-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-read-battclock-c.md
 */

    {
    if (BattClockBase= OpenResource(BATTCLOCKNAME))
        {
        /* Get number of seconds till now */
        AmigaTime = ReadBattClock();

        /* Convert to a ClockData structure */
        Amiga2Date(AmigaTime,&MyClock);

        printf("\nRobin, tell everyone the BatDate and BatTime");

        /* Print the Date */
        printf("\n\nOkay Batman, the BatDate is ");
        printf("%s, %s %d, %d",Days[MyClock.wday],Months[MyClock.month-1],
                               MyClock.mday,MyClock.year);

        /* Convert military time to normal time and set AM/PM */
        if (MyClock.hour < 12)
            ampm = "AM";        /* hour less than 12, must be morning */
        else
            {
            ampm = "PM";         /* hour greater than 12,must be night */
            MyClock.hour -= 12;  /* subtract the extra 12 of military */
            };

        if (MyClock.hour == 0)
            MyClock.hour = 12;   /* don't forget the 12s */

        /* Print the time */
        printf("\n             the BatTime is ");
        printf("%d:%02d:%02d %s\n\n",MyClock.hour,MyClock.min,MyClock.sec,ampm);
        }
    else
       printf("Error: Unable to open the %s\n",BATTCLOCKNAME);

    /* Close the utility library */
    CloseLibrary(UtilityBase);
    }
