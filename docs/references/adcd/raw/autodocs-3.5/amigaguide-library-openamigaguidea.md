# amigaguide.library/OpenAmigaGuideA



```c
    NAME
        OpenAmigaGuideA - [Open](../Includes_and_Autodocs_3._guide/node0196.html) a synchronous AmigaGuide database.

    SYNOPSIS
        handle = OpenAmigaGuideA (nag, attrs);
        d0                         a0   a1

        [AMIGAGUIDECONTEXT](../Includes_and_Autodocs_3._guide/node05D2.html#line86) OpenAmigaGuideA (struct [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102) *,
                                           struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

        handle = OpenAmigaGuide (nag, tag1, ...);

        [AMIGAGUIDECONTEXT](../Includes_and_Autodocs_3._guide/node05D2.html#line86) OpenAmigaGuide (struct [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102) *,
                                          [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) tag1, ...);

    FUNCTION
        Opens a AmigaGuide database, complete with the first viewing
        window, for synchronous activity.

        Before you call OpenAmigaGuide(), you must initialize a [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102)
        structure.  [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102) is a structure that contains all the
        information needed to open a database.  The [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102) structure
        must be retained until the call returns.

        The function will not return until the user closes all the
        windows.

    INPUTS
        nag - Pointer to an instance of a [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102) structure.  That
            structure is initialized with the following data.

                  nag_Lock
                  [Lock](../Includes_and_Autodocs_3._guide/node0186.html) on the directory that the database is located in.
                  Not needed if nag_Name contains the complete path name.

                  nag_Name
                  Name of the AmigaGuide database.

                  nag_Screen
                  [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) to open the viewing windows on, NULL for the
                  Workbench screen.

                  nag_PubScreen
                  Pointer to the name of the public screen to open on.
                  Must already be opened.

                  nag_HostPort
                  Name of the applications' ARexx port (currently not used).

                  nag_ClientPort
                  Base name to use for the databases' ARexx port.

                  nag_Flags
                  Used to specify the requirements of this database.  The
                  flags are defined in [<libraries/amigaguide.h>](../Includes_and_Autodocs_3._guide/node05D2.html).

                  nag_Context
                  NULL terminated array of context nodes, in the form of:

                        /* context array */
                        [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) context[] =
                        {
                            "MAIN",
                            "INTRO",
                            "GADGETS",
                            NULL
                        };

                  The context array is not copied, but referenced,
                  therefore must remain static throughout the useage of
                  the AmigaGuide system.  This array is only referenced
                  when using the SetAmigaGuideContext() function.

                  nag_Node
                  [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) to start at (does not work with OpenAmigaGuideAsync())
```
.

```c
                  nag_Line
                  [Line](../Includes_and_Autodocs_3._guide/node0627.html#line42) to start at (does not work with OpenAmigaGuideAsync())
```
.


```c
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
```
