---
title: Details /  INFO sub-chunks
manual: devices
chapter: devices
section: details-info-sub-chunks
functions: [LoadSeg]
libraries: [dos.library]
---

# Details /  INFO sub-chunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

BRSH - size 82


```c
    WORD    Number;        ; Brush number (between 0 and 7)
    CHAR    Filename[80];  ; IFF ILBM filename

    There may be more than one of these.
```
STNC - size 82


    Same format as BRSH chunk.
TXTR - size 82


```c
    Same format as BRSH chunk.  The Filename field is the name of
    a code module that can be loaded with LoadSeg().
```
OBSV - size 28

```c
    VECTOR  Camera;         ; Camera position
    VECTOR  Rotate;         ; Camera rotation angles
    FRACT   Focal;          ; Camera focal length

    This tells where the camera is, how it is aimed, and its
    focal length.  The rotation angles are in degrees, and specify
    rotations around the X, Y, and Z axes.  The camera looks down
    its own Y axis, with the top of the picture in the direction of
    the Z axis.  If the rotation angles are all zero, its axes
    are aligned with the world coordinate axes.  The rotations are
    performed in the order ZXY about the camera axes.  A positive
    angle rotates Y toward Z, Z toward X, and X toward Y for
    rotations about the X, Y, and Z axes respectively.  To
    understand the focal length, imagine a 320 x 200 pixel
    rectangle perpendicular to, and centered on the camera's
    Y axis.  Any objects in the infinite rectangular cone defined
    by the camera position and the 4 corners of the rectangle will
    appear in the picture.
```
OTRK - size 18


```c
    BYTE    Trackname[18];

    This chunk specifies the name of an object that the camera is
    "tracked" to.  If the name is NULL, the camera doesn't track
    Otherwise, if the object is moved inside Turbo Silver, the
    camera will follow it.
```
OSTR - size 56


```c
    STORY   CStory;         ; a STORY structure for the camera

    The story structure is defined above.
```
FADE - size 12


```c
    FRACT   FadeAt;         ; distance to start fade
    FRACT   FadeBy;         ; distance of total fade
    BYTE    pad;            ; pad byte - must be zero
    COLOR   FadeTo;         ; RGB color to fade to
```
SKYC - size 8


```c
    BYTE    pad;            ; pad byte - must be zero
    COLOR   Horizon;        ; horizon color
    BYTE    pad;            ; pad byte - must be zero
    COLOR   Zenith;         ; zenith color
```
AMBI - size 4


```c
    BYTE    pad;            ; pad byte - must be zero
    COLOR   Ambient;        ; abmient light color
```
GLB0 - size 8



```c
    BYTE    Props[8];       ; an array of 8 "global properties" used
                            ; by Turbo Silver.

    Props[0] - GLB_EDGING       ; edge level (globals requester)
    Props[1] - GLB_PERTURB      ; perturbance (globals requester)
    Props[2] - GLB_SKY_BLEND    ; sky blending factor (0-255)
    Props[3] - GLB_LENS         ; lens type (see below)
    Props[4] - GLB_FADE         ; flag - Sharp/Fuzzy focus (globals)
    Props[5] - GLB_SIZE         ; "apparant size" (see below)
    Props[6] - GLB_RESOLVE      ; resolve depth (globals requester)
    Props[7] - GLB_EXTRA        ; flag - genlock sky on/off

    The edging and perturbance values control the heuristics in ray
    tracing.  The sky blending factor is zero for no blending, and 255
    for full blending.  The lens type is a number from 0-4, corresponding
    to the boxes in the "camera" requester, and correspond to 0) Manual,
    1) Wide angle, 2) Normal, 3) Telephoto, and 4) Custom.  It is used
    in setting the camera's focal length if the camera is tracked to an
    object.  The Sharp/Fuzzy flag turns the "fade" feature on and off -
    non-zero means on.  The "apparant size" parameter is 100 times the
    "custom size" parameter in the camera requester.  And is used to set
    the focal length for a custom lens.  The "resolve depth" controls
    the number of rays the ray tracer will shoot for a single pixel.
    Each reflective/refractive ray increments the depth counter, and
    the count is never allowed to reach the "resolve depth".  If both
    a reflective and a refractive ray are traced, each ray gets its
    own version of the count - so theoretically, a resolve depth of
    4 could allow much more than 4 rays to be traced.  The "genlock
    sky" flag controls whether the sky will be colored, or set to
    the genlock color (color 0 - black) in the final picture.
```
All of the INFO sub-chunks are optional, as is the INFO chunk.
Default values are supplied if the chunks are not present.  The
defaults are:  no brushes, stencils, or textures defined; no story
for the camera; horizon and zenith and ambient light colors set
to black; fade color set to (80,80,80);  un-rotated, un-tracked
camera at (-100, -100, 100); and global properties array set to
[30, 0, 0, 0, 0, 100, 8, 0].

---

## See Also

- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
