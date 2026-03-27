/* Source: ADCD 2.1
 * Section: amigaguide-library-removeamigaguidehostagaguide-library
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/amigaguide-library-removeamigaguidehostagaguide-library.md
 */

    NAME
        RemoveAmigaGuideHostA - [Remove](../Includes_and_Autodocs_3._guide/node022F.html) a dynamic node host.     (V34)

    SYNOPSIS
        use = RemoveAmigaGuideHostA (key, attrs)
        d0                            a0   a1

        [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) RemoveAmigaGuideHostA (AMIGAGUIDEHOST, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

        use = RemoveAmigaGuideHost (key, tag1, ...);

        [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) RemoveAmigaGuideHost (AMIGAGUIDEHOST, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);

    FUNCTION
        This function removes a dynamic node host, that was added by
        AddAmigaGuideHost(), from the system.

    INPUTS
        key - Key that was returned by AddAmigaGuideHost().

        attrs - Additional attributes.  None are defined at this time.

    RETURNS
        use - Number of outstanding clients of this database.  You
            can not exit until use==0.

    SEE ALSO
        [AddAmigaGuideHostA()](../Includes_and_Autodocs_3._guide/node0007.html)
