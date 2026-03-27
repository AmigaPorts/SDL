/* Source: ADCD 2.1
 * Section: iffparse-library-entryhandler
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-entryhandler.md
 */

    Installs an entry handler vector for a specific type of chunk into
    the context for the given [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.  Type and id are the
    longword identifiers for the chunk to handle.  The hook is a client-
    supplied standard 2.0 [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) structure, properly initialized.  Position
    tells where to put the handler in the context.  The handler will be
    called whenever the parser enters a chunk of the given type, so the
    IFF stream will be positioned to read the first data byte in the
    chunk.  The handler will execute in the same context as whoever
    called [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html).  The handler will be called (through the hook)
    with the following arguments:

            A0:     the [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) pointer you passed.
            A2:     the 'object' pointer you passed.
            A1:     pointer to a LONG containing the value
                    IFFCMD_ENTRY.

    The error code your call-back routine returns will affect the parser
    in three different ways:

    Return value            Result
    ------------            ------
    0:                      Normal success;  [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) will continue
                            through the file.
    IFF_RETURN2CLIENT:      [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) will stop and return the value 0.
                            (StopChunk() is internally implemented using
                            this return value.)
    Any other value:        [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) will stop and return the value
                            you supplied.  This is how errors should be
                            returned.
