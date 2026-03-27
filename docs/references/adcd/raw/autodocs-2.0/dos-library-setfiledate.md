# dos.library/SetFileDate



NAME

```c
    SetFileDate -- Sets the modification date for a file or dir (V36)
```
SYNOPSIS

```c
    success = SetFileDate(name, date)
    D0                     D1    D2

    BOOL SetFileDate(STRPTR, struct [DateStamp](../Includes_and_Autodocs_2._guide/node0068.html#line53) *)
```
FUNCTION

    Sets the file date for a file or directory.  Note that for the Old
    File System and the Fast File System, the date of the root directory
    cannot be set.  Other filesystems may not support setting the date
    for all files/directories.
INPUTS

    name - Name of object
    date - New modification date
RESULT

    success - Success/failure indication
SEE ALSO

```c
    [DateStamp()](../Includes_and_Autodocs_2._guide/node0290.html), [Examine()](../Includes_and_Autodocs_2._guide/node029C.html), [ExNext()](../Includes_and_Autodocs_2._guide/node02A0.html), [ExAll()](../Includes_and_Autodocs_2._guide/node029B.html)
```
