# dos.library/FreeArgs



NAME

```c
    FreeArgs - Free allocated memory after [ReadArgs()](../Includes_and_Autodocs_2._guide/node02E1.html) (V36)
```
SYNOPSIS

```c
    FreeArgs(rdargs)
               D1

    void FreeArgs(struct [RDArgs](../Includes_and_Autodocs_2._guide/node0076.html#line96) *)
```
FUNCTION

```c
    Frees memory allocated to return arguments in from [ReadArgs()](../Includes_and_Autodocs_2._guide/node02E1.html).  If
    [ReadArgs](../Includes_and_Autodocs_2._guide/node02E1.html) allocated the [RDArgs](../Includes_and_Autodocs_2._guide/node0076.html#line96) structure it will be freed.
```
INPUTS

```c
    rdargs - structure returned from [ReadArgs()](../Includes_and_Autodocs_2._guide/node02E1.html)
```
SEE ALSO

```c
    [ReadArgs()](../Includes_and_Autodocs_2._guide/node02E1.html), [ReadItem()](../Includes_and_Autodocs_2._guide/node02E2.html), [FindArg()](../Includes_and_Autodocs_2._guide/node02A5.html)
```
