# amiga.lib/ArgArrayDone



NAME

```c
    ArgArrayDone -- release the memory allocated by a previous call
                    to [ArgArrayInit()](../Includes_and_Autodocs_2._guide/node013D.html). (V36)
```
SYNOPSIS

```c
    ArgArrayDone();

    VOID ArgArrayDone(VOID);
```
FUNCTION

```c
    This function frees memory and does cleanup required after a
    call to [ArgArrayInit()](../Includes_and_Autodocs_2._guide/node013D.html). Don't call this until you are done using
    the ToolTypes argument strings.
```
SEE ALSO

```c
    [ArgArrayInit()](../Includes_and_Autodocs_2._guide/node013D.html)
```
