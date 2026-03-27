---
title: AIFF.doc / AIFF / File Structure
manual: devices
chapter: devices
section: aiff-doc-aiff-file-structure
functions: []
libraries: []
---

# AIFF.doc / AIFF / File Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The "EA IFF 85 Standard for Interchange Format Files" defines an overall
structure for storing data in files.  Audio IFF conforms to those portions
of "EA IFF 85" that are germane to Audio IFF.  For a more complete
discussion of "EA IFF 85", please refer to the document "EAIFF 85,
Standard for Interchange Format Files."

An "EA IFF 85" file is made up of a number of chunks of data.  Chunks are
the building blocks of "EA IFF 85" files.  A chunk consists of some header
information followed by data:

		+--------------------+
		|       ckID         |\
		+--------------------+ } header info
	        |      ckSize        |/
		+--------------------+
        	|                    |
        	|                    |
        	|       data         |
        	|                    |
        	|                    |
		+--------------------+

	      Figure 2: IFF Chunk structure

A chunk can be represented using our C-like language in the following
manner:

```c
    typedef struct {
```
	ID		ckID;		/* chunk ID		*/
	long		ckSize;		/* chunk Size		*/

	char		ckData[];	/* data			*/
	} Chunk;

The ckID describes the format of the data portion of a chunk.  A program
can determine how to interpret the chunk data by examining ckID.

The ckSize is the size of the data portion of the chunk, in bytes.  It
does not include the 8 bytes used by ckID and ckSize.

The ckData contains the data stored in the chunk.  The format of this data
is determined by ckID.  If the data is an odd number of bytes in length, a
zero pad byte must be added at the end.  The pad byte is not included in
ckSize.

Note that an array with no size specification (e.g., char ckData[];)
indicates a variable-sized array in our C-like language.  This differs
from standard C.

An Audio IFF file is a collection of a number of different types of
chunks. There is a Common Chunk which contains important parameters
describing the sampled sound, such as its length and sample rate.  There
is a Sound Data Chunk which contains the actual audio samples.  There are
several other optional chunks which define markers, list instrument
parameters, store application-specific information, etc.  All of these
chunks are described in detail in later sections of this document.

The chunks in an Audio IFF file are grouped together in a container chunk.
"EA IFF 85" Standard for Interchange Format Files  defines a number of
container chunks, but the one used by Audio IFF is called a FORM.  A FORM
has the following format:

```c
    typedef struct {
```
	ID	ckID;
	long	ckSize;
	ID	formType;
	char	chunks[];

```c
    }
```
The ckID is always 'FORM'.  This indicates that this is a FORM chunk.

The ckSize contains the size of data portion of the 'FORM' chunk.  Note
that the data portion has been broken into two parts, formType and
chunks[].

The formType field describes what's in the 'FORM' chunk.  For Audio IFF
files, formType is always 'AIFF'.  This indicates that the chunks within
the FORM pertain to sampled sound.  A FORM chunk of formType 'AIFF' is
called a FORM AIFF.

The chunks field are the chunks contained within the FORM.  These chunks
are called local chunks.  A FORM AIFF along with its local chunks make up
an Audio IFF file.

Here is an example of a simple Audio IFF file.  It consists of a file
containing single FORM AIFF which contains two local chunks, a Common
Chunk and a Sound Data Chunk.


```c
                        __________________________
                      | FORM AIFF Chunk          |
                      |   ckID  = 'FORM'         |
                      |   formType = 'AIFF'      |
                      |    __________________    |
                      |   | Common Chunk     |   |
                      |   |   ckID = 'COMM'  |   |
                      |   |__________________|   |
                      |    __________________    |
                      |   | Sound Data Chunk |   |
                      |   |   ckID = 'SSND'  |   |
                      |   |__________________|   |
                      |__________________________|

                     Figure 3: Simple Audio IFF File
```
There are no restrictions on the ordering of local chunks within a FORM
AIFF.

A more detailed example of an Audio IFF file can be found in Appendix A.
Please refer to this example as often as necessary while reading the
remainder of this document.

