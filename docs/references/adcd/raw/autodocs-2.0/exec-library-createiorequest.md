# exec.library/CreateIORequest



NAME

```c
    CreateIORequest() -- create an [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) structure  (V36)
```
SYNOPSIS

```c
    ioReq = CreateIORequest( ioReplyPort, size );
                             A0           D0

    struct [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) *CreateIORequest(struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *, ULONG);
```
FUNCTION

    Allocates memory for and initializes a new IO request block
    of a user-specified number of bytes.  The number of bytes
    must be at least as large as a "struct Message".
INPUTS

```c
    ioReplyPort - Pointer to a port for replies (an initialized message
            port, as created by [CreateMsgPort()](../Includes_and_Autodocs_2._guide/node0345.html) ).  If NULL, this
            function fails.
    size - the size of the IO request to be created.
```
RESULT

```c
    ioReq - A pointer to the new [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block, or NULL.
```
SEE ALSO

```c
    [DeleteIORequest](../Includes_and_Autodocs_2._guide/node0348.html), [CreateMsgPort()](../Includes_and_Autodocs_2._guide/node0345.html), [amiga.lib/CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)
```
