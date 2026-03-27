# dos.library/InternalLoadSeg



NAME

```c
    InternalLoadSeg -- Low-level load routine (V36)
```
SYNOPSIS

```c
    seglist = InternalLoadSeg(fh,table,functionarray,stack)
    D0                        D0  A0        A1        A2

    BPTR InternalLoadSeg(BPTR,BPTR,LONG *,LONG *)
```
FUNCTION

```c
    Loads from fh.  Table is used when loading an overlay, otherwise
    should be NULL.  Functionarray is a pointer to an array of functions.
    Note that the current Seek position after loading may be at any point
    after the last hunk loaded.  The filehandle will not be closed.  If a
    stacksize is encoded in the file, the size will be stuffed in the
    LONG pointed to by stack.  This LONG should be initialized to your
    default value: InternalLoadSeg() will not change it if no stacksize
    is found. Clears unused portions of Code and Data hunks (as well as
    BSS hunks).  (This also applies to [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html) and [NewLoadSeg()](../Includes_and_Autodocs_2._guide/node02D4.html)).

    If the file being loaded is an overlaid file, this will return
    -(seglist).  All other results will be positive.

    NOTE to overlay users: InternalLoadSeg() does NOT return seglist in
    both D0 and D1, as [LoadSeg](../Includes_and_Autodocs_2._guide/node02C5.html) does.  The current ovs.asm uses [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html),
    and assumes returns are in D1.  We will support this for [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html)
    ONLY.
```
INPUTS

```c
    fh            - Filehandle to load from.
    table         - When loading an overlay, otherwise ignored.
    functionarray - Array of function to be used for read, alloc, and free.
       FuncTable[0] ->  Actual = ReadFunc(readhandle,buffer,length),DOSBase
                        D0                D1         A0     D0      A6
       FuncTable[1] ->  Memory = AllocFunc(size,flags), Execbase
                        D0                 D0   D1      a6
       FuncTable[2] ->  FreeFunc(memory,size), Execbase
                                 A1     D0     a6
    stack         - Pointer to storage (ULONG) for stacksize.
```
RESULT

    seglist       - Seglist loaded or NULL.  NOT returned in D1!
BUGS

    Really should use tags.
SEE ALSO

```c
    [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html), [UnLoadSeg()](../Includes_and_Autodocs_2._guide/node0306.html), [NewLoadSeg()](../Includes_and_Autodocs_2._guide/node02D4.html), [InternalUnLoadSeg()](../Includes_and_Autodocs_2._guide/node02C1.html)
```
