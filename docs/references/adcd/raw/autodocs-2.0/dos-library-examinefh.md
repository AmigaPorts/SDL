# dos.library/ExamineFH



NAME

```c
    ExamineFH -- Gets information on an open file (V36)
```
SYNOPSIS

```c
    success = ExamineFH(fh, fib)
    D0                  D1  D2

    BOOL ExamineFH(BPTR, struct [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) *)
```
FUNCTION

```c
    Examines a filehandle and returns information about the file in the
    [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62).  There are no guarantees as to whether the fib_Size
    field will reflect any changes made to the file size it was opened,
    though filesystems should attempt to provide up-to-date information
    for it.
```
INPUTS

```c
    fh  - Filehandle you wish to examine
    fib - [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62), must be longword aligned.
```
RESULT

    success - Success/failure indication
SEE ALSO

```c
    [Examine()](../Includes_and_Autodocs_2._guide/node029C.html), [ExNext()](../Includes_and_Autodocs_2._guide/node02A0.html), [ExAll()](../Includes_and_Autodocs_2._guide/node029B.html), [Open()](../Includes_and_Autodocs_2._guide/node02D6.html), [AllocDosObject()](../Includes_and_Autodocs_2._guide/node027F.html)
```
