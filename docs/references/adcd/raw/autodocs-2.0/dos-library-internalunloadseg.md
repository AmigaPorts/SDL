# dos.library/InternalUnLoadSeg



NAME

```c
    InternalUnLoadSeg -- Unloads a seglist loaded with [InternalLoadSeg()](../Includes_and_Autodocs_2._guide/node02C0.html)
                         (V36)
```
SYNOPSIS

```c
    success = InternalUnLoadSeg(seglist,FreeFunc)
      D0                          D1       A1

    BOOL InternalUnLoadSeg(BPTR,void (*)(STRPTR,ULONG))
```
FUNCTION

```c
    Unloads a seglist using freefunc to free segments.  Freefunc is called
    as for [InternalLoadSeg](../Includes_and_Autodocs_2._guide/node02C0.html).  NOTE: will call [Close()](../Includes_and_Autodocs_2._guide/node028A.html) for overlaid
    seglists.
```
INPUTS

    seglist  - Seglist to be unloaded
    FreeFunc - Function called to free memory
RESULT

```c
    success - returns whether everything went OK (since this may close
              files).  Also returns FALSE if seglist was NULL.
```
BUGS

    Really should use tags
SEE ALSO

```c
    [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html), [UnLoadSeg()](../Includes_and_Autodocs_2._guide/node0306.html), [InternalLoadSeg()](../Includes_and_Autodocs_2._guide/node02C0.html), NewUnLoadSeg(), [Close()](../Includes_and_Autodocs_2._guide/node028A.html)
```
