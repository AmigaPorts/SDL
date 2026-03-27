---
title: 33 / / Management Functions / CollectionChunk() and FindCollection()
manual: libraries
chapter: libraries
section: 33-management-functions-collectionchunk-and-findcollection
functions: [CollectionChunk, FindCollection, PropChunk]
libraries: [iffparse.library]
---

# 33 / / Management Functions / CollectionChunk() and FindCollection()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[PropChunk()](libraries/33-controlling-parsing-propchunk-findprop.md) keeps only one copy of the declared chunk (the one currently
in scope).  [CollectionChunk()](autodocs-2.0/iffparse-library-collectionchunk.md) collects and keeps all instances of a
specified chunk.  This is useful for chunks such as the [ILBM](libraries/33-iffparse-library-iff-form-specifications.md) CRNG chunk,
which can appear multiple times in a [FORM](libraries/33-the-structure-of-iff-files-composite-data-types.md), and which don't override
previous instances of themselves.  CollectionChunk() is called identically
to PropChunk():


```c
    error = CollectionChunk (iff, type, id);
```
When you wish to find the collected chunks currently in scope, you use the
function [FindCollection()](autodocs-2.0/iffparse-library-findcollection.md):


```c
    ci = FindCollection (iff, type, id);
```
You will be returned a pointer to a [CollectionItem](autodocs-2.0/includes-libraries-iffparse-h.md), which is part of a
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

---

## See Also

- [CollectionChunk — iffparse.library](../autodocs/iffparse.library.md#collectionchunk)
- [FindCollection — iffparse.library](../autodocs/iffparse.library.md#findcollection)
- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
