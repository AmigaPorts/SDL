/* Source: ADCD 2.1
 * Section: 27-monitors-modes-and-the-display-database-mode-properties
 * Library: libraries
 * ADCD reference: libraries/27-monitors-modes-and-the-display-database-mode-properties.md
 */

    struct DisplayInfo queryinfo;

    /* fill in the displayinfo buffer with basic Mode display data */

    if(GetDisplayInfoData(handle, (UBYTE *)&queryinfo,sizeof(queryinfo),
       DTAG_DISP,NULL)))
    {
        /* check for Properties of this Mode */

        if(queryinfo.PropertyFlags)
        {
            if(queryinfo.PropertyFlags & DIPF_IS_LACE)
                printf("mode is interlaced");
            if(queryinfo.PropertyFlags & DIPF_IS_DUALPF)
                printf("mode has dual playfields");
            if(queryinfo.PropertyFlags & DIPF_IS_PF2PRI)
                printf("mode has playfield two priority");
            if(queryinfo.PropertyFlags & DIPF_IS_HAM)
                printf("mode uses hold-and-modify");
            if(queryinfo.PropertyFlags & DIPF_IS_ECS)
                printf("mode requires the ECS chip set");
            if(queryinfo.PropertyFlags & DIPF_IS_PAL)
                printf("mode is naturally displayed on pal.monitor");
            if(queryinfo.PropertyFlags & DIPF_IS_SPRITES)
                printf("mode has sprites");
            if(queryinfo.PropertyFlags & DIPF_IS_GENLOCK)
                printf("mode is compatible with genlock displays");
            if(queryinfo.PropertyFlags & DIPF_IS_WB)
                printf("mode will support workbench displays");
            if(queryinfo.PropertyFlags & DIPF_IS_DRAGGABLE)
                printf("mode may be dragged to new positions");
            if(queryinfo.PropertyFlags & DIPF_IS_PANELLED)
                printf("mode is broken up for scan conversion");
            if(queryinfo.PropertyFlags & DIPF_IS_BEAMSYNC)
                printf("mode supports beam synchronization");
        }
    }
