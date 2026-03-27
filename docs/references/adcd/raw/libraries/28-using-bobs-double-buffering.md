# 28 / Using Bobs / Double-Buffering


Double-buffering is the technique of supplying two different memory areas
in which the drawing routines may create images.  The system displays one
memory space while drawing into the other area.  This eliminates the
"flickering" that is visible when a single display is being rendered into
at the same time that it is being displayed.


    Double-buffering For One Means Double-buffering For All.
    --------------------------------------------------------
    If any of the Bobs is double-buffered, then all of them must be
    double-buffered.
To find whether a Bob is to be double-buffered, the system examines the
pointer named [DBuffer](../Libraries_Manual_guide/node0398.html#line10) in the [Bob](../Libraries_Manual_guide/node0398.html) structure.  If this pointer has a value
of NULL, the system does not use double-buffering for this Bob.  For
example:


```c
    myBob.DBuffer = NULL; /* do this if this Bob is NOT double-buffered */
```
 [DBufPacket and Double-Buffering](../Libraries_Manual_guide/node03AA.html) 

