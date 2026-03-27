---
title: 33 IFFParse Library / Parsing an IFF File
manual: libraries
chapter: libraries
section: 33-iffparse-library-parsing-an-iff-file
functions: []
libraries: []
---

# 33 IFFParse Library / Parsing an IFF File

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Chunk reading requires a parser to scan each chunk and dispatch the proper
access/conversion procedure.  For a simple [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) file, such parsing may be
relatively easy, consisting mainly reading in the data of desired chunks,
and seeking over unwanted chunks (and the pad byte after odd-length
chunks). Interpreting nested chunks is more complex, and requires a method
for keeping track of the current context, i.e., the data which is still
relevant at any particular depth into the nest.  The original IFF
specifications compare an IFF file to a C program.  Such a metaphor can be
useful in understanding the scope of of the chunks in an IFF file.

The IFFParse library addresses general [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) parsing requirements by
providing a run-time library which can extract the chunks you want from an
IFF file, with the ability to pass control to you when it reaches a chunk
that requires special processing such as decompression.  IFFParse also
understands complex nested IFF formats and will keep track of the context
for you.

 [Basic Functions and Structures of IFFParse Library](libraries/33-basic-functions-and-structures-of-iffparse-library.md) 

