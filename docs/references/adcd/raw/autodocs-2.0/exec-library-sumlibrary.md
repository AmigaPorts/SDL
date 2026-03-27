# exec.library/SumLibrary



NAME

    SumLibrary -- compute and check the checksum on a library
SYNOPSIS

```c
    SumLibrary(library)
               A1

    void SumLibrary(struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *);
```
FUNCTION

```c
    SumLibrary computes a new checksum on a library.  It can also be
    used to check an old checksum.  If an old checksum does not match,
    and the library has not been marked as changed, then the system
    will call [Alert()](../Includes_and_Autodocs_2._guide/node032E.html).

    This call could also be periodically made by some future
    system-checking task.
```
INPUTS

    library - a pointer to the library to be changed
NOTE

    An alert will occur if the checksum fails.
SEE ALSO

```c
    [SetFunction](../Includes_and_Autodocs_2._guide/node037C.html)
```
