/* Source: ADCD 2.1
 * Section: devices-dev-examples-track-copy-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-track-copy-c.md
 */

    if (buffer=AllocMem(TRACK_SIZE,MEMF_CHIP|MEMF_PUBLIC))
    {
        printf(" Starting Motors\r");
        Motor_On(diskreq0);
        Motor_On(diskreq1);
        All_OK=TRUE;

        NumTracks=FindNumTracks(diskreq0);

        for (track=0;(track<NumTracks) && All_OK;track++)
        {
            printf(" Reading track %d\r",track);

            if (All_OK=Read_Track(diskreq0,buffer,track))
            {
                printf(" Writing track %d\r",track);

                All_OK=Write_Track(diskreq1,buffer,track);
            }
        }
        if (All_OK) printf(" * Copy complete *");
        printf("\n");
        Motor_Off(diskreq0);
        Motor_Off(diskreq1);
        FreeMem(buffer,TRACK_SIZE);
    }
    else printf("No memory for track buffer...\n");
