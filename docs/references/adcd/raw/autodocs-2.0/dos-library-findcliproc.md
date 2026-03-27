# dos.library/FindCliProc



NAME

```c
    FindCliProc -- returns a pointer to the requested CLI process (V36)
```
SYNOPSIS

```c
    proc = FindCliProc(num)
    D0             D1

    struct [Process](../Includes_and_Autodocs_2._guide/node0078.html#line38) *FindCliProc(LONG)
```
FUNCTION

```c
    This routine returns a pointer to the CLI process associated with the
    given CLI number.  If the process isn't an active CLI process, NULL is
    returned.  NOTE: should normally be called inside a [Forbid()](../Includes_and_Autodocs_2._guide/node0353.html), if you
    must use this function at all.
```
INPUTS

```c
    num  - [Task](../Includes_and_Autodocs_2._guide/node008E.html#line25) number of CLI process
```
RESULT

    proc - Pointer to given CLI process
SEE ALSO

```c
    [Cli()](../Includes_and_Autodocs_2._guide/node0287.html), [Forbid()](../Includes_and_Autodocs_2._guide/node0353.html), [MaxCli()](../Includes_and_Autodocs_2._guide/node02D1.html)
```
