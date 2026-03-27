# dos.library/AllocDosObject



   NAME
	AllocDosObject -- Creates a dos object (V36)

   SYNOPSIS
	ptr = AllocDosObject(type, tags)
	D0                    D1    D2

	void *AllocDosObject(ULONG, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)

	ptr = AllocDosObjectTagList(type, tags)
	D0                 	     D1    D2

	void *AllocDosObjectTagList(ULONG, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)

	ptr = AllocDosObjectTags(type, Tag1, ...)

	void *AllocDosObjectTags(ULONG, ULONG, ...)

   FUNCTION
	Create one of several dos objects, initializes it, and returns it
	to you.  Note the DOS_STDPKT returns a pointer to the sp_Pkt of the
	structure.

	This function may be called by a task for all types and tags defined
	in the V37 includes (DOS_FILEHANDLE through DOS_RDARGS and ADO_FH_Mode
	through ADO_PromptLen, respectively).  Any future types or tags
	will be documented as to whether a task may use them.

   INPUTS
	type - type of object requested
	tags - pointer to taglist with additional information

   RESULT
	packet - pointer to the object or NULL

   BUGS
	Before V39, DOS_CLI should be used with care since [FreeDosObject()](../Includes_and_Autodocs_3._guide/node0172.html)
	can't free it.

   SEE ALSO
	[FreeDosObject()](../Includes_and_Autodocs_3._guide/node0172.html), [<dos/dostags.h>](../Includes_and_Autodocs_3._guide/node0658.html), [<dos/dos.h>](../Includes_and_Autodocs_3._guide/node05F8.html)

