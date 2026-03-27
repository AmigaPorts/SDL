# amiga.lib/DoMethod



NAME

```c
    DoMethod -- Perform method on object.  (V36)
```
SYNOPSIS

```c
    result = DoMethod( obj, MethodID, ... )

    ULONG DoMethod( Object *, ULONG, ... );
```
FUNCTION

```c
    Boopsi support function that invokes the supplied message
    on the specified object.  The message is invoked on the
    object's true class.  Equivalent to [DoMethodA()](../Includes_and_Autodocs_2._guide/node0157.html), but allows
    you to build the message on the stack.
```
INPUTS

```c
    obj - pointer to boopsi object
    MethodID - which method to send (see [<intuition/classusr.h>](../Includes_and_Autodocs_2._guide/node00E2.html))
    ... - method-specific message built on the stack
```
RESULT

    result - specific to the message and the object's class.
NOTES

    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
SEE ALSO

```c
    [DoMethodA()](../Includes_and_Autodocs_2._guide/node0157.html), [CoerceMethodA()](../Includes_and_Autodocs_2._guide/node0146.html), [DoSuperMethodA()](../Includes_and_Autodocs_2._guide/node0159.html), [<intuition/classusr.h>](../Includes_and_Autodocs_2._guide/node00E2.html)
    ROM Kernel Manual boopsi section
```
