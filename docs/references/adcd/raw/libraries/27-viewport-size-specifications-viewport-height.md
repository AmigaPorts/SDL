# 27 / / Viewport Size Specifications / ViewPort Height


The [DHeight](../Includes_and_Autodocs_2._guide/node00B8.html#line40) field of the [ViewPort](../Libraries_Manual_guide/node032B.html#line59) structure determines how many video
lines will be reserved to show the height of this display segment.  The
size of the actual segment depends on whether you define a non-interlaced
or an interlaced display.  An interlaced ViewPort displays twice as many
lines as does a non-interlaced ViewPort in the same physical height.

For example, a complete [View](../Libraries_Manual_guide/node032B.html#line51) consisting of two [ViewPort](../Libraries_Manual_guide/node032B.html#line59)s might be defined
as follows:

  * [ViewPort](../Libraries_Manual_guide/node032B.html#line59) 1 is 150 lines, high-resolution mode (uses the top

```c
    three-quarters of the display).
```
  * [ViewPort](../Libraries_Manual_guide/node032B.html#line59) 2 is 49 lines of low-resolution mode (uses the bottom

```c
    quarter of the display and allows the space for the required
    blank line between ViewPorts).
```
Initialize the height directly in DHeight.  Nominal height for a
non-interlaced display is 200 lines for NTSC, 256 for PAL.  Nominal height
for an interlaced display is 400 lines for NTSC, 512 for PAL.

To set your [ViewPort](../Libraries_Manual_guide/node032B.html#line59) to the maximum supported (displayable) height, use
the following code fragment (this requires Release 2):


```c
    struct DimensionInfo querydims;
    struct Rectangle *oscan;
    struct ViewPort viewport;

    if (GetDisplayInfoData( NULL,(UBYTE *)&querydims,
                            sizeof(struct DimensionInfo),
                            DTAG_DIMS, modeID ))
    {
            /* Use StdOScan instead of MaxOScan to get standard   */
            /* overscan dimensions as set by the user in Overscan */
            /* Preferences                                        */
            oscan = &querydims.MaxOScan;
            viewPort->DHeight = oscan->MaxY - oscan->MinY + 1;
    }
```
