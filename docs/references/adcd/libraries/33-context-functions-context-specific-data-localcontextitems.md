---
title: 33 / Context Functions / Context-Specific Data: LocalContextItems
manual: libraries
chapter: libraries
section: 33-context-functions-context-specific-data-localcontextitems
functions: [AllocLocalItem, LocalItemData]
libraries: [iffparse.library]
---

# 33 / Context Functions / Context-Specific Data: LocalContextItems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[ContextNode](libraries/33-context-functions-context-nodes.md)s can contain application data specific to that context.  These
data objects are called [LocalContextItem](autodocs-2.0/includes-libraries-iffparse-h.md)s.  LocalContextItems (LCIs) are a
grey-box structure which contain a type, ID and identification field.
LCIs are used to store context-sensitive data.  The format of this data is
application-defined.  A ContextNode can contain as many LCIs as you want.



        __________________
       |                  |
       |   ContextNode    |
       |   -----------    |
       |  Type - ID_ILBM  |
       |  ID   - ID_BODY  |
       |__________________|
                |
        ________|_________      _______________________________
       |                  |    |                               |
       |   ContextNode    |    |       LocalContextItem        |
       |   -----------    |____|       ----------------        |
       |  Type - ID_ILBM  |    |  Type  - ID_ILBM              |
       |  ID   - ID_FORM  |    |  ID    - ID_BMHD              |
       |__________________|    |  Ident - IFFLCI_PROP          |
                |              |_______________________________|
        ________|_________      _______________________________
       |                  |    |                               |
       |   ContextNode    |    |       LocalContextItem        |
       |   -----------    |    |       ----------------        |
       |  Type - ID_ZOID  |____|  Type  - ID_ILBM              |
       |  ID   - ID_LIST  |    |  ID    - ID_BMHD              |
       |__________________|    |  Ident - IFFLCI_ENTRYHANDLER  |
                |              |_______________________________|
        ________|______________________________________________
       |                                                       |
       |                   I F F H a n d l e                   |
       |_______________________________________________________|


                 Figure 33-3: IFFParse Context Stack
Figure 33-3 shows the relationship between the [IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md), the
[ContextNode](libraries/33-context-functions-context-nodes.md)s, and the LCIs.  The IFFHandle is the root of the tree, so to
speak.  ContextNodes "grow" out of the IFFHandle.  In turn, LCIs "grow"
out of the ContextNodes.  What grows out of an LCI is client-defined.

 [AllocLocalItem()](libraries/33-context-specific-data-localcontextitems-alloclocalitem.md)    [LocalItemData()](libraries/33-context-specific-data-localcontextitems-localitemdata.md) 

---

## See Also

- [AllocLocalItem — iffparse.library](../autodocs/iffparse.library.md#alloclocalitem)
- [LocalItemData — iffparse.library](../autodocs/iffparse.library.md#localitemdata)
