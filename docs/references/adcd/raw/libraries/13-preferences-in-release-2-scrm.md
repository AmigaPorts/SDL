# 13 / Preferences in Release 2 / SCRM




```c
    struct ScreenModePrefs
    {
        ULONG sm_Reserved[4];
        ULONG sm_DisplayID;              /* Displaymode ID */
        UWORD sm_Width;                  /* Screen width */
        UWORD sm_Height;                 /* Screen height */
        UWORD sm_Depth;                  /* Screen depth */
        UWORD sm_Control;                /* BIT 0, Autoscroll yes/no */
    };
```
