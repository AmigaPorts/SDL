/* Source: ADCD 2.1
 * Section: amigaguide-library-openamigaguidea
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/amigaguide-library-openamigaguidea.md
 */

                  nag_Extens
                  Used by V37 and beyond to pass additional arguments.

                  nag_Client
                  This is a private pointer, MUST be initialized to NULL.

        attrs - Additional attributes.

    TAGS
        AGA_HelpGroup (ULONG) -- Unique identifier used to identify the
            AmigaGuide help windows.  See [OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html) and [GetUniqueID()](../Includes_and_Autodocs_3._guide/node05A4.html).

            Default for this tag is NULL.  Applicability is (I). (V39)

    EXAMPLE

        /* Short example showing synchronous AmigaGuide access */
        [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) ShowAmigaGuideFile (STRPTR name, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) node, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) line)
        {
            struct [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102) nag = {NULL};
            [AMIGAGUIDECONTEXT](../Includes_and_Autodocs_3._guide/node05D2.html#line86) handle;
            [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) retval = 0L;

            /* Fill in the [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102) structure */
            nag.nag_Name = name;
            nag.nag_Node = node;
            nag.nag_Line = line;

            /* [Open](../Includes_and_Autodocs_3._guide/node0196.html) the AmigaGuide client */
            if ( handle = OpenAmigaGuide(&nag, NULL))
            {
                /* [Close](../Includes_and_Autodocs_3._guide/node0149.html) the AmigaGuide client */
                CloseAmigaGuide(handle);
            }
            else
            {
                /* Get the reason for failure */
                retval = IoErr();
            }

            return (retval);
        }

    RETURNS
        handle - Handle to a AmigaGuide system.

    SEE ALSO
        [OpenAmigaGuideAsyncA()](../Includes_and_Autodocs_3._guide/node000F.html), [CloseAmigaGuide()](../Includes_and_Autodocs_3._guide/node0009.html)
