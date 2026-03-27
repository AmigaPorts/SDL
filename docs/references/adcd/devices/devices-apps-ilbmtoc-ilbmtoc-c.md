---
title: Devices/apps/ILBMtoC/ILBMtoC.c
manual: devices
chapter: devices
section: devices-apps-ilbmtoc-ilbmtoc-c
functions: [AllocIFF]
libraries: [iffparse.library]
---

# Devices/apps/ILBMtoC/ILBMtoC.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*--------------------------------------------------------------*/
/*								*/
/* ILBMtoC: reads in ILBM, prints out ascii representation, 	*/
/*  for including in C files. 					*/
/*                                                              */
/* Based on ILBMDump.c by Jerry Morrison and Steve Shaw,	*/
/* Electronic Arts.           					*/
/* Jan 31, 1986							*/
/*                                                              */
/* This software is in the public domain.                       */
/* This version for the Amiga computer.                         */
/*                                                              */
/*  Callable from CLI ONLY					*/
/*  modified 05-91 for use wuth iffparse modules		*/
/*  Requires linkage with several other modules - see Makefile  */
/*--------------------------------------------------------------*/

#include "iffp/ilbmapp.h"

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

char *vers = "\0$VER: ILBMtoC 37.5";
char *Copyright = "ILBMtoC v37.5 (Freely Redistributable)";

void GetSuffix(UBYTE *to, UBYTE *fr);
void bye(UBYTE *s, int e);
void cleanup(void);

struct Library *IFFParseBase = NULL;
struct Library *GfxBase = NULL;

/* ILBM frame */
struct ILBMInfo ilbm = {0};


/* ILBM Property chunks to be grabbed - only BMHD needed for this app
 */
LONG	ilbmprops[] = {
		ID_ILBM, ID_BMHD,
		TAG_DONE
		};

/* ILBM Collection chunks (more than one in file) to be gathered */
LONG	*ilbmcollects = NULL;	/* none needed for this app */

/* ILBM Chunk to stop on */
LONG	ilbmstops[] = {
		ID_ILBM, ID_BODY,
		TAG_DONE
		};


UBYTE defSwitch[] = "b";

/** main() ******************************************************************/

void main(int argc, char **argv)
```c
    {
    UBYTE *sw;
    FILE *fp;
    LONG error=NULL;
    UBYTE *ilbmname, name[80], fname[80];

    if ((argc < 2)||(argv[argc-1][0]=='?'))
```
	{
	printf("Usage from CLI: 'ILBMtoC filename switch-string'\n");
	printf(" where switch-string = \n");
	printf("  <nothing> : Bob format (default)\n");
	printf("  s         : Sprite format (with header and trailer words)\n");
	printf("  sn        : Sprite format (No header and trailer words)\n");
	printf("  a         : Attached sprite (with header and trailer)\n");
	printf("  an        : Attached sprite (No header and trailer)\n");
	printf(" Add 'c' to switch list to output CR's with LF's   \n");
	exit(RETURN_OK);
	}


```c
    if(!(GfxBase = OpenLibrary("graphics.library",0)))
```
	bye("Can't open graphics.library",RETURN_FAIL);

```c
    if(!(IFFParseBase = OpenLibrary("iffparse.library",0)))
```
	bye("Can't open iffparse.library",RETURN_FAIL);

/*
 * Here we set up default ILBMInfo fields for our
 * application's frames.
 * Above we have defined the propery and collection chunks
 * we are interested in (some required like BMHD)
 */
```c
    ilbm.ParseInfo.propchks      = ilbmprops;
    ilbm.ParseInfo.collectchks   = ilbmcollects;
    ilbm.ParseInfo.stopchks      = ilbmstops;
    if(!(ilbm.ParseInfo.iff = AllocIFF()))
    	bye(IFFerr(IFFERR_NOMEM),RETURN_FAIL);	/* Alloc an IFFHandle */

    sw = (argc>2) ? (UBYTE *)argv[2] : defSwitch;
    ilbmname = argv[1];

    if (error = loadbrush(&ilbm,ilbmname))
        {
        printf("Can't load ilbm \"%s\", ifferr=%s\n",ilbmname,IFFerr(error));
        bye("",RETURN_WARN);
        }
    else /* Successfully loaded ILBM */
```
	{
	printf(" Creating file %s.c \n",argv[1]);
	GetSuffix(name,argv[1]);
	strcpy(fname,argv[1]);
	strcat(fname,".c");
	fp = fopen(fname,"w");
	if(fp)
	    {
	    BMPrintCRep(ilbm.brbitmap,fp,name,sw);
	    fclose(fp);
	    }
	else  printf("Couldn't open output file: %s. \n", fname);
	unloadbrush(&ilbm);
	}



```c
    printf("\n");
    bye("",RETURN_OK);
    }
```
/* this copies part of string after the last '/' or ':' */
void GetSuffix(to, fr) UBYTE *to, *fr; {
```c
    int i;
    UBYTE c,*s = fr;
    for (i=0; ;i++) {
```
	c = *s++;
	if (c == 0) break;
	if (c == '/') fr = s;
	else if (c == ':') fr = s;
	}


```c
    strcpy(to,fr);
    }
```
void bye(UBYTE *s, int e)


```c
    {
    if(s&&(*s))	printf("%s\n",s);
    cleanup();
    exit(e);
    }
```
void cleanup()

```c
    {
    if(ilbm.ParseInfo.iff)		FreeIFF(ilbm.ParseInfo.iff);

    if(IFFParseBase)	CloseLibrary(IFFParseBase);
    if(GfxBase)		CloseLibrary(GfxBase);
    }
```

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)
