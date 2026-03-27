# dos.library/MatchNext



NAME

```c
    MatchNext - Finds the next file or directory that matches pattern (V36)
```
SYNOPSIS

```c
    error = MatchNext(AnchorPath)
    D0                    D1

    LONG MatchNext(struct [AnchorPath](../Includes_and_Autodocs_2._guide/node0070.html#line53) *)
```
FUNCTION

```c
    Locates the next file or directory that matches a given pattern.
    See [<dos/dosasl.h>](../Includes_and_Autodocs_2._guide/node0070.html) for more information.  Various bits in the flags
    allow the application to control the operation of MatchNext().

    See [MatchFirst()](../Includes_and_Autodocs_2._guide/node02CD.html) for other notes.
```
INPUTS

```c
    [AnchorPath](../Includes_and_Autodocs_2._guide/node0070.html#line53) - Place holder for search.  MUST be longword aligned!
```
RESULT

```c
    error - 0 for success or error code.  (Opposite of most Dos calls)
```
BUGS

```c
    See [MatchFirst()](../Includes_and_Autodocs_2._guide/node02CD.html).
```
SEE ALSO

```c
    [MatchFirst()](../Includes_and_Autodocs_2._guide/node02CD.html), [ParsePattern()](../Includes_and_Autodocs_2._guide/node02DB.html), [Examine()](../Includes_and_Autodocs_2._guide/node029C.html), [CurrentDir()](../Includes_and_Autodocs_2._guide/node028F.html), [Examine()](../Includes_and_Autodocs_2._guide/node029C.html),
    [MatchEnd()](../Includes_and_Autodocs_2._guide/node02CC.html), [ExNext()](../Includes_and_Autodocs_2._guide/node02A0.html), [<dos/dosasl.h>](../Includes_and_Autodocs_2._guide/node0070.html)
```
