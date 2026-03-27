/* Source: ADCD 2.1
 * Section: vi-1-interplay-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vi-1-interplay-c.md
 */

    {
    myAIOreply=CreatePort(0,0);
    if(myAIOreply)
        {
        myAIOreq->ioa_Request.io_Message.mn_ReplyPort   = myAIOreply;
        myAIOreq->ioa_Request.io_Message.mn_Node.ln_Pri = 127;
        myAIOreq->ioa_Request.io_Command                = ADCMD_ALLOCATE;
        myAIOreq->ioa_AllocKey                          = 0;
        myAIOreq->ioa_Data                              = chans;
        myAIOreq->ioa_Length                            = sizeof(chans);

        dev=OpenDevice("audio.device",0L,(struct IORequest *)myAIOreq,0L);

       if(! dev)
            return( myAIOreq ); /* Successful exit */

        DeletePort( myAIOreply );
        }
    FreeMem( myAIOreq, sizeof(struct IOAudio) );
    }
