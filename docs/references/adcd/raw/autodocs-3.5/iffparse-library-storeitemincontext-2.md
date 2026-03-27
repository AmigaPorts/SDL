# iffparse.library/StoreItemInContext



   NAME
	StoreItemInContext -- store local context item in given context node.
	                      (V36)

   SYNOPSIS
	StoreItemInContext(iff, localItem, contextNode);
	                   A0   A1         A2

	VOID StoreItemInContext(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, struct [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103) *,

```c
                               struct [ContextNode](../Includes_and_Autodocs_3._guide/node05E8.html#line84) *);
```
   FUNCTION
	Adds the [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103) to the list of items for the given context
	node. If an LCI with the same Type, ID, and Ident is already
	present in the [ContextNode](../Includes_and_Autodocs_3._guide/node05E8.html#line84), it will be purged and replaced with the
	new one. This is a raw form of [StoreLocalItem()](../Includes_and_Autodocs_3._guide/node037E.html).

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure for this context.
	localItem - pointer to a [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103) to be stored.
	contextNode - pointer to context node in which to store item.

   SEE ALSO
	[StoreLocalItem()](../Includes_and_Autodocs_3._guide/node037E.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)

