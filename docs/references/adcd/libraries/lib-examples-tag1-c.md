---
title: Lib_examples/tag1.c
manual: libraries
chapter: libraries
section: lib-examples-tag1-c
functions: []
libraries: []
---

# Lib_examples/tag1.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* tag1.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfis -j73 tag1.c
Blink FROM LIB:c.o,tag1.o TO tag1 LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
**
** The following example shows simple usage of tags.  It shows how to
** allocate a tag array and use it, it also shows how to build a tag
** array on the stack.
*/

#include <exec/types.h>
#include <exec/libraries.h>
#include <utility/tagitem.h>
#include <intuition/intuition.h>
#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>
#include <clib/utility_protos.h>

extern struct Library *SysBase;
struct Library *IntuitionBase, *UtilityBase;

int main (int argc, char **argv)
{
```c
    struct TagItem *tags;
    struct Window  *win;

    /* For this example we need Version 2.0 */
    if (IntuitionBase = OpenLibrary ("intuition.library", 37))
    {
        /* We need the utility library for this example */
        if (UtilityBase = OpenLibrary ("utility.library", 37))
        {

        /****************************************************************/
        /* This section allocates a tag array, fills it in with values, */
        /* and then uses it.                                            */
        /****************************************************************/

            /* Allocate a tag array */
            if (tags = AllocateTagItems (7))
            {
                /* Fill in our tag array */
                tags[0].ti_Tag = WA_Width;
                tags[0].ti_Data = 320;
                tags[1].ti_Tag = WA_Height;
                tags[1].ti_Data = 50;
                tags[2].ti_Tag = WA_Title;
                tags[2].ti_Data = (ULONG) "RKM Tag Example 1";
                tags[3].ti_Tag = WA_IDCMP;
                tags[3].ti_Data = IDCMP_CLOSEWINDOW;
                tags[4].ti_Tag = WA_CloseGadget;
                tags[4].ti_Data = TRUE;
                tags[5].ti_Tag = WA_DragBar;
                tags[5].ti_Data = TRUE;
                tags[6].ti_Tag = TAG_DONE;

                /* Open the window, using the tag attributes as the
                 * only description. */
                if (win = OpenWindowTagList (NULL, tags))
                {
                    /* Wait for an event to occur */
                    WaitPort (win->UserPort);

                    /* Close the window now that we're done with it */
                    CloseWindow (win);
                }

                /* Free the tag list now that we're done with it */
                FreeTagItems(tags);
            }

        /****************************************************************/
        /* This section builds the tag array on the stack, and passes   */
        /* the array to a function.                                     */
        /****************************************************************/

            /* Now use the VarArgs (or stack based) version. */
            if (win = OpenWindowTags ( NULL,
                                       WA_Width, 320,
                                       WA_Height, 50,
                                       WA_Title, (ULONG)"RKM Tag Example 1",
                                       WA_IDCMP, IDCMP_CLOSEWINDOW,
                                       WA_CloseGadget, TRUE,
                                       WA_DragBar, TRUE,
                                       TAG_DONE))
            {
                /* Wait for an event to occur */
                WaitPort (win->UserPort);

                /* Close the window now that we're done with it */
                CloseWindow (win);
            }

            /* Close the library now */
            CloseLibrary (UtilityBase);
        }

        /* Close the library now that we're done with it */
        CloseLibrary (IntuitionBase);
    }
```
}

