# graphics.library/AttemptLockLayerRom


                       *
NAME

```c
    AttemptLockLayerRom -- Attempt to Lock [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) structure
                                     by rom(gfx lib) code
```
SYNOPSIS

```c
    gotit = AttemptLockLayerRom( layer )
     d0                           a5

    BOOL AttempLockLayerRom( struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) * );
```
FUNCTION

```c
    Query the current state of the lock on this [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33). If it is
    already locked then return FALSE, could not lock. If the
    [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) was not locked then lock it and return TRUE.
    This call does not destroy any registers.
    This call nests so that callers in this chain will not lock
    themselves out.
```
INPUTS

```c
    layer - pointer to [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) structure
```
RESULT

```c
    gotit - TRUE or FALSE depending on whether the [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) was
            successfully locked by the caller.
```
SEE ALSO

```c
    [LockLayerRom()](../Includes_and_Autodocs_2._guide/node045A.html) [UnlockLayerRom()](../Includes_and_Autodocs_2._guide/node0486.html)
```
