# dos.library/SetFileSysTask



NAME

```c
    SetFileSysTask -- Sets the default filesystem for the process (V36)
```
SYNOPSIS

```c
    oldport = SetFileSysTask(port)
    D0                        D1

    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *SetFileSysTask(struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *)
```
FUNCTION

```c
    Sets the default filesystem task's port (pr_FileSystemTask) for the
    current process.
```
INPUTS

    port - The pr_MsgPort of the default filesystem for the process
RESULT

    oldport - The previous FileSysTask value
SEE ALSO

```c
    [GetFileSysTask()](../Includes_and_Autodocs_2._guide/node02B8.html), [Open()](../Includes_and_Autodocs_2._guide/node02D6.html)
```
