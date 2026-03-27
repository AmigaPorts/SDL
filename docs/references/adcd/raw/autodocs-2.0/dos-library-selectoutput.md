# dos.library/SelectOutput



NAME

```c
    SelectOutput -- Select a filehandle as the default input channel (V36)
```
SYNOPSIS

```c
    old_fh = SelectOutput(fh)
    D0                    D1

    BPTR SelectOutput(BPTR)
```
FUNCTION

```c
    Set the current output as the default output for the process.
    This changes the value returned by [Output()](../Includes_and_Autodocs_2._guide/node02D8.html).  old_fh should
    be closed or saved as needed.
```
INPUTS

    fh     - Newly desired output handle
RESULT

    old_fh - Previous current output
SEE ALSO

```c
    [Output()](../Includes_and_Autodocs_2._guide/node02D8.html), [SelectInput()](../Includes_and_Autodocs_2._guide/node02EE.html), [Input()](../Includes_and_Autodocs_2._guide/node02BF.html)
```
