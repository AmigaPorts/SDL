/* Source: ADCD 2.1
 * Section: 2-device-interface-opening-the-audio-device
 * Library: devices
 * ADCD reference: devices/2-device-interface-opening-the-audio-device.md
 */

    UBYTE chans[] = {1,2,4,8};  /* get any of the four channels */

    if (AudioIO)
        {
        AudioIO->ioa_Request.io_Message.mn_ReplyPort  = AudioMP;
        AudioIO->ioa_AllocKey                         = 0;
        AudioIO->ioa_Request.io_Message.mn_Node.ln_Pri= 120;
        AudioIO->ioa_Data                             = chans;
        AudioIO->ioa_Length                           = sizeof(chans);
        }

    if (OpenDevice(AUDIONAME,0L,(struct IORequest *)AudioIO,0L) )
        printf("%s did not open\n",AUDIONAME);
