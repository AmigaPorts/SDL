# exec.library/AddLibrary



NAME

    AddLibrary -- add a library to the system
SYNOPSIS

```c
    AddLibrary(library)
               A1

    void AddLibrary(struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *);
```
FUNCTION

    This function adds a new library to the system, making it available
    to other programs.  The library should be ready to be opened at
    this time.  It will be added to the system library name list, and
    the checksum on the library entries will be calculated.
INPUTS

    library - pointer to a properly initialized library structure
SEE ALSO

```c
    [RemLibrary](../Includes_and_Autodocs_2._guide/node0372.html), [CloseLibrary](../Includes_and_Autodocs_2._guide/node0340.html), [OpenLibrary](../Includes_and_Autodocs_2._guide/node0367.html), [MakeLibrary](../Includes_and_Autodocs_2._guide/node0361.html)
```
