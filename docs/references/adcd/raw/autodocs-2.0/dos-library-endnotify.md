# dos.library/EndNotify



NAME

```c
    EndNotify -- Ends a notification request (V36)
```
SYNOPSIS

```c
    EndNotify(notifystructure)
                    D1

    VOID EndNotify(struct [NotifyRequest](../Includes_and_Autodocs_2._guide/node006E.html#line52) *)
```
FUNCTION

```c
    Removes a notification request.  Safe to call even if [StartNotify()](../Includes_and_Autodocs_2._guide/node0301.html)
    failed.  For NRF_SEND_MESSAGE, it searches your port for any messages
    about the object in question and removes and replies them before
    returning.
```
INPUTS

```c
    notifystructure - a structure passed to [StartNotify()](../Includes_and_Autodocs_2._guide/node0301.html)
```
SEE ALSO

```c
    [StartNotify()](../Includes_and_Autodocs_2._guide/node0301.html), [<dos/notify.h>](../Includes_and_Autodocs_2._guide/node006E.html)
```
