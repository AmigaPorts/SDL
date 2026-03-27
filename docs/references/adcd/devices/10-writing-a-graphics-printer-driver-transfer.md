---
title: 10 / Writing A Graphics Printer Driver / Transfer()
manual: devices
chapter: devices
section: 10-writing-a-graphics-printer-driver-transfer
functions: []
libraries: []
---

# 10 / Writing A Graphics Printer Driver / Transfer()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Transfer() dithers and renders an entire row of pixels passed to
it by the [Render()](devices/10-writing-a-graphics-printer-driver-render.md) function. When Transfer() gets called, it is passed 5
parameters:

Parameters:



          PInfo     - a pointer to a PrtInfo structure
          y         - the row number
          ptr       - a pointer to the buffer
          colors    - a pointer to the color buffers
          BufOffset - the buffer offset for interleaved printing.
The dithering process of Transfer() might entail thresholding, grey-scale
dithering, or color-dithering each destination pixel.

If PInfo->pi_threshold is non-zero, then the dither value is:


       PInfo->pi_threshold \^15
If PInfo->pi_threshold is zero, then the dither value is computed
by:


```c
       *(PInfo->pi_dmatrix + ((y & 3) * 2) + (x & 3))
```
where x is initialized to PInfo->pi_xpos and is incremented for each of
the destination pixels.  Since the printer device uses a 4x4 dither
matrix, you must calculate the dither value exactly as given above.
Otherwise, your driver will be non-standard and the results will be
unpredictable.

The Transfer() function renders by putting a pixel in the print buffer
based on the dither value. If the intensity value for the pixel is greater
than the dither value as computed above, then the pixel should be put in
the print buffer. If it is less than, or equal to the dither value, it
should be skipped to process the next pixel.

Printer         Type of
Color Class     Dithering       Rendering logic
-----------     ---------       ---------------
PCC_BW          Thresholding    Test the black value against the threshold

                                value to see if you should render a black
                                pixel.

                Grey Scale      Test the black value against the dither
                                value to see if you should render a black
                                pixel.

                Color           NA
PCC_YMC         Thresholding    Test the black value against the

                                threshold value to see if you should render
                                a black pixel.  Print yellow, magenta and
                                cyan pixel to make black.

                Grey Scale      Test the black value against the dither
                                value to see if you should render a black
                                pixel. Print yellow, magenta and cyan pixel
                                to make black.

                Color           Test the yellow value against the dither
                                value to see if you should render a yellow
                                pixel. Repeat this process for magenta and
                                cyan.
PCC_YMCB        Thresholding    Test the black value against the threshold

```c
                                value to see if you should render a black
                                pixel.

                Grey Scale      Test the black value against the dither
                                value to see if you should render a black
                                pixel.

                Color           Test the black value against the dither
                                value to see if you should render a black
                                pixel. If black is not rendered, then
                                test the yellow value against the dither
                                value to see if you should render a yellow
                                pixel.  Repeat this process for magenta and
                                cyan. (See the [EpsonX_transfer.c](devices/devices-dev-examples-epsonx-transfer-c.md) file)
```
PCC_YMC_BW      Thresholding    Test the black value against the threshold

                                value to see if you should render a black
                                pixel.

                Grey Scale      Test the black value against the dither
                                value to see if you should render a black
                                pixel.

                Color           Test the yellow value against the dither
                                value to see if you should render a yellow
                                pixel. Repeat this process for magenta and
                                cyan.
In general, if black is rendered for a specific printer dot, then the YMC
values should be ignored, since the combination of YMC is black. It is
recommended that the printer buffer be constructed so that the order of
colors printed is yellow, magenta, cyan and black, to prevent smudging and
minimize color contamination on ribbon color printers.

The example transfer.c files are provided in C for demonstration only.
Writing this module in assembler can cut the time needed for a graphic
dump in half. The EpsonX transfer.asm file is an example of this.

