# locale.library/CloseCatalog



   NAME
	CloseCatalog -- close a message catalog. (V38)

   SYNOPSIS
	CloseCatalog(catalog);
	             A0

	VOID CloseCatalog(struct [Catalog](../Includes_and_Autodocs_3._guide/node05E3.html#line245) *);

   FUNCTION
	Concludes access to a message catalog. The usage count of the
	catalog is decremented. When this count reaches 0, the catalog
	can be expunged from system memory whenever a memory panic occurs.

   INPUTS
	catalog - the message catalog to close. A NULL catalog is a valid
		  parameter and is simply ignored.

   SEE ALSO
	[OpenCatalog()](../Includes_and_Autodocs_3._guide/node045B.html), [GetCatalogStr()](../Includes_and_Autodocs_3._guide/node0458.html)

