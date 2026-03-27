# icon.library/DeleteDiskObject



NAME

```c
    DeleteDiskObject - Delete a Workbench disk object from disk.     (V37)
```
SYNOPSIS

```c
    result = DeleteDiskObject(name)
      D0                      A0

    BOOL DeleteDiskObject(char *);
```
FUNCTION

```c
    This routine will try to delete a Workbench disk object from disk.
    The name parameter will have a ".info" postpended to it, and the
    info file of that name will be deleted.  If the call fails,
    it will return zero.  The reason for the failure may be obtained
    via [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).

    This call also updates the Workbench screen if needed.

    Using this routine protects you from any future changes to
    the way icons are stored within the system.
```
INPUTS

```c
    name -- name of the object (char *)
```
RESULTS

    result -- TRUE if it worked, false if not.
EXAMPLE

```c
    error=NULL;

    *Check if you have the right library version*

    if (((struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *)IconBase)->lib_Version > 36)
    {
            if (!DeleteDiskObject(name)) error=IoErr();
    }
    else
    {
            * Delete name plus ".info" *
    }

    if (error)
    {
            * Do error routine...*
    }
```
SEE ALSO

```c
    [PutDiskObject()](../Includes_and_Autodocs_2._guide/node018E.html), [GetDiskObject()](../Includes_and_Autodocs_2._guide/node018A.html), [FreeDiskObject()](../Includes_and_Autodocs_2._guide/node0187.html)
```
BUGS

    None
