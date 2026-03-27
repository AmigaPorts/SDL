---
title: FANT.doc / Polygon modes
manual: devices
chapter: devices
section: fant-doc-polygon-modes
functions: []
libraries: []
---

# FANT.doc / Polygon modes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#define pTYPEMASK  0x00FF  /* type mask to get just type of poly */
#define pSELECT    0x8000  /* is object selected? */
#define pOUTLINE   0x4000  /* outlined polygon using DotModeSide to
                           ** determine when to not connect a line.
                           ** ex. 0 draws on all sides, 1 will draw on
                           ** everyother side, 2 will leave every second
                           ** side blank, 3 will every third side
                           ** blank, etc. */
#define pBACKDROP  0x2000  /* polygon will be dropped into the background
                           ** during animation. */
#define pMSKBITMAP 0x1000  /* bitmap has a mask */

