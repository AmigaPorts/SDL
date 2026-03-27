/* Source: ADCD 2.1
 * Section: expansion-library-makedosnode
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/expansion-library-makedosnode.md
 */

    /* set up a 3.5" amiga format floppy drive for unit 1 */

    char execName[] = "trackdisk.device";
    char dosName[] = "df1";

    ULONG parmPkt[] = {
        (ULONG) dosName,
        (ULONG) execName,
        1,                  /* unit number */
        0,                  /* [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html) flags */

        /* here is the environment block */
        16,                 /* table upper bound */
        512>>2,             /* # longwords in a block */
        0,                  /* sector origin -- unused */
        2,                  /* number of surfaces */
        1,                  /* secs per logical block -- leave as 1 */
        11,                 /* blocks per track */
        2,                  /* reserved blocks -- 2 boot blocks */
        0,                  /* ?? -- unused */
        0,                  /* interleave */
        0,                  /* lower cylinder */
        79,                 /* upper cylinder */
        5,                  /* number of buffers */
        MEMF_CHIP,          /* type of memory for buffers */
        (~0 >> 1),          /* largest transfer size (largest signed #) */
        ~1,                 /* addmask */
        0,                  /* boot priority */
        0x444f5300,         /* dostype: 'DOS0' */
    };

    struct [Device](../Includes_and_Autodocs_2._guide/node0087.html#line25) [Node](../Includes_and_Autodocs_2._guide/node0091.html#line23) *node, *MakeDosNode();

    node = MakeDosNode( parmPkt );
