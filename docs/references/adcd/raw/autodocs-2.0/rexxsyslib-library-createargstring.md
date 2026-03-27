# rexxsyslib.library/CreateArgstring



NAME

    CreateArgstring - Create an argument string structure
SYNOPSIS

```c
    argstr = CreateArgstring(string, length)
    D0,A0                    A0      D0

    UBYTE *CreateArgstring(UBYTE *, ULONG);
```
FUNCTION

```c
    Allocates a [RexxArg](../Includes_and_Autodocs_2._guide/node0127.html#line87) structure and copies the supplied string into it.
    The returned pointer points at the string part of the structure
    and can be treated like an ordinary string pointer.  (However, care
    must be taken that you do not change the string)
```
INPUTS

```c
    string - A pointer at your input string
    length - The number of bytes of your input string you wish copied.
             (NOTE:  You are limited to 65,535 byte strings)
```
RESULTS

    argstr - A pointer to the argument string.  The results are returned
             in both A0 and D0.  You should always check the result
             as an allocation failure would cause an error.
SEE ALSO

```c
    [DeleteArgstring()](../Includes_and_Autodocs_2._guide/node031B.html), [LengthArgstring()](../Includes_and_Autodocs_2._guide/node031F.html), [ClearRexxMsg()](../Includes_and_Autodocs_2._guide/node0318.html), [FillRexxMsg()](../Includes_and_Autodocs_2._guide/node031D.html)
```
BUGS

