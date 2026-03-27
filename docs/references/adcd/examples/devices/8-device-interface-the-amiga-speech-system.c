/* Source: ADCD 2.1
 * Section: 8-device-interface-the-amiga-speech-system
 * Library: devices
 * ADCD reference: devices/8-device-interface-the-amiga-speech-system.md
 */

    #define BUFLEN 500

    APTR EnglStr;                   /* pointer to sample input string */
    LONG EnglLen;                   /* input length */
    UBYTE PhonBuffer[BUFLEN];       /* place to put the translation */
    LONG rtnCode;                   /* return code from function */

    struct narrator_rb *VoiceIO;    /* speaking I/O request block */
    struct mouth_rb *MouthIO;       /* mouth movement I/O request block */

    EnglStr = "This is Amiga speaking.";    /* a test string */
    EnglLen = strlen(EnglStr);
    rtnCode = Translate(EnglStr, EnglLen, (APTR)&PhonBuffer[0], BUFLEN);

    voice_io->message.io_Command = CMD_WRITE;
    voice_io->message.io_Offset  = 0;
    voice_io->message.io_Data    = PhonBuffer;
    voice_io->message.io_Length  = strlen(PhonBuffer);
    DoIO((struct IORequest *)VoiceIO)
