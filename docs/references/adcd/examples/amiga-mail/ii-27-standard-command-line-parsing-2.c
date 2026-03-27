/* Source: ADCD 2.1
 * Section: ii-27-standard-command-line-parsing
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-27-standard-command-line-parsing.md
 */

    struct RDArgs {
        struct    CSource RDA_Source; /* Select input source */
        LONG      RDA_DAList;         /* PRIVATE. */
        UBYTE     *RDA_Buffer;        /* Optional string parsing space. */
        LONG      RDA_BufSiz;         /* Size of RDA_Buffer (0..n) */
        UBYTE     *RDA_ExtHelp;       /* Optional extended help */
        LONG      RDA_Flags;          /* Flags for any required control */
    };
