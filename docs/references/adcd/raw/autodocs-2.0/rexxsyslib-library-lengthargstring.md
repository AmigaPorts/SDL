# rexxsyslib.library/LengthArgstring



NAME

    LengthArgstring - Returns the length value stored in the argstring
SYNOPSIS

```c
    length = LengthArgstring(argstring)
    D0                       A0

    ULONG LengthArgstring(UBYTE *);
```
FUNCTION

```c
    This function returns the length value stored in the argstring.
    This is *NOT* the same as doing a strlen() type call on the
    argstring.  (Note that argstrings may contain NULLs)
```
INPUTS

    argstring - A pointer to an argstring that was created by ARexx
RESULTS

    length - The length of the argstring.
EXAMPLE

SEE ALSO

```c
    [CreateArgstring()](../Includes_and_Autodocs_2._guide/node0319.html)
```
BUGS

