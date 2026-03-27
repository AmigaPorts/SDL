# rexxsyslib.library/DeleteArgstring



NAME

```c
    DeleteArgstring - Releases an Argstring created by [CreateArgstring()](../Includes_and_Autodocs_2._guide/node0319.html)
```
SYNOPSIS

```c
    DeleteArgstring(argstring)
                    A0

    VOID DeleteArgstring(UBYTE *);
```
FUNCTION

    Releases an argstring.  The argstring must have been created by ARexx
INPUTS

    argstring - A pointer to the string buffer of an argstring.
RESULTS

SEE ALSO

```c
    [CreateArgstring()](../Includes_and_Autodocs_2._guide/node0319.html), [ClearRexxMsg()](../Includes_and_Autodocs_2._guide/node0318.html), [FillRexxMsg()](../Includes_and_Autodocs_2._guide/node031D.html)
```
BUGS

