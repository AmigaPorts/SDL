# dos.library/Input



NAME

    Input -- Identify the program's initial input file handle
SYNOPSIS

```c
    file = Input()
    D0

    BPTR Input(void)
```
FUNCTION

```c
    Input() is used to identify the initial input stream allocated when
    the program was initiated.  Never close the filehandle returned by
    Input!
```
RESULTS

    file - BCPL pointer to a file handle
SEE ALSO

```c
    [Output()](../Includes_and_Autodocs_2._guide/node02D8.html), [SelectInput()](../Includes_and_Autodocs_2._guide/node02EE.html)
```
