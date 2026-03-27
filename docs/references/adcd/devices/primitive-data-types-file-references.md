---
title: Primitive Data Types / File References
manual: devices
chapter: devices
section: primitive-data-types-file-references
functions: []
libraries: []
---

# Primitive Data Types / File References

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Issue: We may need a standard form for references to other files.  A "file
ref" could name a directory and a file in the same type of operating
system as the reference's originator.  Following the reference would
expect the file to be on some mounted volume, or perhaps the same
directory as the file that made the reference.  In a network environment,
a file reference could name a server, too.

Issue: How can we express operating-system independent file references?

Issue: What about a means to reference a portion of another file?  Would
this be a "file ref" plus a reference to a "link" within the target file?

