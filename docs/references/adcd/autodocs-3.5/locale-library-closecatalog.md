---
title: locale.library/CloseCatalog
manual: autodocs-3.5
chapter: autodocs-3.5
section: locale-library-closecatalog
functions: [GetCatalogStr, OpenCatalog]
libraries: [locale.library]
---

# locale.library/CloseCatalog

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CloseCatalog -- close a message catalog. (V38)

   SYNOPSIS
	CloseCatalog(catalog);
	             A0

	VOID CloseCatalog(struct [Catalog](autodocs-3.5/include-libraries-locale-h.md) *);

   FUNCTION
	Concludes access to a message catalog. The usage count of the
	catalog is decremented. When this count reaches 0, the catalog
	can be expunged from system memory whenever a memory panic occurs.

   INPUTS
	catalog - the message catalog to close. A NULL catalog is a valid
		  parameter and is simply ignored.

   SEE ALSO
	[OpenCatalog()](autodocs-3.5/locale-library-opencatalog.md), [GetCatalogStr()](autodocs-3.5/locale-library-getcatalogstr.md)

---

## See Also

- [GetCatalogStr — locale.library](../autodocs/locale.library.md#getcatalogstr)
- [OpenCatalog — locale.library](../autodocs/locale.library.md#opencatalog)
