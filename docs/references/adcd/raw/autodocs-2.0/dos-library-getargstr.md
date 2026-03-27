# dos.library/GetArgStr



NAME

```c
    GetArgStr -- Returns the arguments for the process (V36)
```
SYNOPSIS

```c
    ptr = GetArgStr()
    D0

    STRPTR GetArgStr(void)
```
FUNCTION

```c
    Returns a pointer to the (null-terminated) arguments for the program
    (process).  This is the same string passed in a0 on startup from CLI.
```
RESULT

    ptr - pointer to arguments
SEE ALSO

```c
    [SetArgStr()](../Includes_and_Autodocs_2._guide/node02F1.html), [RunCommand()](../Includes_and_Autodocs_2._guide/node02EA.html)
```
