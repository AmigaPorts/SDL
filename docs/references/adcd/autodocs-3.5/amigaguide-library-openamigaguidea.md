---
title: amigaguide.library/OpenAmigaGuideA
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-openamigaguidea
functions: [GetUniqueID, IoErr, OpenWindow]
libraries: [dos.library, intuition.library, utility.library]
---

# amigaguide.library/OpenAmigaGuideA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        OpenAmigaGuideA - [Open](autodocs-3.5/dos-library-open-2.md) a synchronous AmigaGuide database.

    SYNOPSIS
        handle = OpenAmigaGuideA (nag, attrs);
        d0                         a0   a1

        [AMIGAGUIDECONTEXT](autodocs-3.5/include-libraries-amigaguide-h.md) OpenAmigaGuideA (struct [NewAmigaGuide](autodocs-3.5/include-libraries-amigaguide-h.md) *,
                                           struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

        handle = OpenAmigaGuide (nag, tag1, ...);

        [AMIGAGUIDECONTEXT](autodocs-3.5/include-libraries-amigaguide-h.md) OpenAmigaGuide (struct [NewAmigaGuide](autodocs-3.5/include-libraries-amigaguide-h.md) *,
                                          [Tag](autodocs-3.5/include-utility-tagitem-h.md) tag1, ...);

    FUNCTION
        Opens a AmigaGuide database, complete with the first viewing
        window, for synchronous activity.

        Before you call OpenAmigaGuide(), you must initialize a [NewAmigaGuide](autodocs-3.5/include-libraries-amigaguide-h.md)
        structure.  [NewAmigaGuide](autodocs-3.5/include-libraries-amigaguide-h.md) is a structure that contains all the
        information needed to open a database.  The [NewAmigaGuide](autodocs-3.5/include-libraries-amigaguide-h.md) structure
        must be retained until the call returns.

        The function will not return until the user closes all the
        windows.

    INPUTS
        nag - Pointer to an instance of a [NewAmigaGuide](autodocs-3.5/include-libraries-amigaguide-h.md) structure.  That
            structure is initialized with the following data.

                  nag_Lock
                  [Lock](autodocs-3.5/dos-library-lock-2.md) on the directory that the database is located in.
                  Not needed if nag_Name contains the complete path name.

                  nag_Name
                  Name of the AmigaGuide database.

                  nag_Screen
                  [Screen](autodocs-3.5/include-intuition-screens-h.md) to open the viewing windows on, NULL for the
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
                  flags are defined in [<libraries/amigaguide.h>](autodocs-3.5/include-libraries-amigaguide-h.md).

                  nag_Context
                  NULL terminated array of context nodes, in the form of:

                        /* context array */
                        [STRPTR](autodocs-3.5/include-exec-types-h.md) context[] =
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
                  [Node](autodocs-3.5/include-exec-nodes-h.md) to start at (does not work with OpenAmigaGuideAsync())
```
.

```c
                  nag_Line
                  [Line](autodocs-3.5/include-datatypes-textclass-h.md) to start at (does not work with OpenAmigaGuideAsync())
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
            AmigaGuide help windows.  See [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md) and [GetUniqueID()](autodocs-3.5/utility-library-getuniqueid.md).

            Default for this tag is NULL.  Applicability is (I). (V39)

    EXAMPLE

        /* Short example showing synchronous AmigaGuide access */
        [LONG](autodocs-3.5/include-exec-types-h.md) ShowAmigaGuideFile (STRPTR name, [STRPTR](autodocs-3.5/include-exec-types-h.md) node, [LONG](autodocs-3.5/include-exec-types-h.md) line)
        {
            struct [NewAmigaGuide](autodocs-3.5/include-libraries-amigaguide-h.md) nag = {NULL};
            [AMIGAGUIDECONTEXT](autodocs-3.5/include-libraries-amigaguide-h.md) handle;
            [LONG](autodocs-3.5/include-exec-types-h.md) retval = 0L;

            /* Fill in the [NewAmigaGuide](autodocs-3.5/include-libraries-amigaguide-h.md) structure */
            nag.nag_Name = name;
            nag.nag_Node = node;
            nag.nag_Line = line;

            /* [Open](autodocs-3.5/dos-library-open-2.md) the AmigaGuide client */
            if ( handle = OpenAmigaGuide(&nag, NULL))
            {
                /* [Close](autodocs-3.5/dos-library-close-2.md) the AmigaGuide client */
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
        [OpenAmigaGuideAsyncA()](autodocs-3.5/amigaguide-library-openamigaguideasyncamigaguide-library.md), [CloseAmigaGuide()](autodocs-3.5/amigaguide-library-closeamigaguide.md)
```

---

## See Also

- [GetUniqueID — utility.library](../autodocs/utility.library.md#getuniqueid)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
