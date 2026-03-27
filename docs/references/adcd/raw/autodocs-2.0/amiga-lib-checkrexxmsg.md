# amiga.lib/CheckRexxMsg



NAME

```c
    CheckRexxMsg - Check if a [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) is from ARexx
```
SYNOPSIS

```c
    result = CheckRexxMsg(message)
    D0                    A0

    BOOL CheckRexxMsg(struct [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) *);
```
FUNCTION

```c
    This function checks to make sure that the message is from ARexx
    directly.  It is required when using the Rexx Variable Interface
    routines (RVI) that the message be from ARexx.

    While this function is new in the V37 amiga.lib, it is safe to
    call it in all versions of the operating system.  It is also
    PURE code, thus usable in resident/pure executables.
```
NOTE

    This is a stub in amiga.lib.  It is only available via amiga.lib.
    The stub has two labels.  One, _CheckRexxMsg, takes the arguments
    from the stack.  The other, CheckRexxMsg, takes the arguments in
    registers.
EXAMPLE

```c
    if (CheckRexxMsg(rxmsg))
    {
            /* [Message](../Includes_and_Autodocs_2._guide/node0099.html#line48) is one from ARexx */
    }
```
INPUTS

```c
    message         A pointer to the [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) in question
```
RESULTS

    result          A boolean - TRUE if message is from ARexx.
SEE ALSO

```c
    [GetRexxVar()](../Includes_and_Autodocs_2._guide/node015D.html), [SetRexxVar()](../Includes_and_Autodocs_2._guide/node0165.html)
```
