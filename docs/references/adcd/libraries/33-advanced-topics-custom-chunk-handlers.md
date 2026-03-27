---
title: 33 / Advanced Topics / Custom Chunk Handlers
manual: libraries
chapter: libraries
section: 33-advanced-topics-custom-chunk-handlers
functions: []
libraries: []
---

# 33 / Advanced Topics / Custom Chunk Handlers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Like custom stream handlers, custom chunk handlers are implemented using
Release 2 [Hook](libraries/37-callback-hooks-callback-hook-structure-and-function.md) structures.  See the [previous section](libraries/33-advanced-topics-custom-stream-handlers.md) for details on how a
handler function may be interfaced using a Hook structure.

There are two types of chunk handlers:  entry handlers and exit handlers.
Entry handlers are invoked just after the parser enters the chunk; the
stream will be positioned to read the first byte in the chunk. (If the
chunk is a [FORM](libraries/33-the-structure-of-iff-files-composite-data-types.md), [LIST](libraries/33-the-structure-of-iff-files-composite-data-types.md), [CAT](libraries/33-the-structure-of-iff-files-composite-data-types.md), or [PROP](libraries/33-the-structure-of-iff-files-composite-data-types.md), the longword type will be read by the
parser; the stream will be positioned to read the byte immediately
following the type.)  Exit handlers are invoked just before the parser
leaves the chunk; the stream is not positioned predictably within the
chunk.

 [Installing a Custom Chunk Handler](libraries/33-custom-chunk-handlers-installing-a-custom-chunk-handler.md) 
 [Inside a Custom Chunk Handler](libraries/33-custom-chunk-handlers-inside-a-custom-chunk-handler.md) 
 [The Object Parameter](libraries/33-custom-chunk-handlers-the-object-parameter.md) 

