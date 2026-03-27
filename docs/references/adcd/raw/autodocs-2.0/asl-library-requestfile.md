# asl.library/RequestFile



NAME

```c
    RequestFile -- request user to select file(s) (V36)
```
SYNOPSIS

```c
    BOOL result = RequestFile( request )
    D0                         A0

    BOOL    result;
    struct [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) *request;
```
FUNCTION

```c
    RequestFile() displays a file requester and waits for the user to
    select filenames or cancel the request.  This function is identical
    to the [AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html) function, except that there is no TagList to
    modify the settings for the requester.  See [AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html) for details.
```
INPUT

```c
    request = struct [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) * returned by [AllocFileRequest()](../Includes_and_Autodocs_2._guide/node017D.html).
```
RESULT

```c
    result - See [AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html) result.  NULL indicates cancelled.
```
SEE ALSO

```c
    [AllocFileRequest()](../Includes_and_Autodocs_2._guide/node017D.html), [FreeFileRequest()](../Includes_and_Autodocs_2._guide/node0180.html), [AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html)
```
