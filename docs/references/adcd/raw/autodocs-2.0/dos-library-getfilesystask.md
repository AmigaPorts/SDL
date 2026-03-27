# dos.library/GetFileSysTask



NAME

```c
    GetFileSysTask -- Returns the default filesystem for the process (V36)
```
SYNOPSIS

```c
    port = GetFileSysTask()
    D0

    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *GetFileSysTask(void)
```
FUNCTION

```c
    Returns the default filesystem task's port (pr_FileSystemTask) for the
    current process.
```
RESULT

    port - The pr_MsgPort of the filesystem, or NULL.
SEE ALSO

```c
    [SetFileSysTask()](../Includes_and_Autodocs_2._guide/node02F7.html), [Open()](../Includes_and_Autodocs_2._guide/node02D6.html)
```
