# 13 / Preferences in Release 2 / OSCN




```c
    struct OverscanPrefs
    {
        ULONG            os_Reserved[4];
        ULONG            os_DisplayID;   /* Displaymode ID */
        Point            os_ViewPos;     /* View X/Y Offset */
        Point            os_Text;        /* TEXT overscan dimension */
        struct Rectangle os_Standard;    /* STANDARD overscan dimension */
    };
```
