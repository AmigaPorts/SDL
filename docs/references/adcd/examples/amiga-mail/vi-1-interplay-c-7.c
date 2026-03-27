/* Source: ADCD 2.1
 * Section: vi-1-interplay-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vi-1-interplay-c.md
 */

    {
    /* When two files are played at once, their speeds must match.  Use  */
    /* whichever speed is fastest. Interleaved requests also require the */
    /* speed to be doubled (period is halved).  However, the period      */
    /* cannot be lower than 124 or audio DMA bandwidth will be exceeded. */
    speedfac = inplay->sample_speed;

    if(inplay->next_iplay)
        {
        if(inplay->next_iplay->sample_speed < inplay->sample_speed)
            speedfac = inplay->next_iplay->sample_speed;

        if ( !(inplay->USE_SUMMING) )
            speedfac /= 2;
        }

    if(speedfac < 124)
        speedfac = 124;

    ioa->ioa_Request.io_Command = CMD_WRITE;
    ioa->ioa_Request.io_Flags   = ADIOF_PERVOL;
    ioa->ioa_Volume             = 63;
    ioa->ioa_Period             = speedfac;
    ioa->ioa_Length             = BUF_SIZE;
    ioa->ioa_Cycles             = 1;
    }
