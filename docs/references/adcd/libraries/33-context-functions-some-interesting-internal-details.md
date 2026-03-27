---
title: 33 / Context Functions / Some Interesting Internal Details
manual: libraries
chapter: libraries
section: 33-context-functions-some-interesting-internal-details
functions: [FindLocalItem, FindProp, PropChunk]
libraries: [iffparse.library]
---

# 33 / Context Functions / Some Interesting Internal Details

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    WARNING:
    --------
    This section details some internal implementation details of
    iffparse.library which may help you to understand it better.  Use of
    the following information to do "clever" things in an application is
    forbidden and unsupportable.  Don't even think about it.
It turns out that [StoredProperties](autodocs-2.0/includes-libraries-iffparse-h.md), [CollectionItem](libraries/33-management-functions-collectionchunk-and-findcollection.md)s, and entry and exit
handlers are all implemented using [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md)s.  For example, when you call
[FindProp()](libraries/33-controlling-parsing-propchunk-findprop.md), you are actually calling a front-end to [FindLocalItem()](libraries/33-storing-lcis-findlocalitem.md).  The
mysterious identification value (which has heretofore never been
discussed) is a value which permits you to differentiate between LCIs
having the same type and ID.

For instance, suppose you called [PropChunk()](libraries/33-controlling-parsing-propchunk-findprop.md), asking it to store an [ILBM](libraries/33-iffparse-library-iff-form-specifications.md)
[BMHD](libraries/33-form-ilbm-interpreting-ilbms.md).  PropChunk() will install an entry handler in the form of an [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md),
having type equal to `ILBM', ID equal to `BMHD', and an identification
value of IFFLCI_ENTRYHANDLER.

When an [ILBM BMHD](libraries/33-form-ilbm-interpreting-ilbms.md) is encountered, the entry handler is called, and it
creates and stores another [LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md) having type equal to `ILBM', ID equal to
`BMHD' and an identification value of IFFLCI_PROP.

Thus, when you call [FindProp()](libraries/33-controlling-parsing-propchunk-findprop.md), it merely calls [FindLocalItem()](libraries/33-storing-lcis-findlocalitem.md) with your
type and ID, and supplies IFFLCI_PROP for the identification value.

Therefore, handlers, [StoredProperties](autodocs-2.0/includes-libraries-iffparse-h.md), [CollectionItem](libraries/33-management-functions-collectionchunk-and-findcollection.md)s and your own custom
[LCI](libraries/33-context-functions-context-specific-data-localcontextitems.md)s can never be confused with each other, since they all have unique
identification values.  Since they are all handled (and searched for) in
the same way, they all "override" each other in a consistent way. Just as
StoredProperties higher in the context stack will be found and returned
before identical ones in lower contexts, so will chunk handlers be found
and invoked before ones lower on the context stack (recall
[FindLocalItem()](libraries/33-storing-lcis-findlocalitem.md)'s search procedure).

This means you can temporarily override a chunk handler by installing an
identical handler in a higher context.  The handler will persist until the
context in which it is stored expires, after which, the original one
regains scope.

---

## See Also

- [FindLocalItem — iffparse.library](../autodocs/iffparse.library.md#findlocalitem)
- [FindProp — iffparse.library](../autodocs/iffparse.library.md#findprop)
- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
