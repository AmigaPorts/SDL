# amiga.lib/CoerceMethod



NAME

```c
    CoerceMethod -- Perform method on coerced object.  (V36)
```
SYNOPSIS

```c
    result = CoerceMethod( cl, obj, MethodID, ... )

    ULONG CoerceMethod( struct IClass *, Object *, ULONG, ... );
```
FUNCTION

```c
    Boopsi support function that invokes the supplied message
    on the specified object, as though it were the specified
    class.  Equivalent to [CoerceMethodA()](../Includes_and_Autodocs_2._guide/node0146.html), but allows you to
    build the message on the stack.
```
INPUTS

    cl - pointer to boopsi class to receive the message
    obj - pointer to boopsi object
    ... - method-specific message built on the stack
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
