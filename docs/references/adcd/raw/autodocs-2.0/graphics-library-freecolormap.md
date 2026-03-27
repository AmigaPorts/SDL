# graphics.library/FreeColorMap



NAME

```c
    FreeColorMap -- Free the [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) structure and return memory
                                            to free memory pool.
```
SYNOPSIS

```c
    FreeColorMap( colormap )
                   a0

    void FreeColorMap(struct [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) *);
```
FUNCTION

```c
    Return the memory to the free memory pool that was allocated
    with [GetColorMap](../Includes_and_Autodocs_2._guide/node0445.html).
```
INPUTS

```c
    colormap - pointer to [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) allocated with [GetColorMap](../Includes_and_Autodocs_2._guide/node0445.html)
```
RESULT

    The space is made available for others to use.
BUGS

SEE ALSO

```c
    [SetRGB4()](../Includes_and_Autodocs_2._guide/node047C.html) [GetColorMap()](../Includes_and_Autodocs_2._guide/node0445.html) [graphics/view.h](../Includes_and_Autodocs_2._guide/node00B8.html)
```
