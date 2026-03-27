# asl.library/AllocAslRequest



NAME

```c
    AllocAslRequest -- alloc an ASL requester, with [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) modifiers (V36)
```
SYNOPSIS

```c
    request = AllocAslRequest( type, ptags )
    D0                         D0    A0

    APTR    request;
    ulong   type;
    struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31)       *ptags;
```
FUNCTION

```c
    Allocates an ASL requester data structure of the specified type,
    with optional [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) modifiers.
```
INPUTS

```c
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
```
RESULT

```c
    Pointer to an initialized requester data structure, or NULL on
    failure.  The data structure returned will match the requested
    type; for type ASL_FileRequest, a struct [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) *; for
    ASL_FontRequest, a struct [FontRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line147) *.

    The requester returned may then be passed to [AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html), and
    is freed by calling [FreeAslRequest()](../Includes_and_Autodocs_2._guide/node017F.html).
```
SEE ALSO

```c
    [AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html), [FreeAslRequest()](../Includes_and_Autodocs_2._guide/node017F.html)
```
