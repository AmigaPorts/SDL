/* Source: ADCD 2.1
 * Section: intuition-library-buildsysrequest
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-buildsysrequest.md
 */

    ReqWindow = BuildSysRequest( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), BodyText, PosText, NegText,
    D0                           A0      A1        A2       A3
                       IDCMPFlags, Width, Height )
                       D0          D1     D2

    struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *BuildSysRequest( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, struct [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) *,
            struct [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) *, struct [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) *, ULONG, WORD, WORD );
