---
title: 33 IFFParse Library / Stream Management
manual: libraries
chapter: libraries
section: 33-iffparse-library-stream-management
functions: []
libraries: []
---

# 33 IFFParse Library / Stream Management

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A stream is a linear array of bytes that may be accessed sequentially or
randomly.  DOS files are streams.  IFFParse uses Release 2 [Hook](libraries/37-callback-hooks-callback-hook-structure-and-function.md) structures
(defined in <utility/[hooks.h](autodocs-2.0/includes-utility-hooks-h.md)>) to implement a general stream management
facility.  This allows the IFFParse library to read, write, and seek any
type of file handle or device by using an application-provided hook
function to open, read, write, seek and close the stream.

Built on top of this facility, IFFParse has two internal stream managers:
one for unbuffered DOS files (AmigaDOS filehandles), and one for the
Clipboard.

 [Initialization](libraries/33-stream-management-initialization.md)    [Termination](libraries/33-stream-management-termination.md)    [Custom Streams](libraries/33-stream-management-custom-streams.md) 

