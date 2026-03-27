/* Source: ADCD 2.1
 * Section: include-graphics-monitor-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-graphics-monitor-h.md
 */

    struct	ExtendedNode	ms_Node;
    UWORD	ms_Flags;
    LONG	ratioh;
    LONG	ratiov;
    UWORD	total_rows;
    UWORD	total_colorclocks;
    UWORD	DeniseMaxDisplayColumn;
    UWORD	BeamCon0;
    UWORD	min_row;
    struct	SpecialMonitor	*ms_Special;
    UWORD	ms_OpenCount;
    LONG	(*ms_transform)();
    LONG	(*ms_translate)();
    LONG	(*ms_scale)();
    UWORD	ms_xoffset;
    UWORD	ms_yoffset;
    struct	Rectangle	ms_LegalView;
    LONG	(*ms_maxoscan)();	/* maximum legal overscan */
    LONG	(*ms_videoscan)();	/* video display overscan */
    UWORD	DeniseMinDisplayColumn;
    ULONG	DisplayCompatible;
    struct	List DisplayInfoDataBase;
    struct	SignalSemaphore DisplayInfoDataBaseSemaphore;
    LONG	(*ms_MrgCop)();
    LONG	(*ms_LoadView)();
    LONG	(*ms_KillView)();
