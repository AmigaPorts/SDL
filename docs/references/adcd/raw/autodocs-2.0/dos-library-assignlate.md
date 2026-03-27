# dos.library/AssignLate



NAME

```c
    AssignLate -- Creates an assignment to a specified path later (V36)
```
SYNOPSIS

```c
    success = AssignLate(name,path)
    D0                    D1   D2

    BOOL AssignLate(STRPTR,STRPTR)
```
FUNCTION

```c
    Sets up a assignment that is expanded upon the FIRST reference to the
    name.  The path (a string) would be attached to the node.  When
    the name is referenced (Open("FOO:xyzzy"...), the string will be used
    to determine where to set the assign to, and if the directory can be
    locked, the assign will act from that point on as if it had been
    created by [AssignLock()](../Includes_and_Autodocs_2._guide/node0282.html).

    A major advantage is assigning things to unmounted volumes, which
    will be requested upon access (useful in startup sequences).
```
INPUTS

```c
    name - Name of device to be assigned (without trailing ':')
    path - Name of late assignment to be resolved on the first reference.
```
RESULT

    success - Success/failure indicator of the operation
SEE ALSO

```c
    [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html), [AssignAdd()](../Includes_and_Autodocs_2._guide/node0280.html), [AssignPath()](../Includes_and_Autodocs_2._guide/node0283.html), [AssignLock()](../Includes_and_Autodocs_2._guide/node0282.html),
```
