# exec.library/RemTail



NAME

    RemTail -- remove the tail node from a list
SYNOPSIS

```c
    node = RemTail(list)
    D0             A0

    struct [Node](../Includes_and_Autodocs_2._guide/node0091.html#line23) *RemTail(struct [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) *);
```
FUNCTION

    Remove the last node from a list, and return a pointer to it. If
    the list is empty, return zero. Assembly programmers may prefer to
    use the REMTAIL macro from "exec/lists.i".
WARNING

    This function does not arbitrate for access to the list.  The
    calling task must be the owner of the involved list.
INPUTS

    list - a pointer to the target list header
RESULT

    node - the node removed or zero when empty list
SEE ALSO

```c
    [AddHead](../Includes_and_Autodocs_2._guide/node0325.html), [AddTail](../Includes_and_Autodocs_2._guide/node032C.html), [Enqueue](../Includes_and_Autodocs_2._guide/node034D.html), Insert, Remove, [RemHead](../Includes_and_Autodocs_2._guide/node0370.html), RemTail
```
