# 18 / What is a Library? / Minimum Subset of Library Vectors


The first four code vectors of a library must be the following entries:

OPEN

```c
    is the entry point called by the function [OpenLibrary()](../Libraries_Manual_guide/node028E.html#line15).  In most
    libraries, OPEN increments the library variable [lib_OpenCnt](../Libraries_Manual_guide/node0292.html#line7). This
    variable is also used by CLOSE and EXPUNGE.
```
CLOSE

```c
    is the entry point called by the function [CloseLibrary()](../Libraries_Manual_guide/node028E.html#line91). It
    decrements the library variable [lib_OpenCnt](../Libraries_Manual_guide/node0292.html#line7) and may do a delayed
    EXPUNGE.
```
EXPUNGE

    prepares the library for removal from the system. This often includes
    deallocating memory resources that were reserved during
    initialization. EXPUNGE not only frees the memory allocated for data
    structures, but also the areas reserved for the library node itself.
RESERVED

    is a fourth function vector reserved for future use. It must always
    return zero.
