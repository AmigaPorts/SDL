---
title: FANT.doc / Polygon types
manual: devices
chapter: devices
section: fant-doc-polygon-types
functions: []
libraries: []
---

# FANT.doc / Polygon types

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#define pDELETE    0x7000  /* object is a filler (deleted from display) */
#define pFILLED    0       /* filled polygon */
#define pLINE      1       /* not-connected line polygon */
#define pLINED     2       /* connected line polygon */
#define pTEXTBLOCK 3       /* text block to draw */
#define pCIRCLEDOT 4       /* draw circle dots at vertex's using
                           ** dotSize at size. */
#define pRECTDOT   5       /* draw square dots at vertex's using
                           ** dotSize at size. */
#define pBITMAPDOT 6       /* draw dots using a bitmap at vertex's using
                           ** BitMap. */
#define pBITMAP    7       /* draw just bitmap image */

/* These are used for the pTEXTBLOCK polygon type
*/
/* Text justification
*/
#define tLEFT      0
#define tCENTER    1
#define tRIGHT     2
/* Text style
*/
#define tNORMAL    (int)(FS_NORMAL)
#define tBOLD      (int)(FSF_BOLD)
#define tITALIC    (int)(FSF_ITALIC)
#define tUNDERLINE (int)(FSF_UNDERLINED)
#define tEXTENDED  (int)(FSF_EXTENDED)

