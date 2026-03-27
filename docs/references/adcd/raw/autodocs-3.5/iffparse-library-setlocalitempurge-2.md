# iffparse.library/SetLocalItemPurge



   NAME
	SetLocalItemPurge -- set purge vector for a local context item. (V36)

   SYNOPSIS
	SetLocalItemPurge(localItem, purgeHook);
	                  A0         A1

	VOID SetLocalItemPurge(struct [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103) *, struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *);

   FUNCTION
	Sets a local context item to use a client-supplied cleanup (purge)
	vector for disposal when its context is popped. The purge vector
	will be called when the [ContextNode](../Includes_and_Autodocs_3._guide/node05E8.html#line84) containing this local item is
	popped off the context stack and is about to be deleted itself. If
	the purge vector has not been set, the parser will use [FreeLocalItem()](../Includes_and_Autodocs_3._guide/node0367.html)
	to delete the item, but if this function is used to set the purge
	vector, the supplied vector will be called with the following
	arguments:

		A0:	pointer to purgeHook.
		A2:	pointer to [LocalContextItem](../Includes_and_Autodocs_3._guide/node05E8.html#line103) to be freed.
		A1:	pointer to a [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) containing the value
			IFFCMD_PURGELCI.

	The user purge vector is then responsible for calling [FreeLocalItem()](../Includes_and_Autodocs_3._guide/node0367.html)
	as part of its own cleanup. Although the purge vector can return a
	value, it will be ignored -- purge vectors must always work (best to
	return 0, though).

   INPUTS
	localItem - pointer to a local context item.
	purgeHook - pointer to a [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) structure.

   SEE ALSO
	[AllocLocalItem()](../Includes_and_Autodocs_3._guide/node035A.html), [FreeLocalItem()](../Includes_and_Autodocs_3._guide/node0367.html), [<utility/hooks.h>](../Includes_and_Autodocs_3._guide/node0617.html)
	[<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)

