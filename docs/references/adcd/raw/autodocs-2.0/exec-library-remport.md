# exec.library/RemPort



NAME

    RemPort -- remove a message port from the system
SYNOPSIS

```c
    RemPort(port)
            A1

    void RemPort(struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *);
```
FUNCTION

    This function removes a message port structure from the system's
    message port list.  Subsequent attempts to rendezvous by name with
    this port will fail.
INPUTS

    port - pointer to a message port
SEE ALSO

```c
    [AddPort](../Includes_and_Autodocs_2._guide/node0329.html), [FindPort](../Includes_and_Autodocs_2._guide/node034F.html)
```
