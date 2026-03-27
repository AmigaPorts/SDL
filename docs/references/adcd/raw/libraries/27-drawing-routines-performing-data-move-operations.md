# 27 / Drawing Routines / Performing Data Move Operations


The graphics library includes several routines that use the hardware
blitter to handle the rectangularly organized data that you work with when
doing raster-based graphics.  These blitter routines do the following:


      * Clear an entire segment of memory

      * Set a raster to a specific color

      * Scroll a subrectangle of a raster

      * Draw a pattern "through a stencil"

      * Extract a pattern from a bit-packed array and draw it into a
        raster

      * Copy rectangular regions from one bitmap to another

      * Control and utilize the hardware-based data mover, the blitter
The following sections cover these routines in detail.


```c
    WARNING:
    --------
    The graphics library rendering and data movement routines generally
    wait to get access to the blitter, start their blit, and then exit
    without waiting for the blit to finish.  Therefore, you must
    [WaitBlit()](../Libraries_Manual_guide/node0368.html) after a graphics rendering or data movement call if you
    intend to immediately deallocate, examine, or perform order-dependent
    processor operations on the memory used in the call.
```
 [Clearing a Memory Area](../Libraries_Manual_guide/node0361.html) 
 [Setting a Whole Raster to a Color](../Libraries_Manual_guide/node0362.html) 
 [Scrolling a Sub-rectangle of a Raster](../Libraries_Manual_guide/node0363.html) 
 [Drawing through a Stencil](../Libraries_Manual_guide/node0364.html) 
 [Extracting from a Bit-packed Array](../Libraries_Manual_guide/node0365.html) 
 [Copying Rectangular Areas](../Libraries_Manual_guide/node0366.html) 
 [Scaling Rectangular Areas](../Libraries_Manual_guide/node0367.html) 
 [When to Wait for the Blitter](../Libraries_Manual_guide/node0368.html) 
 [Accessing the Blitter Directly](../Libraries_Manual_guide/node0369.html) 

