# 27 / / Viewport Size Specifications / ViewPort Width


The [DWidth](../Includes_and_Autodocs_2._guide/node00B8.html#line40) variable in the [ViewPort](../Libraries_Manual_guide/node032B.html#line59) structure determines how wide, in
pixels, the display segment will be.  To set your ViewPort to the maximum
supported (displayable) NTSC high-resolution width, use the following
fragment (this requires Release 2):


```c
    struct DimensionInfo querydims;
    struct Rectangle *oscan;
    struct ViewPort viewport;

    /* Use PAL_MONITOR_ID instead of NTSC_MONITOR_ID to get PAL   */
    /* dimensions                                                 */
    if (GetDisplayInfoData( NULL,(UBYTE *)&querydims, sizeof(querydims),
        DTAG_DIMS, NTSC_MONITOR_ID|HIRES_KEY ))
    {
            /* Use StdOScan instead of MaxOScan to get standard   */
            /* overscan dimensions as set by the user in Overscan */
            /* Preferences                                        */
            oscan = &querydims.MaxOScan;
            viewPort->DWidth = oscan->MaxX - oscan->MinX + 1;
    }
```
You may specify a smaller value of pixels per line to produce a narrower
display segment or simply set [ViewPort.DWidth](../Includes_and_Autodocs_2._guide/node00B8.html#line40) to the nominal value for
this resolution.

Although the system software allows you define low-resolution displays as
wide as 362 pixels and high-resolution displays as wide as 724 pixels, you
should use caution in exceeding the normal values of 320 or 640,
respectively.  Because display overscan varies from one monitor to
another, many video displays will not be able to show all of a wider
display, and sprite display may also be affected.  However, if you use the
standard overscan values ([DimensionInfo.StdOScan](../Includes_and_Autodocs_2._guide/node00BD.html#line91)) provided by the Release
2 function [GetDisplayInfoData()](../Libraries_Manual_guide/node033D.html) as shown above, the user's preference for
the size of the display will be satisfied.

If you are using hardware sprites or VSprites with your display, and you
specify [ViewPort](../Libraries_Manual_guide/node032B.html#line59) widths exceeding 320 or 640 pixels (for low or
high-resolution, respectively), it is likely that some hardware sprites
will not be properly rendered on the screen. These sprites may not be
rendered because playfield DMA (direct memory access) takes precedence
over sprite DMA when an extra-wide display is produced.  See the Amiga
[Hardware](../Hardware_Manual_guide/node012B.html) Reference Manual for a more complete description of this
phenomenon.

