/* Source: ADCD 2.1
 * Section: 8-device-interface-opening-the-narrator-device
 * Library: devices
 * ADCD reference: devices/8-device-interface-opening-the-narrator-device.md
 */

    struct  MsgPort   *MouthMP;
    struct  mouth_rb  *MouthIO;

    if (MouthMP = CreatePort("narrator_read", 0))
      if (!(MouthIO = (struct mouth_rb *)
                 AllocMem(sizeof(struct mouth_rb),MEMF_PUBLIC|MEMF_CLEAR)))
          {
          /* Copy I/O request used in OpenDevice */
          MouthIO->voice = *VoiceIO;
          /* Set port */
          MouthIO->voice.message.io_Message.mn_ReplyPort=MouthMP;
          }
      else
          printf("AllocMem failed\n");
    else
        printf("CreatePort failed\n");
