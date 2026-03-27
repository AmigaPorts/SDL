# amiga.lib/SetRexxVar



NAME

    SetRexxVar - Sets the value of a variable of a running ARexx program
SYNOPSIS

```c
    error = SetRexxVar(message,varname,value,length)
    D0                 A0      A1      D0    D1

    LONG SetRexxVar(struct [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) *,char *,char *,ULONG);
```
FUNCTION

    This function will attempt to the the value of the symbol
    varname in the ARexx script that sent the message.

    While this function is new in the V37 amiga.lib, it is safe to
    call it in all versions of the operating system.  It is also
    PURE code, thus usable in resident/pure executables.
NOTE

```c
    This is a stub in amiga.lib.  It is only available via amiga.lib.
    The stub has two labels.  One, _SetRexxVar, takes the arguments
    from the stack.  The other, SetRexxVar, takes the arguments in
    registers.

    This routine does a [CheckRexxMsg()](../Includes_and_Autodocs_2._guide/node0144.html) on the message.
```
EXAMPLE


```c
    char    *value;

    /* [Message](../Includes_and_Autodocs_2._guide/node0099.html#line48) is one from ARexx */
    if (!SetRexxVar(rxmsg,"TheVar","25 Dollars",10))
    {
            /* The value of TheVar will now be "25 Dollars" */
    }
```
INPUTS


    message         A message gotten from an ARexx script
    varname         The name of the variable to set
    value           A string that will be the new value of the variable
    length          The length of the value string
RESULTS

```c
    error           0 for success, otherwise an error code.
                    (Other codes may exists, these are documented)
                    3  == Insufficient Storage
                    9  == String too long
                    10 == invalid message
```
SEE ALSO

```c
    SetRexxVar(), [CheckRexxMsg()](../Includes_and_Autodocs_2._guide/node0144.html)
```
