# dos.library/UnLoadSeg



NAME

```c
    UnLoadSeg -- Unload a seglist previously loaded by [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html)
```
SYNOPSIS

```c
    success = UnLoadSeg( seglist )
    D0                     D1

    BOOL UnLoadSeg(BPTR)
```
FUNCTION

```c
    Unload a seglist loaded by [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html).  'seglist' may be zero.
    Overlaid segments will have all needed cleanup done, including
    closing files.
```
INPUTS

    seglist - BCPL pointer to a segment identifier
RESULTS

    success - returns 0 if a NULL seglist was passed or if it failed
              to close an overlay file.  NOTE: this function returned
              a random value before V36!
SEE ALSO

```c
    [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html), [InternalLoadSeg()](../Includes_and_Autodocs_2._guide/node02C0.html), [InternalUnLoadSeg()](../Includes_and_Autodocs_2._guide/node02C1.html)
```
