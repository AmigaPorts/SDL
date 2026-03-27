/* Source: ADCD 2.1
 * Section: iffparse-library-initiff
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-initiff.md
 */

    Initializes an [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) as a general user-defined stream by
    allowing the user to declare a hook that the library will call to
    accomplish the low-level reading, writing, and seeking of the stream.
    Flags are the stream I/O flags for the specified stream; typically a
    combination of the IFFF_?SEEK flags.

    The stream vector is called with the following arguments:

            A0:     pointer to streamhook.
            A2:     pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
            A1:     pointer to [IFFStreamCmd](../Includes_and_Autodocs_2._guide/node010B.html#line55) struct.

    The [IFFStreamCmd](../Includes_and_Autodocs_2._guide/node010B.html#line55) packet appears as follows:

            sc_Command:     Contains an IFFCMD_#? value
            sc_Buf:         Pointer to memory buffer
            sc_NBytes:      Number of bytes involved in operation

    The values taken on by sc_Command, and their meaning, are as follows:

    IFFCMD_INIT:
            Prepare your stream for reading.  This is used for certain
            streams that can't be read immediately upon opening, and need
            further preparation.  (The clipboard.device is an example of
            such a stream.)  This operation is allowed to fail;  any
            error code will be returned directly to the client.  sc_Buf
            and sc_NBytes have no meaning here.
    IFFCMD_CLEANUP:
            Terminate the transaction with the associated stream.  This
            is used with streams that can't simply be closed.  (Again,
            the clipboard is an example of such a stream.)  This
            operation is not permitted to fail;  any error returned will
            be ignored (best to return 0, though).  sc_Buf and sc_NBytes
            have no meaning here.
    IFFCMD_READ:
            Read from the stream.  You are to read sc_NBytes from the
            stream and place them in the buffer pointed to by sc_Buf.
            Any (non-zero) error returned will be remapped by the parser
            into IFFERR_READ.
    IFFCMD_WRITE:
            Write to the stream.  You are to write sc_NBytes to the
            stream from the buffer pointed to by sc_Buf.  Any (non-zero)
            error returned will be remapped by the parser into
            IFFERR_WRITE.
    IFFCMD_SEEK:
            Seek on the stream.  You are to perform a seek on the stream
            relative to the current position.  sc_NBytes is signed;
            negative values mean seek backward, positive values mean seek
            forward.  sc_Buf has no meaning here.  Any (non-zero) error
            returned will be remapped by the parser into IFFERR_SEEK.

    All errors are returned in D0.  A return of 0 indicates success.
    UNDER NO CIRCUMSTANCES are you permitted to write to the [IFFStreamCmd](../Includes_and_Autodocs_2._guide/node010B.html#line55)
    structure.
