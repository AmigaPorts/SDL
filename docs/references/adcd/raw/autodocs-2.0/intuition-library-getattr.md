# intuition.library/GetAttr



NAME

```c
    GetAttr -- Inquire the value of some attribute of an object. (V36)
```
SYNOPSIS

```c
    attr = GetAttr( AttrID, Object, StoragePtr )
    D0              D0      A0      A1

    ULONG GetAttr( ULONG, APTR, ULONG * );
```
FUNCTION

```c
    Inquires from the specified object the value of the specified
    attribute.

    You always pass the address of a long variable, which will
    receive the same value that would be passed to SetAttrs() in
    the ti_Data portion of a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) element.  See the documentation
    for the class for exceptions to this general rule.

    Not all attributes will respond to this function.  Those that
    will are documented on a class-by-class basis.
```
INPUTS

```c
    AttrID = the attribute tag ID understood by the object's class
    Object = abstract pointer to the boopsi object you are interested in
    StoragePtr = pointer to appropriate storage for the answer
```
RESULT

```c
    Returns FALSE (0) if the inquiries of attribute are not provided
    by the object's class.
```
NOTES

    This function invokes the OM_GET method of the object.
BUGS

SEE ALSO

```c
    [NewObject()](../Includes_and_Autodocs_2._guide/node022F.html), [DisposeObject()](../Includes_and_Autodocs_2._guide/node020D.html), SetAttrs(), [MakeClass()](../Includes_and_Autodocs_2._guide/node0227.html),
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```
