# trackdisk.device/TD_REMCHANGEINT



NAME

    TD_REMCHANGEINT -- remove a disk change software interrupt handler.
FUNCTION

```c
    This command removes a disk change software interrupt added
    by a previous use of [TD_ADDCHANGEINT](../Includes_and_Autodocs_2._guide/node0523.html).
```
IO REQUEST INPUT

```c
    The same IO request used for [TD_ADDCHANGEINT](../Includes_and_Autodocs_2._guide/node0523.html).

    io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      TD_REMCHANGEINT
    io_Flags        0
    io_Length       sizeof(struct Interrupt)
    io_Data         pointer to [Interrupt](../Includes_and_Autodocs_2._guide/node008C.html#line23) structure
```
IO REQUEST RESULT

```c
    io_Error - 0 for success, or an error code as defined in
               [<devices/trackdisk.h>](../Includes_and_Autodocs_2._guide/node005B.html)
```
BUGS

```c
    This command did not function properly under versions of Kickstart
    earlier than V36. A valid workaround under these older versions of
    Kickstart is:

            Forbid();
            Remove(ioRequest);
            Permit();

    Do not use this workaround in versions of Kickstart >= V36, use
    TD_REMCHANGEINT instead (for future compatibility with V38+).
```
SEE ALSO

```c
    [TD_ADDCHANGEINT](../Includes_and_Autodocs_2._guide/node0523.html), [<devices/trackdisk.h>](../Includes_and_Autodocs_2._guide/node005B.html)
```
