/* Source: ADCD 2.1
 * Section: iffparse-library-initiffasclip
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-initiffasclip.md
 */

    Initializes the given [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) to be a clipboard stream.  The
    function initializes the stream processing vectors to operate on
    streams of the [ClipboardHandle](../Includes_and_Autodocs_2._guide/node010B.html#line115) type.  The iff_Stream field will still
    need to be initialized to point to a [ClipboardHandle](../Includes_and_Autodocs_2._guide/node010B.html#line115) as returned from
    [OpenClipboard()](../Includes_and_Autodocs_2._guide/node01CE.html).
