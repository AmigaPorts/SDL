---
title: AIFF.doc / AIFF / The Text Chunks, Name, Author, Copyright, Annotation
manual: devices
chapter: devices
section: aiff-doc-aiff-the-text-chunks-name-author-copyright
functions: []
libraries: []
---

# AIFF.doc / AIFF / The Text Chunks, Name, Author, Copyright, Annotation

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These four chunks are included in the definition of every "EA IFF 85"
file. All are text chunks; their data portion consists solely of text.
Each of these chunks is optional.

```c
    #define 	NameID 'NAME' 	/* ckID for Name Chunk */
    #define 	NameID 'AUTH' 	/* ckID for Author Chunk */
    #define 	NameID '(c) ' 	/* ckID for Copyright Chunk */
    #define 	NameID 'ANNO' 	/* ckID for Annotation Chunk */

    typedef struct {
```
	ID	ckID;
	long	ckSize;
	char 	text[];

```c
    }TextChunk;
```
The ckID is either 'NAME', 'AUTH', '(c) ', or 'ANNO' depending on whether
the chunk is a Name Chunk, Author Chunk, Copyright Chunk, or  Annotation
Chunk, respectively.  For the Copyright Chunk, the 'c' is lowercase and
there is a space (0x20) after the close parenthesis.

The ckSize is the size of the data portion of the chunk, in this case the
text.

The text field contains pure ASCII characters.  it is not a pstring or a C
string.  The number of characters in text is determined by ckSize.  The
contents of text depend on the chunk, as described below:

 [Name Chunk](devices/aiff-the-text-chunks-name-chunk.md) 
 [Author Chunk](devices/aiff-the-text-chunks-author-chunk.md) 
 [Copyright Chunk](devices/aiff-the-text-chunks-copyright-chunk.md) 
 [Annotation Chunk](devices/aiff-the-text-chunks-annotation-chunk.md) 

