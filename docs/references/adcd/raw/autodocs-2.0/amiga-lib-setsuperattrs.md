# amiga.lib/SetSuperAttrs



NAME

```c
    SetSuperAttrs -- Invoke OM_SET method on superclass with varargs. (V36)
```
SYNOPSIS

```c
    result = SetSuperAttrs( cl, obj, tag, ... )

    ULONG SetSuperAttrs( struct IClass *, Object *, ULONG, ... );
```
FUNCTION

```c
    Boopsi support function which invokes the OM_SET method on the
    superclass of the supplied class for the supplied object.  Allows
    the ops_AttrList to be supplied on the stack (i.e. in a varargs
    way).  The equivalent non-varargs function would simply be

        DoSuperMethod( cl, obj, OM_SET, taglist, NULL );
```
INPUTS

    cl - pointer to boopsi class whose superclass is to
        receive the OM_SET message
    obj - pointer to boopsi object
    tag - list of tag-attribute pairs, ending in TAG_DONE
RESULT

    result - class and message-specific result.
NOTES

    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
SEE ALSO

```c
    [CoerceMethodA()](../Includes_and_Autodocs_2._guide/node0146.html), [DoMethodA()](../Includes_and_Autodocs_2._guide/node0157.html), [DoSuperMethodA()](../Includes_and_Autodocs_2._guide/node0159.html), [<intuition/classusr.h>](../Includes_and_Autodocs_2._guide/node00E2.html)
    ROM Kernel Manual boopsi section
```
