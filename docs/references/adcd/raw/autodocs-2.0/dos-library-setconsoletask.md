# dos.library/SetConsoleTask



NAME

```c
    SetConsoleTask -- Sets the default console for the process (V36)
```
SYNOPSIS

```c
    oldport = SetConsoleTask(port)
    D0                        D1

    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *SetConsoleTask(struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *)
```
FUNCTION

```c
    Sets the default console task's port (pr_ConsoleTask) for the
    current process.
```
INPUTS

    port - The pr_MsgPort of the default console handler for the process
RESULT

    oldport - The previous ConsoleTask value.
SEE ALSO

```c
    [GetConsoleTask()](../Includes_and_Autodocs_2._guide/node02B5.html), [Open()](../Includes_and_Autodocs_2._guide/node02D6.html)
```
