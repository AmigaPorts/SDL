# commodities.library/RemoveCxObj



NAME

```c
    RemoveCxObj -- remove a commodity object from a list. (V36)
```
SYNOPSIS

```c
    RemoveCxObj(co);
                A0

    VOID RemoveCxObj(CxObj *);
```
FUNCTION

```c
    This function remove 'co' from any list it may be a part of.
    Will not crash if 'co' is NULL, or if it has not been inserted
    in a list (and is not corrupted).

    It is not recommended to remove a broker from the master list.
```
INPUTS
   co - the object to remove, may be NULL

SEE ALSO

```c
    [AttachCxObj()](../Includes_and_Autodocs_2._guide/node019F.html), [EnqueueCxObj()](../Includes_and_Autodocs_2._guide/node01AC.html), [InsertCxObj()](../Includes_and_Autodocs_2._guide/node01AD.html)
```
