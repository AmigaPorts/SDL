# amiga.lib/DoSuperMethod



NAME

```c
    DoSuperMethod -- Perform method on object coerced to superclass. (V36)
```
SYNOPSIS

```c
    result = DoSuperMethod( cl, obj, MethodID, ... )

    ULONG DoSuperMethod( struct IClass *, Object *, ULONG, ... );
```
FUNCTION

```c
    Boopsi support function that invokes the supplied message
    on the specified object, as though it were the superclass
    of the specified class.  Equivalent to [DoSuperMethodA()](../Includes_and_Autodocs_2._guide/node0159.html),
    but allows you to build the message on the stack.
```
INPUTS

    cl - pointer to boopsi class whose superclass is to
        receive the message
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
