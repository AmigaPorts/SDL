---
title: XI-25/AppKeyMap.doc
manual: amiga-mail
chapter: amiga-mail
section: xi-25-appkeymap-doc
functions: []
libraries: []
---

# XI-25/AppKeyMap.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

AppKeyMap.o/AlterAppKeyMap                         AppKeyMap.o/AlterAppKeyMap

   NAME
	AlterAppKeyMap -- Changes keyboard mappings for a keymap

   SYNOPSIS
	AlterAppKeyMap(mykeymap, keyarray, arrayentries);

	void AlterAppKeyMap(struct KeyMap *,
		            struct MyKey *,
		            UWORD);

   FUNCTION
	Using an array of MyKey structures (which describe a series of
	rawkeys), this function	changes the rawkey's corresponding
	mapping values in mykeymap.  Only call this function on
	a private copy of a KeyMap (including its data).

   INPUTS
	mykeymap = pointer to a KeyMap structure.  AlterAppKeyMap() will
	  make changes to this KeyMap's data, so this KeyMap should
	  be a private copy of a KeyMap (including the data the KeyMap
	  points to).

	keyarray  = pointer to an array of struct MyKey (from
	  appkeymap.h):

```c
            struct MyKey
            {
              UBYTE RawCode;	/* RawCode of character to change      */
```
				/* in the KeyMap.  Correponds to the   */
				/* Lo/HiKeyMap structures from the     */
				/* KeyMap structure.		       */


```c
              UBYTE MapType;	/* The Lo/HiKeyMapTypes field.         */
              UBYTE Capsable;   /* This TRUE/FALSE state of this bit   */
                                /* gets translated to the correspond-  */
                                /* bit in KeyMap.Lo/HiCapsable.        */
              UBYTE Repeatable; /* This TRUE/FALSE state of this bit   */
                                /* gets translated to the correspond-  */
                                /* bit in KeyMap.Lo/HiRepeatable.      */
              ULONG Map;	/* Map data for key.  This points to   */
              			/* data for the rawkey.  Its format    */
              			/* depends on the key type. This field */
              			/* correponds to KeyMap.Lo/HiKeyMap.   */
            };

        arrayentries = The number of MyKey entries in keyarray.
```
   RESULT
	For each MyKey entry in keyarray, AlterKeyMap() finds the correpsonding
	raw key	entry in mykeymap and changes the data to match the entry
	in keyarray.  AlterKeyMap() makes changes directly to the KeyMap's
	data, so don't call this function on a system copy of a keymap, make
	a copy of it.

	Note that the console.device's CD_ASKKEYMAP only copies a KeyMap
	structure, which is only a set of pointers.  If you want to customize
	a copy of a keymap, you also have to duplicate the data that
	the KeyMap references.  If you do not duplicate the keymap data when
	customizing a keymap, you'll write over data that many keymaps are
	currently using.

	This function assumes that the keymap passed to it was duplicated
	using the CreateAppKeyMap() function.  CreateAppKeyMap() puts
	the keymap tables in a specific order and AlterAppKeyMap()
	expects to find the tables in that order.  Only call AlterAppKeyMap()
	on keymaps duplicated with CreateAppKeyMap().

   BUGS

   SEE ALSO
	console.device/CD_ASKKEYMAP console.device/CD_SETKEYMAP "appkeymap.h"
	AppKeyMap.o/CreateAppKeyMap() AppKeyMap.o/DeleteAppKeyMap()

AppKeyMap.o/CreateAppKeyMap                       AppKeyMap.o/CreateAppKeyMap

   NAME
	CreateAppKeyMap -- Create a new KeyMap by duplicating an existing one.

   SYNOPSIS
	newkeymap = CreateAppKeyMap(origkeymap);

	struct KeyMap *CreateAppKeyMap(struct KeyMap *);

   FUNCTION
	This function accepts a pointer to a KeyMap structure and duplicates it.
	CreateAppKeyMap() allocates the memory for a KeyMap structure and all
	the tables associated with that keymap.

   INPUTS
	origkeymap = points to a KeyMap to duplicate.

   RESULT
	If successful, this function returns a pointer to a duplicate of
	origkeymap.  CreateAppKeyMap() duplicates all of the tables that
	origkeymap references, so an application can make changes to the
	duplicate.  If CreateAppKeyMap() fails, it returns NULL.  The
	DeleteAppKeyMap() function deallocates the resources allocated
	by CreateAppKeyMap().

	CreateAppKeyMap() places the duplicate tables in an order so
	that a "Lo" table (for example, KeyMap.km_LoKeyMap) is immediately
	followed by the corresponding "Hi" table (KeyMap.km_HiKeyMap).
	This allows application to reference the two tables as one using
	the raw key value as an index.

   BUGS

   SEE ALSO
	console.device/CD_ASKKEYMAP console.device/CD_SETKEYMAP "appkeymap.h"
	AppKeyMap.o/AlterAppKeyMap() AppKeyMap.o/DeleteAppKeyMap()







AppKeyMap.o/DeleteAppKeyMap                       AppKeyMap.o/DeleteAppKeyMap

   NAME
	DeleteAppKeyMap -- Relinquish the resources allocated by
	                   CreateAppKeyMap.

   SYNOPSIS
	DeleteAppKeyMap(mykeymap);

	void DeleteAppKeyMap(struct KeyMap *);

   FUNCTION
   	This function accepts a pointer to a keymap allocated by
   	CreateAppKeyMap() and deallocates the resources allocated
   	by that function.

   INPUTS
	mykeymap = points to a KeyMap to deallocate.

   RESULT
   	Frees memory previously used by mykeymap and its associated tables.

   BUGS

   SEE ALSO
	console.device/CD_ASKKEYMAP console.device/CD_SETKEYMAP "appkeymap.h"
	AppKeyMap.o/AlterAppKeyMap() AppKeyMap.o/CreateAppKeyMap()

