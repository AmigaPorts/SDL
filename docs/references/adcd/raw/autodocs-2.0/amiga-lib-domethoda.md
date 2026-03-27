# amiga.lib/DoMethodA



NAME

```c
    DoMethodA -- Perform method on object.  (V36)
```
SYNOPSIS

```c
    result = DoMethodA( obj, msg )

    ULONG DoMethodA( Object *, Msg * );
```
FUNCTION

    Boopsi support function that invokes the supplied message
    on the specified object.  The message is invoked on the
    object's true class.
INPUTS

    obj - pointer to boopsi object
    msg - pointer to method-specific message to send
RESULT

    result - specific to the message and the object's class.
NOTES

```c
    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
    Some early example code may refer to this function as DM().
```
SEE ALSO

```c
    [DoMethod()](../Includes_and_Autodocs_2._guide/node0156.html), [CoerceMethodA()](../Includes_and_Autodocs_2._guide/node0146.html), [DoSuperMethodA()](../Includes_and_Autodocs_2._guide/node0159.html), [<intuition/classusr.h>](../Includes_and_Autodocs_2._guide/node00E2.html)
    ROM Kernel Manual boopsi section
```
