# asl.library/FreeAslRequest



NAME

```c
    FreeAslRequest - frees requester obtained from [AllocAslRequest](../Includes_and_Autodocs_2._guide/node017C.html) (V36)
```
SYNOPSIS

```c
    FreeAslRequest( request )
                    A0

    APTR request;
```
FUNCTION

```c
    FreeAslRequest() is used to free the structure returned by
    [AllocAslRequest()](../Includes_and_Autodocs_2._guide/node017C.html) or [AllocFileRequest()](../Includes_and_Autodocs_2._guide/node017D.html), in order to free
    all resources associated with that requester after the
    application has completed all use of the data structures.
```
INPUTS

```c
    request - value returned from [AllocAslRequest()](../Includes_and_Autodocs_2._guide/node017C.html) or
                    [AllocFileRequest()](../Includes_and_Autodocs_2._guide/node017D.html).
```
RESULT

    None.  All resources associated with the request will be
    freed.
SEE ALSO

```c
    [AllocAslRequest()](../Includes_and_Autodocs_2._guide/node017C.html), [AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html), [AllocFileRequest()](../Includes_and_Autodocs_2._guide/node017D.html)
```
