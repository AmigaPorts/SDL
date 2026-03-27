# commodities.library/InsertCxObj



NAME

```c
    InsertCxObj -- insert a commodity object in a list after a given
                   object. (V36)
```
SYNOPSIS

```c
    InsertCxObj(headObj,co,pred);
                A0      A1 A2

    VOID InsertCxObj(CxObj *,CxObj *,CxObj *);
```
FUNCTION

    Adds 'co' to the list of objects pointed to by 'headObj' after
    object 'pred'.
INPUTS

    headObj - pointer to a list of objects
    co - the object to insert in the list
    pred - the object after which 'co' should be inserted. If this is NULL
           then 'co' is added to the head of the list.
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
