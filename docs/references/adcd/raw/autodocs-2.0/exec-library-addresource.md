# exec.library/AddResource



NAME

    AddResource -- add a resource to the system
SYNOPSIS

```c
    AddResource(resource)
                A1

    void AddResource(APTR);
```
FUNCTION

```c
    This function adds a new resource to the system and makes it
    available to other users.  The resource must be ready to be called
    at this time.

    Resources currently have no system-imposed structure, however they
    must start with a standard named node (LN_SIZE), and should with
    a standard [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) node (LIB_SIZE).
```
INPUTS

    resource - pointer an initialized resource node
SEE ALSO

```c
    [RemResource](../Includes_and_Autodocs_2._guide/node0375.html), [OpenResource](../Includes_and_Autodocs_2._guide/node0368.html), [MakeLibrary](../Includes_and_Autodocs_2._guide/node0361.html)
```
