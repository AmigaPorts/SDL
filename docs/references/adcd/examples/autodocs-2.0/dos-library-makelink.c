/* Source: ADCD 2.1
 * Section: dos-library-makelink
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-makelink.md
 */

    Create a filesystem link from 'name' to dest.  For "soft-links",
    dest is a pointer to a null-terminated path string.  For "hard-
    links", dest is a lock (BPTR).  'soft' is FALSE for hard-links,
    non-zero otherwise.

    Soft-links are resolved at access time by a combination of the
    filesystem (by returning ERROR_IS_SOFT_LINK to dos), and by
    Dos (using [ReadLink()](../Includes_and_Autodocs_2._guide/node02E3.html) to resolve any links that are hit).

    Hard-links are resolved by the filesystem in question.  A series
    of hard-links to a file are all equivalent to the file itself.
    If one of the links (or the original entry for the file) is
    deleted, the data remains until there are no links left.
