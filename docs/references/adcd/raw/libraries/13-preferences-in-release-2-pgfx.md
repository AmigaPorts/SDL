# 13 / Preferences in Release 2 / PGFX




```c
    struct PrinterGfxPrefs
    {
        LONG  pg_Reserved[4];
        UWORD pg_Aspect;          /* Horizontal or vertical */
        UWORD pg_Shade;           /* B&W, Greyscale, Color */
        UWORD pg_Image;           /* Positive or negative image */
        WORD  pg_Threshold;       /* Black threshold */
        UBYTE pg_ColorCorrect;    /* RGB color correction */
        UBYTE pg_Dimensions;      /* Dimension type */
        UBYTE pg_Dithering;       /* Type of dithering */
        UWORD pg_GraphicFlags;    /* Rastport dump flags */
        UBYTE pg_PrintDensity;    /* Print density 1 - 7 */
        UWORD pg_PrintMaxWidth;   /* Maximum width */
        UWORD pg_PrintMaxHeight;  /* Maximum height */
        UBYTE pg_PrintXOffset;    /* X Offset */
        UBYTE pg_PrintYOffset;    /* Y Offset */
    };
```
The possible values of each field are defined in <prefs/[printergfx.h](../Libraries_Manual_guide/node05E0.html#line29)>.
Note that your application is responsible for checking if the supplied
values are valid.

