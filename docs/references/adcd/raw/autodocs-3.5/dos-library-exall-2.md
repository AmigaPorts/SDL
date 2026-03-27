# dos.library/ExAll



   NAME
	ExAll -- [Examine](../Includes_and_Autodocs_3._guide/node015C.html) an entire directory (V36)

   SYNOPSIS
	continue = ExAll(lock, buffer, size, type, control)
	D0               D1     D2     D3    D4     D5

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) ExAll(BPTR,[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57),[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39),[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39),struct [ExAllControl](../Includes_and_Autodocs_3._guide/node0608.html#line69) *)

   FUNCTION
	Examines an entire directory.

 [Lock](../Includes_and_Autodocs_3._guide/node0186.html) must be on a directory.  Size is the size of the buffer supplied.
 The buffer will be filled with (partial) [ExAllData](../Includes_and_Autodocs_3._guide/node0608.html#line44) structures, as
 specified by the type field.

 Type is a value from those shown below that determines which information is
 to be stored in the buffer.  Each higher value adds a new thing to the list
 as described in the table below:-

	ED_NAME		FileName
	ED_TYPE		Type
	ED_SIZE		Size in bytes
	ED_PROTECTION	Protection bits
	ED_DATE		3 longwords of date
	ED_COMMENT	Comment (will be NULL if no comment)
			Note: the V37 ROM/disk filesystem returns this
			incorrectly as a BSTR.  See BUGS for a workaround.
	ED_OWNER	owner user-id and group-id (if supported)  (V39)

 Thus, ED_NAME gives only filenames, and ED_OWNER gives everything.

 NOTE: V37 dos.library, when doing ExAll() emulation, and RAM: filesystem
 will return an error if passed ED_OWNER.  If you get ERROR_BAD_NUMBER,
 retry with ED_COMMENT to get everything but owner info.  All filesystems
 supporting ExAll() must support through ED_COMMENT, and must check Type
 and return ERROR_BAD_NUMBER if they don't support the type.

 The V37 ROM/disk filesystem doesn't fill in the comment field correctly
 if you specify ED_OWNER.  See BUGS for a workaround if you need to use
 ED_OWNER.

 The ead_Next entry gives a pointer to the next entry in the buffer.  The
 last entry will have NULL in ead_Next.

 The control structure is required so that FFS can keep track if more than
 one call to ExAll is required.  This happens when there are more names in
 a directory than will fit into the buffer.  The format of the control
 structure is as follows:-

 NOTE: the control structure MUST be allocated by AllocDosObject!!!

 Entries:  This field tells the calling application how many entries are
	    in the buffer after calling ExAll.  Note: make sure your code
	    handles the 0 entries case, including 0 entries with continue
	    non-zero.

 LastKey:  This field ABSOLUTELY MUST be initialised to 0 before calling
	    ExAll for the first time.  Any other value will cause nasty
	    things to happen.  If ExAll returns non-zero, then this field
	    should not be touched before making the second and subsequent
	    calls to ExAll.  Whenever ExAll returns non-zero, there are more
	    calls required before all names have been received.

	    As soon as a FALSE return is received then ExAll has completed
	    (if [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) returns ERROR_NO_MORE_ENTRIES - otherwise it returns
	    the error that occured, similar to ExNext.)

 MatchString
	    If this field is NULL then all filenames will be returned.  If
	    this field is non-null then it is interpreted as a pointer to
	    a string that is used to pattern match all file names before
	    accepting them and putting them into the buffer.  The default
	    AmigaDOS caseless pattern match routine is used.  This string
	    MUST have been parsed by ParsePatternNoCase()!

 MatchFunc:
	    Contains a pointer to a hook for a routine to decide if the entry
	    will be included in the returned list of entries.  The entry is
	    filled out first, and then passed to the hook.  If no MatchFunc is
	    to be called then this entry should be NULL.  The hook is
	    called with the following parameters (as is standard for hooks):

	    [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) = MatchFunc( hookptr, data, typeptr )
				a0	a1	a2
	    (a0 = ptr to hook, a1 = ptr to filled in [ExAllData](../Includes_and_Autodocs_3._guide/node0608.html#line44), a2 = ptr
	     to longword of type).

	    MatchFunc should return FALSE if the entry is not to be
	    accepted, otherwise return TRUE.

	Note that Dos will emulate ExAll() using [Examine()](../Includes_and_Autodocs_3._guide/node015C.html) and [ExNext()](../Includes_and_Autodocs_3._guide/node0160.html)
	if the handler in question doesn't support the ExAll() packet.

   INPUTS
	lock    - [Lock](../Includes_and_Autodocs_3._guide/node0186.html) on directory to be examined.
	buffer  - Buffer for data returned (MUST be at least word-aligned,
		  preferably long-word aligned).
	size    - Size in bytes of 'buffer'.
	type    - Type of data to be returned.
	control - Control data structure (see notes above).  MUST have been
		  allocated by AllocDosObject!

   RESULT
	continue - Whether or not ExAll is done.  If FALSE is returned, either
		   ExAll has completed (IoErr() == ERROR_NO_MORE_ENTRIES), or
		   an error occurred (check IoErr()).  If non-zero is returned,
		   you MUST call ExAll again until it returns FALSE.

   EXAMPLE

   eac = AllocDosObject(DOS_EXALLCONTROL,NULL);
   if (!eac) ...
   ...
   eac->eac_LastKey = 0;
   do {

```c
       more = ExAll(lock, EAData, sizeof(EAData), ED_FOO, eac);
       if ((!more) && (IoErr() != ERROR_NO_MORE_ENTRIES)) {
           * ExAll failed abnormally *
           break;
       }
       if (eac->eac_Entries == 0) {
           * ExAll failed normally with no entries *
           continue;                   * ("more" is *usually* zero) *
       }
       ead = (struct [ExAllData](../Includes_and_Autodocs_3._guide/node0608.html#line44) *) EAData;
       do {
           * use ead here *
           ...
           * get next ead *
           ead = ead->ed_Next;
       } while (ead);
```
   } while (more);
   ...
   FreeDosObject(DOS_EXALLCONTROL,eac);

   BUGS
	In V36, there were problems with ExAll (particularily with
	eac_MatchString, and ed_Next with the ramdisk and the emulation
	of it in Dos for handlers that do not support the packet.  It is
	advised you only use this under V37 and later.

	The V37 ROM/disk filesystem incorrectly returned comments as BSTR's
	(length plus characters) instead of CSTR's (null-terminated).  See
	the next bug for a way to determine if the filesystem is a V37
	ROM/disk filesystem.  Fixed in V39.

	The V37 ROM/disk filesystem incorrectly handled values greater than
	ED_COMMENT.  Because of this, ExAll() information is trashed if
	ED_OWNER is passed to it.  Fixed in V39.  To work around this, use
	the following code to identify if a filesystem is a V37 ROM/disk
	filesystem:

 // return TRUE if this is a V37 ROM filesystem, which doesn't (really)
 // support ED_OWNER safely

 [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) CheckV37(BPTR lock)
 {
 	struct [FileLock](../Includes_and_Autodocs_3._guide/node05D9.html#line455) *l = BADDR(lock);
 	struct [Resident](../Includes_and_Autodocs_3._guide/node0643.html#line17) *resident;
 	struct [DosList](../Includes_and_Autodocs_3._guide/node05D9.html#line371) *dl;
 	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) result = FALSE;

 	dl = LockDosList(LDF_READ|LDF_DEVICES);

 	// if the lock has a volume and no device, we won't find it,
	// so we know it's not a V37 ROM/disk filesystem
 	do {
 	    dl = NextDosEntry(dl,LDF_READ|LDF_DEVICES);
 	    if (dl && (dl->dol_Task == l->fl_Task))
 	    {
 		// found the filesystem - test isn't actually required,
		// but we know the filesystem we're looking for will always
		// have a startup msg.  If we needed to examine the message,
		// we would need a _bunch_ of checks to make sure it's not
		// either a small value (like port-handler uses) or a BSTR.
 		if (dl->dol_misc.dol_handler.dol_Startup)
 		{
 			// try to make sure it's the ROM fs or l:FastFileSystem
 			if (resident =
 			    FindRomTag(dl->dol_misc.dol_handler.dol_SegList))
 			{
 				if (resident->rt_Version < 39 &&
 				    (strncmp(resident->rt_IdString,"fs 37.",
 					     strlen("fs 37.")) == 0 ||
 				     strncmp(resident->rt_Name,"ffs 37.",
 					     strlen("ffs 37.")) == 0))
 				{
 					result = TRUE;
 				}
 			}
 		}
 		break;
 	    }
 	} while (dl);

 	UnLockDosList(LDF_READ|LDF_DEVICES);

 	return result;
 }


   SEE ALSO
	[Examine()](../Includes_and_Autodocs_3._guide/node015C.html), [ExNext()](../Includes_and_Autodocs_3._guide/node0160.html), [ExamineFH()](../Includes_and_Autodocs_3._guide/node015D.html), [MatchPatternNoCase()](../Includes_and_Autodocs_3._guide/node0190.html),
	[ParsePatternNoCase()](../Includes_and_Autodocs_3._guide/node019C.html), [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html), [ExAllEnd()](../Includes_and_Autodocs_3._guide/node015B.html)

