# intuition.library/NewObject



NAME

```c
    NewObjectA -- Create an object from a class. (V36)
    NewObject -- Varargs stub for NewObjectA(). (V36)
```
SYNOPSIS

```c
    object = NewObjectA( class, classID, tagList )
    D0                   A0     A1       A2

    APTR NewObjectA( struct IClass *, UBYTE *, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) * );

    object = NewObject( class, classID, Tag1, ... )

    APTR NewObject( struct IClass *, UBYTE *, ULONG, ... );
```
FUNCTION

```c
    This is the general method of creating objects from 'boopsi' classes.
    ('Boopsi' stands for "basic object-oriented programming system for
    Intuition".)

    You specify a class either as a pointer (for a private class) or
    by its ID string (for public classes).  If the class pointer
    is NULL, then the classID is used.

    You further specify initial "create-time" attributes for the
    object via a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list, and they are applied to the resulting
    generic data object that is returned.  The attributes, their meanings,
    attributes applied only at create-time, and required attributes
    are all defined and documented on a class-by-class basis.
```
INPUTS

```c
    class = abstract pointer to a boopsi class gotten via [MakeClass()](../Includes_and_Autodocs_2._guide/node0227.html).
    classID = the name/ID string of a public class.  This parameter is
            only used if 'class' is NULL.
    tagList = pointer to array of TagItems containing attribute/value
            pairs to be applied to the object being created
```
RESULT

```c
    A boopsi object, which may be used in different contexts such
    as a gadget or image, and may be manipulated by generic functions.
    You eventually free the object using [DisposeObject()](../Includes_and_Autodocs_2._guide/node020D.html).
```
NOTES

    This function invokes the OM_NEW "method" for the class specified.
BUGS

```c
    Typedef's for 'Object' and 'Class' are defined in the include
    files but not used consistently.  The generic type APTR is
    probably best used for object and class "handles", with the
    type (UBYTE *) used for classID strings.
```
SEE ALSO

```c
    [DisposeObject()](../Includes_and_Autodocs_2._guide/node020D.html), SetAttrs(), [GetAttr()](../Includes_and_Autodocs_2._guide/node021B.html), [MakeClass()](../Includes_and_Autodocs_2._guide/node0227.html),
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```
