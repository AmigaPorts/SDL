---
title: gadtools.library/FreeMenus
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-freemenus-2
functions: [CreateMenusA]
libraries: [gadtools.library]
---

# gadtools.library/FreeMenus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeMenus -- frees memory allocated by [CreateMenusA()](autodocs-3.5/gadtools-library-createmenusa-2.md). (V36)

   SYNOPSIS
	FreeMenus(menu)
	          A0

	VOID FreeMenus(struct [Menu](autodocs-3.5/include-intuition-intuition-h.md) *);

   FUNCTION
	Frees the menus allocated by [CreateMenusA()](autodocs-3.5/gadtools-library-createmenusa-2.md).  It is safe to
	call this function with a NULL parameter.

   INPUTS
	menu - pointer to menu structure (or first MenuItem) obtained
	       from [CreateMenusA()](autodocs-3.5/gadtools-library-createmenusa-2.md).

   SEE ALSO
	[CreateMenusA()](autodocs-3.5/gadtools-library-createmenusa-2.md)

---

## See Also

- [CreateMenusA — gadtools.library](../autodocs/gadtools.library.md#createmenusa)
