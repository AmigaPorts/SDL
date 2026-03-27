/* Source: ADCD 2.1
 * Section: devices-dev-examples-speak-narrator-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-speak-narrator-c.md
 */

    {
    /*Set the NEWIORB bit in the flags field to use the new fields*/
    VoiceIO->flags = NDF_NEWIORB;

    /* Open the narrator device */
    if (OpenDevice("narrator.device",0,(struct IORequest *)VoiceIO,0L))
        /* Inform user that it could not be opened */
        printf("Error: narrator.device did not open\n");
    else
        {
         /* Speak the string using the default parameters */
         VoiceIO->ch_masks = &audio_chan[0];
         VoiceIO->nm_masks = sizeof(audio_chan);
         VoiceIO->message.io_Command = CMD_WRITE;
         VoiceIO->message.io_Data = PhoneticText;
         VoiceIO->message.io_Length = strlen(PhoneticText);
         DoIO(VoiceIO);

         /* Now change some of the characteristics:
          *    Raise the first formant, lower the third formant,
          *    and move 50% of the way towards AO.
          * and speak it again.
          */

        VoiceIO->A1adj = -32;          /* Shut off first formant  */
        VoiceIO->A3adj =  11;          /* Raise the third formant */
        VoiceIO->centralize = 50;      /* Move 50% of the way     */
        VoiceIO->centphon = "AO";      /* towards AO              */
        DoIO(VoiceIO);

        /* Close the narrator device */
        CloseDevice((struct IORequest *)VoiceIO);
        }
    /* Delete the IORequest */
    DeleteIORequest(VoiceIO);
    }
