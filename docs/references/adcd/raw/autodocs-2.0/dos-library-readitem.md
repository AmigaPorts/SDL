# dos.library/ReadItem



NAME

```c
    ReadItem - reads a single argument/name from command line (V36)
```
SYNOPSIS

```c
    value = ReadItem(buffer, maxchars, input)
    D0                D1        D2      D3

    LONG ReadItem(STRPTR, LONG, struct [CSource](../Includes_and_Autodocs_2._guide/node0076.html#line62) *)
```
FUNCTION

```c
    Reads a "word" from either [Input()](../Includes_and_Autodocs_2._guide/node02BF.html) (buffered), or via [CSource](../Includes_and_Autodocs_2._guide/node0076.html#line62), if it
    is non-NULL (see [<dos/rdargs.h>](../Includes_and_Autodocs_2._guide/node0076.html) for more information).  Handles
    quoting and some '*' substitutions (*e and *n) inside quotes (only).
    See [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html) for a listing of values returned by ReadItem()
    (ITEM_XXXX).  A "word" is delimited by whitespace, quotes, or an EOF.

    ReadItem always unreads the last thing read (UnGetC(fh,-1)) so the
    caller can find out what the terminator was.
```
INPUTS

```c
    buffer   - buffer to store word in.
    maxchars - size of the buffer
    input    - [CSource](../Includes_and_Autodocs_2._guide/node0076.html#line62) input or NULL (uses FGetC(Input()))
```
RESULT

```c
    value - See [<dos/dos.h>](../Includes_and_Autodocs_2._guide/node0068.html) for return values.
```
SEE ALSO

```c
    [ReadArgs()](../Includes_and_Autodocs_2._guide/node02E1.html), [FindArg()](../Includes_and_Autodocs_2._guide/node02A5.html), [UnGetC()](../Includes_and_Autodocs_2._guide/node0305.html), [FGetC()](../Includes_and_Autodocs_2._guide/node02A2.html), [Input()](../Includes_and_Autodocs_2._guide/node02BF.html), [<dos/dos.h>](../Includes_and_Autodocs_2._guide/node0068.html),
    [<dos/rdargs.h>](../Includes_and_Autodocs_2._guide/node0076.html), [FreeArgs()](../Includes_and_Autodocs_2._guide/node02AF.html)
```
