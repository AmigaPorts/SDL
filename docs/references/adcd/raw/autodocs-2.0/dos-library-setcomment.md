# dos.library/SetComment



NAME

    SetComment -- Change a files' comment string
SYNOPSIS

```c
    success = SetComment( name, comment )
    D0                    D1    D2

    BOOL SetComment(STRPTR, STRPTR)
```
FUNCTION

```c
    SetComment() sets a comment on a file or directory. The comment is
    a pointer to a null-terminated string of up to 80 characters in the
    current ROM filesystem (and RAM:).  Note that not all filesystems
    will support comments (for example, NFS usually will not), or the
    size of comment supported may vary.
```
INPUTS

    name    - pointer to a null-terminated string
    comment - pointer to a null-terminated string
RESULTS

    success - boolean
SEE ALSO

```c
    [Examine()](../Includes_and_Autodocs_2._guide/node029C.html), [ExNext()](../Includes_and_Autodocs_2._guide/node02A0.html), [SetProtection()](../Includes_and_Autodocs_2._guide/node02FD.html)
```
