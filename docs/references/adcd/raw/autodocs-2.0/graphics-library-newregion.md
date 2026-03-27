# graphics.library/NewRegion



NAME

    NewRegion -- Get an empty region.
SYNOPSIS

```c
    region = NewRegion()
      d0

    struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) *NewRegion();
```
FUNCTION

```c
    Create a [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) structure, initialize it to empty, and return
    a pointer it.
```
RESULTS

```c
    region - pointer to initialized region. If it could not allocate
            required memory region = NULL.
```
INPUTS

    none
BUGS

SEE ALSO

```c
    [graphics/regions.h](../Includes_and_Autodocs_2._guide/node00B7.html)
```
