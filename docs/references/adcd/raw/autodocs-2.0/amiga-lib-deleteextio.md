# amiga.lib/DeleteExtIO



NAME

    DeleteExtIO - return memory allocated for extended IO request
SYNOPSIS

```c
    DeleteExtIO(ioReq);

    VOID DeleteExtIO(struct [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) *);
```
FUNCTION

```c
    Frees up an IO request as allocated by [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html).
```
INPUTS

```c
    ioReq - the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block to be freed, or NULL.
```
SEE ALSO

```c
    [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)
```
