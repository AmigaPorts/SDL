---
title: icon.library/ChangeToSelectedIconColor
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-changetoselectediconcolor
functions: []
libraries: []
---

# icon.library/ChangeToSelectedIconColor

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ChangeToSelectedIconColor -- Modify an RGB colour value for use in
	    a selected icon image (V44)

   SYNOPSIS
	ChangeToSelectedIconColor(cr)
	                          A0

	VOID ChangeToSelectedIconColor(struct [ColorRegister](autodocs-3.5/include-datatypes-pictureclass-h.md) *cr);

   FUNCTION
	This function will change the provided RGB colour value to make it
	suitable for use in an icon's select image. This may involve darkening
	or toning the colour. Usually, icon.library calls this function
	when creating a select image for palette mapped icons which do not
	contain "real" select images.

   INPUTS
	cr -- Pointer to a [ColorRegister](autodocs-3.5/include-datatypes-pictureclass-h.md), containing the RGB colour value
	    to be changed.

