# resource.library/RL_OpenResource



   NAME
	RL_OpenResource - open a resource (V44)

   SYNOPSIS
	resource = RL_OpenResource(resobject, screen, catalog)
	 D0                         A0         A1      A2

	[RESOURCEFILE](../Includes_and_Autodocs_3._guide/node0666.html#line16) RL_OpenResource(APTR, struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *, struct [Catalog](../Includes_and_Autodocs_3._guide/node05E3.html#line245) *);

   FUNCTION
	This routine opens a resource object.

	If you give a NULL for the parameter screen do not call [RL_NewObjectA](../Includes_and_Autodocs_3._guide/node0544.html)
	or [RL_NewGroupA](../Includes_and_Autodocs_3._guide/node0543.html). You must first set a screen with
	[RL_SetResourceScreen](../Includes_and_Autodocs_3._guide/node0546.html).

   INPUTS
	resobject -- a pointer to a resource object
	screen -- a pointer to a [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132). This may be NULL
	catalog -- a pointer to a [Catalog](../Includes_and_Autodocs_3._guide/node05E3.html#line245). This may be NULL

   RESULTS
	resource -- a pointer to a resource or NULL

   EXAMPLE

	extern char RCTResource[];
	struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *screen;

	screen = LockPubScreen(NULL);
	[RESOURCEFILE](../Includes_and_Autodocs_3._guide/node0666.html#line16) resource = RL_OpenResource(RCTResource, screen, NULL);
	if (resource)
	{
		/* create your objects here */
	}
	RL_CloseResource(resource);
	UnlockPubScreen(NULL,screen);

   SEE ALSO
	[intuition.library/LockPubScreen](../Includes_and_Autodocs_3._guide/node03C1.html)
	[intuition.library/OpenScreenTagList](../Includes_and_Autodocs_3._guide/node03D4.html)
	locale.library/OpenCatalogA
	[resource.library/RL_CloseResource](../Includes_and_Autodocs_3._guide/node053F.html)
	[resource.library/RL_SetResourceScreen](../Includes_and_Autodocs_3._guide/node0546.html)

