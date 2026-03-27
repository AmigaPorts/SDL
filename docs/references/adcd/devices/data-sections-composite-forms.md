---
title: Data Sections / Composite FORMs
manual: devices
chapter: devices
section: data-sections-composite-forms
functions: []
libraries: []
---

# Data Sections / Composite FORMs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) [chunk](devices/primitive-data-types-chunks.md) inside a FORM is a full-fledged data section.  This means you
can build a composite object such as a multi-frame animation sequence by
nesting available picture FORMs and sound effect FORMs.  You can insert
additional [chunk](devices/primitive-data-types-chunks.md)s with information like frame rate and frame count.

Using composite [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s, you leverage on existing programs that create and
edit the component FORMs.  Those editors may even look into your composite
object to copy out its type of component.  Such editors are not allowed to
replace their component objects within your composite object.  That's
because the IFF standard lets you specify consistency requirements for the
composite FORM such as maintaining a count or a directory of the
components.  Only programs that are written to uphold the rules of your
FORM type may create or modify such FORMs.

Therefore, in designing a program that creates composite objects, you are
strongly requested to provide a facility for your users to import and
export the nested [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s.  Import and export could move the data through a
clipboard or a file.

Here are several existing [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) types and rules for defining new ones:

 [FTXT](devices/composite-forms-ftxt.md)      [ILBM](devices/composite-forms-ilbm.md)      [PICs](devices/composite-forms-pics.md)      [Other Macintosh Resource Types](devices/composite-forms-other-macintosh-resource-types.md) 

