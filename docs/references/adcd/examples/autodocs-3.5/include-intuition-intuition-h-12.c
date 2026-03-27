/* Source: ADCD 2.1
 * Section: include-intuition-intuition-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-intuition-intuition-h.md
 */

    /* Pointer to the active screen:
     * Note: if there are no open screens, thd_Screen will be NULL.
     * thd_Width and thd_Height will then describe an NTSC 640x400
     * screen.	Please scale accordingly.
     */
    struct Screen *thd_Screen;

    /* The width and height (measured in pixels of the active screen)
     * that your are to scale to:
     */
    ULONG thd_Width;
    ULONG thd_Height;

    /* Non-zero if the screen or something about the screen
     * changed since the last time you were invoked:
     */
    LONG thd_ScreenChanged;
