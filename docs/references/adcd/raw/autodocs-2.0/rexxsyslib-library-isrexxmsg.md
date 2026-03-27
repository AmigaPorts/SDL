# rexxsyslib.library/IsRexxMsg



NAME

    IsRexxMsg - Function to determine if a message came from ARexx
SYNOPSIS

```c
    result = IsRexxMsg(msgptr)
    D0                 A0

    BOOL IsRexxMsg(struct [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) *);
```
FUNCTION

    This function can be used to determine if a message came from an
    ARexx program.
INPUTS

```c
    msgptr - A pointer to the suspected [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99).
```
RESULTS

    result - A boolean:  TRUE if it is an ARexx message, FALSE if not.
SEE ALSO

```c
    [CreateRexxMsg()](../Includes_and_Autodocs_2._guide/node031A.html)
```
BUGS

