/* Source: ADCD 2.1
 * Section: dos-library-newloadseg
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-newloadseg.md
 */

    Does a [LoadSeg](../Includes_and_Autodocs_2._guide/node02C5.html) on a file, and takes additional actions based on the
    tags supplied.

    Clears unused portions of Code and Data hunks (as well as BSS hunks).
    (This also applies to [InternalLoadSeg()](../Includes_and_Autodocs_2._guide/node02C0.html) and [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html)).

    NOTE to overlay users: NewLoadSeg() does NOT return seglist in
    both D0 and D1, as [LoadSeg](../Includes_and_Autodocs_2._guide/node02C5.html) does.  The current ovs.asm uses [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html),
    and assumes returns are in D1.  We will support this for [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html)
    ONLY.
