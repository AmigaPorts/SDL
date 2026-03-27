---
title: Lib_examples/findboards.c
manual: libraries
chapter: libraries
section: lib-examples-findboards-c
functions: []
libraries: []
---

# Lib_examples/findboards.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* findboards.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 findboards.c
Blink FROM LIB:c.o,findboards.o TO findboards LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
*/
#include <exec/types.h>
#include <exec/memory.h>
#include <libraries/dos.h>
#include <libraries/configvars.h>

#include <clib/exec_protos.h>
#include <clib/expansion_protos.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

struct Library   *ExpansionBase = NULL;

void main(int argc, char **argv)
{
```c
    struct ConfigDev *myCD;
    UWORD m,i;
    UBYTE p,f,t;

    if((ExpansionBase=OpenLibrary("expansion.library",0L))==NULL)
```
	exit(RETURN_FAIL);

```c
    /*--------------------------------------------------*/
    /* FindConfigDev(oldConfigDev,manufacturer,product) */
    /* oldConfigDev = NULL for the top of the list      */
    /* manufacturer = -1 for any manufacturer           */
    /* product      = -1 for any product                */
    /*--------------------------------------------------*/

    myCD = NULL;
    while(myCD=FindConfigDev(myCD,-1L,-1L)) /* search for all ConfigDevs */
```
	{
	printf("\n---ConfigDev structure found at location $%lx---\n",myCD);

	/* These values were read directly from the board at expansion time */
	printf("Board ID (ExpansionRom) information:\n");

	t = myCD->cd_Rom.er_Type;
	m = myCD->cd_Rom.er_Manufacturer;
	p = myCD->cd_Rom.er_Product;
	f = myCD->cd_Rom.er_Flags;
	i = myCD->cd_Rom.er_InitDiagVec;

	printf("er_Manufacturer         =%d=$%04x=(~$%4x)\n",m,m,(UWORD)~m);
	printf("er_Product              =%d=$%02x=(~$%2x)\n",p,p,(UBYTE)~p);

	printf("er_Type                 =$%02x",myCD->cd_Rom.er_Type);
	if(myCD->cd_Rom.er_Type & ERTF_MEMLIST)
	    printf("  (Adds memory to free list)\n");
	else printf("\n");

	printf("er_Flags                =$%02x=(~$%2x)\n",f,(UBYTE)~f);
	printf("er_InitDiagVec          =$%04x=(~$%4x)\n",i,(UWORD)~i);


	/* These values are generated when the AUTOCONFIG(tm) software
	 * relocates the board
	 */
	printf("Configuration (ConfigDev) information:\n");
	printf("cd_BoardAddr            =$%lx\n",myCD->cd_BoardAddr);
	printf("cd_BoardSize            =$%lx (%ldK)\n",
	       myCD->cd_BoardSize,((ULONG)myCD->cd_BoardSize)/1024);

	printf("cd_Flags                =$%x",myCD->cd_Flags);
	if(myCD->cd_Flags & CDF_CONFIGME)
	    printf("\n");
	else printf("  (driver clears CONFIGME bit)\n");
	}
```c
    CloseLibrary(ExpansionBase);
```
}

