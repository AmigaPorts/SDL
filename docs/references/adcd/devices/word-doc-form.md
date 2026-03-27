---
title: WORD.doc / FORM
manual: devices
chapter: devices
section: word-doc-form
functions: []
libraries: []
---

# WORD.doc / FORM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

FORM ID:  WORD

FORM Purpose:  Document storage (supports color, fonts, pictures)

FORM Description:

This include file describes FORM WORD and its Chunks

   /*

```c
    *      IFF Form WORD structures and defines
    *      Copyright (c) 1987 New Horizons Software, Inc.
    *
    *      Permission is hereby granted to use this file in any and all
    *      applications.  Modifying the structures or defines included
    *      in this file is not permitted without written consent of
    *      New Horizons Software, Inc.
    */
```
   #include ":IFF/ILBM.h"        /* Makes use of ILBM defines */

   #define ID_WORD      MakeID('W','O','R','D')      /* Form type */

   #define ID_FONT      MakeID('F','O','N','T')      /* Chunks */
   #define ID_COLR      MakeID('C','O','L','R')
   #define ID_DOC       MakeID('D','O','C',' ')
   #define ID_HEAD      MakeID('H','E','A','D')
   #define ID_FOOT      MakeID('F','O','O','T')
   #define ID_PCTS      MakeID('P','C','T','S')
   #define ID_PARA      MakeID('P','A','R','A')
   #define ID_TABS      MakeID('T','A','B','S')
   #define ID_PAGE      MakeID('P','A','G','E')
   #define ID_TEXT      MakeID('T','E','X','T')
   #define ID_FSCC      MakeID('F','S','C','C')
   #define ID_PINF      MakeID('P','I','N','F')

   /*

    *   Special text characters for page number, date, and time
    *   Note:  ProWrite currently supports only PAGENUM_CHAR, and only in
    *      headers and footers
    */
   #define PAGENUM_CHAR   0x80
   #define DATE_CHAR      0x81
   #define TIME_CHAR      0x82

