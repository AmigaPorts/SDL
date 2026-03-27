/* Source: ADCD 2.1
 * Section: vi-1-interplay-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vi-1-interplay-c.md
 */

    {
    /* Read the first 8 bytes of the Chunk to get the type and size */
    rdcount =Read( filehandle, iobuffer, 8L );
    if(rdcount==8L)
        {
        pChunk=(Chunk *)iobuffer;
        switch(pChunk->ckID)
            {

            case ID_VHDR:
                /* AllocMem() ckSize rounded up and read */
                /* the VHDR, filling in the InterPlay */
                if(pChunk->ckSize & 1L)
                    pChunk->ckSize++;

                pV8Head = AllocMem(pChunk->ckSize, MEMF_PUBLIC);
                if(pV8Head)
                    {
                    rdcount=Read(filehandle,pV8Head,pChunk->ckSize);
                    if(rdcount==pChunk->ckSize )
                        {
                        if(pV8Head->sCompression==sCmpNone)
                            {
                            /* Set the playback speed */
                            play->sample_speed = (UWORD)
                                        (3579545L / pV8Head->samplesPerSec);

                            /* Set up start, end of sample data */
                            play->sample_size = pV8Head->oneShotHiSamples
                                                   + pV8Head->repeatHiSamples;
                            }
                        else error="Can't read compressed file\n";
                        }
                    else error="Read problem in header\n";

                    FreeMem(pV8Head, pChunk->ckSize );
                    }
                else error="Couldn't get header memory\n";
                NO_VHDR = FALSE;
                break;

            case ID_BODY:
                /* Technically, a VHDR could come after a BODY.*/
                /* This is a pretty unlikely occurence though. */
                if(NO_VHDR)
                    {
                    if(pChunk->ckSize & 1L)
                        pChunk->ckSize++;

                    rdcount = Seek(filehandle, pChunk->ckSize, OFFSET_CURRENT);
                    if(rdcount==-1)
                        error="Problem during BODY-skipping seek\n";
                    else
                        play->offsetBody=rdcount;
                    }
                NO_BODY = FALSE;
                break;

            default:
                /* Ignore other Chunks, skipping over them */
                if(pChunk->ckSize & 1L)
                    pChunk->ckSize++;

                rdcount = Seek(filehandle, pChunk->ckSize, OFFSET_CURRENT);
                if(rdcount==-1)
                    error="Problem during chunk-skipping seek\n";
                break;
            }
        }
    else error = "Read error or file too short2\n";
    }
