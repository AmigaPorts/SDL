/* Source: ADCD 2.1
 * Section: 30-regions-installing-regions
 * Library: libraries
 * ADCD reference: libraries/30-regions-installing-regions.md
 */

    /*
    ** Sample installation and removal of a clipping region
    */
    register struct Region     *new_region ;
    register struct Region     *old_region ;

    /* If the application owns the layer and has not installed a region,
    ** old_region will return NULL here.
    */
    old_region = InstallClipRegion(win->WLayer, new_region);

    /* draw into the layer or window */

    if (NULL != (old_region = InstallClipRegion(win->WLayer, old_region)))
        {
        /* throw the used region away.  This region could be saved and
        ** used again later, if desired by the application.
        */
        DisposeRegion(new_region) ;
        }


    A Warning About InstallClipRegion().
    ------------------------------------
    The program must not call [InstallClipRegion()](../Includes_and_Autodocs_2._guide/node0399.html) inside of a
    [Begin](../Libraries_Manual_guide/node011E.html)/[EndRefresh()](../Libraries_Manual_guide/node011E.html#line25) or [Begin/EndUpdate()](../Libraries_Manual_guide/node03EF.html#line32) pair.  The following code
    segment shows how to modify the user clipping region when using these
    calls.  See the Autodoc for [BeginRefresh()](../Includes_and_Autodocs_2._guide/node0200.html) for more details.


    register struct Region     *new_region ;
    register struct Region     *old_region ;

    /* you have to have already setup the new_region and old_region */

    BeginRefresh(window);
    /* draw through the damage list */
    /* into the layer or window */
    EndRefresh(window, FALSE);              /* keep the damage list */

    old_region = InstallClipRegion(win->WLayer, new_region);

    BeginRefresh(window);
    /* draw through the damage list and the new_region */
    /* into the layer or window */
    EndRefresh(window, FALSE);              /* keep the damage list */

    /* put back the old region */
    new_region = InstallClipRegion(win->WLayer, old_region);

    BeginRefresh(window);
    EndRefresh(window, TRUE);               /* remove the damage list */

    old_region = InstallClipRegion(win->WLayer, new_region);

    BeginRefresh(window);
    /* draw through the new_region only into the layer or window */
    EndRefresh(window, FALSE);

    /* finally get rid of the new region, old_region still installed */
    if (NULL != (new_region = InstallClipRegion(win->WLayer, old_region)))
        DisposeRegion(new_region) ;
