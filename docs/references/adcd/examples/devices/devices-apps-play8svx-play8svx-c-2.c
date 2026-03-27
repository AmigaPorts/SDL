/* Source: ADCD 2.1
 * Section: devices-apps-play8svx-play8svx-c
 * Library: devices
 * ADCD reference: devices/devices-apps-play8svx-play8svx-c.md
 */

    {
    LONG error = 0L;
    BYTE *buf;
    Voice8Header *vhdr;

    if(!esvx)			return(CLIENT_ERROR);
    if(!(buf = esvx->sample))	return(CLIENT_ERROR);

    /* LoadSample copied VHDR and NAME (if any) to our esvx frame */
    vhdr = &esvx->Vhdr;
    if(esvx->name[0]) printf("\nNAME: %s",esvx->name);

    printf("\n\nVHDR Info:");
    printf("\noneShotHiSamples=%ld", vhdr->oneShotHiSamples);
    printf("\nrepeatHiSamples=%ld", vhdr->repeatHiSamples);
    printf("\nsamplesPerHiCycle=%ld", vhdr->samplesPerHiCycle);
    printf("\nsamplesPerSec=%ld", vhdr->samplesPerSec);
    printf("\nctOctave=%ld", vhdr->ctOctave);
    printf("\nsCompression=%ld", vhdr->sCompression);
    printf("\nvolume=0x%lx", vhdr->volume);
    printf("\nData = %3ld %3ld %3ld %3ld %3ld %3ld %3ld %3ld",
           buf[0],buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7]);
    printf("\n       %3ld %3ld %3ld %3ld %3ld %3ld %3ld %3ld ...\n",
           buf[8+0],buf[8+1],buf[8+2],buf[8+3],buf[8+4],buf[8+5],
           buf[8+6],buf[8+ 7]);

    return(error);
    }
