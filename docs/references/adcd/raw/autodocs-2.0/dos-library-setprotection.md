# dos.library/SetProtection



NAME

    SetProtection -- Set protection for a file or directory
SYNOPSIS

```c
    success = SetProtection( name, mask )
    D0                       D1    D2:4

    BOOL SetProtection (STRPTR, LONG)
```
FUNCTION

```c
    SetProtection() sets the protection attributes on a file or
    directory. The lower bits of the mask are as follows:

    bit 4: 1 = file has not changed         0 = file has been changed
    bit 3: 1 = reads not allowed,           0 = reads allowed.
    bit 2: 1 = writes not allowed,          0 = writes allowed.
    bit 1: 1 = execution not allowed,       0 = execution allowed.
    bit 0: 1 = deletion not allowed,        0 = deletion allowed.

    Before V36, the ROM filesystem didn't respect the Read and Write
    bits.  In V36 or later and in the FFS, the Read and Write
    bits are respected.

    The archive bit should be cleared by the filesystem whenever the file
    is changed.  Backup utilities will generally set the bit after
    backing up each file.

    The V36 Shell looks at the execute bit, and will refuse to execute
    a file if it is set.

    Other bits will be defined in the [<dos/dos.h>](../Includes_and_Autodocs_2._guide/node0068.html) include files.  Rather
    than referring to bits by number you should use the definitions in
    [<dos/dos.h>](../Includes_and_Autodocs_2._guide/node0068.html).
```
INPUTS

    name - pointer to a null-terminated string
    mask - the protection mask required
RESULTS

    success - boolean
SEE ALSO

```c
    [SetComment()](../Includes_and_Autodocs_2._guide/node02F2.html), [Examine()](../Includes_and_Autodocs_2._guide/node029C.html), [ExNext()](../Includes_and_Autodocs_2._guide/node02A0.html), [<dos/dos.h>](../Includes_and_Autodocs_2._guide/node0068.html)
```
