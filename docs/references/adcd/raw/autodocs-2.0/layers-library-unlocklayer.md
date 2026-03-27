# layers.library/UnlockLayer



NAME

    UnlockLayer -- Unlock layer and allow graphics routines to use it.
SYNOPSIS

```c
    UnlockLayer( l )
                 a0

    void UnlockLayer( struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *);
```
FUNCTION

```c
    When finished changing the ClipRects or whatever you were
    doing with this layer you must call UnlockLayer() to allow
    other tasks to proceed with graphic output to the layer.
```
INPUTS

    l - pointer to a layer
BUGS

SEE ALSO

```c
    [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html), [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)
```
