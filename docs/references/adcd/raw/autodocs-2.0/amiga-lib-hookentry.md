# amiga.lib/HookEntry



NAME

```c
    HookEntry -- Assembler to HLL conversion stub for hook entry.  (V36)
```
SYNOPSIS

```c
    result = HookEntry( struct [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) *, Object *, APTR )
    D0                  A0             A2        A1
```
FUNCTION

```c
    By definition, a standard hook entry-point must receive the
    hook in A0, the object in A2, and the message in A1.  If your
    hook entry-point is written in a high-level language and is
    expecting its parameters on the stack, then HookEntry() will
    put the three parameters on the stack and invoke the function
    stored in the hook h_SubEntry field.

    This function is only useful to hook implementers, and is
    never called from C.
```
INPUTS

    hook - pointer to hook being invoked
    object - pointer to hook-specific data
    msg - pointer to hook-specific message
RESULT

    result - a hook-specific result.
NOTES

    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
EXAMPLE

```c
    If your hook dispatcher is this:

    dispatch( struct [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) *hookPtr, Object *obj, APTR msg )
    {
        ...
    }

    Then when you initialize your hook, you would say:

    myhook.h_Entry = HookEntry;     /* amiga.lib stub */
    myhook.h_SubEntry = dispatch;   /* HLL entry */
```
SEE ALSO

```c
    [CallHook()](../Includes_and_Autodocs_2._guide/node0142.html), [CallHookA()](../Includes_and_Autodocs_2._guide/node0143.html), [<utility/hooks.h>](../Includes_and_Autodocs_2._guide/node012D.html)
```
