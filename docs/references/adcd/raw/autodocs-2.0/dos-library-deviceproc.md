# dos.library/DeviceProc



NAME

```c
    DeviceProc -- Return the process [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) of specific I/O handler
```
SYNOPSIS

```c
    process = DeviceProc( name )
    D0                    D1

    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *DeviceProc (STRPTR)
```
FUNCTION

```c
    DeviceProc() returns the process identifier of the process which
    handles the device associated with the specified name. If no
    process handler can be found then the result is zero. If the name
    refers to an assign then a directory lock is returned in [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).
    This lock should not be UnLock()ed or Examine()ed (if you wish to do
    so, [DupLock()](../Includes_and_Autodocs_2._guide/node0297.html) it first).
```
BUGS

```c
    In V36, if you try to DeviceProc() something relative to an assign
    made with [AssignPath()](../Includes_and_Autodocs_2._guide/node0283.html), it will fail.  This is because there's no
    way to know when to unlock the lock.  If you're writing code for
    V36 or later, it is highly advised you use [GetDeviceProc()](../Includes_and_Autodocs_2._guide/node02B7.html) instead,
    or make your code conditional on V36 to use GetDeviceProc()/
    [FreeDeviceProc()](../Includes_and_Autodocs_2._guide/node02B0.html).
```
SEE ALSO

```c
    [GetDeviceProc()](../Includes_and_Autodocs_2._guide/node02B7.html), [FreeDeviceProc()](../Includes_and_Autodocs_2._guide/node02B0.html), [DupLock()](../Includes_and_Autodocs_2._guide/node0297.html), [UnLock()](../Includes_and_Autodocs_2._guide/node0307.html), [Examine()](../Includes_and_Autodocs_2._guide/node029C.html)
```
