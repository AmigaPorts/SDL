/* Source: ADCD 2.1
 * Section: dos-library-internalloadseg
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-internalloadseg.md
 */

    Loads from fh.  Table is used when loading an overlay, otherwise
    should be NULL.  Functionarray is a pointer to an array of functions.
    Note that the current Seek position after loading may be at any point
    after the last hunk loaded.  The filehandle will not be closed.  If a
    stacksize is encoded in the file, the size will be stuffed in the
    LONG pointed to by stack.  This LONG should be initialized to your
    default value: InternalLoadSeg() will not change it if no stacksize
    is found. Clears unused portions of Code and Data hunks (as well as
    BSS hunks).  (This also applies to [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html) and [NewLoadSeg()](../Includes_and_Autodocs_2._guide/node02D4.html)).

    If the file being loaded is an overlaid file, this will return
    -(seglist).  All other results will be positive.

    NOTE to overlay users: InternalLoadSeg() does NOT return seglist in
    both D0 and D1, as [LoadSeg](../Includes_and_Autodocs_2._guide/node02C5.html) does.  The current ovs.asm uses [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html),
    and assumes returns are in D1.  We will support this for [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html)
    ONLY.
