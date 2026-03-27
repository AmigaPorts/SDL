/* Source: ADCD 2.1
 * Section: 5-string-gadget-type-program-control-of-string-gadgets
 * Library: libraries
 * ADCD reference: libraries/5-string-gadget-type-program-control-of-string-gadgets.md
 */

       BOOL activated;

       /* Open window with NULL IDCMPFlags */
       win = OpenWindow( ... );

       /* Set the UserPort to your shared port, and turn on message
        * passing, which includes the IDCMP_ACTIVEWINDOW message.
        */
       win->UserPort = sharedport;
       ModifyIDCMP( win, ... | IDCMP_ACTIVEWINDOW | ... );

       /* If the window became active before the ModifyIDCMP() got
        * executed, then this ActivateGadget() can succeed.  If not, then
        * this ActivateGadget() might be too early, but in that case, we
        * know we'll receive the IDCMP_ACTIVEWINDOW event.  We handle that
        * below.
        */
        activated = ActivateGadget( stringgad, win, NULL );
