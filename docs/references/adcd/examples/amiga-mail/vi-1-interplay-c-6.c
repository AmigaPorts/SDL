/* Source: ADCD 2.1
 * Section: vi-1-interplay-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vi-1-interplay-c.md
 */

    {
    /* In case the VHDR came after the BODY, seek back to the BODY */
    if(play->offsetBody)
        {
        rdcount = Seek(filehandle, play->offsetBody, OFFSET_BEGINNING);
        if(rdcount==-1)
            error="Couldn't seek to BODY\n";
        }

    /* OK now get the BODY data into a memory block */
    play->sample_loc = AllocMem( play->sample_size, MEMF_PUBLIC );
    if(play->sample_loc)
        {
        rdcount = Read(filehandle, play->sample_loc, play->sample_size);
        if(rdcount!=play->sample_size)
            error = "Error during BODY read\n";
        else
            play->sample_byte=play->sample_loc;
        }
    else
        error="Couldn't get memory for BODY Chunk\n";
    }
