# 31 Commodities Exchange Library / New Input Events


Commodities Exchange also has functions used to introduce new input events
to the input stream.


```c
    struct InputEvent *InvertString( UBYTE *string, ULONG *keymap );
    void               FreeIEvents( struct InputEvent *ie );
    void               AddIEvents( struct InputEvent *ie );
```
[InvertString()](../Includes_and_Autodocs_2._guide/node0160.html) is an amiga.lib function that accepts an ASCII string and
creates a linked list of input events that translate into the string using
the supplied keymap (or the system default if the key map is NULL).  The
NULL terminated string may contain ANSI character codes, an input
description enclosed in angle (<>) brackets, or one of the following
backslash escape characters:


    \r -- return
    \t -- tab
    \\ -- backslash
For example:


    abc<alt f1>\rhi there.
[FreeIEvents()](../Includes_and_Autodocs_2._guide/node015C.html) frees a list of input events allocated by [InvertString()](../Includes_and_Autodocs_2._guide/node0160.html).
[AddIEvents()](../Includes_and_Autodocs_2._guide/node019E.html) is a commodities.library function that adds a linked list of
input events at the the top of the Commodities network.  Each input event
in the list is made into an individual [CxMessage](../Libraries_Manual_guide/node0403.html).  Note that if passed a
linked list of input events created by InvertString(), the order the
events appear in the string will be reversed.


```c
     [PopShell.c](../Libraries_Manual_guide/node0584.html) 
```
