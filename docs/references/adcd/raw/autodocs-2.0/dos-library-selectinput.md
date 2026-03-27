# dos.library/SelectInput



NAME

```c
    SelectInput -- Select a filehandle as the default input channel (V36)
```
SYNOPSIS

```c
    old_fh = SelectInput(fh)
    D0                   D1

    BPTR SelectInput(BPTR)
```
FUNCTION

```c
    Set the current input as the default input for the process.
    This changes the value returned by [Input()](../Includes_and_Autodocs_2._guide/node02BF.html).  old_fh should
    be closed or saved as needed.
```
INPUTS

    fh     - Newly default input handle
RESULT

    old_fh - Previous default input filehandle
SEE ALSO

```c
    [Input()](../Includes_and_Autodocs_2._guide/node02BF.html), [SelectOutput()](../Includes_and_Autodocs_2._guide/node02EF.html), [Output()](../Includes_and_Autodocs_2._guide/node02D8.html)
```
