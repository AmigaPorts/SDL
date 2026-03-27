---
title: workbench.library/AddAppMenuItemA
manual: autodocs-3.5
chapter: autodocs-3.5
section: workbench-library-addappmenuitema-2
functions: []
libraries: []
---

# workbench.library/AddAppMenuItemA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddAppMenuItemA - add a menu item to Workbench's list            (V36)

                         of AppMenuItems.
   SYNOPSIS
	AppMenuItem = AddAppMenuItemA(id, userdata, text, msgport, taglist)
	D0                            D0     D1      A0     A1       A2

	struct AppMenuItem *AddAppMenuItemA(ULONG, ULONG, char *,
	                                    struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *,
	                                    struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	Alternate, varargs version:
	struct AppMenuItem *AddAppMenuItem(ULONG, ULONG, char *,
	                                   struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *,
	                                   tag1, data1,
	                                   tag2, data2,
	                                   ...
	                                   TAG_END );

   FUNCTION
	Attempt to add the text as a menu item to Workbench's list
	of AppMenuItems (the 'Tools' menu strip).

   INPUTS
	id - this variable is strictly for your own use and is ignored by
	     Workbench.  Typical uses in C are in switch and case statements,
	     and in assembly language table lookup.
	userdata - this variable is strictly for your own use and is ignored
	           by Workbench.
	text - text for the menu item (char *); starting with V44, any menu
	       label consisting entirely of '-', '_' or '~' characters will
	       result in a separator bar to be added in place of a textual
	       item.
	msgport - pointer to message port Workbench will use to send you an
	          [AppMessage](autodocs-3.5/include-workbench-workbench-h.md) message of type 'MTYPE_APPMENUITEM' when your
	          menuitem gets selected.
	taglist - ptr to a list of tag items.  Must be NULL for V2.0.

   TAGS
	WBAPPMENUA_CommandKeyString (STRPTR) -- Command key to assign to
	    this AppMenu. This must be a NUL-terminated string. If the
	    string is empty, it will be ignored. Also, if the command key
	    is already in use by a different menu item it will be ignored,
	    too. In any case, only the first character of the string will
	    be used (V44).

	    This tag defaults to NULL.

   RESULTS
	AppMenuItem - a pointer to an appmenuitem structure which you pass to
	              [RemoveAppMenuItem](autodocs-3.5/workbench-library-removeappmenuitem-2.md) when you want to remove the menuitem
	              from Workbench's list of AppMenuItems.  NULL if
	              workbench was unable to add your menu item; typically
	              happens when Workbench is not running or under low
	              memory conditions.

	          Starting with V44 NULL will be returned if you attempt to
	          add an AppMenu item to a menu which already contains 63
	          menu items.

   NOTES
	For this function call to succeed, Workbench must be open. This
	means that the LoadWB command was executed and the Workbench
	screen has been opened.

   SEE ALSO
	[workbench.library/RemoveAppMenuItem](autodocs-3.5/workbench-library-removeappmenuitem-2.md)

   BUGS
	workbench.library V37 through V40 does not limit the number of menu
	items to 63. Any menu items after the 63rd will not be selectable.
	This bug was fixed in V44.

