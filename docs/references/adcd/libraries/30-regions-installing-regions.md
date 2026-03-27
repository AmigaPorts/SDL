---
title: 30 / Regions / Installing Regions
manual: libraries
chapter: libraries
section: 30-regions-installing-regions
functions: [BeginRefresh, EndRefresh, EndUpdate, InstallClipRegion]
libraries: [intuition.library, layers.library]
---

# 30 / Regions / Installing Regions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Use the function [InstallClipRegion()](autodocs-2.0/layers-library-installclipregion.md) to install the region.


```c
    struct Region *InstallClipRegion( struct Layer *layer,
                                      struct Region *region );
```
This installs a transparent clipping region to a layer.  All subsequent
graphics calls will be clipped to this region.  The region must be removed
with a second call to [InstallClipRegion()](autodocs-2.0/layers-library-installclipregion.md) before removing the layer.


```c
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
    The program must not call [InstallClipRegion()](autodocs-2.0/layers-library-installclipregion.md) inside of a
    [Begin](libraries/4-preserving-the-window-display-optimized-window-refreshing.md)/[EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) or [Begin/EndUpdate()](libraries/30-layers-creating-and-using-new-layers.md) pair.  The following code
    segment shows how to modify the user clipping region when using these
    calls.  See the Autodoc for [BeginRefresh()](autodocs-2.0/intuition-library-beginrefresh.md) for more details.


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
```

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [EndUpdate — layers.library](../autodocs/layers.library.md#endupdate)
- [InstallClipRegion — layers.library](../autodocs/layers.library.md#installclipregion)
