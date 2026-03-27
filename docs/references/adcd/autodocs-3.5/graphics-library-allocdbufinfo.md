---
title: graphics.library/AllocDBufInfo
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-allocdbufinfo
functions: [ChangeVPBitMap, FreeDBufInfo, WaitBlit]
libraries: [graphics.library]
---

# graphics.library/AllocDBufInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       AllocDBufInfo -- [Allocate](autodocs-3.5/exec-library-allocate-2.md) structure for multi-buffered animation (V39)
```
   SYNOPSIS
```c
       AllocDBufInfo(vp)
```
		      a0

	struct [DBufInfo](autodocs-3.5/include-graphics-view-h.md) * AllocDBufInfo(struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *)

   FUNCTION
	Allocates a structure which is used by the [ChangeVPBitMap()](autodocs-3.5/graphics-library-changevpbitmap.md)
	routine.

   INPUTS

```c
       vp  =  A pointer to a [ViewPort](autodocs-3.5/include-graphics-view-h.md) structure.
```
   BUGS

   NOTES
	Returns 0 if there is no memory available or if the display mode
	of the viewport does not support double-buffering.

	The only fields of the [DBufInfo](autodocs-3.5/include-graphics-view-h.md) structure which can be used by application
	programs are the dbi_SafeMessage, dbi_DispMessage, dbi_UserData1 and
	dbi_UserData2 fields.

	dbi_SafeMessage and dbi_DispMessage are standard exec message structures
	which may be used for synchronizing your animation with the screen update.

	dbi_SafeMessage is a message which is replied to when it is safe to write to
	the old [BitMap](autodocs-3.5/include-graphics-gfx-h.md) (the one which was installed when you called ChangeVPBitMap).

	dbi_DispMessage is replied to when it is safe to call [ChangeVPBitMap](autodocs-3.5/graphics-library-changevpbitmap.md) again
	and be certain that the new frame has been seen at least once.

	The dbi_UserData1 and dbi_UserData2 fields, which are stored after each
	message, are for your application to stuff any data into that it may need
	to examine when looking at the reply coming into the ReplyPort for either
	of the embedded [Message](autodocs-3.5/include-exec-ports-h.md) structures.

	[DBufInfo](autodocs-3.5/include-graphics-view-h.md) structures MUST be allocated with this function. The size of
	the structure will grow in future releases.

	The following fragment shows proper double buffering synchronization:

	int SafeToChange=TRUE, SafeToWrite=TRUE, CurBuffer=1;
	struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *ports[2];    /* reply ports for DispMessage and SafeMessage
*/
	struct [BitMap](autodocs-3.5/include-graphics-gfx-h.md) *BmPtrs[2];
	struct [DBufInfo](autodocs-3.5/include-graphics-view-h.md) *myDBI;

	... allocate bitmap pointers, [DBufInfo](autodocs-3.5/include-graphics-view-h.md), set up viewports, etc.

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
	[FreeDBufInfo()](autodocs-3.5/graphics-library-freedbufinfo.md) [ChangeVPBitMap()](autodocs-3.5/graphics-library-changevpbitmap.md)

---

## See Also

- [ChangeVPBitMap — graphics.library](../autodocs/graphics.library.md#changevpbitmap)
- [FreeDBufInfo — graphics.library](../autodocs/graphics.library.md#freedbufinfo)
- [WaitBlit — graphics.library](../autodocs/graphics.library.md#waitblit)
