---
title: graphics.library/FreeCprList
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-freecprlist-2
functions: []
libraries: []
---

# graphics.library/FreeCprList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       FreeCprList -- deallocate hardware copper list
   SYNOPSIS
```c
       FreeCprList(cprlist)
```
		      a0

	void FreeCprList(struct [cprlist](autodocs-3.5/include-graphics-copper-h.md) *);

   FUNCTION

```c
       return [cprlist](autodocs-3.5/include-graphics-copper-h.md) to free memory pool
```
   INPUTS

```c
       [cprlist](autodocs-3.5/include-graphics-copper-h.md) - pointer to [cprlist](autodocs-3.5/include-graphics-copper-h.md) structure
```
   RESULTS
	memory returned and made available to other tasks

   BUGS

   SEE ALSO
	[graphics/copper.h](autodocs-3.5/include-graphics-copper-h.md)

