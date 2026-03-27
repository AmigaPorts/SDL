/* Source: ADCD 2.1
 * Section: dos-library-matchfirst
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-matchfirst.md
 */

    Locates the first file or directory that matches a given pattern.
    MatchFirst() is passed your pattern (you do not pass it through
    [ParsePattern()](../Includes_and_Autodocs_2._guide/node02DB.html) - MatchFirst() does that for you), and the control
    structure.  MatchFirst() normally initializes your [AnchorPath](../Includes_and_Autodocs_2._guide/node0070.html#line53)
    structure for you, and returns the first file that matched your
    pattern, or an error.  Note that [MatchFirst()/MatchNext()](../Includes_and_Autodocs_2._guide/node02CE.html) are unusual
    for Dos in that they return 0 for success, or the error code (see
    [<dos/dos.h>](../Includes_and_Autodocs_2._guide/node0068.html)), instead of the application getting the error code
    from [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).

    When looking at the result of [MatchFirst()/MatchNext()](../Includes_and_Autodocs_2._guide/node02CE.html), the ap_Info
    field of your [AnchorPath](../Includes_and_Autodocs_2._guide/node0070.html#line53) has the results of an [Examine()](../Includes_and_Autodocs_2._guide/node029C.html) of the object.
    You normally get the name of the object from fib_FileName, and the
    directory it's in from ap_Current->an_Lock.  To access this object,
    normally you would temporarily [CurrentDir()](../Includes_and_Autodocs_2._guide/node028F.html) to the lock, do an action
    to the file/dir, and then [CurrentDir()](../Includes_and_Autodocs_2._guide/node028F.html) back to your original directory.
    This makes certain you affect the right object even when two volumes
    of the same name are in the system.  You can use ap_Buf (with
    ap_Strlen) to get a name to report to the user.

    To initialize the [AnchorPath](../Includes_and_Autodocs_2._guide/node0070.html#line53) structure (particularily when reusing
    it), set ap_BreakBits to the signal bits (CDEF) that you want to take
    a break on, or NULL, if you don't want to convenience the user.
    ap_Flags should be set to any flags you need or all 0's otherwise.
    ap_FoundBreak should be cleared if you'll be using breaks.

    If you want to have the FULL PATH NAME of the files you found,
    allocate a buffer at the END of this structure, and put the size of
    it into ap_Strlen.  If you don't want the full path name, make sure
    you set ap_Strlen to zero.  In this case, the name of the file, and
    stats are available in the ap_Info, as per usual.

    Then call MatchFirst() and then afterwards, [MatchNext()](../Includes_and_Autodocs_2._guide/node02CE.html) with this
    structure.  You should check the return value each time (see below)
    and take the appropriate action, ultimately calling [MatchEnd()](../Includes_and_Autodocs_2._guide/node02CC.html) when
    there are no more files or you are done.  You can tell when you are
    done by checking for the normal AmigaDOS return code
    ERROR_NO_MORE_ENTRIES.

    Note: patterns with trailing slashes may cause [MatchFirst()/MatchNext()](../Includes_and_Autodocs_2._guide/node02CE.html)
    to return with an ap_Current->an_Lock on the object, and a filename
    of the empty string ("").

    See [ParsePattern()](../Includes_and_Autodocs_2._guide/node02DB.html) for more information on the patterns.
