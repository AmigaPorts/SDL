# dos.library/MaxCli



NAME

```c
    MaxCli -- returns the highest CLI process number possibly in use (V36)
```
SYNOPSIS

```c
    number = MaxCli()
    D0

    LONG MaxCli(void)
```
FUNCTION

```c
    Returns the highest CLI number that may be in use.  CLI numbers are
    reused, and are usually as small as possible.  To find all CLIs, scan
    using [FindCliProc()](../Includes_and_Autodocs_2._guide/node02A6.html) from 1 to MaxCLI().  The number returned by
    MaxCli() may change as processes are created and destroyed.
```
RESULT

    number - The highest CLI number that _may_ be in use.
SEE ALSO

```c
    [FindCliProc()](../Includes_and_Autodocs_2._guide/node02A6.html), [Cli()](../Includes_and_Autodocs_2._guide/node0287.html)
```
