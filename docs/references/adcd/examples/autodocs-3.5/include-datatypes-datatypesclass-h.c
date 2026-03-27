/* Source: ADCD 2.1
 * Section: include-datatypes-datatypesclass-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-datatypes-datatypesclass-h.md
 */

    struct SignalSemaphore	 si_Lock;	/* Locked while in DoAsyncLayout() */
    ULONG			 si_Flags;

    LONG			 si_TopVert;	/* Top row (in units) */
    LONG			 si_VisVert;	/* Number of visible rows (in units) */
    LONG			 si_TotVert;	/* Total number of rows (in units) */
    LONG			 si_OTopVert;	/* Previous top (in units) */
    LONG			 si_VertUnit;	/* Number of pixels in vertical unit */

    LONG			 si_TopHoriz;	/* Top column (in units) */
    LONG			 si_VisHoriz;	/* Number of visible columns (in units) */
    LONG			 si_TotHoriz;	/* Total number of columns (in units) */
    LONG			 si_OTopHoriz;	/* Previous top (in units) */
    LONG			 si_HorizUnit;	/* Number of pixels in horizontal unit */
