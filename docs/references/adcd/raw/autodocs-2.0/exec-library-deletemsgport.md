# exec.library/DeleteMsgPort



NAME

```c
    DeleteMsgPort - Free a message port created by [CreateMsgPort](../Includes_and_Autodocs_2._guide/node0345.html)  (V36)
```
SYNOPSIS

```c
    DeleteMsgPort(msgPort)
                  a0

    void DeleteMsgPort(struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *);
```
FUNCTION

```c
    Frees a message port created by [CreateMsgPort()](../Includes_and_Autodocs_2._guide/node0345.html).  All messages that
    may have been attached to this port must have already been
    replied to.
```
INPUTS

    msgPort - A message port.  NULL for no action.
SEE ALSO

```c
    [CreateMsgPort()](../Includes_and_Autodocs_2._guide/node0345.html), [amiga.lib/DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)
```
