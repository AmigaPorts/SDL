# nonvolatile.library/GetNVInfo



   NAME
	GetNVInfo -- report information on the current nonvolatile storage.
		     (V40)

   SYNOPSIS
	information = GetNVInfo(killRequesters);
	D0			D1

	struct [NVInfo](../Includes_and_Autodocs_3._guide/node0635.html#line28) *GetNVInfo(BOOL);

   FUNCTION
	Finds the user's preferred nonvolatile device and reports information
	about it.

   INPUTS
	killRequesters - suppress system requesters flag. TRUE if all system
			 requesters are to be suppressed during this function.
			 FALSE if system requesters are allowed.

   RESULT
	information - pointer to an [NVInfo](../Includes_and_Autodocs_3._guide/node0635.html#line28) structure. This structure contains
		      information on the NV storage media with the largest
		      storage. The structure contains 2 longword fields:
		      nvi_MaxStorage and nvi_FreeStorage. Both values are
		      rounded down to the nearest ten. The nvi_MaxStorage
		      field is defined as the total amount of nonvolatile
		      storage available on this device. The nvi_FreeStorage is
		      defined as the amount of available space for NVDISK or
		      the amount of non-locked storage for NVRAM. For NVDISK,
		      the nvi_FreeStorage takes into account the amount of
		      overhead room required to store a new App/Item. This
		      amount is 3 blocks to allow room for storing a new Item
		      file and possibly a new App directory. For NVRAM, the
		      amount of overhead is 5 bytes. However, the amount of
		      room required to store a new NVRAM item depends on the
		      length of the App and Item names. Refer to [StoreNV()](../Includes_and_Autodocs_3._guide/node04E2.html)
		      function for storage details.

		      This function may return NULL in the case of failure.

   SEE ALSO
	[FreeNVData()](../Includes_and_Autodocs_3._guide/node04DD.html), [StoreNV()](../Includes_and_Autodocs_3._guide/node04E2.html), [<libraries/nonvolatile.h>](../Includes_and_Autodocs_3._guide/node0635.html)

