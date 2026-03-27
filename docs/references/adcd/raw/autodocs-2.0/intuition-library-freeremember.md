# intuition.library/FreeRemember



NAME

```c
    FreeRemember -- Free memory allocated by calls to [AllocRemember()](../Includes_and_Autodocs_2._guide/node01FE.html).
```
SYNOPSIS

```c
    FreeRemember( RememberKey, ReallyForget )
                  A0           D0

    VOID FreeRemember( struct [Remember](../Includes_and_Autodocs_2._guide/node00D4.html#line1233) **, BOOL );
```
FUNCTION

```c
    This function frees up memory allocated by the [AllocRemember()](../Includes_and_Autodocs_2._guide/node01FE.html)
    function.  It will either free up just the [Remember](../Includes_and_Autodocs_2._guide/node00D4.html#line1233) structures, which
    supply the link nodes that tie your allocations together, or it will
    deallocate both the link nodes AND your memory buffers too.

    If you want to deallocate just the [Remember](../Includes_and_Autodocs_2._guide/node00D4.html#line1233) structure link nodes,
    you should set the ReallyForget argument to FALSE.  However, if you
    want FreeRemember to really deallocate all the memory, including
    both the [Remember](../Includes_and_Autodocs_2._guide/node00D4.html#line1233) structure link nodes and the buffers you requested
    via earlier calls to [AllocRemember()](../Includes_and_Autodocs_2._guide/node01FE.html), then you should set the
    ReallyForget argument to TRUE.

    NOTE WELL: Once you call this function passing it FALSE, the
    linkages between all the memory chunks are lost, and you
    cannot subsequently use FreeRemember() to free them.
```
INPUTS

```c
    RememberKey = the address of a pointer to struct [Remember](../Includes_and_Autodocs_2._guide/node00D4.html#line1233).  This
       pointer should either be NULL or set to some value (possibly
       NULL) by a call to [AllocRemember()](../Includes_and_Autodocs_2._guide/node01FE.html).
    ReallyForget = a BOOL FALSE or TRUE describing, respectively,
       whether you want to free up only the [Remember](../Includes_and_Autodocs_2._guide/node00D4.html#line1233) nodes or
       if you want this procedure to really forget about all of
       the memory, including both the nodes and the memory buffers
       referenced by the nodes.
```
EXAMPLE

```c
    struct [Remember](../Includes_and_Autodocs_2._guide/node00D4.html#line1233) *RememberKey;
    RememberKey = NULL;
    AllocRemember(&RememberKey, BUFSIZE, MEMF_CHIP);
    FreeRemember(&RememberKey, TRUE);
```
RESULT

    None
BUGS

SEE ALSO

```c
    [AllocRemember()](../Includes_and_Autodocs_2._guide/node01FE.html), [exec.library/FreeMem()](../Includes_and_Autodocs_2._guide/node0355.html)
```
