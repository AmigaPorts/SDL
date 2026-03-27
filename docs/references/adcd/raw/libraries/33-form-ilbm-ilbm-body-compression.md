# 33 / / FORM ILBM / ILBM BODY Compression


The BODY contains pixel data for the image.  Width, Height, and depth
(Planes) is specified in the [BMHD](../Libraries_Manual_guide/node0461.html#line3).

If the [BMHD](../Libraries_Manual_guide/node0461.html#line3) Compression byte is 0, then the scan line data is not
compressed. If Compression=1, then each scan line is individually
compressed as follows:


```c
    while (not produced the desired number of bytes)

            /* get a byte, call it N */

            if (N >= 0 && N <= 127)
                    /* copy the next N+1 bytes literally */

            if (N >= -127 && N <= -1)
                    /* repeat the next byte N+1 times */

            if (N == -128)
                    /* skip it, presumably it's padding */
```
