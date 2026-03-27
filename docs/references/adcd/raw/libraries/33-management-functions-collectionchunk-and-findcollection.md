# 33 / / Management Functions / CollectionChunk() and FindCollection()


[PropChunk()](../Libraries_Manual_guide/node0434.html) keeps only one copy of the declared chunk (the one currently
in scope).  [CollectionChunk()](../Includes_and_Autodocs_2._guide/node01BC.html) collects and keeps all instances of a
specified chunk.  This is useful for chunks such as the [ILBM](../Libraries_Manual_guide/node045D.html#line8) CRNG chunk,
which can appear multiple times in a [FORM](../Libraries_Manual_guide/node042A.html#line7), and which don't override
previous instances of themselves.  CollectionChunk() is called identically
to PropChunk():


```c
    error = CollectionChunk (iff, type, id);
```
When you wish to find the collected chunks currently in scope, you use the
function [FindCollection()](../Includes_and_Autodocs_2._guide/node01C1.html):


```c
    ci = FindCollection (iff, type, id);
```
You will be returned a pointer to a [CollectionItem](../Includes_and_Autodocs_2._guide/node010B.html#line99), which is part of a
singly-linked list of all copies of the specified chunk collected so far
that are currently in scope.


```c
    struct CollectionItem {
            struct CollectionItem   *ci_Next;
            LONG                    ci_Size;
            UBYTE                   *ci_Data;
    };
```
The size of this copy of the chunk is in the CollectionItem's ci_Size
field.  The ci_Data field points to the chunk data itself.  The ci_Next
field points to the next CollectionItem in the list.  The last element in
the list has ci_Next set to NULL.

The most recently-encountered instance of the chunk will be first in the
list, followed by earlier chunks.  Some might consider this ordering
backwards.

If NULL is returned, the specified chunk was never encountered.

