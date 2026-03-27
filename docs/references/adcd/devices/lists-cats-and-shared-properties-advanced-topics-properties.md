---
title: LISTs, CATs and Shared Properties (Advanced topics) / Properties for LIST
manual: devices
chapter: devices
section: lists-cats-and-shared-properties-advanced-topics-properties
functions: []
libraries: []
---

# LISTs, CATs and Shared Properties (Advanced topics) / Properties for LIST

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Optional "properties for [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)" store the origin of the list's contents in
a PROP [chunk](devices/primitive-data-types-chunks.md) for the pseudo [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) type "LIST".  They are the properties
originating program "OPGM", processor family "OCPU", computer type "OCMP",
computer serial number or network address "OSN ", and user name "UNAM". In
our imperfect world, these could be called upon to distinguish between
unintended variations of a data format or to work around bugs in
particular originating/receiving program pairs.  Issue: Specify the format
of these properties.

A creation date could also be stored in a property, but let's ask that
file creating, editing, and transporting programs maintain the correct
date in the local file system.  Programs that move files between machine
types are expected to copy across the creation dates.

