/* Source: ADCD 2.1
 * Section: dos-library-readlink
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-readlink.md
 */

    ReadLink() takes a lock/name pair (usually from a failed attempt
    to use them to access an object with packets), and asks the
    filesystem to find the softlink and fill buffer with the modified
    path string.  You then start the resolution process again by
    calling [GetDeviceProc()](../Includes_and_Autodocs_2._guide/node02B7.html) with the new string from ReadLink().

    Soft-links are resolved at access time by a combination of the
    filesystem (by returning ERROR_IS_SOFT_LINK to dos), and by
    Dos (using ReadLink() to resolve any links that are hit).
