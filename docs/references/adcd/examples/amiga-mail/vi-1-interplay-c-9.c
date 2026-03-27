/* Source: ADCD 2.1
 * Section: vi-1-interplay-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vi-1-interplay-c.md
 */

    {
    /*
    ** REGULAR LOGIC for playing a single sample on a single channel.
    */
    remainder1= inplay->sample_size - (inplay->sample_byte-inplay->sample_loc);
    if(remainder1 > BUF_SIZE)
        {
        CopyMem(inplay->sample_byte,ioa->ioa_Data,BUF_SIZE);
        inplay->sample_byte+=BUF_SIZE;
        }
    else
        {
        CopyMem(inplay->sample_byte,ioa->ioa_Data,remainder1);
        ioa->ioa_Length=remainder1;
        inplay->sample_done=1L;
        }
    }
