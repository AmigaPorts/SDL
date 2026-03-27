# asl.library/AllocFileRequest



NAME

```c
    AllocFileRequest -- allocates a [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) structure (V36)
```
SYNOPSIS

```c
    request = AllocFileRequest()
    D0

    struct [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) *request;
```
FUNCTION

```c
    Creates and initializes the data structure required to pass to the
    [RequestFile()](../Includes_and_Autodocs_2._guide/node0181.html) function.
```
INPUTS

```c
    None.  If you wish to get other than default values, you can use
    [AllocAslRequest()](../Includes_and_Autodocs_2._guide/node017C.html) to set up a file request with tag items.
```
RESULT

```c
    Pointer to a struct [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65), which is to be passed to the
    [RequestFile()](../Includes_and_Autodocs_2._guide/node0181.html) function.

    The returned [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) pointer has public fields which are
    readable by the application as defined in aslbase.h.
```
CAUTION

```c
    The application MUST use either the AllocFileRequest(), or
    [AllocAslRequest()](../Includes_and_Autodocs_2._guide/node017C.html), function to allocate the structure to be passed to
    the FileRequest() or [AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html) functions; it is not possible to
    create a struct FileRequest except through the library calls.

    Also, any modifications MUST be done through [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) values, rather
    than directly modifying, unless explicitly documented otherwise.
```
SEE ALSO

```c
    [RequestFile()](../Includes_and_Autodocs_2._guide/node0181.html), [FreeAslRequest()](../Includes_and_Autodocs_2._guide/node017F.html), [AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html)
```
