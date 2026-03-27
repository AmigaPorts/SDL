# amiga.lib/NewList



NAME

    NewList -- prepare a list structure for use
SYNOPSIS

```c
    NewList(list)

    VOID NewList(struct [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) *);
    VOID NewList(struct [MinList](../Includes_and_Autodocs_2._guide/node007D.html#line32) *);
```
FUNCTION

```c
    Perform the magic needed to prepare a [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) header structure for
    use; the list will be empty and ready to use.  (If the list is the
    full featured type, you may need to initialize lh_Type afterwards)

    Assembly programmers may want to use the NEWLIST macro instead.
```
INPUTS

```c
    list - pointer to a [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) or [MinList](../Includes_and_Autodocs_2._guide/node007D.html#line32).
```
SEE ALSO

```c
    [<exec/lists.h>](../Includes_and_Autodocs_2._guide/node007D.html)
```
