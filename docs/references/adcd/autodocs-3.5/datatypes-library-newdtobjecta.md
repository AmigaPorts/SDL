---
title: datatypes.library/NewDTObjectA
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-newdtobjecta
functions: [IoErr]
libraries: [dos.library]
---

# datatypes.library/NewDTObjectA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	NewDTObjectA - Create an data type object.              (V39)

    SYNOPSIS
	o = NewDTObjectA (name, attrs);
	d0		  d0   a0

	[Object](autodocs-3.5/include-intuition-classusr-h.md) *NewDTObjectA (APTR, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	o = NewDTObject (name, tag1, ...);

	[Object](autodocs-3.5/include-intuition-classusr-h.md) *NewDTObject (APTR, [Tag](autodocs-3.5/include-utility-tagitem-h.md) tag1, ...);

    FUNCTION
	This is the method for creating datatype objects from
	'boopsi' classes.  Boopsi' stands for "basic object-oriented
	programming system for Intuition".)

	You further specify initial "create-time" attributes for the
	object via a [TagItem](autodocs-3.5/include-utility-tagitem-h.md) list, and they are applied to the
	resulting datatype object that is returned.

    INPUTS
	name - Name of the data source.  Usually an existing file name.

	attrs - Pointer to a taglist containing additional arguments.

    TAGS
	DTA_SourceType - Specify the type of source data; such as coming
	    from a file or clipboard (defaults to DTST_FILE).  If
	    source type is clipboard, then the name field contains the
	    numeric clipboard unit. If source type is DTST_MEMORY,
	    the name field will be ignored (V44).

	DTA_Handle - Can optionally be used instead of the name field.
	    Must be a valid [FileHandle](autodocs-3.5/include-dos-dosextens-h.md) if DTA_SourceType is DTST_FILE.
	    Must be a valid [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) if DTA_SourceType is DTST_CLIPBOARD.
	    Will be ignored if DTA_SourceType is DTST_MEMORY.

	DTA_DataType - Specify the class of data.  Data is a pointer to a
	    valid [DataType](autodocs-3.5/include-datatypes-datatypes-h.md).  This is only used when attempting to create
	    a new object that doesn't have any source data.

	DTA_GroupID - Specify that the object must be of this type, or
	    NewDTObject() will fail with [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) of
	    ERROR_OBJECT_WRONG_TYPE.

	DTA_SourceAddress (APTR) -- For DTST_MEMORY source data, this
	    specifies the memory address at which the source data is
	    located. This must be non-NULL. This attribute is required
	    for DTST_MEMORY source data (V44).

	DTA_SourceSize (ULONG) -- For DTST_MEMORY source data, this
	    specifies the size of the source data (in bytes). This must
	    be greater than 0. This attribute is required for DTST_MEMORY
	    source data (V44).

	GA_Left, GA_RelRight, GA_Top, GA_RelBottom, GA_Width, GA_RelWidth,
	GA_Height, GA_RelHeight - Specify the placement of the object
	    within the destination window.

	GA_ID - Specify the object ID.

	GA_UserData - Specify the application specific data for the
	    object.

    RETURNS
	A boopsi object, which may be used in different contexts such
	as a gadget or image, and may be manipulated by generic functions.
	You eventually free the object using [DisposeDTObject()](autodocs-3.5/datatypes-library-disposedtobject.md).

	A NULL return indicates failure.  Use [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) to get error value.
	Following is a summary of the error number used and there meaning
	as it relates to DataTypes.

	ERROR_REQUIRED_ARG_MISSING - Indicates that a required attribute
	    wasn't passed in.
	ERROR_BAD_NUMBER - An invalid group ID was passed in.
	ERROR_OBJECT_WRONG_TYPE - [Object](autodocs-3.5/include-intuition-classusr-h.md) data type doesn't match
	    DTA_GroupID.
	ERROR_NO_FREE_STORE - Not enough memory.
	DTERROR_UNKNOWN_DATATYPE - Unable to open the class library
	    associated with the data type.
	DTERROR_COULDNT_OPEN - Unable to open the data object.
	ERROR_NOT_IMPLEMENTED - Unknown handle type.

    NOTES
	This function invokes the OM_NEW "method" for the class specified.

	The DTST_MEMORY source type introduced in V44 makes in-memory
	data available to subclasses as if the data were stored in a
	file. Thus, subclasses will see the data as DTST_FILE. Since
	the data does not correspond to an on-disk file, subclasses
	and examine hook code must not assume that they will be able
	to reopen the "file" whose data has been provided to them.

    EXAMPLE
	[STRPTR](autodocs-3.5/include-exec-types-h.md) fileName = "s:startup-sequence"
	[Object](autodocs-3.5/include-intuition-classusr-h.md) *o;

	/* Simplest use is to just open an existing file */
	if (o = NewDTObject ((APTR)fileName, NULL))
	{
	    /* Free the object when we are done with it */
	    [DisposeDTObject](autodocs-3.5/datatypes-library-disposedtobject.md) (o);
	}

    SEE ALSO
	[AddDTObject()](autodocs-3.5/datatypes-library-adddtobject.md), [DisposeDTObject()](autodocs-3.5/datatypes-library-disposedtobject.md), [RemoveDTObject()](autodocs-3.5/datatypes-library-removedtobject.md),
	intuition.library/NewObjectA()

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
