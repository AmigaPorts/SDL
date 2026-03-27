---
title: AIFF / The Comments Chunk / Comments Chunk Format
manual: devices
chapter: devices
section: aiff-the-comments-chunk-comments-chunk-format
functions: []
libraries: []
---

# AIFF / The Comments Chunk / Comments Chunk Format

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    #define 	CommentID	'COMT'	/* ckID for Comments Chunk  */

    typedef struct {
```
	ID		ckID;
	long		ckSize;

	unsigned short  numComments;
	Comment		comments[];

```c
    }CommentsChunk;
```
The ckID is always 'COMT'.  The ckSize is the size of the data portion of
the chunk, in bytes.  It does not include the 8 bytes used by ckID and
ckSize.

The numComments field contains the number of comments in the Comments
Chunk. This is followed by the comments themselves.  Comments are always
even numbers of bytes in length, so there is no padding between comments
in the Comments Chunk.

The Comments Chunk is optional.  No more than one Comments Chunk may
appear in a single FORM AIFF.

