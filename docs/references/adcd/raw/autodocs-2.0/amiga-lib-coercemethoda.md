# amiga.lib/CoerceMethodA



NAME

```c
    CoerceMethodA -- Perform method on coerced object.  (V36)
```
SYNOPSIS

```c
    result = CoerceMethodA( cl, obj, msg )

    ULONG CoerceMethodA( struct IClass *, Object *, Msg * );
```
FUNCTION

    Boopsi support function that invokes the supplied message
    on the specified object, as though it were the specified
    class.
INPUTS

    cl - pointer to boopsi class to receive the message
    obj - pointer to boopsi object
    msg - pointer to method-specific message to send
RESULT

    result - class and message-specific result.
NOTES

```c
    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
    Some early example code may refer to this function as CM().
```
SEE ALSO

```c
    [CoerceMethod()](../Includes_and_Autodocs_2._guide/node0145.html), [DoMethodA()](../Includes_and_Autodocs_2._guide/node0157.html), [DoSuperMethodA()](../Includes_and_Autodocs_2._guide/node0159.html), [<intuition/classusr.h>](../Includes_and_Autodocs_2._guide/node00E2.html)
    ROM Kernel Manual boopsi section
```
