/* Source: ADCD 2.1
 * Section: 2-device-interface-opening-the-audio-device
 * Library: devices
 * ADCD reference: devices/2-device-interface-opening-the-audio-device.md
 */

      {
      AudioIO = (struct IOAudio *)
                AllocMem(sizeof(struct IOAudio), MEMF_PUBLIC | MEMF_CLEAR);
      if (AudioIO)
          {
          AudioIO->ioa_Request.io_Message.mn_ReplyPort  = AudioMP;
          AudioIO->ioa_AllocKey                         = 0;
          }

      if (OpenDevice(AUDIONAME,0L,(struct IORequest *)AudioIO,0L) )
          printf("%s did not open\n",AUDIONAME);
