---
title: AIFF.doc / AIFF / The Application Specific Chunk
manual: devices
chapter: devices
section: aiff-doc-aiff-the-application-specific-chunk
functions: []
libraries: []
---

# AIFF.doc / AIFF / The Application Specific Chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Application Specific Chunk can be used for any purposes whatsoever by
developers and application authors.  For example, an application that
edits sounds might want to use this chunk to store editor state parameters
such as magnification levels, last cursor position, etc.

    #define	ApplicationSpecificID 'APPL' /* ckID for Application */
					     /*  Specific Chunk.     */
```c
    typedef struct {
```
	ID		ckID;
	long		ckSize;
	OSType		applicationSignature;
	char		data[];

```c
    } ApplicationSpecificChunk;
```
The ckID is always 'APPL'.  The ckSize is the size of the data portion of
the chunk, in bytes.  It does not include the 8 bytes used by ckID and
ckSize.

The applicationSignature identifies a particular application.  For
Macintosh applications, this will be the application's four character
signature.

The OSType field is used by applications which run on platforms from Apple
Computer, Inc.  For the Apple II, the OStype field should be set to
'pdos'. For the Macintosh, this field should be set to the four character
signature as registered with Apple Technical Support.

The data field is the data specific to the application.

The Application Specific Chunk is optional.  Any number of Application
Specific Chunks may exist in a single FORM AIFF.

