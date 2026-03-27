# exec.library/AddDevice



NAME

    AddDevice -- add a device to the system
SYNOPSIS

```c
    AddDevice(device)
              A1

    void AddDevice(struct [Device](../Includes_and_Autodocs_2._guide/node0087.html#line25) *);
```
FUNCTION

    This function adds a new device to the system device list, making
    it available to other programs.  The device must be ready to be
    opened at this time.
INPUTS

    device - pointer to a properly initialized device node
SEE ALSO

```c
    [RemDevice](../Includes_and_Autodocs_2._guide/node036F.html), [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html), [CloseDevice](../Includes_and_Autodocs_2._guide/node04CC.html), [MakeLibrary](../Includes_and_Autodocs_2._guide/node0361.html)
```
