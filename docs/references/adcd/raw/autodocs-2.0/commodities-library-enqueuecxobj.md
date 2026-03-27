# commodities.library/EnqueueCxObj



NAME

```c
    EnqueueCxObj -- insert a commodity object within a list of objects
                    based on object priority. (V36)
```
SYNOPSIS

```c
    EnqueueCxObj(headObj,co);
                 A0      A1

    VOID EnqueueCxObj(CxObj *,CxObj *);
```
FUNCTION

```c
    This function puts object 'co' into the list of object 'headObj'.
    The insertion point is determined by the object's priority. The
    objects are kept in the list from the highest priority to the
    lowest. New nodes are inserted in front of the first node with a
    lower priority. Hence a FIFO queue for nodes of equal priority.

    The priority of the commodity object can be set using [SetCxObjPri()](../Includes_and_Autodocs_2._guide/node01B2.html).
```
INPUTS

    headObj - pointer to a list of objects
    co - the object to add to the list
RESULTS

```c
    If 'co' is NULL, this function will record that fact in the
    internal accumulated error of 'headObj'. This error record
    can be retrieved using [CxObjError()](../Includes_and_Autodocs_2._guide/node01A6.html) and cleared using
    [ClearCxObjError()](../Includes_and_Autodocs_2._guide/node01A0.html).
```
SEE ALSO

```c
    [SetCxObjPri()](../Includes_and_Autodocs_2._guide/node01B2.html), [CxObjError()](../Includes_and_Autodocs_2._guide/node01A6.html), [ClearCxObjError()](../Includes_and_Autodocs_2._guide/node01A0.html)
```
