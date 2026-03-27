---
title: 33 / / Custom Stream Handlers / Inside a Custom Stream Handler
manual: libraries
chapter: libraries
section: 33-custom-stream-handlers-inside-a-custom-stream-handler
functions: []
libraries: []
---

# 33 / / Custom Stream Handlers / Inside a Custom Stream Handler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the library calls your stream handler, you'll be passed a pointer to
the [Hook](libraries/37-callback-hooks-callback-hook-structure-and-function.md) structure (hook in the example used here), a pointer to the
[IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md) (iff), and a pointer to an [IFFStreamCmd](autodocs-2.0/includes-libraries-iffparse-h.md) structure (actionpkt).
Your stream pointer may be found in iff->[iff_Stream](libraries/33-stream-management-initialization.md) where you previously
stored it.  The IFFStreamCmd (actionpkt) will describe the action that
IFFParse needs you to perform on your stream:


/* Custom stream handler is passed struct IFFStreamCmd *actionpkt */
struct IFFStreamCmd {

```c
    LONG    sc_Command;     /*  Operation to be performed (IFFCMD_) */
    APTR    sc_Buf;         /*  Pointer to data buffer              */
    LONG    sc_NBytes;      /*  Number of bytes to be affected      */
    };
```
/* Possible call-back command values.  (Using 0 as the value for
 * IFFCMD_INIT was, in retrospect, probably a bad idea.)
 */
#define IFFCMD_INIT     0   /*  Prepare the stream for a session    */
#define IFFCMD_CLEANUP  1   /*  Terminate stream session            */
#define IFFCMD_READ     2   /*  Read bytes from stream              */
#define IFFCMD_WRITE    3   /*  Write bytes to stream               */
#define IFFCMD_SEEK     4   /*  Seek on stream                      */
#define IFFCMD_ENTRY    5   /*  You just entered a new context      */
#define IFFCMD_EXIT     6   /*  You're about to leave a context     */
#define IFFCMD_PURGELCI 7   /*  Purge a LocalContextItem            */


Your custom stream handler should perform the requested action on your
custom stream, and then return 0 for success or an IFFParse error if an
error occurred.  The following code demonstrates a sample stream handler
for a stream which was opened with a compiler's [fopen()](libraries/33-custom-stream-handlers-installing-a-custom-stream-handler.md) buffered file I/O
function:


static LONG mystreamhandler ( struct Hook *hook,
```c
                              struct IFFHandle *iff,
                              struct IFFStreamCmd *actionpkt )
```
{
```c
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
```
}

