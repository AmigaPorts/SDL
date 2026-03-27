# locale.library/StrConvert



   NAME
	StrConvert -- transform a string according to collation information.
		      (V38)

   SYNOPSIS
	length = StrConvert(locale,string,buffer,bufferSize,type);
	D0                  A0     A1     A2     D0         D1

	ULONG StrConvert(struct [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) *,[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57),[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37),ULONG,ULONG);

   FUNCTION
	This function transforms the passed string and places the resulting
	into the supplied buffer. No more than bufferSize bytes are copied
	into the buffer.

	The transformation is such that if the C strcmp() function is applied
	to two transformed strings, it returns a value corresponding to
	the result returned by the [StrnCmp()](../Includes_and_Autodocs_3._guide/node045F.html) function applied to the two
	original strings.

   INPUTS
	locale - the locale to use for the transformation
	string - NULL-terminated string to transform
	buffer - buffer where to put the transformed string
	bufferSize - maximum number of bytes to deposit in the buffer
	             StrConvert() may require more storage than
		     the unconverted string does
	type - describes how the transformation is to be performed. See
	       the documentation on [StrnCmp()](../Includes_and_Autodocs_3._guide/node045F.html) for more information on the
	       comparison types available

   RESULT
	length - length of the transformed string which is the number of bytes
		 deposited in the buffer minus 1 (since strings are NULL-
		 terminated)

   SEE ALSO
	[StrnCmp()](../Includes_and_Autodocs_3._guide/node045F.html), [<libraries/locale.h>](../Includes_and_Autodocs_3._guide/node05E3.html)

