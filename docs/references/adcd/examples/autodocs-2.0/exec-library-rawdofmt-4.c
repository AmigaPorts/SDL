/* Source: ADCD 2.1
 * Section: exec-library-rawdofmt
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-rawdofmt.md
 */

    This Amiga ROM function formats word values in the data stream.  If
    your compiler defaults to longs, you must add an "l" to your
    % specifications.  This can get strange for characters, which might
    look like "%lc".

    The result of RawDoFmt() is *ONLY* valid in V36 and later releases
    of EXEC.  Pre-V36 versions of EXEC have "random" return values.
