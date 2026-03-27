---
title: 33 / Context Functions / Context Nodes
manual: libraries
chapter: libraries
section: 33-context-functions-context-nodes
functions: [CurrentChunk, ParentChunk]
libraries: [iffparse.library]
---

# 33 / Context Functions / Context Nodes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The current context is said to be the top element on the stack.
Contextual information is stored in a structure called a [ContextNode](autodocs-2.0/includes-libraries-iffparse-h.md):


```c
    struct ContextNode {
            struct MinNode  cn_Node;
            LONG            cn_ID;
            LONG            cn_Type;
            LONG            cn_Size; /*  Size of this chunk             */
            LONG            cn_Scan; /*  # of bytes read/written so far */
            /*  There are private fields hiding here.  */
            };
```
 [CurrentChunk()](libraries/33-context-nodes-currentchunk.md)    [ParentChunk()](libraries/33-context-nodes-parentchunk.md) 

---

## See Also

- [CurrentChunk — iffparse.library](../autodocs/iffparse.library.md#currentchunk)
- [ParentChunk — iffparse.library](../autodocs/iffparse.library.md#parentchunk)
