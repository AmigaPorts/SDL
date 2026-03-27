# commodities.library/AttachCxObj



NAME

```c
    AttachCxObj -- attach a commodity object to the end of an existing
                   list of objects. (V36)
```
SYNOPSIS

```c
    AttachCxObj(headObj,co);
                A0      A1

    VOID AttachCxObj(CxObj *,CxObj *);
```
FUNCTION

    Adds 'co' to the list of objects pointed to by 'headObj'. The
    new object is added at the end of the list.
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
    [CxObjError()](../Includes_and_Autodocs_2._guide/node01A6.html), [ClearCxObjError()](../Includes_and_Autodocs_2._guide/node01A0.html)
```
