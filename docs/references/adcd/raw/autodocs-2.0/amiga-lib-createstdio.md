# amiga.lib/CreateStdIO



NAME

```c
    CreateStdIO -- create an [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28) structure
```
SYNOPSIS

```c
    ioReq = CreateStdIO(port);

    struct [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28) *CreateStdIO(struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *)
```
FUNCTION

```c
    Allocates memory for and initializes a new [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28) structure.
```
INPUTS

    port - an already initialized message port to be used for this IO
           request's reply port. If this is NULL this function fails.
RESULT

```c
    ioReq - a new [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28) structure, or NULL if there was not enough
            memory
```
SEE ALSO

```c
    [DeleteStdIO()](../Includes_and_Autodocs_2._guide/node0154.html), [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html), [exec.library/CreateIORequest()](../Includes_and_Autodocs_2._guide/node0344.html)
```
