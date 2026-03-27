# exec.library/CloseLibrary



NAME

    CloseLibrary -- conclude access to a library
SYNOPSIS

```c
    CloseLibrary(library)
                 A1

    void CloseLibrary(struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *);
```
FUNCTION

    This function informs the system that access to the given library
    has been concluded.  The user must not reference the library or any
    function in the library after this close.

    Starting with V36, it is safe to pass a NULL instead of
    a library pointer.
INPUTS

    library - pointer to a library node
NOTE

```c
    [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) writers must pass a SegList pointer or NULL back from their
    open point.  This value is used by the system, and not visible as
    a return code from CloseLibrary.
```
SEE ALSO

```c
    [OpenLibrary](../Includes_and_Autodocs_2._guide/node0367.html)
```
