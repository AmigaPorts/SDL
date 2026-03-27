# 3 / Forming a Basic Playfield / Basic Playfield Summary


The steps for defining a basic playfield are summarized below:

1. Define Playfield Characteristics
   --------------------------------
   a.  [Specify color](../Hardware_Manual_guide/node0066.html)  for each pixel:

```c
      * Load desired colors in color table registers.

      * Define color of each pixel in terms of the binary value
        that points at the desired color register.

      * Build bitplanes and set bitplane registers:

           Bits 12-14 in  [BPLCON0](../Hardware_Manual_guide/node0092.html)  - number of bitplanes ( [BPU2 - BPU0](../Hardware_Manual_guide/node0068.html#line4) ).
            [BPLxPTH](../Hardware_Manual_guide/node006B.html#line32)  - pointer to bitplane starting position in memory
```
	               (written as a long word).

   b.  [Specify resolution](../Hardware_Manual_guide/node0069.html) :


```c
      * Low resolution:

          320 pixels in each horizontal line.
          Clear bit 15 in register  [BPLCON0](../Hardware_Manual_guide/node0092.html)  ( [HIRES](../Hardware_Manual_guide/node0069.html#line7) ).

      * High resolution:

          640 pixels in each horizontal line.
          Set bit 15 in register  [BPLCON0](../Hardware_Manual_guide/node0092.html)  ( [HIRES](../Hardware_Manual_guide/node0069.html#line7) ).
```
   c.  [Specify interlaced or non-interlaced mode](../Hardware_Manual_guide/node0069.html) :


```c
      * Interlaced mode:

          400 vertical lines for NTSC, 512 for PAL.
          Set bit 2 in register  [BPLCON0](../Hardware_Manual_guide/node0092.html)  ( [LACE](../Hardware_Manual_guide/node0069.html#line94) ).

      * Non-interlaced mode:

          200 vertical lines for NTSC, 256 for PAL.
          Clear bit 2 in  [BPLCON0](../Hardware_Manual_guide/node0092.html)  ( [LACE](../Hardware_Manual_guide/node0069.html#line94) ).
```
2.  [Allocate Memory](../Hardware_Manual_guide/node006A.html) . To calculate data-bytes in the total bitplanes,
   -----------------  use the following formula:


          Bytes per line * lines in playfield * number of bitplanes
3.  [Define Size of Display Window](../Hardware_Manual_guide/node006F.html) .
   -------------------------------
   * Write start position of display window in  [DIWSTRT](../Hardware_Manual_guide/node0070.html) :


```c
      Horizontal position in bits 0 through 7 (low order bits).
      Vertical position in bits 8 through 15 (high order bits).
```
   * Write stop position of display window in  [DIWSTOP](../Hardware_Manual_guide/node0071.html) :


      Horizontal position in bits 0 through 7.
      Vertical position in bits 8 through 15.
4.  [Define Data Fetch](../Hardware_Manual_guide/node0072.html) . Set registers  [DDFSTRT](../Hardware_Manual_guide/node0072.html#line9)  and  [DDFSTOP](../Hardware_Manual_guide/node0072.html#line31) :
   -------------------
   * For  [DDFSTRT](../Hardware_Manual_guide/node0072.html#line9) , use the horizontal position as shown in

```c
      [Setting the Display Window Starting Position](../Hardware_Manual_guide/node0070.html) .
```
   * For  [DDFSTOP](../Hardware_Manual_guide/node0072.html#line31) , use the horizontal position as shown in

```c
      [Setting the Display Window Stopping Position](../Hardware_Manual_guide/node0071.html) .
```
5.  [Define Modulo](../Hardware_Manual_guide/node0072.html#line46) . Set registers  [BPL1MOD and BPL2MOD](../Hardware_Manual_guide/node0072.html#line108) .  Set modulo to 0
   ---------------  for non-interlaced, 40 for interlaced.

6. Write Copper Instructions To Handle  [Redisplay](../Hardware_Manual_guide/node0075.html) .
   -----------------------------------------------

7.  [Enable Color Display](../Hardware_Manual_guide/node0076.html) .For the A1000: set bit 9 in  [BPLCON0](../Hardware_Manual_guide/node0092.html)  to enable the
   ---------------------- the color display on a composite video monitor.

                          RGB video is not affected.  Only the A1000 has
                          color composite video output, other Amiga models
                          cannot enable this feature using standard
                          hardware.
