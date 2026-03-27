---
title: AIFF / The Comments Chunk / Comment
manual: devices
chapter: devices
section: aiff-the-comments-chunk-comment
functions: []
libraries: []
---

# AIFF / The Comments Chunk / Comment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A comment consists of a time stamp, marker id, and a text count followed
by text.

```c
    typedef struct {
```
	unsigned long	timeStamp;
	MarkerID	marker;
	unsigned short	count;
	char		text;

```c
    } Comment;
```
The timeStamp indicates when the comment was created.  On the Amiga, units
are the number of seconds since January 1, 1978.  On the Macintosh, units
are the number of seconds since January 1, 1904.

A comment can be linked to a marker.  This allows applications to store
long descriptions of markers as a comment.  If the comment is referring to
a marker, then the marker field is the ID of that marker.  Otherwise,
marker is zero, indicating that this comment is not linked to a marker.

The count is the length of the text that makes up the comment.  This is a
16-bit quantity, allowing much longer comments than would be available
with a pstring.

The text field contains the comment itself.

The Comments Chunk is optional.  No more than one Comments Chunk may
appear in a single FORM AIFF.

