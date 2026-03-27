/* Source: ADCD 2.1
 * Section: intuition-library-beginrefresh
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-beginrefresh.md
 */

    Code fragment for "two pass" window refreshing, in response
    to an IDCMP_REFRESHWINDOW message:
    switch ( imsg->Class )
    {
    ...
    case IDCMP_REFRESHWINDOW:
        window = imsg->IDCMPWindow;

        /* this lock only needed for "two-pass" refreshing */
        LockLayerInfo( &window->WScreen->LayerInfo );

        /* refresh pass for region 1 */
        origclip = InstallClipRegion( window->WLayer, region1 );
        BeginRefresh( window );
        myRefreshRegion1( window );
        EndRefresh( window, FALSE );

        /* refresh pass for region 2 */
        InstallClipRegion( window->WLayer, region2 );
        BeginRefresh( window );
        myRefreshRegion2( window );
        EndRefresh( window, TRUE );         /* and dispose damage list */

        /* restore and unlock */
        InstallClipRegion( window->WLayer, origclip );
        UnlockLayerInfo( &window->WScreen->LayerInfo );
        break;
    ...
    }
