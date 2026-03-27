# iffparse.library/StopChunks



NAME

    StopChunks -- Declare many stop chunks at once.
SYNOPSIS

```c
    error = StopChunks (iff, list, n)
     d0                 a0    a1  d0

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    LONG             *list;
    LONG             n;
```
FUNCTION

```c
    (is to [StopChunk()](../Includes_and_Autodocs_2._guide/node01D9.html) as [PropChunks()](../Includes_and_Autodocs_2._guide/node01D4.html) is to PropChunk().)
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
    list    - pointer to array of longword chunk types and identifiers.
    n       - number of chunks to declare.
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [StopChunk()](../Includes_and_Autodocs_2._guide/node01D9.html)
```
