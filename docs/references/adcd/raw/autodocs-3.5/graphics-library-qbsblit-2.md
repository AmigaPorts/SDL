# graphics.library/QBSBlit



   NAME

	QBSBlit -- Synchronize the blitter request with the video beam.

   SYNOPSIS

	QBSBlit( bsp )
		 a1

	void QBSBlit( struct [bltnode](../Includes_and_Autodocs_3._guide/node05DF.html#line87) * );

   FUNCTION
	Call a user routine for use of the blitter, enqueued separately from

```c
       the [QBlit](../Includes_and_Autodocs_3._guide/node030E.html) queue.  Calls the user routine contained in the blit
       structure when the video beam is located at a specified position
       onscreen.   Useful when you are trying to blit into a visible part
       of the screen and wish to perform the data move while the beam is
       not trying to display that same area.  (prevents showing part of
       an old display and part of a new display simultaneously).  Blitter
       requests on the QBSBlit queue take precedence over those on the
       regular blitter queue. The beam position is specified in the blitnode.
```
   INPUTS
	bsp - pointer to a blit structure.  See description in the

             Graphics Support section of the manual for more info.
   RESULT

       User routine is called when the QBSBlit queue reaches this
       request AND the video beam is in the specified position.
       If there are lots of blits going on and the video beam
       has wrapped around back to the top it will call all the
       remaining bltnodes as fast as it can to try and catch up.
   NOTES

```c
       [QBlit()](../Includes_and_Autodocs_3._guide/node030E.html), and QBSBlit() have been rewritten for V39.  Queued
       blits are now handled in FIFO order.  Tasks trying to
       [OwnBlitter()](../Includes_and_Autodocs_3._guide/node030C.html) are now given a fair share of the total
       blitter time available.  QBSBlit() is no longer queued
       separately from nodes added by [QBlit()](../Includes_and_Autodocs_3._guide/node030E.html).  This fixes the
       ordering dependencies listed under BUGS in prior autodoc
       notes.
```
   BUGS

   SEE ALSO
	[QBlit()](../Includes_and_Autodocs_3._guide/node030E.html) [hardware/blit.h](../Includes_and_Autodocs_3._guide/node05DF.html)

