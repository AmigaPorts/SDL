# 1 / / Libraries of Functions / Opening a Library in C


Call [OpenLibrary()](../Libraries_Manual_guide/node000D.html) to open an Amiga function library. OpenLibrary()
returns the address of the library structure (or library base) which you
must assign to a specific global system variable as specified in the
[table above](../Libraries_Manual_guide/node000D.html#line49) (case is important).

If the library cannot open for some reason, the [OpenLibrary()](../Libraries_Manual_guide/node000D.html) function
returns zero.  Here's a brief example showing how it's used in C.


```c
     [easy.c](../Libraries_Manual_guide/node0578.html) 
```
