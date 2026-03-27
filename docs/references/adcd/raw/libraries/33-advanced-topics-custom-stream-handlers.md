# 33 / Advanced Topics / Custom Stream Handlers


As discussed earlier, IFFParse contains built-in stream handlers for
AmigaDOS file handles as returned by [Open()](../Libraries_Manual_guide/node042E.html#line10), and for the clipboard.device.
If you are using AmigaDOS filehandles or the clipboard.device, you need
not supply a custom stream handler.

If you wish to use your compiler's own file I/O functions (such as fread()
) or need to read or write to an unusual handler or Exec device, you must
provide a custom stream handler for your [IFFHandle](../Libraries_Manual_guide/node042C.html).  Your custom stream
handler will be called to perform all reads, writes, and seeks on your
custom stream.  The allows you to use compiler file I/O functions, Exec
device commands, or any other method to perform the requested stream
operations.

If you are implementing your own custom stream handler, you will need to
know the mechanics of hook call-backs, and how to interpret the
parameters.  An IFFParse custom stream handler is simply a function in
your code that follows Release 2 hook function conventions (Hook functions
are also known as callback functions.  See the "[Utility Library](../Libraries_Manual_guide/node04A2.html)" chapter
for more details).

 [Installing a Custom Stream Handler](../Libraries_Manual_guide/node0455.html) 
 [Inside a Custom Stream Handler](../Libraries_Manual_guide/node0456.html) 

