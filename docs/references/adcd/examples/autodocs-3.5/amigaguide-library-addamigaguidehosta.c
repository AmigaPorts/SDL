/* Source: ADCD 2.1
 * Section: amigaguide-library-addamigaguidehosta
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/amigaguide-library-addamigaguidehosta.md
 */

    NAME
        AddAmigaGuideHostA - Add a dynamic node host.           (V34)

    SYNOPSIS
        handle = AddAmigaGuideHostA (hook, name, attrs);
        d0                            a0    d0    a1

        AMIGAGUIDEHOST AddAmigaGuideHostA (struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57),
                                          struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

    FUNCTION
        This function adds a callback hook to the dynamic node list.

        A dynamic node allows an application to incorporate context-
        sensitive or live project data within their help system.

    INPUTS
        hook - The callback hook.
        name - Name of the [AmigaGuideHost](../Includes_and_Autodocs_3._guide/node05D2.html#line144) database that you are adding.
            The name must be unique.
        attrs - Additional attributes.  None are defined at this time.

    RETURNS
        Returns NULL if unable to add the dynamic node host, otherwise
        returns a pointer to a handle that will eventually be passed
        to RemoveAmigaGuideHost() to remove the dynamic node host from
        the list.

    NOTES
        When AmigaGuide attempts to resolve a LINK command, it performs
        the following sequence of events.

           Splits the name into a path, a database and a node (only
             the node is required).
           Opens the database.
           Performs the following searches until the node is found:
             Search the local database.
             Search the local cross reference list.
             Search the local dynamic node host.
             Search the global help file (system help).
             Search the global cross reference list.
             Search the global dynamic node hosts.

    SEE ALSO
        [RemoveAmigaGuideHostA()](../Includes_and_Autodocs_3._guide/node0010.html)

    EXAMPLE

        /* [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) dispatcher */
        ULONG __asm hookEntry(
                register __a0 struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *h,
                register __a2 VOID *obj,
                register __a1 VOID *msg)
        {
            /* Pass the parameters on the stack */
            return ((h->h_SubEntry)(h, obj, msg));
        }

        ULONG __saveds
        dispatchAmigaGuideHost (struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *h, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) db, [Msg](../Includes_and_Autodocs_3._guide/node0636.html#line28) msg)
        {
            struct [opNodeIO](../Includes_and_Autodocs_3._guide/node05D2.html#line201) *onm = (struct [opNodeIO](../Includes_and_Autodocs_3._guide/node05D2.html#line201) *) msg;
            ULONG retval = 0;

            switch (msg->MethodID)
            {
                /* Does this node belong to you? */
                case HM_FINDNODE:
                    {
                        struct [opFindHost](../Includes_and_Autodocs_3._guide/node05D2.html#line189) *ofh = (struct [opFindHost](../Includes_and_Autodocs_3._guide/node05D2.html#line189) *) msg;

                        kprintf("Find [%s] in %sn", ofh->ofh_Node, db);

                        /* Return TRUE to indicate that it's your node,
                         * otherwise return FALSE. */
                         retval = TRUE;
                    }
                    break;

                /* [Open](../Includes_and_Autodocs_3._guide/node0196.html) a node. */
                case HM_OPENNODE:
                    kprintf("Open [%s] in %sn", onm->onm_Node, db);

                    /* Provide the contents of the node */
                    onm->onm_DocBuffer = TEMP_NODE;
                    onm->onm_BuffLen   = strlen(TEMP_NODE);

                    /* Indicate that we were able to open the node */
                    retval = TRUE;
                    break;

                /* [Close](../Includes_and_Autodocs_3._guide/node0149.html) a node, that has no users. */
                case HM_CLOSENODE:
                    kprintf("Close [%s] in %sn", onm->onm_Node, db);

                    /* Indicate that we were able to close the node */
                    retval = TRUE;
                    break;

                /* Free any extra memory */
                case HM_EXPUNGE:
                    kprintf("Expunge [%s]n", db);
                    break;

                default:
                    kprintf("Unknown method %ldn", msg->MethodID);
                    break;
            }

            return (retval);
        }

        main(int argc, char **argv)
        {
            struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) hook;
            AMIGAGUIDEHOST hh;

            /* [Open](../Includes_and_Autodocs_3._guide/node0196.html) the library */
            if (AmigaGuideBase = OpenLibrary("amigaguide.library", 33))
            {
                /* Initialize the hook */
                hook.h_Entry    = hookEntry;
                hook.h_SubEntry = dispatchAmigaGuideHost;

                /* Add the [AmigaGuideHost](../Includes_and_Autodocs_3._guide/node05D2.html#line144) to the system */
                if (hh = AddAmigaGuideHost(&hook, "ExampleHost", NULL))
                {
                    /* [Wait](../Includes_and_Autodocs_3._guide/node0246.html) until we're told to quit */
                    Wait(SIGBREAKF_CTRL_C);

                    /* Try removing the host */
                    while (RemoveAmigaGuideHost(hh, NULL) > 0)
                    {
                        /* [Wait](../Includes_and_Autodocs_3._guide/node0246.html) a while */
                        Delay(5);
                    }
                }

                /* close the library */
                CloseLibrary(AmigaGuideBase);
            }
        }

    BUGS
        When a dynamic node host is first added it will receive a
        HM_FINDNODE message with an onm_Node of "Main".  The
        AGA_HelpGroup attribute will always be zero for this
        particular message.
