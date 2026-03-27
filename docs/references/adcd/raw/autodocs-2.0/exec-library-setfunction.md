# exec.library/SetFunction



NAME

    SetFunction -- change a function vector in a library
SYNOPSIS

```c
    oldFunc = SetFunction(library, funcOffset, funcEntry)
    D0                    A1       A0.W        D0

    APTR SetFunction(struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *,LONG,APTR);
```
FUNCTION

    SetFunction is a functional way of changing where vectors in a
    library point.  They are changed in such a way that the
    checksumming process will never falsely declare a library to be
    invalid.
WARNING

    If you use SetFunction on a function that can be called from
    interrupts, you are obligated to provide your own arbitration.
NOTE

```c
    SetFunction cannot be used on non-standard libraries like pre-V36
    dos.library.  Here you must manually [Forbid()](../Includes_and_Autodocs_2._guide/node0353.html), preserve all 6
    original bytes, set the new vector, [SumLibrary()](../Includes_and_Autodocs_2._guide/node0384.html), then [Permit()](../Includes_and_Autodocs_2._guide/node0369.html).
```
INPUTS

    library    - a pointer to the library to be changed
    funcOffset - the offset of the function to be replaced
    funcEntry  - pointer to new function
RESULTS

    oldFunc    - pointer to the old function that was just replaced
