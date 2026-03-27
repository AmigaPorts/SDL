# graphics.library/AllocDBufInfo



   NAME

```c
       AllocDBufInfo -- [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) structure for multi-buffered animation (V39)
```
   SYNOPSIS
```c
       AllocDBufInfo(vp)
```
		      a0

	struct [DBufInfo](../Includes_and_Autodocs_3._guide/node05ED.html#line278) * AllocDBufInfo(struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *)

   FUNCTION
	Allocates a structure which is used by the [ChangeVPBitMap()](../Includes_and_Autodocs_3._guide/node02BD.html)
	routine.

   INPUTS

```c
       vp  =  A pointer to a [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure.
```
   BUGS

   NOTES
	Returns 0 if there is no memory available or if the display mode
	of the viewport does not support double-buffering.

	The only fields of the [DBufInfo](../Includes_and_Autodocs_3._guide/node05ED.html#line278) structure which can be used by application
	programs are the dbi_SafeMessage, dbi_DispMessage, dbi_UserData1 and
	dbi_UserData2 fields.

	dbi_SafeMessage and dbi_DispMessage are standard exec message structures
	which may be used for synchronizing your animation with the screen update.

	dbi_SafeMessage is a message which is replied to when it is safe to write to
	the old [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) (the one which was installed when you called ChangeVPBitMap).

	dbi_DispMessage is replied to when it is safe to call [ChangeVPBitMap](../Includes_and_Autodocs_3._guide/node02BD.html) again
	and be certain that the new frame has been seen at least once.

	The dbi_UserData1 and dbi_UserData2 fields, which are stored after each
	message, are for your application to stuff any data into that it may need
	to examine when looking at the reply coming into the ReplyPort for either
	of the embedded [Message](../Includes_and_Autodocs_3._guide/node062E.html#line46) structures.

	[DBufInfo](../Includes_and_Autodocs_3._guide/node05ED.html#line278) structures MUST be allocated with this function. The size of
	the structure will grow in future releases.

	The following fragment shows proper double buffering synchronization:

	int SafeToChange=TRUE, SafeToWrite=TRUE, CurBuffer=1;
	struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *ports[2];    /* reply ports for DispMessage and SafeMessage
*/
	struct [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) *BmPtrs[2];
	struct [DBufInfo](../Includes_and_Autodocs_3._guide/node05ED.html#line278) *myDBI;

	... allocate bitmap pointers, [DBufInfo](../Includes_and_Autodocs_3._guide/node05ED.html#line278), set up viewports, etc.

	myDBI->dbi_SafeMessage.mn_ReplyPort=ports[0];
	myDBI->dbi_DispMessage.mn_ReplyPort=ports[1];
	while (! done)
	{
	    if (! SafeToWrite)
		while(! GetMsg(ports[0])) Wait(1l<<(ports[0]->mp_SigBit));
	    SafeToWrite=TRUE;

	    ... render to bitmap # CurBuffer.

	    if (! SafeToChange)
		while(! GetMsg(ports[1])) Wait(1l<<(ports[1]->mp_SigBit));
	    SafeToChange=TRUE;
	    WaitBlit();         /* be sure rendering has finished */
	    ChangeVPBitMap(vp,BmPtrs[CurBuffer],myDBI);
	    SafeToChange=FALSE;
	    SafeToWrite=FALSE;
	    CurBuffer ^=1;	/* toggle current buffer */
	}
```c
       if (! SafeToChange)	/* cleanup pending messages */
```
	    while(! GetMsg(ports[1])) Wait(1l<<(ports[1]->mp_SigBit));
```c
       if (! SafeToWrite)	/* cleanup */
```
	    while(! GetMsg(ports[0])) Wait(1l<<(ports[0]->mp_SigBit));

   SEE ALSO
	[FreeDBufInfo()](../Includes_and_Autodocs_3._guide/node02DA.html) [ChangeVPBitMap()](../Includes_and_Autodocs_3._guide/node02BD.html)

