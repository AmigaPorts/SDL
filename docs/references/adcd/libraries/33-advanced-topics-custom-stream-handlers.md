---
title: 33 / Advanced Topics / Custom Stream Handlers
manual: libraries
chapter: libraries
section: 33-advanced-topics-custom-stream-handlers
functions: [Open]
libraries: [dos.library]
---

# 33 / Advanced Topics / Custom Stream Handlers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As discussed earlier, IFFParse contains built-in stream handlers for
AmigaDOS file handles as returned by [Open()](libraries/33-stream-management-initialization.md), and for the clipboard.device.
If you are using AmigaDOS filehandles or the clipboard.device, you need
not supply a custom stream handler.

If you wish to use your compiler's own file I/O functions (such as fread()
) or need to read or write to an unusual handler or Exec device, you must
provide a custom stream handler for your [IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md).  Your custom stream
handler will be called to perform all reads, writes, and seeks on your
custom stream.  The allows you to use compiler file I/O functions, Exec
device commands, or any other method to perform the requested stream
operations.

If you are implementing your own custom stream handler, you will need to
know the mechanics of hook call-backs, and how to interpret the
parameters.  An IFFParse custom stream handler is simply a function in
your code that follows Release 2 hook function conventions (Hook functions
are also known as callback functions.  See the "[Utility Library](libraries/37-utility-library-callback-hooks.md)" chapter
for more details).

 [Installing a Custom Stream Handler](libraries/33-custom-stream-handlers-installing-a-custom-stream-handler.md) 
 [Inside a Custom Stream Handler](libraries/33-custom-stream-handlers-inside-a-custom-stream-handler.md) 

---

## See Also

- [Open — dos.library](../autodocs/dos.library.md#open)
