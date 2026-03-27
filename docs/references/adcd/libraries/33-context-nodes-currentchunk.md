---
title: 33 / / Context Nodes / CurrentChunk()
manual: libraries
chapter: libraries
section: 33-context-nodes-currentchunk
functions: [CurrentChunk]
libraries: [iffparse.library]
---

# 33 / / Context Nodes / CurrentChunk()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can obtain a pointer to the current [ContextNode](libraries/33-context-functions-context-nodes.md) through the function
[CurrentChunk()](autodocs-2.0/iffparse-library-currentchunk.md):


```c
    currentnode = CurrentChunk (iff);
```
The [ContextNode](libraries/33-context-functions-context-nodes.md) tells you the type, ID, and size of the currently active
chunk.  If there is no currently active context, NULL is returned.

---

## See Also

- [CurrentChunk — iffparse.library](../autodocs/iffparse.library.md#currentchunk)
