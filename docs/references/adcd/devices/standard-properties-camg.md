---
title: Standard Properties / CAMG
manual: devices
chapter: devices
section: standard-properties-camg
functions: [ModeNotAvailable]
libraries: [graphics.library]
---

# Standard Properties / CAMG

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A "CAMG" chunk is specifically for Commodore Amiga ILBM's.  All
Amiga-based reader and writer software should deal with CAMG.  The Amiga
supports many different video display modes including interlace, Extra
Halfbrite, hold and modify (HAM), plus a variety of new modes under the
2.0 operating system. A CAMG chunk contains a single long word (length=4)
which specifies the Amiga display mode of the picture.

Prior to 2.0, it was possible to express all available Amiga ViewModes in
16 bits of flags (Viewport->Modes or NewScreen->ViewModes).  Old-style
writers and readers place a 16-bit Amiga ViewModes value in the low word
of the CAMG, and zeros in the high word.  The following Viewmode flags
should always be removed from old-style 16-bit ViewModes values when
writing or reading them:

EXTENDED_MODE | SPRITES | VP_HIDE |

```c
          GENLOCK_AUDIO | GENLOCK_VIDEO (=0x7102, mask=0x8EFD)
```
New ILBM readers and writers, should treat the full CAMG longword as a
32-bit ModeID to support new and future display modes.

New [ILBM writers](devices/devices-modules-saveilbm-c.md), when running under the 2.0 Amiga operating system,
should directly store the full 32-bit return value of the graphics
function GetVPModeID(vp) in the CAMG longword.  When running under 1.3,
store a 16-bit Viewmodes value masked as described above. 

[ILBM readers](devices/devices-modules-ilbmr-c.md) should only mask bits out of a CAMG if the CAMG has a zero
upper word (see exception below).  New ILBM readers, when running under
2.0, should then treat the 32-bit CAMG value as a ModeID, and should use
the graphics ModeNotAvailable() function to determine if the mode is
available.  If the mode is not available, fall back to another suitable
display mode.  When running under 1.3, the low word of the CAMG may
generally be used to open a compatible display.

Note that one popular graphics package stores junk in the upper word of
the CAMG of brushes, and incorrect values (generally zero) in the low
word.  You can screen for such junk values by testing for non-zero in the
upper word of a ModeID in conjunction with the 0x00001000 bit NOT set in
the low word.

The following code fragment demonstrates ILBM reader filtering of
inappropriate bits in 16-bit CAMG values.

#include <graphics/view.h>
#include <graphics/displayinfo.h>

/* Knock bad bits out of old-style CAMG modes before checking availability.
 * (some ILBM CAMG's have these bits set in old 1.3 modes, and should not)
 * If not an extended monitor ID, or if marked as extended but missing
 * upper 16 bits, screen out inappropriate bits now.
 */
if((!(modeid & MONITOR_ID_MASK)) ||
```c
    ((modeid & EXTENDED_MODE)&&(!(modeid & 0xFFFF0000))))
```
   modeid &=

```c
      (~(EXTENDED_MODE|SPRITES|GENLOCK_AUDIO|GENLOCK_VIDEO|VP_HIDE));
```
/* Check for bogus CAMG like some brushes have, with junk in
 * upper word and extended bit NOT set not set in lower word.
 */
if((modeid & 0xFFFF0000)&&(!(modeid & EXTENDED_MODE)))

```c
    {
    /* Bad CAMG, so ignore CAMG and determine a mode based on
     * based on pagesize or aspect
     */
     modeid = NULL;
     if(wide >= 640) modeid |= HIRES;
     if(high >= 400) modeid |= LACE;
     }
```
/* Now, ModeNotAvailable() may be used to determine if mode is available.
 *
 * If the mode is not available, you may prompt the user for a mode
 * choice, or search the 2.0 display database for an appropriate
 * replacement mode, or you may be able to get a relatively compatible
 * old display mode by masking out all bits except
 * HIRES | LACE | HAM | EXTRA_HALFBRITE
 */

   if((modeid & 0xFFFF0000)&&(!(modeid & 0x00001000)))
	{
	/* Then probably invalid ModeID */
	}

---

## See Also

- [ModeNotAvailable — graphics.library](../autodocs/graphics.library.md#modenotavailable)
