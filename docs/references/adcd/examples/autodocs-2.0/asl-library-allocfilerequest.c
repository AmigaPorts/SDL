/* Source: ADCD 2.1
 * Section: asl-library-allocfilerequest
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/asl-library-allocfilerequest.md
 */

    The application MUST use either the AllocFileRequest(), or
    [AllocAslRequest()](../Includes_and_Autodocs_2._guide/node017C.html), function to allocate the structure to be passed to
    the FileRequest() or [AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html) functions; it is not possible to
    create a struct FileRequest except through the library calls.

    Also, any modifications MUST be done through [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) values, rather
    than directly modifying, unless explicitly documented otherwise.
