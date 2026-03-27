/* Source: ADCD 2.1
 * Section: vi-1-interplay-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vi-1-interplay-c.md
 */

    {
    play1=inplay;
    play2=inplay->next_iplay;

    remainder1 = play1->sample_size - (play1->sample_byte - play1->sample_loc);
    remainder2 = play2->sample_size - (play2->sample_byte - play2->sample_loc);

    if(play1->USE_SUMMING)
        {
        /*
        ** AVERAGING LOGIC for playing TWO samples on ONE channel
        */
        for(x=0; x<BUF_SIZE ;x++)
            {
            value = 0;

            if( x<remainder1 )
                {
                value += *( (BYTE *)(play1->sample_byte) );
                play1->sample_byte++;
                }
            else if( x==remainder1 )
                play1->sample_done=1;

            if( x<remainder2 )
                {
                value += *( (BYTE *)(play2->sample_byte) );
                play2->sample_byte++;
                }
            else if( x==remainder2 )
                play2->sample_done=1;

            *(ioa->ioa_Data + x) = (UBYTE) (value/2);
            }
        }
    else
        {
        /*
        ** INTERLEAVE LOGIC for playing TWO samples on ONE channel
        */

        /* If there are more bytes in the 1st sample data file, place them in */
        /* the EVEN positions in the playback buffer of this IOAudio request. */
        for(x=0; (x<BUF_SIZE) && (x<2*remainder1); x+=2 )
            {
            *(ioa->ioa_Data + x) = *(play1->sample_byte);
            play1->sample_byte++;
            }
        /* If there are no more bytes then mark the 1st sample as done */
        if(x<BUF_SIZE)
            play1->sample_done=1L;

        while(x<BUF_SIZE)      /* Pad the playback buffer with zeroes. */
            {
            *(ioa->ioa_Data + x) = 0;
            x+=2;
            }

        /* If there are more bytes in the 2nd sample data file, place them in */
        /* the ODD positions in the playback buffer of this IOAudio request.  */
        for(x=1; (x<BUF_SIZE) && (x<2*remainder2);x+=2)
            {
            *(ioa->ioa_Data + x) = *(play2->sample_byte);
            play2->sample_byte++;
            }
        /* If there are no more bytes then mark the 2nd sample as done */
        if(x<BUF_SIZE)
            play2->sample_done=1L;

        while(x<BUF_SIZE)      /* Pad the playback buffer with zeroes. */
            {
            *(ioa->ioa_Data + x) = 0;
            x+=2;
            }
        }
    }
