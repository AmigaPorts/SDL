# layers.library/NewLayerInfo



NAME

```c
    NewLayerInfo -- Allocate and Initialize full [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure.
```
SYNOPSIS

```c
    result = NewLayerInfo()
    d0

    struct [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) *NewLayerInfo( void );
```
FUNCTION

```c
    Allocate memory required for full [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure.
    Initialize [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure in preparation to use
    other layer operations on this list of layers.
    Make the [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) unlocked (open).
```
INPUTS

    None
RESULT

```c
    result- pointer to [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure if successful
            NULL if not enough memory
```
BUGS

SEE ALSO

```c
    [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)
```
