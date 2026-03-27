/* Source: ADCD 2.1
 * Section: 33-custom-stream-handlers-inside-a-custom-stream-handler
 * Library: libraries
 * ADCD reference: libraries/33-custom-stream-handlers-inside-a-custom-stream-handler.md
 */

    register FILE   *stream;
    register LONG   nbytes, error;
    register UBYTE  *buf;


    stream  = (FILE *) iff->iff_Stream;    /* get stream pointer */
    nbytes  = actionpkt->sc_NBytes;        /* length for command */
    buf     = (UBYTE *) actionpkt->sc_Buf; /* buffer for the command */

    /* Now perform the action specified by the actionpkt->sc_Command */

    switch (actionpkt->sc_Command) {
    case IFFCMD_READ:
        /*
         * IFFCMD_READ means read sc_NBytes from the stream and place
         * it in the memory pointed to by sc_Buf.  Be aware that
         * sc_NBytes may be larger than can be contained in an int.
         * This is important if you plan on recompiling this for
         * 16-bit ints, since fread() takes int arguments.
         *
         * Any error code returned will be remapped by IFFParse into
         * IFFERR_READ.
         */
        error = (fread (buf, 1, nbytes, stream) != nbytes);
        break;

    case IFFCMD_WRITE:
        /*
         * IFFCMD_WRITE is analogous to IFFCMD_READ.
         *
         * Any error code returned will be remapped by IFFParse into
         * IFFERR_WRITE.
         */
        error = (fwrite (buf, 1, nbytes, stream) != nbytes);
        break;

    case IFFCMD_SEEK:
        /*
         * IFFCMD_SEEK asks that you performs a seek relative to the
         * current position.  sc_NBytes is a signed number,
         * indicating seek direction (positive for forward, negative
         * for backward).  sc_Buf has no meaning here.
         *
         * Any error code returned will be remapped by IFFParse into
         * IFFERR_SEEK.
         */
        error = (fseek (stream, nbytes, 1) == -1);
        break;

    case IFFCMD_INIT:
        /*
         * IFFCMD_INIT means to prepare your stream for reading.
         * This is used for certain streams that can't be read
         * immediately upon opening, and need further preparation.
         * This operation is allowed to fail;  the error code placed
         * in D0 will be returned directly to the client.
         *
         * An example of such a stream is the clipboard.  The
         * clipboard.device requires you to set the io_ClipID and
         * io_Offset to zero before starting a read.  You would
         * perform such a sequence here.  (Stdio files need no such
         * preparation, so we simply return zero for success.)
         */
    case IFFCMD_CLEANUP:
        /*
         * IFFCMD_CLEANUP means to terminate the transaction with
         * the associated stream.  This is used for streams that
         * can't simply be closed.  This operation is not allowed to
         * fail;  any error returned will be ignored.
         *
         * An example of such a stream is (surprise!) the clipboard.
         * It requires you to explicitly end reads by CMD_READing
         * past the end of a clip, and end writes by sending a
         * CMD_UPDATE.  You would perform such a sequence here.
         * (Again, stdio needs no such sequence.)
         */
        error = 0;
        break;
    }
    return (error);
