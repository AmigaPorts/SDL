# 13 / Preferences in Release 2 / FONT




```c
    struct FontPrefs
    {
        LONG            fp_Reserved[4];
        UBYTE           fp_FrontPen;     /* Textcolor */
        UBYTE           fp_BackPen;      /* Character background color */
        UBYTE           fp_DrawMode;
        struct TextAttr fp_TextAttr;
        BYTE            fp_Name[FONTNAMESIZE]; /* Font name */
    };
```
