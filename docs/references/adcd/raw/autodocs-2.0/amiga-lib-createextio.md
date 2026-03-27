# amiga.lib/CreateExtIO



NAME

```c
    CreateExtIO -- create an [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) structure
```
SYNOPSIS

```c
    ioReq = CreateExtIO(port,ioSize);

    struct [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) *CreateExtIO(struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *, ULONG);
```
FUNCTION

```c
    Allocates memory for and initializes a new IO request block
    of a user-specified number of bytes. The number of bytes
    MUST be the size of a legal [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) (or extended IORequest)
    or very nasty things will happen.
```
INPUTS

    port - an already initialized message port to be used for this IO
           request's reply port. If this is NULL this function fails.
    ioSize - the size of the IO request to be created.
RESULT

    ioReq - a new IO Request block, or NULL if there was not enough memory
EXAMPLE

```c
    if (ioReq = CreateExtIO(CreatePort(NULL,0),sizeof(struct IOExtTD)))
```
SEE ALSO

```c
    [DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html), [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html), [exec.library/CreateMsgPort()](../Includes_and_Autodocs_2._guide/node0345.html)
```
