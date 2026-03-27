# dos.library/StartNotify



NAME

```c
    StartNotify -- Starts notification on a file or directory (V36)
```
SYNOPSIS

```c
    success = StartNotify(notifystructure)
    D0                          D1

    BOOL StartNotify(struct [NotifyRequest](../Includes_and_Autodocs_2._guide/node006E.html#line52) *)
```
FUNCTION

    Posts a notification request.  Do not modify the notify structure while
    it is active.  You will be notified when the file or directory changes.
    For files, you will be notified after the file is closed.  Not all
    filesystems will support this: applications should NOT require it.  In
    particular, most network filesystems won't support it.
INPUTS

```c
    notifystructure - A filled-in [NotifyRequest](../Includes_and_Autodocs_2._guide/node006E.html#line52) structure
```
RESULT

    success - Success/failure of request
BUGS

```c
    The V36 floppy/HD filesystem doesn't actually send notifications.  The
    V36 ram handler (ram:) does.  This has been fixed for V37.
```
SEE ALSO

```c
    [EndNotify()](../Includes_and_Autodocs_2._guide/node0299.html), [<dos/notify.h>](../Includes_and_Autodocs_2._guide/node006E.html)
```
