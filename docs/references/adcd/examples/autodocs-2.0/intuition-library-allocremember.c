/* Source: ADCD 2.1
 * Section: intuition-library-allocremember
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-allocremember.md
 */

    struct [Remember](../Includes_and_Autodocs_2._guide/node00D4.html#line1233) *RememberKey;
    RememberKey = NULL;
    buffer = AllocRemember(&RememberKey, BUFSIZE, MEMF_CHIP);
    if (buffer)
    {
        /* Use the buffer */
        ...
    }
    FreeRemember(&RememberKey, TRUE);
