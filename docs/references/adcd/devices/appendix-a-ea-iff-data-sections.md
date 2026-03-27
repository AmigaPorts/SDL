---
title: Appendix A / EA IFF/ Data Sections
manual: devices
chapter: devices
section: appendix-a-ea-iff-data-sections
functions: []
libraries: []
---

# Appendix A / EA IFF/ Data Sections

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The first thing we need of a file is to check: Does it contain IFF data
and, if so, does it contain the kind of data we're looking for?  So we
come to the notion of a "data section".

A "data section" or IFF "[FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)" is one self-contained "data object" that
might be stored in a file by itself.  It is one high level data object
such as a picture or a sound effect, and generally contains a grouping of
chunks.  The IFF structure "FORM" makes it self-identifying.  It could be
a composite object like a musical score with nested musical instrument
descriptions.

 [Group FORM](devices/data-sections-group-form.md) 
 [Composite FORMs](devices/data-sections-composite-forms.md) 
 [Designing New Data Sections](devices/data-sections-designing-new-data-sections.md) 

