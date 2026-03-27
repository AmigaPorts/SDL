# datatypes.library/ObtainDataTypeA



   NAME
	ObtainDataTypeA - Examines a handle and return its [DataType](../Includes_and_Autodocs_3._guide/node05F7.html#line174).
```c
                                                               (V39)
```
   SYNOPSIS
	dtn = ObtainDataTypeA (type, handle, attrs);
	d0			d0    a0      a1

	struct [DataType](../Includes_and_Autodocs_3._guide/node05F7.html#line174) *ObtainDataTypeA (ULONG, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	dtn = ObtainDataType (type, handle, tag1, ...);

	struct [DataType](../Includes_and_Autodocs_3._guide/node05F7.html#line174) *ObtainDataType (ULONG, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) tag1, ...);

   FUNCTION
	This function examines the data that the handle points to,
	and returns a [DataType](../Includes_and_Autodocs_3._guide/node05F7.html#line174) record that describes the data.

   INPUTS
	type - Type of handle.

	handle - Handle to examine.
	    For DTST_FILE, handle must be [BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) lock.
	    For DTST_CLIPBOARD, handle must be struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *.
	    For DTST_MEMORY, handle will be ignored (you need
	    to specify the additional information required by this
	    source type through the attrs list).

	attrs - Additional attributes (see TAGS).

   TAGS
	DTA_SourceAddress (APTR) -- For DTST_MEMORY source data, this
	    specifies the memory address at which the source data is
	    located. This must be non-NULL. This attribute is required
	    for DTST_MEMORY source data (V44).

	DTA_SourceSize (ULONG) -- For DTST_MEMORY source data, this
	    specifies the size of the source data (in bytes). This must
	    be greater than 0. This attribute is required for DTST_MEMORY
	    source data (V44).

   NOTES
	The datatypes.library maintains a sorted list of all the
	[DataType](../Includes_and_Autodocs_3._guide/node05F7.html#line174) descriptors.  The descriptor can consist of a
	function, a data mask for the first 64 bytes of the data,
	and a name pattern.

	The sort order for the list is:

	    Descriptors with a function and no mask or name pattern.
	    Descriptors with a function and a mask or name pattern.
	    Descriptors with no function and a mask or name pattern.

	Within each group, they are also sorted in descending priority
	and descending mask length.

	The DTST_MEMORY source type introduced in V44 makes in-memory
	data available to subclasses as if the data were stored in a
	file. Thus, subclasses will see the data as DTST_FILE. Since
	the data does not correspond to an on-disk file, subclasses
	and examine hook code must not assume that they will be able
	to reopen the "file" whose data has been provided to them.

   RETURNS
	Success returns a pointer to a [DataType](../Includes_and_Autodocs_3._guide/node05F7.html#line174).  You must call
	FreeDataType() when you are done with the handle.

	A NULL return indicates failure.  Use [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) to get error value.
	Following is a summary of the error number used and there meaning
	as it relates to DataTypes.

	ERROR_NO_FREE_STORE - Not enough memory.
	ERROR_OBJECT_NOT_FOUND - Unable to open the data object.
	ERROR_NOT_IMPLEMENTED - Unknown handle type.

   SEE ALSO
	FreeDataType()

