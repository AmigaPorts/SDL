---
title: IV-1/wbarg.c
manual: amiga-mail
chapter: amiga-mail
section: iv-1-wbarg-c
functions: []
libraries: []
---

# IV-1/wbarg.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* wbarg.c
 * How to get an icon from a Workbench argument
 * Written by David N. Junod, 27-Aug-90
 */
/*
Copyright (c) 1990-1999 Amiga, Inc.

This example is provided in electronic form by Amiga, Inc.
for use with the Amiga Mail Volume II technical publication.
Amiga Mail Volume II contains additional information on the correct
usage of the techniques and operating system functions presented in
these examples.  The source and executable code of these examples may
only be distributed in free electronic form, via bulletin board or
as part of a fully non-commercial and freely redistributable
diskette.  Both the source and executable code (including comments)
must be included, without modification, in any copy.  This example
may not be published in printed form or distributed with any
commercial product. However, the programming techniques and support
routines set forth in these examples may be used in the development
of original executable software products for Amiga
computers.

All other rights reserved.

This example is provided "as-is" and is subject to change; no
warranties are made.  All use is at your own risk. No liability or
responsibility is assumed.
*/

#include <exec/types.h>
#include <exec/memory.h>
#include <exec/libraries.h>
#include <libraries/dos.h>
#include <workbench/icon.h>
#include <workbench/startup.h>
#include <clib/dos_protos.h>
#include <clib/exec_protos.h>
#include <clib/wb_protos.h>
#include <pragmas/dos_pragmas.h>
#include <pragmas/exec_pragmas.h>
#include <pragmas/wb_pragmas.h>
#include <string.h>

extern struct Library *IconBase, *DOSBase, *SysBase;

struct DiskObject *GetDiskObjectNew (STRPTR name);
struct DiskObject *GetDiskObject (STRPTR name);

#pragma libcall IconBase GetDiskObjectNew 84 801

/****** wbarg/IconFromWBArg ********************************************
*
*   NAME
*	IconFromWBArg - Obtains the icon from a Workbench argument.
*
*   SYNOPSIS
*	dob = IconFromWBArg (wbarg);
*
*	struct DiskObject *dob;
*	struct WBArg *wbarg;
*
*   FUNCTION
*	Given a valid Workbench argument, this command will return the
*	proper icon.  This call uses the new (V36) GetDiskObjectNew call
*	to ensure that an icon will be returned.
*
*	This functions requires dos.library and icon.library to be opened
*	by the application.
*
*   INPUTS
*	wbarg	- Pointer to a filled in WBArg structure.
*
*   RESULTS
*	dob	- Pointer to a DiskObject structure.  Application must call
*		  FreeDiskObject when done with the icon.
*
**********************************************************************/

struct DiskObject *IconFromWBArg (struct WBArg * arg)
{
```c
    struct DiskObject *dob = NULL;
    UBYTE work_name[34];
    BPTR old, new;

    /* Copy the WBArg contents */
    strcpy (work_name, arg->wa_Name);

    /* Duplicate the lock */
    if (new = DupLock (arg->wa_Lock))
    {
```
	BOOL success = FALSE;

	/*
	 * If we don't have a name, then get one. Only Tools & Projects have a
	 * valid name.
	 */
	if (strlen (work_name) == 0)
	{
	    LONG msize = sizeof (struct FileInfoBlock);
	    struct FileInfoBlock *info;

	    /* This block needs to be longword aligned, so allocate it */
	    if (info = (struct FileInfoBlock *) AllocMem (msize, MEMF_CLEAR))
	    {
		/* Examine the lock, so that we can figure out the name */
		if (Examine (new, info))
		{
		    /* Copy the name of the lock */
		    strcpy (work_name, info->fib_FileName);

		    /* See if the lock is a directory */
		    if (info->fib_DirEntryType > 0)
		    {
			/* Unlock the existing lock */
			UnLock (new);

			/* Go to the parent drawer */
			if ((new = ParentDir (arg->wa_Lock)) == NULL)
			{
			    /* A disk icon was passed */
			    strcpy (work_name, "disk");
			    new = DupLock (arg->wa_Lock);

			}	/* End of if disk */
		    }		/* End of if directory */

		    /* We have a name */
		    success = TRUE;

		}		/* End of examine */

		/* Free the temporary block */
		FreeMem ((APTR) info, msize);
	    }
	}
	else
	{
	    /* Show that we have a name to work with */
	    success = TRUE;
	}

	/* See if we should try getting the icon */
	if (success)
	{
	    /* go to the directory where the icon resides */
	    old = CurrentDir (new);

	    /*
	     * GetDiskObjectNew is a new function, for AmigaOS version 2.0,
	     * therefore we need to check the version level.
	     */
	    if (IconBase->lib_Version >= 36)
		dob = GetDiskObjectNew (work_name);
	    else
		dob = GetDiskObject (work_name);

	    /* go back to where we used to be */
	    CurrentDir (old);
	}

	/* release the duplicated lock */
	UnLock (new);
```c
    }

    /* return the icon */
    return (dob);
```
}

