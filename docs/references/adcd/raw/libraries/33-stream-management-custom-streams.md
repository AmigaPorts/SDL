# 33 / Stream Management / Custom Streams


A custom stream handler can allow you (and iffparse.library) to use your
compiler's own file I/O functions such as fopen(), fread() and fwrite(),
rather than the lower-level AmigaDOS equivalents [Open()](../Libraries_Manual_guide/node042E.html#line10), [Read()](../Includes_and_Autodocs_2._guide/node02E0.html), and
[Write()](../Includes_and_Autodocs_2._guide/node0310.html).  A custom stream handler could also be used to read or write [IFF](../Libraries_Manual_guide/node0428.html)
files from an Exec device or an unusual handler or filesystem.

If you install your own stream handler function, iffparse.library will
call your function whenever it needs to read, write, or seek on your file.
Your stream handler function will then perform these stream actions for
iffparse.library.  See the "[Custom Stream Handlers](../Libraries_Manual_guide/node0454.html)" section for more
information on custom stream handlers.

