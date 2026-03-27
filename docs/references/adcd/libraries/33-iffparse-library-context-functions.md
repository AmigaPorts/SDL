---
title: 33 IFFParse Library / Context Functions
manual: libraries
chapter: libraries
section: 33-iffparse-library-context-functions
functions: [PopChunk, PushChunk]
libraries: [iffparse.library]
---

# 33 IFFParse Library / Context Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Internally, IFFParse maintains [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) nesting and scoping context via a
context stack.  The [PushChunk()](libraries/33-creating-chunks-in-a-file-pushchunk.md) and [PopChunk()](libraries/33-creating-chunks-in-a-file-popchunk.md) functions get their names
from this basic idea of the iffparse.library.  Direct access to this stack
is not allowed.  However, many functions are provided to assist in
examining and manipulating the context stack.


    About the Context Stack.
    ------------------------
    It is probably easier to think of a stack of blocks on a table in
    front of you when reading this discussion.
As the nesting level increases (as would happen when parsing a nested [LIST](libraries/33-the-structure-of-iff-files-composite-data-types.md)
or [FORM](libraries/33-the-structure-of-iff-files-composite-data-types.md)), the depth of the context stack increases; new elements are added
to the top.  When these contexts expire, the [ContextNode](libraries/33-context-functions-context-nodes.md)s are deleted and
the stack shrinks.

 [Context Nodes](libraries/33-context-functions-context-nodes.md) 
 [The Default Context](libraries/33-context-functions-the-default-context.md) 
 [Context-Specific Data: LocalContextItems](libraries/33-context-functions-context-specific-data-localcontextitems.md) 
 [Storing LCIs](libraries/33-context-functions-storing-lcis.md) 
 [Some Interesting Internal Details](libraries/33-context-functions-some-interesting-internal-details.md) 

---

## See Also

- [PopChunk — iffparse.library](../autodocs/iffparse.library.md#popchunk)
- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)
