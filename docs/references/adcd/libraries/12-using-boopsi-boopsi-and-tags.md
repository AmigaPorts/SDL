---
title: 12 / / Using Boopsi / Boopsi and Tags
manual: libraries
chapter: libraries
section: 12-using-boopsi-boopsi-and-tags
functions: []
libraries: []
---

# 12 / / Using Boopsi / Boopsi and Tags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Boopsi uses tag lists to pass and manipulate its attributes.  To Boopsi,
each [TagItem](libraries/37-tags-tag-functions-and-structures.md) (defined in <utility/[tagitem.h](autodocs-2.0/includes-utility-tagitem-h.md)>) in a tag list is an
attribute/value pair.  The TagItem.ti_Tag field contains an ID for the
attribute and the ti_Data field holds the attribute's value.

For example, the string gadget class defines an attribute called
[STRINGA_LongVal](libraries/b-strgclass-attributes-stringa-longval-isgnu.md), which is the current integer value of the gadget. Certain
[gadgetclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md) objects have an attribute called GA_Image.  Its value is not
an integer, it is a pointer to an image.

Note that these tag lists can also contain utility.library Global System
control tags (like [TAG_SKIP](libraries/37-tags-simple-tag-usage.md) and [TAG_DONE](libraries/37-tags-simple-tag-usage.md)), which Boopsi uses in processing
its tag lists.  Any application that ends up processing these lists should
do so using the tag manipulation functions from utility.library.  For more
information on tags and utility.library, see the "[Utility Library](libraries/37-utility-library.md)" chapter
of this manual.

