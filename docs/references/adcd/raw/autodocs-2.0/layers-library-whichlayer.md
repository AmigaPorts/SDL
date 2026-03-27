# layers.library/WhichLayer



NAME

```c
    WhichLayer -- Which [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) is this point in?
```
SYNOPSIS

```c
    layer = WhichLayer( li, x, y )
    d0                  a0  d0 d1

    struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *WhichLayer(struct Layer_Info*, WORD, WORD);
```
FUNCTION

```c
    Starting at the topmost layer check to see if this point (x,y)
        occurs in this layer.  If it does return the pointer to this
        layer. Return NULL if there is no layer at this point.
```
INPUTS

```c
    li  = pointer to LayerInfo structure
    (x,y) = coordinate in the [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47)
```
RESULTS

    layer - pointer to the topmost layer that this point is in
            NULL if this point is not in a layer
SEE ALSO

```c
    [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)
```
