# asl.library/FreeFileRequest



NAME

```c
    FreeFileRequest -- frees requester allocated by [AllocFileRequest](../Includes_and_Autodocs_2._guide/node017D.html) (V36)
```
SYNOPSIS

```c
    FreeFileRequest( request )
                     A0

    struct [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) *request;
```
FUNCTION

```c
    This function is identical to the [FreeAslRequest()](../Includes_and_Autodocs_2._guide/node017F.html) function, but is
    documented for source code compatability and ease of use.
    Applications may use either [FreeAslRequest()](../Includes_and_Autodocs_2._guide/node017F.html) or FreeFileRequest() to
    free the data structures allocated by [AllocFileRequest()](../Includes_and_Autodocs_2._guide/node017D.html).
```
INPUTS

```c
    request = the return value from [AllocFileRequest()](../Includes_and_Autodocs_2._guide/node017D.html).
```
SEE ALSO

```c
    [FreeAslRequest()](../Includes_and_Autodocs_2._guide/node017F.html)
```
