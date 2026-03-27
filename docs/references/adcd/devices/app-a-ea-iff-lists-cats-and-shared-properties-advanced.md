---
title: App.A EA IFF/ LISTs, CATs, and Shared Properties (Advanced topics)
manual: devices
chapter: devices
section: app-a-ea-iff-lists-cats-and-shared-properties-advanced
functions: []
libraries: []
---

# App.A EA IFF/ LISTs, CATs, and Shared Properties (Advanced topics)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Data often needs to be grouped together, for example, consider a list of
icons. Sometimes a trick like arranging little images into a big raster
works, but generally they'll need to be structured as a first class group.
The objects "[LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)" and "[CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) " are IFF-universal mechanisms for this
purpose.  Note: [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) and CAT are advanced topics the first time reader
will want to skip.

Property settings sometimes need to be shared over a list of similar
objects. E.g., a list of icons may share one color map.  [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) provides a
means called "[PROP](devices/a-quick-introduction-to-iff-advanced-topics.md)" to do this.  One purpose of a LIST is to define the
scope of a PROP. A "[CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) ", on the other hand, is simply a concatenation of
objects.

Simpler programs may skip [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)s and [PROP](devices/a-quick-introduction-to-iff-advanced-topics.md)s altogether and just handle [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s
and [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) s.  All "fully-conforming" IFF programs also know about "CAT ",
"LIST", and "PROP".  Any program that reads a [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) inside a LIST must
process shared PROPs to correctly interpret that FORM.

 [Group CAT](devices/lists-cats-and-shared-properties-advanced-topics-group-cat.md)     [Group LIST](devices/lists-cats-and-shared-properties-advanced-topics-group-list.md)     [Group PROP](devices/lists-cats-and-shared-properties-advanced-topics-group-prop.md)     [Properties for LIST](devices/lists-cats-and-shared-properties-advanced-topics-properties.md) 

