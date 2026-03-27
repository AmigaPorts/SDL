---
title: Standard Data and Property Chunks / Optional Text Chunks
manual: devices
chapter: devices
section: standard-data-and-property-chunks-optional-text-chunks-2
functions: []
libraries: []
---

# Standard Data and Property Chunks / Optional Text Chunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Several text chunks may be included in a FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md) to keep ancillary
information.

The optional property "NAME" names the musical score, for instance "Fugue
in C".

The optional property "(c) " holds a copyright notice for the score.  The
chunk ID "(c) " serves the function of the copyright characters "(c) ".
E.g., a "(c) " chunk containing "1986 Electronic Arts" means "(c) 1986
Electronic Arts".

The optional property "AUTH" holds the name of the score's author.

The chunk types "NAME", "(c) ", and "AUTH" are property chunks.  Putting
more than one NAME (or other) property in a [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) is redundant.  Just the
last NAME counts.  A property should be shorter than 256 characters.
Properties can appear in a [PROP](devices/a-quick-introduction-to-iff-advanced-topics.md) [SMUS](devices/smus-iff-simple-musical-score-introduction.md) to share them over a [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) of FORMs
"SMUS".

The optional data chunk "ANNO" holds any text annotations typed in by the
author.

An ANNO chunk is not a property chunk, so you can put more than one in a
FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md).  You can make ANNO chunks any length up to 2^31 - 1 characters,
but 32767 is a practical limit.  Since they're not properties, ANNO chunks
don't belong in a [PROP](devices/a-quick-introduction-to-iff-advanced-topics.md) [SMUS](devices/smus-iff-simple-musical-score-introduction.md).  That means they can't be shared over a [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)
of FORMs [SMUS](devices/smus-iff-simple-musical-score-introduction.md).

Syntactically, each of these chunks contains an array of 8-bit ASCII
characters in the range " " (SP, hex 20) through "~" (tilde, hex 7F), just
like a standard "TEXT" chunk.  [See "Strings, String Chunks, and String
Properties" in "[EA IFF 85](devices/a-quick-introduction-to-iff-what-is-iff.md)" Electronic Arts Interchange File Format.]  The
chunk's ckSize field holds the count of characters.


```c
    #define ID_NAME MakeID('N', 'A', 'M', 'E')
    /* NAME chunk contains a CHAR[], the musical score's name.       */

    #define ID_Copyright MakeID('(', 'c', ')', ' ')
    /* "(c) " chunk contains a CHAR[], the FORM's copyright notice.  */

    #define ID_AUTH MakeID('A', 'U', 'T', 'H')
    /* AUTH chunk contains a CHAR[], the name of the score's author. */

    #define ID_ANNO MakeID('A', 'N', 'N', 'O')
    /* ANNO chunk contains a CHAR[], author's text annotations.      */
```
Remember to store a 0 pad byte after any odd-length chunk.

