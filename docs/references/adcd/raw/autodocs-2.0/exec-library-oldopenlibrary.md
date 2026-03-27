# exec.library/OldOpenLibrary



NAME

```c
    OldOpenLibrary -- obsolete [OpenLibrary](../Includes_and_Autodocs_2._guide/node0367.html)
```
SYNOPSIS

```c
    library = OldOpenLibrary(libName)
    D0                       A1

    struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *OldOpenLibrary(APTR);
```
FUNCTION

```c
    The 1.0 release of the Amiga system had an incorrect version of
    [OpenLibrary](../Includes_and_Autodocs_2._guide/node0367.html) that did not check the version number during the
    library open.  This obsolete function is provided so that object
    code compiled using a 1.0 system will still run.

    This exactly the same as "OpenLibrary(libName,0L);"
```
INPUTS

    libName - the name of the library to open
RESULTS

    library - a library pointer for a successful open, else zero
SEE ALSO

```c
    [CloseLibrary](../Includes_and_Autodocs_2._guide/node0340.html)
```
