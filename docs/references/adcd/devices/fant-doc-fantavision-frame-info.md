---
title: FANT.doc / Fantavision frame info
manual: devices
chapter: devices
section: fant-doc-fantavision-frame-info
functions: []
libraries: []
---

# FANT.doc / Fantavision frame info

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
**     Each frame has this structure defined.
*/
typedef struct FrameFormat
{
   int OpCode;           /* Frame opcode */
   long Parm;            /* contains frame number for opNEXT, opREPEAT */
   char Rep1, Rep2;      /* Rep1 is repeat counter, Rep2 is not used */
   int TweenRate;        /* number of tweens per frame */

   int ChannelIndex[2];  /* -3 stop sound is this channel

```c
                         ** -2 modify current sound
                         ** -1 no sound for this channel
                         ** (all others) is an index into the sound
                         ** list.  Which sound to use.
                         */
```
   int NumberOfPolys;    /* number of polygons in this frame */
   int ColorPalette[32]; /* xRGB - format 4 bits per register */
   int Pan, Tilt;        /* 0 is centered, (+-) amounts are in pixels */
   int Modes;            /* Frame modes */
   int pad;              /* expansion */
};

