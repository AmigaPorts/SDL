# dos.library/MatchEnd



NAME

```c
    MatchEnd -- Free storage allocated for [MatchFirst()/MatchNext()](../Includes_and_Autodocs_2._guide/node02CE.html) (V36)
```
SYNOPSIS

```c
    MatchEnd(AnchorPath)
                 D1

    VOID MatchEnd(struct [AnchorPath](../Includes_and_Autodocs_2._guide/node0070.html#line53) *)
```
FUNCTION

    Return all storage associated with a given search.
INPUTS

```c
    [AnchorPath](../Includes_and_Autodocs_2._guide/node0070.html#line53) - Anchor used for [MatchFirst()/MatchNext()](../Includes_and_Autodocs_2._guide/node02CE.html)
                 MUST be longword aligned!
```
SEE ALSO

```c
    [MatchFirst()](../Includes_and_Autodocs_2._guide/node02CD.html), [ParsePattern()](../Includes_and_Autodocs_2._guide/node02DB.html), [Examine()](../Includes_and_Autodocs_2._guide/node029C.html), [CurrentDir()](../Includes_and_Autodocs_2._guide/node028F.html), [Examine()](../Includes_and_Autodocs_2._guide/node029C.html),
    [MatchNext()](../Includes_and_Autodocs_2._guide/node02CE.html), [ExNext()](../Includes_and_Autodocs_2._guide/node02A0.html), [<dos/dosasl.h>](../Includes_and_Autodocs_2._guide/node0070.html)
```
