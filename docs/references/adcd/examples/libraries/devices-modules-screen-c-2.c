/* Source: ADCD 2.1
 * Section: devices-modules-screen-c
 * Library: libraries
 * ADCD reference: libraries/devices-modules-screen-c.md
 */

    /* For now, simply masks out everything but old mode bits.
     * This is just a cheap way to get some kind of display open
     *   and may be totally invalid for future modes.
     * Should search the display database for a suitable mode
     * based on the specific needs of your application.
     */
    newmode = mode & MODE_ID_MASK;

    D(bug("Try 0x%08lx instead of 0x%08lx\n",newmode,mode));
    return(newmode);
