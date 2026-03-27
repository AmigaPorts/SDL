/* Source: ADCD 2.1
 * Section: asl-library-allocaslrequest
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/asl-library-allocaslrequest.md
 */

    Pointer to an initialized requester data structure, or NULL on
    failure.  The data structure returned will match the requested
    type; for type ASL_FileRequest, a struct [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) *; for
    ASL_FontRequest, a struct [FontRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line147) *.

    The requester returned may then be passed to [AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html), and
    is freed by calling [FreeAslRequest()](../Includes_and_Autodocs_2._guide/node017F.html).
