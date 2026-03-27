# 30 / Regions / Creating and Deleting Regions


You allocate a [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) data structure with the [NewRegion()](../Includes_and_Autodocs_2._guide/node0460.html) call.


```c
    struct Region *NewRegion( void );
```
The [NewRegion()](../Includes_and_Autodocs_2._guide/node0460.html) function allocates and initializes a [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) structure that
has no drawable areas defined in it.  If the application draws through a
new region, nothing will be drawn as the region is empty.  The application
must add rectangles to the region before any graphics will appear.

Use [DisposeRegion()](../Includes_and_Autodocs_2._guide/node0434.html) to free the [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) structure when you are done with it.


```c
    void DisposeRegion( struct Region *region );
```
[DisposeRegion()](../Includes_and_Autodocs_2._guide/node0434.html) returns all memory associated with a region to the system
and deallocates all rectangles that have been linked to it.


```c
    Don't Forget to Free Your Rectangles.
    -------------------------------------
    All of the functions that add rectangles to the region make copies
    of the rectangles.  If the program allocates a rectangle, then adds
    it to a region, it still must deallocate the rectangle.  The call to
    [DisposeRegion()](../Includes_and_Autodocs_2._guide/node0434.html) will not deallocate rectangles explicitly
    allocated by the application.
```
