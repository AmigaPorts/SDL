# exec.library/FreeEntry



NAME

    FreeEntry -- free many regions of memory
SYNOPSIS

```c
    FreeEntry(memList)
              A0
    void FreeEntry(struct [MemList](../Includes_and_Autodocs_2._guide/node0089.html#line57) *);
```
FUNCTION

```c
    This function takes a memList structure (as returned by AllocEntry)
    and frees all the entries.
```
INPUTS

```c
    memList -- pointer to structure filled in with [MemEntry](../Includes_and_Autodocs_2._guide/node0089.html#line41)
               structures
```
SEE ALSO

```c
    [AllocEntry](../Includes_and_Autodocs_2._guide/node0331.html)
```
