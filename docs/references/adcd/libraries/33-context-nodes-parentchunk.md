---
title: 33 / / Context Nodes / ParentChunk()
manual: libraries
chapter: libraries
section: 33-context-nodes-parentchunk
functions: [ParentChunk]
libraries: [iffparse.library]
---

# 33 / / Context Nodes / ParentChunk()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To find the parent of a context, you call [ParentChunk()](autodocs-2.0/iffparse-library-parentchunk.md) on the relevant
[ContextNode](libraries/33-context-functions-context-nodes.md):


```c
    parentnode = ParentChunk(currentnode);
```
If there is no parent context, NULL is returned.

---

## See Also

- [ParentChunk — iffparse.library](../autodocs/iffparse.library.md#parentchunk)
