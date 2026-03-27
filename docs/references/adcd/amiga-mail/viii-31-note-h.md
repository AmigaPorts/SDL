---
title: VIII-31/Note.h
manual: amiga-mail
chapter: amiga-mail
section: viii-31-note-h
functions: []
libraries: []
---

# VIII-31/Note.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
** Note.h - Some generic external references
*/
/* (c)  Copyright 1992-1999 Amiga, Inc.   All rights reserved. */
/* The information contained herein is subject to change without    */
/* notice, and is provided "as is" without warranty of any kind,    */
/* either expressed or implied.  The entire risk as to the use of   */
/* this information is assumed by the user.                         */

extern struct Library   *IntuitionBase,


```c
                        *SockBase;
```
/*
** Amiga System Includes
*/

#include <exec/types.h>
#include <exec/exec.h>
#include <dos/dos.h>
#include <dos/rdargs.h>
#include <dos/dostags.h>
#include <dos/dosextens.h>
#include <intuition/intuition.h>
#include <utility/tagitem.h>

/*
** Amiga System Prototypes
*/

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>

/*
** socket.library Includes
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <ss/socket.h>
/* make sure you rename <ss/socket_pragmas.sas|manx>
to <ss/socket_pragmas.h> */
#include <ss/socket_pragmas.h>
#include <netdb.h>

/*
** ...and some generic ANSI stuff
*/

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>

/*
** The definition of the structure which is the message packet passed
** between the client and server.  This has been kept about as minimal
** as possible, but the buffers had to be designated that way to keep
** the code of the handler routines down in size.
**
** The #define's give the valid types that may be in the nn_Code field
** of the NetNote packet.
*/

struct NetNote
{
```c
    int     nn_Code;
    int     nn_Retval;
    char    nn_Text[200],
            nn_Button[40];
```
};

#define NN_MSG  0
#define NN_ACK  1
#define NN_ERR  2

/*
** This definition is used in both the client and server as the name any
** entries in the INET:DB/SERVICES file will be under.
*/

#define APPNAME "notes"

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }
#endif

/*
** End of note.h
*/

