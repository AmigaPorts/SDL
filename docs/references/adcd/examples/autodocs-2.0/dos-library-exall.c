/* Source: ADCD 2.1
 * Section: dos-library-exall
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-exall.md
 */

        ExAll for the first time.  Any other value will cause nasty
        things to happen.  If ExAll returns non-zero, then this field
        should not be touched before making the second and subsequent
        calls to ExAll.  Whenever ExAll returns non-zero, there are more
        calls required before all names have been received.

        As soon as a FALSE return is received then ExAll has completed
        (if [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) returns ERROR_NO_MORE_ENTRIES - otherwise it returns
        the error that occured, similar to ExNext.)
