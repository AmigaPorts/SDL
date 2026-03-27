/* Source: ADCD 2.1
 * Section: 8-device-interface-opening-the-narrator-device
 * Library: devices
 * ADCD reference: devices/8-device-interface-opening-the-narrator-device.md
 */

    struct MsgPort *VoiceMP;
    struct narrator_rb *VoiceIO;

    if (VoiceMP = CreatePort("speech_write",0))
        if (VoiceIO = (struct narrator_rb *)
                        CreateExtIO(VoiceMP,sizeof(struct narrator_rb));
            if (OpenDevice("narrator.device", 0, VoiceIO, 0))
                    printf("narrator.device did not open\n");
