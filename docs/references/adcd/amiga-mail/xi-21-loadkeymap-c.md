---
title: XI-21/LoadKeyMap.c
manual: amiga-mail
chapter: amiga-mail
section: xi-21-loadkeymap-c
functions: [FindName, Forbid, LoadSeg, Permit]
libraries: [dos.library, exec.library]
---

# XI-21/LoadKeyMap.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#include <exec/types.h>
#include <exec/memory.h>
#include <exec/libraries.h>
#include <devices/keymap.h>
#include <dos/dos.h>

#include <clib/exec_protos.h>
#include <clib/utility_protos.h>
#include <clib/dos_protos.h>

#include <pragmas/exec_pragmas.h>
#include <pragmas/utility_pragmas.h>
#include <pragmas/dos_pragmas.h>

#include "loadkeymap.h"


/*****************************************************************************/


extern struct Library *SysBase;
extern struct Library *UtilityBase;
extern struct Library *DOSBase;


/*****************************************************************************/


/* Case-insensitive version of FindName() */
static struct Node *FindNameNC(struct List *list, STRPTR name)
{
struct Node *node;
WORD         result;

```c
    node = list->lh_Head;
    while (node->ln_Succ)
    {
        result = Stricmp(name,node->ln_Name);
        if (result == 0)
            return(node);

        node = node->ln_Succ;
    }

    return(NULL);
```
}


/*****************************************************************************/


struct KeyMap *LoadKeyMap(STRPTR name)
{
BPTR                   segment;
struct KeyMapResource *kr;
struct KeyMapNode     *kn;
STRPTR                 base;

```c
    kn      = NULL;
    segment = NULL;

    /* open the keymap resource, in order to gain access to the keymap list */
    if (kr = (struct KeyMapResource *)OpenResource("keymap.resource"))
    {
        segment = NULL;
        base = FilePart(name);

        /* must access the list under Forbid() */
        Forbid();

        /* is the keymap we want already on the keymap list? */
        if (!(kn = (struct KeyMapNode *)FindNameNC(&kr->kr_List,base)))
        {
            /* if not on the keymap list, try loading it */
            if (segment = LoadSeg(name))
            {
                /* see if someone added it to the keymap list while we were
                 * doing a LoadSeg() (which broke Forbid() )
                 */
                if (!(kn = (struct KeyMapNode *)FindNameNC(&kr->kr_List,base)))
                {
                    kn = (struct KeyMapNode *)((segment << 2) + sizeof(BPTR));

                    /* we've loaded a keymap file. Do a few sanity checks
                     * to make sure it is a keymap, and not some bogus
                     * load file
                     */
                    if (TypeOfMem(kn->kn_Node.ln_Name)
                    &&  Stricmp(name,kn->kn_Node.ln_Name))
                    {
                        /* add to the system's keymap list */
                        AddHead(&(kr->kr_List),(struct Node *)kn);
                    }
                    else
                    {
                        /* bogus load file! Get rid of it and fail */
                        UnLoadSeg(segment);
                        kn = NULL;
                    }
                }
                else
                {
                    /* the keymap was added to the list behind our back!
                     * Free what was loaded and return happily
                     */
                    UnLoadSeg(segment);
                }
            }
        }

        /* get out of forbidden state */
        Permit();
    }

    if (kn)
        return(&kn->kn_KeyMap);

    return(NULL);
```
}

---

## See Also

- [FindName — exec.library](../autodocs/exec.library.md#findname)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
