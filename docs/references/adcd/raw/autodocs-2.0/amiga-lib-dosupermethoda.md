# amiga.lib/DoSuperMethodA



NAME

```c
    DoSuperMethodA -- Perform method on object coerced to superclass. (V36)
```
SYNOPSIS

```c
    result = DoSuperMethodA( cl, obj, msg )

    ULONG DoSuperMethodA( struct IClass *, Object *, Msg * );
```
FUNCTION

    Boopsi support function that invokes the supplied message
    on the specified object, as though it were the superclass
    of the specified class.
INPUTS

    cl - pointer to boopsi class whose superclass is to
        receive the message
    obj - pointer to boopsi object
    msg - pointer to method-specific message to send
RESULT

    result - class and message-specific result.
NOTES

```c
    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
    Some early example code may refer to this function as DSM().
```
SEE ALSO

```c
    [CoerceMethodA()](../Includes_and_Autodocs_2._guide/node0146.html), [DoMethodA()](../Includes_and_Autodocs_2._guide/node0157.html), [DoSuperMethod()](../Includes_and_Autodocs_2._guide/node0158.html), [<intuition/classusr.h>](../Includes_and_Autodocs_2._guide/node00E2.html)
    ROM Kernel Manual boopsi section
```
