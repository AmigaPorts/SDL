---
title: locale.library/GetCatalogStr
manual: autodocs-3.5
chapter: autodocs-3.5
section: locale-library-getcatalogstr
functions: [CloseCatalog, OpenCatalog]
libraries: [locale.library]
---

# locale.library/GetCatalogStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetCatalogStr -- get a string from a message catalog. (V38)

   SYNOPSIS
	string = GetCatalogStr(catalog,stringNum,defaultString);
	D0                     A0      D0        A1

	[STRPTR](autodocs-3.5/include-exec-types-h.md) GetCatalogStr(struct [Catalog](autodocs-3.5/include-libraries-locale-h.md) *,[LONG](autodocs-3.5/include-exec-types-h.md),STRPTR);

   FUNCTION
	This function returns a specific string within a message catalog.
	If the catalog parameter is NULL, or the requested message does not
	exist, then defaultString is returned.

   INPUTS
	catalog - a message catalog as obtained from [OpenCatalog()](autodocs-3.5/locale-library-opencatalog.md), or NULL
	stringNum - a message number within the catalog
	defaultString - string to return in case "catalog" is NULL or
	                "stringNum" can't be found

   RESULT
	string - a pointer to a NULL-terminated string. The returned string
		 is READ-ONLY, do NOT modify! This string pointer is valid
		 only as long as the catalog remains open.

   SEE ALSO
	[OpenCatalog()](autodocs-3.5/locale-library-opencatalog.md), [CloseCatalog()](autodocs-3.5/locale-library-closecatalog.md)

---

## See Also

- [CloseCatalog — locale.library](../autodocs/locale.library.md#closecatalog)
- [OpenCatalog — locale.library](../autodocs/locale.library.md#opencatalog)
