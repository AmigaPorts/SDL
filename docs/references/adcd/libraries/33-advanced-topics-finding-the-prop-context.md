---
title: 33 / Advanced Topics / Finding The PROP Context
manual: libraries
chapter: libraries
section: 33-advanced-topics-finding-the-prop-context
functions: [FindPropContext, StoreLocalItem]
libraries: [iffparse.library]
---

# 33 / Advanced Topics / Finding The PROP Context

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Earlier it was mentioned that supplying a position value of [IFFSLI_PROP](libraries/33-storing-lcis-storelocalitem.md) to
[StoreLocalItem()](libraries/33-storing-lcis-storelocalitem.md) would store it in the topmost property scope.
[FindPropContext()](autodocs-2.0/iffparse-library-findpropcontext.md) is the routine that finds that topmost context.

Property chunks (such as the [BMHD](libraries/33-form-ilbm-interpreting-ilbms.md), [CMAP](libraries/33-form-ilbm-interpreting-ilbms.md), and others) have dominion over
the [FORM](libraries/33-the-structure-of-iff-files-composite-data-types.md) that contains them; they are said to be "in scope" and their
definition persists until the FORM's context ends.  Thus, a property chunk
has a scoping level equal to the FORM that contains it; when the FORM
ends, the property dies with it.

Consider a more complicated example.  Suppose you have a [LIST](libraries/33-the-structure-of-iff-files-composite-data-types.md) with a [PROP](libraries/33-the-structure-of-iff-files-composite-data-types.md)
in it.  PROPs are the global variables of LISTs; thus a property chunk
declared in a PROP will persist until the LIST's context ends.

This is what [FindPropContext()](autodocs-2.0/iffparse-library-findpropcontext.md) is looking for; a context level in which a
property chunk may be installed.

[FindPropContext()](autodocs-2.0/iffparse-library-findpropcontext.md) starts at the parent of the current context (second from
the top of the context stack) and starts searching downward, looking for
the first [FORM](libraries/33-the-structure-of-iff-files-composite-data-types.md) or [LIST](libraries/33-the-structure-of-iff-files-composite-data-types.md) context it finds.  If it finds one, it returns a
pointer to that [ContextNode](libraries/33-context-functions-context-nodes.md).  If it can't find a suitable context level,
it returns NULL.

[FindPropContext()](autodocs-2.0/iffparse-library-findpropcontext.md) is called as follows:


```c
    struct ContextNode *cn;

    cn = FindPropContext (iff);
```

---

## See Also

- [FindPropContext — iffparse.library](../autodocs/iffparse.library.md#findpropcontext)
- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)
