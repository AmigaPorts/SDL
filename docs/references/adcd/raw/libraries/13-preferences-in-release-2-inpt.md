# 13 / Preferences in Release 2 / INPT




```c
    struct InputPrefs
    {
        LONG           ip_Reserved[4];
        UWORD          ip_PointerTicks; /* Sensitivity of the pointer */
        struct timeval ip_DoubleClick;  /* Interval between clicks */
        struct timeval ip_KeyRptDelay;  /* keyboard repeat delay   */
        struct timeval ip_KeyRptSpeed;  /* Keyboard repeat speed   */
        WORD           ip_MouseAccel;   /* Mouse acceleration      */
    };
```
