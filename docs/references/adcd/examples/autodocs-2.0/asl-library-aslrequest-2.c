/* Source: ADCD 2.1
 * Section: asl-library-aslrequest
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/asl-library-aslrequest.md
 */

    request = requester structure allocated with [AllocAslRequest()](../Includes_and_Autodocs_2._guide/node017C.html).
    ptags = pointer to an array of TagItems which may be used to
        modify the requester.

    AslRequestTags( type, tags... ) which accepts your tags
    on the stack, is available in amiga.lib.

    Example Usage: AslRequestTags( ASL_FileRequest,
                                   ASL_Hail, "My Title Bar",
                                   TAG_DONE );
