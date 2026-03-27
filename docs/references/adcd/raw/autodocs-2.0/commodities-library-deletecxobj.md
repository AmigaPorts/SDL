# commodities.library/DeleteCxObj



NAME

```c
    DeleteCxObj -- delete a commmodity object. (V36)
```
SYNOPSIS

```c
    DeleteCxObj(co);
                A0

    VOID DeleteCxObj(CxObj *);
```
FUNCTION

```c
    Deletes a commodity object of any type. If the object
    is linked into a list, it is first removed. Note that
    the handle 'co' is invalid after this function is called.

    Also note that deleting an object which has other objects attached
    to it may be undesirable. Use the function [DeleteCxObjAll()](../Includes_and_Autodocs_2._guide/node01A9.html)
    to delete an entire sub-tree of objects.
```
INPUTS

    co - the commodity object to delete
SEE ALSO

```c
    [DeleteCxObjAll()](../Includes_and_Autodocs_2._guide/node01A9.html)
```
