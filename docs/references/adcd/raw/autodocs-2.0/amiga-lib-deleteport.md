# amiga.lib/DeletePort



NAME

```c
    DeletePort - free a message port created by [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)
```
SYNOPSIS

```c
    DeletePort(port)

    VOID DeletePort(struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *);
```
FUNCTION

```c
    Frees a message port created by [CreatePort](../Includes_and_Autodocs_2._guide/node0148.html). All messages that
    may have been attached to this port must have already been
    replied before this function is called.
```
INPUTS

    port - message port to delete
SEE ALSO

```c
    [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)
```
