/* Source: ADCD 2.1
 * Section: 28-double-buffering-dbufpacket-and-double-buffering
 * Library: libraries
 * ADCD reference: libraries/28-double-buffering-dbufpacket-and-double-buffering.md
 */

    struct Bob        myBob = {0};
    struct DBufPacket myDBufPacket = {0};

    /* Allocate a DBufPacket for myBob same size as previous example */
    if (NULL != (myDBufPacket.BufBuffer = AllocRaster(48, 20 * 5)))
        {
        /* tell Bob about its double buff status */
        myBob.DBuffer = myDBufPacket;
        }
