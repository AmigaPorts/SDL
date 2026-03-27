---
title: Attributes
manual: amiga-mail
chapter: amiga-mail
section: attributes
functions: []
libraries: []
---

# Attributes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All boopsi objects have attributes associated with them.  These
attributes reflect various properties of a specific object.  For
example, an image object has attributes such as IA_Left, IA_Top,
IA_Width, and IA_Height, all of which correspond to fields in the Image
structure.  Five methods deal with an object's attributes:

  OM_NEW sets attributes at object creation (initialization) time
  OM_SET changes attributes after the object has been created
  OM_GET reads an object attribute
  OM_UPDATE updates an object attribute (for use by objects only)
  OM_NOTIFY notifies one object of changes to another object's attributes

Not all of these methods apply to all attributes.  Some attributes are
not "settable" or not "gettable", for example.   See the [appendix](amiga-mail/iv-23-appendix-boopsi-class-reference.md) at
the end of this article to find out which of these methods apply to
specific attributes.

