---
title: 27 / ECS and Genlocking Features / Genlock Control
manual: libraries
chapter: libraries
section: 27-ecs-and-genlocking-features-genlock-control
functions: [GetVPModeID, LoadView, MakeScreen, MakeVPort, MrgCop, RethinkDisplay, VideoControl, ViewAddress]
libraries: [graphics.library, intuition.library]
---

# 27 / ECS and Genlocking Features / Genlock Control

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Using [VideoControl()](autodocs-2.0/graphics-library-videocontrol.md), a program can enable, disable, or obtain the state
of a [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)'s genlocking features.  It returns NULL if no error
occurred.  The function uses a tag based interface:


```c
    error = BOOL VideoControl( struct ColorMap *cm, struct TagItem *ti );
```
The ti argument is a list of video commands stored in an array of [TagItem](libraries/37-tags-tag-functions-and-structures.md)
structures.  The cm argument specifies which [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) and, indirectly,
which [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) these genlock commands will be applied to.  The possible
commands are:


    VTAG_BITPLANEKEY_GET, _SET, _CLR
    VTAG_CHROMA_PLANE_GET, _SET
    VTAG_BORDERBLANK_GET, _SET, _CLR
    VTAG_BORDERNOTRANS_GET, _SET, _CLR
    VTAG_CHROMAKEY_GET, _SET, _CLR
    VTAG_CHROMAPEN_GET, _SET, _CLR
This section covers only the genlock [VideoControl()](autodocs-2.0/graphics-library-videocontrol.md) tags.  See
<graphics/[videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md)> for a complete list of all the available tags
you can use with VideoControl().

VTAG_BITPLANEKEY_GET is used to find out the status of the bitplane keying
mode.  VTAG_BITPLANEKEY_SET and VTAG_BITPLANEKEY_CLR activate and
deactivate bitplane keying mode.  If bitplane key mode is on, genlocking
will key on the bits set in a specific bitplane from the [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) (the
specific bitplane is set with a different tag).  The data portion of these
tags is NULL.

For inquiry commands like VTAG_BITPLANEKEY_GET (tags ending in _GET),
[VideoControl()](autodocs-2.0/graphics-library-videocontrol.md) changes the _GET tag ID ([ti_Tag](libraries/37-tags-tag-functions-and-structures.md)) to the corresponding _SET
or _CLR tag ID, reflecting the current state of the genlock mode.  For
example, when passed the following tag array:


```c
    struct TagItem videocommands[] =
    {
        {VTAG_BITPLANEKEY_GET, NULL},
        {VTAG_END_CM, NULL}
    };
```
[VideoControl()](autodocs-2.0/graphics-library-videocontrol.md) changes the VTAG_BITPLANEKEY_GET tag ID ([ti_Tag](libraries/37-tags-tag-functions-and-structures.md)) to
VTAG_BITPLANEKEY_SET if bitplane keying is currently on, or to
VTAG_BITPLANEKEY_CLR if bitplane keying is off.  In both of these cases,
VideoControl() only uses the tag's ID, ignoring the tag's data field
([ti_Data](libraries/37-tags-tag-functions-and-structures.md)).

The VTAG_CHROMA_PLANE_GET tag returns the number of the bitplane keyed on
when bitplane keying mode is on.  [VideoControl()](autodocs-2.0/graphics-library-videocontrol.md) changes the tag's data
value to the bitplane number.  VTAG_CHROMA_PLANE_SET sets the bitplane
number to the tag's data value.

VTAG_BORDERBLANK_GET is used to obtain the border blank mode status. This
tag works exactly like VTAG_BITPLANEKEY_GET.  [VideoControl()](autodocs-2.0/graphics-library-videocontrol.md) changes the
tag's ID to reflect the current border blanking state.
VTAG_BORDERBLANK_SET and VTAG_BORDERBLANK_CLR activate and deactivate
border blanking.  If border blanking is on, the Amiga will not display
anything in its display border, allowing an external video signal to show
through the border area.  On the Amiga display, the border appears black.
The data portion of these tags is NULL.

The VTAG_BORDERNOTRANS_GET, _SET and _CLR tags are used, respectively, to
obtain the status of border-not-transparent mode, and to activate and to
deactivate this mode.  If set, the Amiga display's border will overlay
external video with the color in register 0.  Because border blanking mode
takes precedence over border-not-transparent mode, setting
border-not-transparent has no effect if border blanking is on.  The data
portion of these tags is NULL.

The VTAG_CHROMAKEY_GET, _SET and _CLR tags are used, respectively, to
obtain the status of chroma keying mode, and to activate and deactivate
chroma keying mode.  If set, the genlock will key on colors from specific
color registers (the specific color registers are set using a different
tag).  If chroma keying is not set, the genlock will key on color register
0.  The data portion of these tags is NULL.

VTAG_CHROMAPEN_GET obtains the chroma keying status of an individual color
register.  The tag's [ti_Data](libraries/37-tags-tag-functions-and-structures.md) field contains the register number.  Like the
other _GET tags, [VideoControl()](autodocs-2.0/graphics-library-videocontrol.md) changes the tag ID ([ti_Tag](libraries/37-tags-tag-functions-and-structures.md)) to one that
reflects the current state of the mode.  VTAG_CHROMAPEN_SET and
VTAG_CHROMAPEN_CLR activate and deactivate chroma keying for each
individual color register.  Chroma keying can be active for more than one
register.  By turning off border blanking and activating chroma keying
mode, but turning off chroma keying for each color register, a program can
overlay every part of an external video source, completely blocking it out.

After using [VideoControl()](autodocs-2.0/graphics-library-videocontrol.md) to set values in the [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md), the
corresponding [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) has to be rebuilt with [MakeVPort()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md), [MrgCop()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md) and
[LoadView()](libraries/27-display-routines-and-structures-loading-and-displaying.md), so the changes can take effect.  A program that uses a
screen's ViewPort rather than its own ViewPort should use the Intuition
functions [MakeScreen()](libraries/3-screen-functions-that-integrate-intuition-and-graphics.md) and [RethinkDisplay()](libraries/3-screen-functions-that-integrate-intuition-and-graphics.md) to make the display changes
take effect.

The following code fragment shows how to access the genlock modes.


struct Screen *genscreen;
struct ViewPort *vp;
struct TagItem vtags [24];


```c
    /* The complete example opened a window, rendered some colorbars,  */
    /* and added gadgets to allow the user to turn the various genlock */
    /* modes on and off.                                               */

    vp = &(genscreen->ViewPort);

    /* Ascertain the current state of the various modes. */

    /* Is borderblanking on? */
    vtags[0].ti_Tag = VTAG_BORDERBLANK_GET;
    vtags[0].ti_Data = NULL;

    /* Is bordertransparent set? */
    vtags[1].ti_Tag = VTAG_BORDERNOTRANS_GET;
    vtags[1].ti_Data = NULL;

    /* Key on bitplane? */
    vtags[2].ti_Tag = VTAG_BITPLANEKEY_GET;
    vtags[2].ti_Tag = NULL;

    /* Get plane which is used to key on */
    vtags[3].ti_Tag = VTAG_CHROMA_PLANE_GET;
    vtags[3].ti_Data = NULL;

    /* Chromakey overlay on? */
    vtags[4].ti_Tag = VTAG_CHROMAKEY_GET;
    vtags[4].ti_Data = NULL;

    for (i = 0; i < 16; i++)
    {
        /* Find out which colors overlay */
        vtags[i + 5].ti_Tag = VTAG_CHROMA_PEN_GET;
        vtags[i + 5].ti_Data = i;
    }

    /* Indicate end of tag array */
    vtags[21].ti_Tag = VTAG_END_CM;
    vtags[21].ti_Data = NULL;

    /* And send the commands. On return the Tags themselves will
    * indicate the genlock settings for this ViewPort's ColorMap.
    */
    error = VideoControl(vp->ColorMap, vtags);

    /* The complete program sets gadgets to reflect current states. */

    /* Will only send single commands from here on. */
    vtags[1].ti_Tag = VTAG_END_CM;

    /* At this point the complete program gets an input event and
       sets/clears the genlock modes as requested using the vtag list and
       VideoControl().
    */

    /* send video command */
    error = VideoControl(vp->ColorMap, vtags);

    /* Now use MakeScreen() and RethinkDisplay() to make the VideoControl()
    *  changes take effect.  If we were using our own ViewPort rather than
    *  borrowing one from a screen, we would instead do:
    *
    *   MakeVPort(ViewAddress(),vp);
    *   MrgCop(ViewAddress());
    *   LoadView(ViewAddres());
    */
    MakeScreen(genscreen);
    RethinkDisplay();
```
/* The complete program closes and frees everything it had opened or
   allocated.
*/


/* The complete example calls the CheckPAL function, which is included
   below in its entirety for illustrative purposes.
*/

BOOL CheckPAL(STRPTR screenname)
{
```c
    struct Screen *screen;
    ULONG modeID = LORES_KEY;
    struct DisplayInfo displayinfo;
    BOOL IsPAL;

    if (GfxBase->LibNode.lib_Version >= 36)
    {
        /*
        * We got at least V36, so lets use the new calls to find out what
        * kind of videomode the user (hopefully) prefers.
        */

        if (screen = LockPubScreen(screenname))
        {
            /*
            * Use graphics.library/GetVPModeID() to get the ModeID of the
            * specified screen.  Will use the default public screen
            * (Workbench most of the time) if NULL It is _very_ unlikely
            * that this would be invalid, heck it's impossible.
            */
            if ((modeID = GetVPModeID(&(screen->ViewPort))) != INVALID_ID)
            {
                /*
                * If the screen is in VGA mode, we can't tell whether the
                * system is PAL or NTSC. So to be foolproof we fall back
                * to the displayinfo of the default monitor by inquiring
                * about just the LORES_KEY displaymode if we don't know.
                * The default.monitor reflects the initial video setup of
                * the system, thus for either ntsc.monitor or pal.monitor.
                * We only use the displaymode of the is an alias specified
                * public screen if it's display mode is PAL or NTSC and
                * NOT the default.
                */
                if (!((modeID & MONITOR_ID_MASK) == NTSC_MONITOR_ID ||
                (modeID & MONITOR_ID_MASK) == PAL_MONITOR_ID))
                modeID = LORES_KEY;
            }
            UnlockPubScreen(NULL, screen);
        } /* if fails modeID = LORES_KEY. Can't lock screen, so fall back
          *  on default monitor.
          */

        if (GetDisplayInfoData(NULL, (UBYTE *) & displayinfo,
        sizeof(struct DisplayInfo), DTAG_DISP, modeID))
        {
            if (displayinfo.PropertyFlags & DIPF_IS_PAL)
                IsPAL = TRUE;
            else
                IsPAL = FALSE;
            /* Currently the default monitor is always either PAL or
            *  NTSC.
            */
        }
    }
    else
        /* < V36. The enhancements to the videosystem in V36 (and above)
        *  cannot be better expressed than with the simple way to determine
        *  PAL in V34.
        */
        IsPAL= (GfxBase->DisplayFlags & PAL) ? TRUE : FALSE;

    return(IsPAL);
```
}

---

## See Also

- [GetVPModeID — graphics.library](../autodocs/graphics.library.md#getvpmodeid)
- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeScreen — intuition.library](../autodocs/intuition.library.md#makescreen)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
- [ViewAddress — intuition.library](../autodocs/intuition.library.md#viewaddress)
