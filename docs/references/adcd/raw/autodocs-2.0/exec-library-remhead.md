# exec.library/RemHead



NAME

    RemHead -- remove the head node from a list
SYNOPSIS

```c
    node = RemHead(list)
    D0             A0

    struct [Node](../Includes_and_Autodocs_2._guide/node0091.html#line23) *RemHead(struct [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) *);
```
FUNCTION

    Get a pointer to the head node and remove it from the list.
    Assembly programmers may prefer to use the REMHEAD macro from
    "exec/lists.i".
WARNING

    This function does not arbitrate for access to the list.  The
    calling task must be the owner of the involved list.
INPUTS

    list - a pointer to the target list header
RESULT

    node - the node removed or zero when empty list
SEE ALSO

```c
    [AddHead](../Includes_and_Autodocs_2._guide/node0325.html), [AddTail](../Includes_and_Autodocs_2._guide/node032C.html), [Enqueue](../Includes_and_Autodocs_2._guide/node034D.html), Insert, Remove, [RemTail](../Includes_and_Autodocs_2._guide/node0377.html)
```
