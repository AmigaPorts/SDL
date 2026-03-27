---
title: FANT.doc / Fantavision movie header
manual: devices
chapter: devices
section: fant-doc-fantavision-movie-header
functions: []
libraries: []
---

# FANT.doc / Fantavision movie header

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
** This header defines how much RAM is needed, how many frames, and sounds
** in the movie.
*/

typedef struct FantHeader
{
   int PointsPerObj;     /* number of vertexs per object */
   int ObjsPerFrame;     /* number of objects per frame */
   int ScreenDepth;      /* 0 to 6, for number of bit planes */
   int ScreenWidth;      /* in pixels */
   int ScreenHeight;     /* in pixels */
   int BackColor;        /* background color palette number */
   long SizeOfMovie;     /* RAM Size of movie, expanded */
   int pad[30];          /* padding for expanding */
   int NumberOfFrames;
   int NumberOfSounds;
   int NumberOfBitMaps;
   int Background;       /* non-zero if first bitmap is a background */
   int SpeedOfMovie;     /* 100 is normal speed, 50 is half speed, etc */
   int pad[3];           /* expansion */
};

