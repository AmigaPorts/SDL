/* Source: ADCD 2.1
 * Section: iv-3-screendisplaymodes-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-screendisplaymodes-c.md
 */

                    if (displayinfo.PropertyFlags & DIPF_IS_PAL)
                        skipID = PAL_MONITOR_ID;
                    else
                        skipID = NTSC_MONITOR_ID;
                    while ((modeID = NextDisplayInfo(modeID)) != INVALID_ID) {
                        if ((modeID & MONITOR_ID_MASK) != skipID) {
