# intuition.library/DisposeObject



NAME

```c
    DisposeObject -- Deletes a 'boopsi' object. (V36)
```
SYNOPSIS

```c
    DisposeObject( Object )
                   A0

    VOID DisposeObject( APTR );
```
FUNCTION

```c
    Deletes a boopsi object and all of it auxiliary data.
    These objects are all created by [NewObject()](../Includes_and_Autodocs_2._guide/node022F.html).  Objects
    of certain classes "own" other objects, which will also
    be deleted when the object is passed to DisposeObject().
    Read the per-class documentation carefully to be aware
    of these instances.
```
INPUTS

```c
    Object = abstract pointer to a boopsi object returned by [NewObject()](../Includes_and_Autodocs_2._guide/node022F.html)
```
NOTES

    This function invokes the OM_DISPOSE method.
RESULT

    None.
BUGS

SEE ALSO

```c
    [NewObject()](../Includes_and_Autodocs_2._guide/node022F.html), SetAttrs(), [GetAttr()](../Includes_and_Autodocs_2._guide/node021B.html), [MakeClass()](../Includes_and_Autodocs_2._guide/node0227.html),
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```
