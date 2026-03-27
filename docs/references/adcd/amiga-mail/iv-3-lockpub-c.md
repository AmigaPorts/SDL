---
title: IV-3/Lockpub.c
manual: amiga-mail
chapter: amiga-mail
section: iv-3-lockpub-c
functions: [LockPubScreenList, UnlockPubScreenList]
libraries: [intuition.library]
---

# IV-3/Lockpub.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * V36 Lock public screen list example
 *
 * Compiled with SAS/C 6.56:  sc NMINC STRMERGE NOSTKCHK LINK lockpub.c
 * Use V36 include files.
 *
 * Copyright (c) 1990-1999 Amiga, Inc.
 *
 * This example is provided in electronic form by Amiga,
 * Inc. for use with the Amiga Mail Volume II technical publication.
 * Amiga Mail Volume II contains additional information on the correct
 * usage of the techniques and operating system functions presented in
 * these examples.  The source and executable code of these examples may
 * only be distributed in free electronic form, via bulletin board or
 * as part of a fully non-commercial and freely redistributable
 * diskette.  Both the source and executable code (including comments)
 * must be included, without modification, in any copy.  This example
 * may not be published in printed form or distributed with any
 * commercial product. However, the programming techniques and support
 * routines set forth in these examples may be used in the development
 * of original executable software products for Amiga
 * computers.
 *
 * All other rights reserved.
 *
 * This example is provided "as-is" and is subject to change; no
 * warranties are made.  All use is at your own risk. No liability or
 * responsibility is assumed.
 *
 */

#include <string.h>

#include <intuition/intuition.h>
#include <intuition/screens.h>
#include <exec/memory.h>
#include <exec/lists.h>

#include <clib/intuition_protos.h>
#include <clib/exec_protos.h>
#include <clib/alib_protos.h>

void main (void);

struct IntuitionBase *IntuitionBase;

void main(void)
{

```c
    struct List *publist;
    struct List *copy_publist;
    struct PubScreenNode *psnode;
    struct PubScreenNode *copy_psnode;

    /* fails silently if not V36 */
    if (IntuitionBase = OpenLibrary("intuition.library", 36)) {
        if (copy_publist = AllocMem(sizeof(struct List), MEMF_CLEAR)) {
            NewList(copy_publist);

            /* Lock the public screen list */
            publist = LockPubScreenList();

            /* and copy it */
            for (psnode = (struct PubScreenNode *)publist->lh_Head;
                     psnode->psn_Node.ln_Succ;
                     psnode = (struct PubScreenNode *)psnode->psn_Node.ln_Succ) {
                if (copy_psnode = AllocMem(sizeof(struct PubScreenNode), MEMF_CLEAR)) {
                    /* Copy the structure */
                    *copy_psnode = *psnode;

                    /* ln_Name points to the public screen name, make your own copy */
                    if (copy_psnode->psn_Node.ln_Name =
                            AllocMem(strlen(psnode->psn_Node.ln_Name) + 1, MEMF_CLEAR))
                        strcpy(copy_psnode->psn_Node.ln_Name, psnode->psn_Node.ln_Name);
                    else
                        printf("Not enough memory to copy screen name\n");

                    AddTail(copy_publist, (struct Node *)copy_psnode);
                } else {
                    printf("out of memory\n");
                    break;
                }
           }
           UnlockPubScreenList();

           psnode = (struct PubScreenNode *)copy_publist->lh_Head;
           while (copy_psnode = (struct PubScreenNode *)psnode->psn_Node.ln_Succ) {
                printf("%s\n", psnode->psn_Node.ln_Name);

                printf("psn_Screen       0x%lx\n", psnode->psn_Screen);
```
				                                               /* a pointer to the public screen */
```c
                printf("psn_Flags        0x%lx\n", psnode->psn_Flags);
```
				                                               /* the flags */
```c
                printf("psn_VisitorCount %ld\n", psnode->psn_VisitorCount);
                                                               /* the number of visitorwindows */
                printf("psn_SigTask      0x%lx\n", psnode->psn_SigTask);
```
				                                               /* The task to signal when the */
```c
                                                               /* visitor is gone */
                printf("psn_SigBit       %ld\n\n", psnode->psn_SigBit);
```
				                                               /* The signalbit number to use */
```c
                                                               /* to signal the task */

                if (psnode->psn_Node.ln_Name)
                    FreeMem(psnode->psn_Node.ln_Name, strlen(psnode->psn_Node.ln_Name) + 1);
                Remove((struct Node *)psnode);
                FreeMem(psnode, sizeof(struct PubScreenNode));
                psnode = copy_psnode;
           }
           FreeMem(copy_publist, sizeof(struct List));
        }
        CloseLibrary(IntuitionBase);
    }
```
}

---

## See Also

- [LockPubScreenList — intuition.library](../autodocs/intuition.library.md#lockpubscreenlist)
- [UnlockPubScreenList — intuition.library](../autodocs/intuition.library.md#unlockpubscreenlist)
