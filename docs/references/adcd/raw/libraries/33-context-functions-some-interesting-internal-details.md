# 33 / Context Functions / Some Interesting Internal Details




    WARNING:
    --------
    This section details some internal implementation details of
    iffparse.library which may help you to understand it better.  Use of
    the following information to do "clever" things in an application is
    forbidden and unsupportable.  Don't even think about it.
It turns out that [StoredProperties](../Includes_and_Autodocs_2._guide/node010B.html#line90), [CollectionItem](../Libraries_Manual_guide/node0437.html#line14)s, and entry and exit
handlers are all implemented using [LCI](../Libraries_Manual_guide/node044A.html)s.  For example, when you call
[FindProp()](../Libraries_Manual_guide/node0434.html), you are actually calling a front-end to [FindLocalItem()](../Libraries_Manual_guide/node0450.html).  The
mysterious identification value (which has heretofore never been
discussed) is a value which permits you to differentiate between LCIs
having the same type and ID.

For instance, suppose you called [PropChunk()](../Libraries_Manual_guide/node0434.html), asking it to store an [ILBM](../Libraries_Manual_guide/node045D.html#line8)
[BMHD](../Libraries_Manual_guide/node0461.html#line3).  PropChunk() will install an entry handler in the form of an [LCI](../Libraries_Manual_guide/node044A.html),
having type equal to `ILBM', ID equal to `BMHD', and an identification
value of IFFLCI_ENTRYHANDLER.

When an [ILBM BMHD](../Libraries_Manual_guide/node0461.html#line3) is encountered, the entry handler is called, and it
creates and stores another [LCI](../Libraries_Manual_guide/node044A.html) having type equal to `ILBM', ID equal to
`BMHD' and an identification value of IFFLCI_PROP.

Thus, when you call [FindProp()](../Libraries_Manual_guide/node0434.html), it merely calls [FindLocalItem()](../Libraries_Manual_guide/node0450.html) with your
type and ID, and supplies IFFLCI_PROP for the identification value.

Therefore, handlers, [StoredProperties](../Includes_and_Autodocs_2._guide/node010B.html#line90), [CollectionItem](../Libraries_Manual_guide/node0437.html#line14)s and your own custom
[LCI](../Libraries_Manual_guide/node044A.html)s can never be confused with each other, since they all have unique
identification values.  Since they are all handled (and searched for) in
the same way, they all "override" each other in a consistent way. Just as
StoredProperties higher in the context stack will be found and returned
before identical ones in lower contexts, so will chunk handlers be found
and invoked before ones lower on the context stack (recall
[FindLocalItem()](../Libraries_Manual_guide/node0450.html)'s search procedure).

This means you can temporarily override a chunk handler by installing an
identical handler in a higher context.  The handler will persist until the
context in which it is stored expires, after which, the original one
regains scope.

