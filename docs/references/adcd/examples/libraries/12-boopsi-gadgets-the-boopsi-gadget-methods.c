/* Source: ADCD 2.1
 * Section: 12-boopsi-gadgets-the-boopsi-gadget-methods
 * Library: libraries
 * ADCD reference: libraries/12-boopsi-gadgets-the-boopsi-gadget-methods.md
 */

    struct Screen          *gi_Screen;
    struct Window          *gi_Window;     /* null for screen gadgets */
    struct Requester       *gi_Requester;  /* null if not GTYP_REQGADGET */

    /* rendering information: don't use these without cloning/locking.
     * Official way is to call ObtainGIRPort()
     */
    struct RastPort        *gi_RastPort;
    struct Layer           *gi_Layer;

    /* copy of dimensions of screen/window/g00/req(/group)
     * that gadget resides in.  Left/Top of this box is
     * offset from window mouse coordinates to gadget coordinates
     *  screen gadgets:                 0,0 (from screen coords)
     *  window gadgets (no g00):        0,0
     *  GTYP_GZZGADGETs (borderlayer):  0,0
     *  GZZ innerlayer gadget:          borderleft, bordertop
     *  Requester gadgets:              reqleft, reqtop
     */
    struct IBox            gi_Domain;

    /* these are the pens for the window or screen */
    struct {
        UBYTE   DetailPen;
        UBYTE   BlockPen;
    }                      gi_Pens;

    /* the Detail and Block pens in gi_DrInfo->dri_Pens[] are
     * for the screen.  Use the above for window-sensitive colors.
     */
    struct DrawInfo        *gi_DrInfo;

    /* reserved space: this structure is extensible
     * anyway, but using these saves some recompilation
     */
    ULONG                  gi_Reserved[6];
