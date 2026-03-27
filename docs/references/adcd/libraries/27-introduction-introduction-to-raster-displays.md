---
title: 27 / Introduction / Introduction To Raster Displays
manual: libraries
chapter: libraries
section: 27-introduction-introduction-to-raster-displays
functions: []
libraries: []
---

# 27 / Introduction / Introduction To Raster Displays

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are three major television standards in common use around the world:
NTSC, PAL, and SECAM.  NTSC is used primarily in the United States and
Japan; PAL and SECAM are used primarily in Europe.  The Amiga currently
supports both NTSC and PAL.  The major differences between the two systems
are refresh frequency and the number of scan lines produced.  Where
necessary, the differences will be described and any special
considerations will be mentioned.

The Amiga produces its video displays on standard television or video
monitors by using raster display techniques.  The picture you see on the
video display screen is made up of a series of horizontal video lines
stacked one on top of another, as illustrated in the following figure.
Each line represents one sweep of an electronic video beam, which "paints"
the picture as it moves along.  The beam sweeps from left to right,
producing the full screen one line at a time.  After producing the full
screen, the beam returns to the top of the display screen.


```c
     [Figure 27-1: How the Video Display Picture Is Produced](libraries/lib-pics-27-1-pic.md) 
```
The diagonal lines in the figure show how the video beam returns to the
start of each horizontal line.

 [Effect of Display Overscan on the Viewing Area](libraries/27-effect-of-display-overscan-on-the-viewing-area.md) 
 [Color Information for the Video Lines](libraries/27-color-information-for-the-video-lines.md) 

