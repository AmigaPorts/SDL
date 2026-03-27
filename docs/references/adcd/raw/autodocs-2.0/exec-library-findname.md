# exec.library/FindName



NAME

    FindName -- find a system list node with a given name
SYNOPSIS

```c
    node = FindName(start, name)
    D0,Z            A0     A1

    struct [Node](../Includes_and_Autodocs_2._guide/node0091.html#line23) *FindName(struct [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) *, STRPTR);
```
FUNCTION

    Traverse a system list until a node with the given name is found.
    To find multiple occurrences of a string, this function may be
    called with a node starting point.

    No arbitration is done for access to the list!  If multiple tasks
    access the same list, an arbitration mechanism such as
    SignalSemaphores must be used.
INPUTS

```c
    start - a list header or a list node to start the search
            (if node, this one is skipped)
    name - a pointer to a name string terminated with NULL
```
RESULTS

    node - a pointer to the node with the same name else
        zero to indicate that the string was not found.
