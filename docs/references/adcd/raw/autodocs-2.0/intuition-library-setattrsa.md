# intuition.library/SetAttrsA



NAME

```c
    SetAttrsA -- Specify attribute values for an object. (V36)
    SetAttrs -- Varargs stub for SetAttrsA(). (V36)
```
SYNOPSIS

```c
    result = SetAttrsA( Object, TagList )
    D0                  A0      A1

    ULONG SetAttrsA( APTR, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) * );

    result = SetAttrs( Object, Tag1, ... )

    ULONG SetAttrs( APTR, ULONG, ... );
```
FUNCTION

```c
    Specifies a set of attribute/value pairs with meaning as
    defined by a 'boopsi' object's class.

    This function does not provide enough context information or
    arbitration for boopsi gadgets which are attached to windows
    or requesters.  For those objects, use SetGadgetAttrs().
```
INPUTS

```c
    Object = abstract pointer to a boopsi object.
    TagList = array of [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) structures with attribute/value pairs.
```
RESULT

    The object does whatever it wants with the attributes you provide.
    The return value tends to be non-zero if the changes would require
    refreshing gadget imagery, if the object is a gadget.
NOTES

```c
    This function invokes the OM_SET method with a NULL [GadgetInfo](../Includes_and_Autodocs_2._guide/node00D2.html#line26)
    parameter.
```
BUGS

SEE ALSO

```c
    [NewObject()](../Includes_and_Autodocs_2._guide/node022F.html), [DisposeObject()](../Includes_and_Autodocs_2._guide/node020D.html), [GetAttr()](../Includes_and_Autodocs_2._guide/node021B.html), [MakeClass()](../Includes_and_Autodocs_2._guide/node0227.html),
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```
