# amiga.lib/CallHookA



NAME

```c
    CallHookA -- Invoke a hook given a pointer to a message.  (V36)
```
SYNOPSIS

```c
    result = CallHookA( hookPtr, obj, message )

    ULONG CallHook( struct [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) *, Object *, APTR );
```
FUNCTION

```c
    Invoke a hook on the supplied hook-specific data (an "object")
    and a parameter packet ("message").  This function is equivalent
    to [utility.library/CallHookPkt()](../Includes_and_Autodocs_2._guide/node03D0.html).
```
INPUTS

    hookPtr - A system-standard hook
    obj - hook-specific data object
    message - The hook-specific message you wish to send
RESULT

    result - a hook-specific result.
NOTES

    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
SEE ALSO

```c
    [CallHook()](../Includes_and_Autodocs_2._guide/node0142.html), [utility.library/CallHookPkt()](../Includes_and_Autodocs_2._guide/node03D0.html), [<utility/hooks.h>](../Includes_and_Autodocs_2._guide/node012D.html)
```
