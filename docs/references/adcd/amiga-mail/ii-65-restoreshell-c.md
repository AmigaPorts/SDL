---
title: II-65/RestoreShell.c
manual: amiga-mail
chapter: amiga-mail
section: ii-65-restoreshell-c
functions: [Forbid, Permit]
libraries: [exec.library]
---

# II-65/RestoreShell.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* RestoreShell.c - Execute me to compile me with SAS/C 6.56
; (c)  Copyright 1992-1999 Amiga, Inc.   All rights reserved.
; The information contained herein is subject to change without notice,
; and is provided "as is" without warranty of any kind, either expressed
; or implied.  The entire risk as to the use of this information is
; assumed by the user.
;
sc DATA=NEAR NMINC STRMERGE NOSTKCHK NODEBUG IGNORE=73 RestoreShell.c
slink FROM lib:c.o RestoreShell.o TO RestoreShell LIBRARY lib:sc.lib lib:amiga.lib smallcode smalldata
quit
*/
/* restore the BootShell as the UserShell.  Note that this
   only switches back the BootShell, it does not unload the
   current user shell ("shell" on the resident list) as it
   is possible that some instance of it can still be running.
*/
#include <exec/types.h>
#include <dos/dosextens.h>
#include <clib/exec_protos.h>
#include <clib/dos_protos.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }
#endif

UBYTE *vers = "\0$VER: RestoreShell 1.0";

void main(void)
{
```c
    struct Segment
        *bootshell_seg,
        *shell_seg;

    Forbid();
    shell_seg = FindSegment("shell", NULL, CMD_SYSTEM);
    bootshell_seg = FindSegment("bootshell", NULL, CMD_SYSTEM);
    if (bootshell_seg)
```
		shell_seg->seg_Seg = bootshell_seg->seg_Seg;
```c
    Permit();
```
}

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
