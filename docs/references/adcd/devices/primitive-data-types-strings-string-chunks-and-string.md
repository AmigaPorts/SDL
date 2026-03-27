---
title: Primitive Data Types / Strings, String Chunks, and String Properties
manual: devices
chapter: devices
section: primitive-data-types-strings-string-chunks-and-string
functions: []
libraries: []
---

# Primitive Data Types / Strings, String Chunks, and String Properties

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In a string of ASCII text, linefeed (0x0A) denotes a forced line break
(paragraph or line terminator).  Other control characters are not used.
(Cf. Characters.)  For maximum compatibility with line editors, two
linefeed characters are often used to indicate a paragraph boundary.

The ckID for a chunk that contains a string of plain, unformatted text is
"TEXT".  As a practical matter, a text string should probably not be
longer than 32767 bytes.  The standard allows up to 2^31 - 1 bytes.  The
ckID "TEXT" is globally reserved for this use.

When used as a data property (see below), a text string chunk may be 0 to
255 characters long.  Such a string is readily converted to a C string or
a Pascal STRING[255].  The ckID of a property must have a unique property
name, not "TEXT".

When used as a part of a chunk or data property, restricted C string
format is normally used.  That means 0 to 255 characters followed by a
NULL byte (ASCII value 0).

