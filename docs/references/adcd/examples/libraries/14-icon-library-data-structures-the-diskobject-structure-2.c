/* Source: ADCD 2.1
 * Section: 14-icon-library-data-structures-the-diskobject-structure
 * Library: libraries
 * ADCD reference: libraries/14-icon-library-data-structures-the-diskobject-structure.md
 */

    If the icon is associated with a directory (WBDISK, WBDRAWER,
    WBGARBAGE), it needs a [DrawerData](../Includes_and_Autodocs_2._guide/node0135.html#line51) structure to go with it.  This
    structure contains an Intuition [NewWindow](../Libraries_Manual_guide/node0102.html#line8) structure (see the
    "[Intuition Windows](../Libraries_Manual_guide/node0102.html)" chapter for more information):

        struct DrawerData
            {
            struct NewWindow dd_NewWindow; /* structure to open window */
            LONG             dd_CurrentX;  /* current x coordinate of  */
                                           /* origin                   */
            LONG             dd_CurrentY;  /* current y coordinate of  */
                                           /* origin                   */
            };

    Workbench uses this to hold the current window position and size of
    the window so it will reopen in the same place.
