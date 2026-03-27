---
title: 13 / Preferences 1.3 & Older Versions / Preferences Structure in 1.3
manual: libraries
chapter: libraries
section: 13-preferences-1-3-older-versions-preferences-structure-in
functions: []
libraries: []
---

# 13 / Preferences 1.3 & Older Versions / Preferences Structure in 1.3

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Preferences structure in 1.3 and earlier versions of the OS is a
static 232 byte data structure defined in <intuition/[preferences.h](autodocs-2.0/includes-intuition-preferences-h.md)> as
follows:


struct Preferences
{
```c
    /* the default font height */
    BYTE FontHeight;                  /* height for system default font  */

    /* constant describing what's hooked up to the port */
    UBYTE PrinterPort;                /* printer port connection         */

    /* the baud rate of the port */
    UWORD BaudRate;                   /* baud rate for the serial port   */

    /* various timing rates */
    struct timeval KeyRptSpeed;       /* repeat speed for keyboard       */
    struct timeval KeyRptDelay;       /* Delay before keys repeat        */
    struct timeval DoubleClick;       /* Interval allowed between clicks */

    /* Intuition Pointer data */
    UWORD PointerMatrix[POINTERSIZE]; /* Definition of pointer sprite    */
    BYTE XOffset;                     /* X-Offset for active 'bit'       */
    BYTE YOffset;                     /* Y-Offset for active 'bit'       */
    UWORD color17;                    /***********************************/
    UWORD color18;                    /* Colours for sprite pointer      */
    UWORD color19;                    /***********************************/
    UWORD PointerTicks;               /* Sensitivity of the pointer      */

    /* Workbench Screen colors */
    UWORD color0;                     /***********************************/
    UWORD color1;                     /*  Standard default colours       */
    UWORD color2;                     /*   Used in the Workbench         */
    UWORD color3;                     /***********************************/

    /* positioning data for the Intuition View */
    BYTE ViewXOffset;                 /* Offset for top lefthand corner  */
    BYTE ViewYOffset;                 /* X and Y dimensions              */
    WORD ViewInitX, ViewInitY;        /* View initial offset values      */

    BOOL EnableCLI;                 /* CLI availability switch (OBSOLETE)*/

    /* printer configurations */
    UWORD PrinterType;                    /* printer type                */
    UBYTE PrinterFilename[FILENAME_SIZE]; /* file for printer            */

    /* print format and quality configurations */
    UWORD PrintPitch;                 /* print pitch                     */
    UWORD PrintQuality;               /* print quality                   */
    UWORD PrintSpacing;               /* number of lines per inch        */
    UWORD PrintLeftMargin;            /* left margin in characters       */
    UWORD PrintRightMargin;           /* right margin in characters      */
    UWORD PrintImage;                 /* positive or negative            */
    UWORD PrintAspect;                /* horizontal or vertical          */
    UWORD PrintShade;                 /* b&w, half-tone, or color        */
    WORD PrintThreshold;              /* darkness ctrl for b/w dumps     */

    /* print paper descriptors */
    UWORD PaperSize;                  /* paper size                      */
    UWORD PaperLength;                /* paper length in number of lines */
    UWORD PaperType;                  /* continuous or single sheet      */

    /* Serial device settings: These are 6 nibble-fields in 3 bytes      */
    /* (these look a little strange so the defaults will map out to 0)   */
    UBYTE   SerRWBits;   /* upper nibble = (8-number of read bits)       */
                         /* lower nibble = (8-number of write bits)      */
    UBYTE   SerStopBuf;  /* upper nibble = (number of stop bits - 1)     */
                         /* lower nibble = (table value for BufSize)     */
    UBYTE   SerParShk;   /* upper nibble = (value for Parity setting)    */
                         /* lower nibble = (value for Handshake mode)    */
    UBYTE   LaceWB;      /* if workbench is to be interlaced             */

    UBYTE   WorkName[FILENAME_SIZE]; /* temp file for printer            */

    BYTE    RowSizeChange;           /* affect NormalDisplayRows/Columns */
    BYTE    ColumnSizeChange;

    UWORD    PrintFlags;    /* user preference flags                     */
    UWORD    PrintMaxWidth; /* max width of printed picture in 10ths/in  */
    UWORD    PrintMaxHeight;/* max height of printed picture in 10ths/in */
    UBYTE    PrintDensity;  /* print density                             */
    UBYTE    PrintXOffset;  /* offset of printed picture in 10ths/inch   */

    UWORD    wb_Width;      /* override default workbench width  */
    UWORD    wb_Height;     /* override default workbench height */
    UBYTE    wb_Depth;      /* override default workbench depth  */

    UBYTE    ext_size;      /* extension information -- do not touch! */
                            /* extension size in blocks of 64 bytes   */
```
};

