---
title: 15 / Elements of GadTools / GadTools Tags
manual: libraries
chapter: libraries
section: 15-elements-of-gadtools-gadtools-tags
functions: []
libraries: []
---

# 15 / Elements of GadTools / GadTools Tags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Many of the GadTools functions use [TagItem](libraries/37-tags-tag-functions-and-structures.md) arrays or tag lists to pass
information across the function interface.  These tag-based functions come
in two types, one that takes a pointer to an array of tag items and one
that takes a variable number of tag item arguments directly in the
function call.  In general, the second form, often called the varargs form
because the call takes a variable number of arguments, is provided for
convenience and is internally converted to the first form.  When looking
through the Autodocs or other Amiga reference material, the documentation
for both forms is usually available in the array-based function
description.

All GadTools tags begin with a leading "GT".  In general, they also have a
two-letter mnemonic for the kind of gadget in question.  For example,
slider gadgets recognize tags such as "[GTSL_Level](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)".  The GadTools tags are
defined in <libraries/[gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md)>.  Certain GadTools gadgets also
recognize other Intuition tags such as GA_Disabled and PGA_Freedom, which
can be found in <intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>.

For more information on tags and tag-based functions, be sure to see the
"[Utility Library](libraries/37-utility-library-tags.md)" chapter in this manual.

