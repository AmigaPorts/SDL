/* Source: ADCD 2.1
 * Section: include-graphics-monitor-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-graphics-monitor-h.md
 */

    struct	ExtendedNode	spm_Node;
    UWORD	spm_Flags;
    LONG	(*do_monitor)();
    LONG	(*reserved1)();
    LONG	(*reserved2)();
    LONG	(*reserved3)();
    struct	AnalogSignalInterval	hblank;
    struct	AnalogSignalInterval	vblank;
    struct	AnalogSignalInterval	hsync;
    struct	AnalogSignalInterval	vsync;
