# graphics.library/FreeCprList



NAME

    FreeCprList -- deallocate hardware copper list
SYNOPSIS

```c
    FreeCprList(cprlist)
                  a0

    void FreeCprList(struct [cprlist](../Includes_and_Autodocs_2._guide/node00AD.html#line55) *);
```
FUNCTION

```c
    return [cprlist](../Includes_and_Autodocs_2._guide/node00AD.html#line55) to free memory pool
```
INPUTS

```c
    [cprlist](../Includes_and_Autodocs_2._guide/node00AD.html#line55) - pointer to [cprlist](../Includes_and_Autodocs_2._guide/node00AD.html#line55) structure
```
RESULTS

    memory returned and made available to other tasks
BUGS

SEE ALSO

```c
    [graphics/copper.h](../Includes_and_Autodocs_2._guide/node00AD.html)
```
