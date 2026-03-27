# amiga.lib/DeleteStdIO



NAME

```c
    DeleteStdIO - return memory allocated for [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28)
```
SYNOPSIS

```c
    DeleteStdIO(ioReq);

    VOID DeleteStdIO(struct [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28) *);
```
FUNCTION

```c
    Frees up an [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28) as allocated by [CreateStdIO()](../Includes_and_Autodocs_2._guide/node0149.html).
```
INPUTS

```c
    ioReq - the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block to be freed, or NULL.
```
SEE ALSO

```c
    [CreateStdIO()](../Includes_and_Autodocs_2._guide/node0149.html), [DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html), [exec.library/CreateIORequest()](../Includes_and_Autodocs_2._guide/node0344.html)
```
