/* Source: ADCD 2.1
 * Section: asl-library-allocaslrequest
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/asl-library-allocaslrequest.md
 */

    type = type of requester to create.  Currently defined types
        include ASL_FileRequest and ASL_FontRequest.
    ptags = pointer to a tagitem array, which is defined for each
        specified type.  See "asl.h" and example programs for usage
        of various tag types.  See [AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html) for specifications
        of currently defined tag values and their effects.

    Note that tag values stay in effect for each use of the
    requester until they are cleared or modified by passing the
    same tag with a new value.

    AllocAslRequestTags( type, tags... ) which accepts your tags
    on the stack, is available in amiga.lib.

    Example Usage: AllocAslRequestTags( ASL_FileRequest,
                                        ASL_Hail, "My Title Bar",
                                        TAG_DONE );
