/* Source: ADCD 2.1
 * Section: vi-1-interplay-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vi-1-interplay-c.md
 */

    {
    CloseDevice( (struct IORequest *) rel );

    if(rel->ioa_Request.io_Message.mn_ReplyPort)
        {
        DeletePort(rel->ioa_Request.io_Message.mn_ReplyPort);
        }
    FreeMem( rel, sizeof(struct IOAudio) );
    }
