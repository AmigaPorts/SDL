/* Source: ADCD 2.1
 * Section: lib-examples-animtools-h
 * Library: libraries
 * ADCD reference: libraries/lib-examples-animtools-h.md
 */

        struct AnimOb  *nas_HeadOb; /* common Head of Object.               */
        WORD   *nas_Images;         /* array of Comp image data             */
        SHORT  *nas_Xt;             /* arrays of initial offsets.           */
        SHORT  *nas_Yt;             /* arrays of initial offsets.           */
        SHORT  *nas_Times;          /* array of Initial Timer value.        */
        WORD (**nas_Routines)();    /* Array of fns called when comp drawn  */
        SHORT   nas_CFlags;         /* Flags for the Component.             */
        SHORT   nas_Count;          /* Num Comps in seq (= arrays size)     */
        SHORT   nas_SingleImage;    /* one (or count) images.               */
        } NEWANIMSEQ;
