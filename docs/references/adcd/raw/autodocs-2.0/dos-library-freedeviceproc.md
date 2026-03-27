# dos.library/FreeDeviceProc



NAME

```c
    FreeDeviceProc -- Releases port returned by [GetDeviceProc()](../Includes_and_Autodocs_2._guide/node02B7.html) (V36)
```
SYNOPSIS

```c
    FreeDeviceProc(devproc)
                     D1

    void FreeDeviceProc(struct [DevProc](../Includes_and_Autodocs_2._guide/node0078.html#line418) *)
```
FUNCTION

```c
    Frees up the structure created by [GetDeviceProc()](../Includes_and_Autodocs_2._guide/node02B7.html), and any associated
    temporary locks.

    Decrements the counter incremented by [GetDeviceProc()](../Includes_and_Autodocs_2._guide/node02B7.html).  The counter
    is in an extension to the 1.3 process structure.  After calling
    FreeDeviceProc(), do not use the port or lock again!  It is safe to
    call FreeDeviceProc(NULL).
```
INPUTS

```c
    devproc - A value returned by [GetDeviceProc()](../Includes_and_Autodocs_2._guide/node02B7.html)
```
BUGS

    Counter not currently active in 2.0.
SEE ALSO

```c
    [GetDeviceProc()](../Includes_and_Autodocs_2._guide/node02B7.html), [DeviceProc()](../Includes_and_Autodocs_2._guide/node0295.html), [AssignLock()](../Includes_and_Autodocs_2._guide/node0282.html), [AssignLate()](../Includes_and_Autodocs_2._guide/node0281.html),
    [AssignPath()](../Includes_and_Autodocs_2._guide/node0283.html)
```
