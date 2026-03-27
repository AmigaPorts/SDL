# exec.library/DeleteIORequest



NAME

```c
    DeleteIORequest() - Free a request made by [CreateIORequest()](../Includes_and_Autodocs_2._guide/node0344.html)  (V36)
```
SYNOPSIS

```c
    DeleteIORequest( ioReq );
                     a0

    void DeleteIORequest(struct [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) *);
```
FUNCTION

```c
    Frees up an IO request as allocated by [CreateIORequest()](../Includes_and_Autodocs_2._guide/node0344.html).
```
INPUTS

```c
    ioReq - A pointer to the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block to be freed, or NULL.
            This function uses the mn_Length field to determine how
            much memory to free.
```
SEE ALSO

```c
    [CreateIORequest()](../Includes_and_Autodocs_2._guide/node0344.html), [amiga.lib/DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)
```
