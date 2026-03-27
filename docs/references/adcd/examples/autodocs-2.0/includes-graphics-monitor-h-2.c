/* Source: ADCD 2.1
 * Section: includes-graphics-monitor-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-graphics-monitor-h.md
 */

    struct	ExtendedNode	spm_Node;
    UWORD	spm_Flags;
    int	(*do_monitor)();
    int	(*reserved1)();
    int	(*reserved2)();
    int	(*reserved3)();
    struct	AnalogSignalInterval	hblank;
    struct	AnalogSignalInterval	vblank;
    struct	AnalogSignalInterval	hsync;
    struct	AnalogSignalInterval	vsync;
