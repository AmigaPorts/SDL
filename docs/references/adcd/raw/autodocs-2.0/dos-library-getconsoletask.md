# dos.library/GetConsoleTask



NAME

```c
    GetConsoleTask -- Returns the default console for the process (V36)
```
SYNOPSIS

```c
    port = GetConsoleTask()
    D0

    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *GetConsoleTask(void)
```
FUNCTION

```c
    Returns the default console task's port (pr_ConsoleTask) for the
    current process.
```
RESULT

    port - The pr_MsgPort of the console handler, or NULL.
SEE ALSO

```c
    [SetConsoleTask()](../Includes_and_Autodocs_2._guide/node02F3.html), [Open()](../Includes_and_Autodocs_2._guide/node02D6.html)
```
