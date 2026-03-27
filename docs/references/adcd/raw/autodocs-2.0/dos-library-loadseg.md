# dos.library/LoadSeg



NAME

    LoadSeg -- Scatterload a loadable file into memory
SYNOPSIS

```c
    seglist = LoadSeg( name )
    D0                 D1

    BPTR LoadSeg(STRPTR)
```
FUNCTION

```c
    The file 'name' should be a load module produced by the linker.
    LoadSeg() scatterloads the CODE, DATA and BSS segments into memory,
    chaining together the segments with BPTR's on their first words.
    The end of the chain is indicated by a zero.  There can be any number
    of segments in a file.  All necessary relocation is handled by
    LoadSeg().

    In the event of an error any blocks loaded will be unloaded and a
    NULL result returned.

    If the module is correctly loaded then the output will be a pointer
    at the beginning of the list of blocks. Loaded code is unloaded via
    a call to [UnLoadSeg()](../Includes_and_Autodocs_2._guide/node0306.html).
```
INPUTS

    name - pointer to a null-terminated string
RESULTS

    seglist - BCPL pointer to a seglist
SEE ALSO

```c
    [UnLoadSeg()](../Includes_and_Autodocs_2._guide/node0306.html), [InternalLoadSeg()](../Includes_and_Autodocs_2._guide/node02C0.html), [InternalUnLoadSeg()](../Includes_and_Autodocs_2._guide/node02C1.html), [CreateProc()](../Includes_and_Autodocs_2._guide/node028E.html),
    [CreateNewProc()](../Includes_and_Autodocs_2._guide/node028D.html), [NewLoadSeg()](../Includes_and_Autodocs_2._guide/node02D4.html).
```
