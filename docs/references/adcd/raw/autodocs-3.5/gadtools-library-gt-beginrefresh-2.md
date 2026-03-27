# gadtools.library/GT_BeginRefresh



   NAME
	GT_BeginRefresh -- begin refreshing friendly to GadTools. (V36)

   SYNOPSIS
	GT_BeginRefresh(win)
	                A0

	VOID GT_BeginRefresh(struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *);

   FUNCTION
	Invokes the [intuition.library/BeginRefresh()](../Includes_and_Autodocs_3._guide/node0397.html) function in a manner
	friendly to the [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) Toolkit.  This function call permits the
	GadTools gadgets to refresh themselves at the correct time.
	Call [GT_EndRefresh()](../Includes_and_Autodocs_3._guide/node027D.html) function when done.

   INPUTS
	win - pointer to [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) structure for which a IDCMP_REFRESHWINDOW
	      IDCMP event was received.

   NOTES
	The nature of GadTools precludes the use of the IDCMP flag
	WFLG_NOCAREREFRESH.  You must handle IDCMP_REFRESHWINDOW events
	in at least the minimal way, namely:

		case IDCMP_REFRESHWINDOW:
		    GT_BeginRefresh(win);
		    GT_EndRefresh(win, TRUE);
		    break;

   SEE ALSO
	[intuition.library/BeginRefresh()](../Includes_and_Autodocs_3._guide/node0397.html)

