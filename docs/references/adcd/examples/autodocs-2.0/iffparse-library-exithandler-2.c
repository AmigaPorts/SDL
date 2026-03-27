/* Source: ADCD 2.1
 * Section: iffparse-library-exithandler
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-exithandler.md
 */

    Installs an exit handler vector for a specific type of chunk into the
    context for the given [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.  Type and id are the longword
    identifiers for the chunk to handle.  The hook is a client-supplied
    standard 2.0 [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) structure, properly initialized.  Position tells
    where to put the handler in the context.  The handler will be called
    just before the parser exits the given chunk in the "pause" parse
    state.  The IFF stream may not be positioned predictably within the
    chunk.  The handler will execute in the same context as whoever
    called [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html).  The handler will be called (through the hook)
    with the following arguments:

            A0:     the [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) pointer you passed.
            A2:     the 'object' pointer you passed.
            A1:     pointer to a LONG containing the value
                    IFFCMD_EXIT.

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
