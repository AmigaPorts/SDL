# gadtools.library/CreateContext



   NAME
	CreateContext -- create a place for GadTools context data. (V36)

   SYNOPSIS
	gad = CreateContext(glistpointer);
	D0                  A0

	struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *CreateContext(struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) **);

   FUNCTION
	Creates a place for GadTools to store any context data it might
	need for your window.  In reality, an unselectable invisible
	gadget is created, with room for the context data.
	This function also establishes the linkage from a glist type
	pointer to the individual gadget pointers.  Call this function
	before any of the other gadget creation calls.

   INPUTS
	glistptr - address of a pointer to a [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213), which was previously
	           set to NULL.  When all the gadget creation is done, you may
	           use that pointer as your NewWindow.FirstGadget, or
	           in [intuition.library/AddGList()](../Includes_and_Autodocs_3._guide/node0393.html),
	           [intuition.library/RefreshGList()](../Includes_and_Autodocs_3._guide/node03DD.html), [FreeGadgets()](../Includes_and_Autodocs_3._guide/node0278.html), etc.

   RESULT
	gad - pointer to context gadget, or NULL if failure.

   EXAMPLE

	struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *gad;
	struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *glist = NULL;
	gad = CreateContext(&glist);
	/*  Other creation calls go here */
	if (gad)
	{
	    myNewWindow.FirstGadget = glist;
	    if ( myWindow = OpenWindow(&myNewWindow) )
	    {
		GT_RefreshWindow(win,NULL);
		/* other stuff */
		CloseWindow(myWindow);
	    }
	}
	FreeGadgets(glist);

