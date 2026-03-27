/* Source: ADCD 2.1
 * Section: 27-performing-data-move-operations-accessing-blitter
 * Library: libraries
 * ADCD reference: libraries/27-performing-data-move-operations-accessing-blitter.md
 */

    This is the address of your blitter function that the blitter queuer
    will call when your turn comes up.  Your function must be formed as a
    subroutine, with an RTS instruction at the end. Follow Amiga
    programming conventions by placing the return value in D0 (or in C,
    use return(value)).

    If you return a nonzero value, the system will call your routine
    again next time the blitter is idle until you finally return 0.  This
    is done so that you can maintain control over the blitter; for
    example, it allows you to handle all five bitplanes if you are
    blitting an object with 32 colors.  For display purposes, if you are
    blitting multiple objects and then saving and restoring the
    background, you must be sure that all planes of the object are
    positioned before another object is overlaid.  This is the reason for
    the lockup in the blitter queue; it allows all work per object to be
    completed before going on to the next one.

    Note:
    -----
    Not all C compilers can handle *function() properly!  The system
    actually tests the processor status codes for a condition of
    equal-to-zero (Z flag set) or not-equal-to-zero (Z flag clear) when
    your blitter routine returns.  Some C compilers do not set the
    processor status code properly (i.e., according to the value
    returned), thus it is not possible to use such compilers to write the
    (*function)()) routine.  In that case assembly language should be
    used.  Blitter functions are normally written in assembly language
    anyway so they can take advantage of the ability of [QBlit()](../Includes_and_Autodocs_2._guide/node0468.html) and
    [QBSBlit()](../Includes_and_Autodocs_2._guide/node0469.html) to pass them parameters in processor registers.

    The register passing conventions for these routines are as follows.
    Register A0 receives a pointer to the system hardware registers so
    that all hardware registers can be referenced as an offset from that
    address.  Register A1 contains a pointer to the current bltnode.  You
    may have queued up multiple blits, each of which perhaps uses the
    same blitter routine.  You can access the data for this particular
    operation as an offset from the value in A1.  For instance, a typical
    user of these routines can precalculate the blitter register values
    to be placed in the blitter registers and, when the routine is
    called, simply copy them in.  For example, you can create a new
    structure such as the following:

        INCLUDE "exec/types.i"
        INCLUDE "hardware/blit.i"

        STRUCTURE mybltnode,0
                          ; Make this new structure compatible with a
                          ; bltnode by making the first element a bltnode
                          ;  structure.
        STRUCT bltnode,bn_SIZEOF
                UWORD   bltcon1         ; Blitter control register 1.
                UWORD   fwmask          ; First and last word masks.
                UWORD   lwmask
                UWORD   bltmda          ; Modulos for sources a, b,and c.
                UWORD   bltmdb
                UWORD   bltmdc
                UWORD   any_more_data   ; add anything else you want
        LABEL mbn_SIZEOF

    Other forms of data structures are certainly possible, but this
    should give you the general idea.
