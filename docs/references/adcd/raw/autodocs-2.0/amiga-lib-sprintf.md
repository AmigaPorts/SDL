# amiga.lib/sprintf



NAME

    sprintf - format a C-like string into a string buffer.
SYNOPSIS

```c
    sprintf(destination formatstring [,value [, values] ] );
```
FUNCTION

```c
    Performs string formatting identical to [printf](../Includes_and_Autodocs_2._guide/node0162.html), but directs the output
    into a specific destination in memory. This uses the ROM version
    of [printf](../Includes_and_Autodocs_2._guide/node0162.html) [(exec.library/RawDoFmt()](../Includes_and_Autodocs_2._guide/node036C.html)), so it is very small.

    Assembly programmers can call this by placing values on the
    stack, followed by a pointer to the formatstring, followed
    by a pointer to the destination string.
```
INPUTS

```c
    destination - the address of an area in memory into which the
                  formatted output is to be placed.
    formatstring - pointer to a null terminated string describing the
                   desired output formatting (see [printf()](../Includes_and_Autodocs_2._guide/node0162.html) for a
                   description of this string).
    value(s) - numeric information to be formatted into the output
               stream.
```
SEE ALSO

```c
     [printf()](../Includes_and_Autodocs_2._guide/node0162.html), [exec.library/RawDoFmt()](../Includes_and_Autodocs_2._guide/node036C.html)
```
