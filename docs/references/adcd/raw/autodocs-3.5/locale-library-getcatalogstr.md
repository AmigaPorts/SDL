# locale.library/GetCatalogStr



   NAME
	GetCatalogStr -- get a string from a message catalog. (V38)

   SYNOPSIS
	string = GetCatalogStr(catalog,stringNum,defaultString);
	D0                     A0      D0        A1

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) GetCatalogStr(struct [Catalog](../Includes_and_Autodocs_3._guide/node05E3.html#line245) *,[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39),STRPTR);

   FUNCTION
	This function returns a specific string within a message catalog.
	If the catalog parameter is NULL, or the requested message does not
	exist, then defaultString is returned.

   INPUTS
	catalog - a message catalog as obtained from [OpenCatalog()](../Includes_and_Autodocs_3._guide/node045B.html), or NULL
	stringNum - a message number within the catalog
	defaultString - string to return in case "catalog" is NULL or
	                "stringNum" can't be found

   RESULT
	string - a pointer to a NULL-terminated string. The returned string
		 is READ-ONLY, do NOT modify! This string pointer is valid
		 only as long as the catalog remains open.

   SEE ALSO
	[OpenCatalog()](../Includes_and_Autodocs_3._guide/node045B.html), [CloseCatalog()](../Includes_and_Autodocs_3._guide/node0452.html)

