---
title: The Display Database
manual: amiga-mail
chapter: amiga-mail
section: the-display-database
functions: [GetDisplayInfoData]
libraries: [graphics.library]
---

# The Display Database

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Release 2.0 of the OS introduces system support for different monitor
types and programmable display modes.  Applications can make use of
these features through the Display Database.  The Display Database
provides an easy way for applications to stay compatible with past,
present and future versions of the OS and the display hardware.

The database contains information about the available monitor types
(like PAL or VGA) and the display modes that a particular monitor type
is capable of displaying (like Lores, Hires, SuperHires, etc).  This
database makes it possible for the user to dynamically add new monitor
types to the system, typically by calling the addmonitor command using
a monitor spec file as an argument.  These monitor types will be added
to the database after the default monitor. The default monitor
properties are determined at boot time based on the configuration of
the custom chip set. The default monitor is always either an alias for
the NTSC or PAL monitor type.

When a monitor type is added to the database, the system figures out
which display modes are available to this monitor type, based on the
properties of the monitor's spec file and the configuration of the
custom chip set.  Later, the Display Database can be queried on the
availability of a particular display mode using the appropriate
graphics.library calls.

The following is an example of how to use graphics.library functions
to find out what display modes are available. See the 2.0 Autodocs for
a detailed description of the various functions.




```c
    ULONG modeID;
    ULONG skipID;

    ULONG error, result;
    struct DisplayInfoHandle displayhandle;
    struct DisplayInfo displayinfo;
    struct NameInfo nameinfo;

    /* graphics.library must be opened */

    /* Don't want duplicate entries in the list for the
     * 'default monitor', so we'll skip the the videomode
     * for which default.monitor is the alias.
     */

    /* INVALID_ID indicates both the start and the end of the list of
       available keys */
    modeID = INVALID_ID;

    GetDisplayInfoData(NULL, (UBYTE *) & displayinfo,
            sizeof(struct DisplayInfo), DTAG_DISP, LORES_KEY);
    if (displayinfo.PropertyFlags & DIPF_IS_PAL)
        skipID = PAL_MONITOR_ID;
    else
        skipID = NTSC_MONITOR_ID;


    /* Given a ModeID, NextDisplayInfo
                        returns the next ModeID in the list */
    while((modeID = NextDisplayInfo(modeID)) != INVALID_ID) {

        /* Skip it? */
        if (modeID & MONITOR_ID_MASK != skipID) {

            /* ModeNotAvailable returns NULL if a displaymode,
               specified by the modeID, is available, or an error
               indicating why it is not available.
            */
            if ((error = ModeNotAvailable(modeID)) == NULL) {

                /* This displaymode is available, get the naming
                   information. GetDisplayInfoData, can either be
                   called with a handle to a displaymode record, or
                   the display modeID. Never use the handle directly.
                */

                /* returns NULL if not found */
                if (displayhandle = FindDisplayInfo(modeID)) {
                    result = GetDisplayInfoData(displayhandle,
                            (UBYTE *)&nameinfo, sizeof(struct NameInfo),
                            DTAG_NAME, NULL);
                    if (result)     /* 'result' indicates the number
                                        of bytes placed in the buffer */
                        printf("%s is available.\n", nameinfo.Name);
                }
            }
        }
    }
```
Using the GetDisplayInfoData() function, this example asks only for
the descriptive name of the display mode via the NameInfo structure.
Using this same function with a different tag, other information on a
particular display mode can be obtained.  GetDisplayInfoData() can
supply information about the properties of the display mode
(DisplayInfo), the display mode's dimensions (DimensionInfo) or the
display mode's monitor specifications (MonitorInfo).  Refer to
graphics/displayinfo.h for a description of the various structures.

---

## See Also

- [GetDisplayInfoData — graphics.library](../autodocs/graphics.library.md#getdisplayinfodata)
