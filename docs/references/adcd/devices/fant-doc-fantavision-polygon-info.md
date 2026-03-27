---
title: FANT.doc / Fantavision polygon info
manual: devices
chapter: devices
section: fant-doc-fantavision-polygon-info
functions: []
libraries: []
---

# FANT.doc / Fantavision polygon info

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
**     Each polygon has this structure defined.
*/
typedef struct PolyFormat
{
   int NumberOfPoints;   /* how many vertexs for this polygon */
   int Type;             /* polygon type */
   int Color;            /* palette color number (see note 1) */
   Rect Bounds;          /* enclosing rectangle of polygon */
   int Depth;            /* polygon view depth (see note 2) */
   char DotModeSize;     /* in pixels, not larger than 40 */
   char DotModeSide;     /* determines outlining features */
   int OutlineColor;     /* palette color number for outline */
   int BitMapIndex;      /* if not -1,then bitmap index into bitmap list */
   int BMRealWidth;      /* in pixels */
   int BMRealHeight;
   int TextLength;       /* length of text for pTEXTBLOCK */
   int TextJust;
   char TextSize;        /* size in pixels */
   char TextStyle;
   long pad;             /* expansion */
   Point p[];            /* array of points defining vertexs */
};

