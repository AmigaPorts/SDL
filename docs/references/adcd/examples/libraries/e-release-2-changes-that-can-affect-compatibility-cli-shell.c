/* Source: ADCD 2.1
 * Section: e-release-2-changes-that-can-affect-compatibility-cli-shell
 * Library: libraries
 * ADCD reference: libraries/e-release-2-changes-that-can-affect-compatibility-cli-shell.md
 */

    receive "<CSI>0 v" in their input stream indicating the user wants to
    paste text from the clipboard.  This shouldn't cause any problems for
    programs which parse correctly (however we know that it does; the
    most common problems are outputting the sequence, or confusing it
    with another sequence like that for FKEY 1 which is "<CSI>0~").
