---
title: Devices/other/ilbmscan.c
manual: devices
chapter: devices
section: devices-other-ilbmscan-c
functions: [AllocIFF]
libraries: [iffparse.library]
---

# Devices/other/ilbmscan.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* ilbmscan.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -j73 ilbmscan.c
Blink FROM LIB:c.o,ilbmscan.o TO ilbmscan LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit

*
* ilbmscan.c:	Prints the size, aspect, mode, etc. of ILBM's
*		Scans through an IFF file for all ILBM's
*
* Usage: ilbmscan -c		; For clipboard scanning
*    or  ilbmscan <file>	; For DOS file scanning
*
* Based on sift.c by by Stuart Ferguson and Leo Schwab
*/

#include <exec/types.h>
#include <exec/memory.h>
#include <libraries/dos.h>
#include <libraries/iffparse.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/iffparse_protos.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

/*  The structure of a FORM ILBM 'BMHD' and 'CAMG' chunks
 *  Such structures are defined in the spec for a FORM
 *  and may also be provided in include files
 */
/*  Bitmap header (BMHD) structure  */
typedef struct {
```c
        UWORD   w, h;           /*  Width, height in pixels */
        WORD    x, y;           /*  x, y position for this bitmap  */
        UBYTE   nplanes;        /*  # of planes  */
        UBYTE   Masking;
        UBYTE   Compression;
        UBYTE   pad1;
        UWORD   TransparentColor;
        UBYTE   XAspect, YAspect;
        WORD    PageWidth, PageHeight;
```
} BitMapHeader;

/* Commodore Amiga (CAMG) Viewmodes structure */
typedef struct {
   ULONG ViewModes;
   } CamgChunk;

#define ID_ILBM         MAKE_ID('I','L','B','M')
#define ID_BMHD         MAKE_ID('B','M','H','D')
#define ID_CMAP         MAKE_ID('C','M','A','P')
#define ID_CAMG         MAKE_ID('C','A','M','G')
#define ID_BODY         MAKE_ID('B','O','D','Y')

void PrintILBMInfo(struct IFFHandle *);

#define MINARGS 2

/* 2.0 Version string for c:Version to find */
UBYTE vers[] = "\0$VER: ilbmscan 37.3";

UBYTE usage[] = "Usage: ilbmscan IFFfilename (or -c for clipboard)";

/*
 * Text error messages for possible IFFERR_#? returns from various
 * IFF routines.  To get the index into this array, take your IFFERR code,
 * negate it, and subtract one.
 *  idx = -error - 1;
 */
char	*errormsgs[] = {
	"End of file (not an error).",
	"End of context (not an error).",
	"No lexical scope.",
	"Insufficient memory.",
	"Stream read error.",
	"Stream write error.",
	"Stream seek error.",
	"File is corrupt.",
	"IFF syntax error.",
	"Not an IFF file.",
	"Required call-back hook missing.",
	"Return to client.  You should never see this."
};

struct Library *IFFParseBase;


void main(int argc, char **argv)
{
```c
    struct IFFHandle	*iff = NULL;
    long		error;
    short		cbio;

    	/* if not enough args or '?', print usage */
    	if(((argc)&&(argc<MINARGS))||(argv[argc-1][0]=='?'))
```
		{
	    	printf("%s\n",usage);
	    	exit(RETURN_OK);
	    	}

	/*
	 * Check to see if we are doing I/O to the Clipboard.
	 */
	cbio = (argv[1][0] == '-'  &&  argv[1][1] == 'c');

	if (!(IFFParseBase = OpenLibrary ("iffparse.library", 0L)))
		{
		printf("Can't open iff parsing library.");
		goto bye;
		}

	/*
	 * Allocate IFF_File structure.
	 */
	if (!(iff = AllocIFF ()))
		{
		printf ("AllocIFF() failed.");
		goto bye;
		}

	/*
	 * Internal support is provided for both AmigaDOS files, and the
	 * clipboard.device.  This bizarre 'if' statement performs the
	 * appropriate machinations for each case.
	 */
	if (cbio)
		{
		/*
		 * Set up IFF_File for Clipboard I/O.
		 */
		if (!(iff->iff_Stream =
				(ULONG) OpenClipboard (PRIMARY_CLIP)))
			{
			printf("Clipboard open failed.");
			goto bye;
			}
		InitIFFasClip (iff);
		}
	else
		{
		/*
		 * Set up IFF_File for AmigaDOS I/O.
		 */
		if (!(iff->iff_Stream = Open (argv[1], MODE_OLDFILE)))
			{
			printf("File open failed.");
			goto bye;
			}
		InitIFFasDOS (iff);
		}

	/*
	 * Start the IFF transaction.
	 */
	if (error = OpenIFF (iff, IFFF_READ))
		{
		printf("OpenIFF failed.");
		goto bye;
		}

	/* We want to collect BMHD and CAMG */
	PropChunk(iff, ID_ILBM, ID_BMHD);
	PropChunk(iff, ID_ILBM, ID_CAMG);
	PropChunk(iff, ID_ILBM, ID_CMAP);

	/* Stop at the BODY */
	StopChunk(iff, ID_ILBM, ID_BODY);

	/* And let us know (IFFERR_EOC) when leaving a FORM ILBM */
	StopOnExit(iff,ID_ILBM, ID_FORM);

	/* Do the scan.
	 * The while(1) will let us delve into more complex formats
	 * to find FORM ILBM's
	 */
	while (1)
		{
		error = ParseIFF(iff, IFFPARSE_SCAN);
		/*
		 * Since we're only interested in when we enter a context,
		 * we "discard" end-of-context (_EOC) events.
		 */
		if (error == IFFERR_EOC)
			{
			printf("Exiting FORM ILBM\n\n");
			continue;
			}
		else if (error)
			/*
			 * Leave the loop if there is any other error.
			 */
			break;

		/*
		 * If we get here, error was zero
		 * Since we did IFFPARSE_SCAN, zero error should mean
		 * we are at our Stop Chunk (BODY)
		 */
		PrintILBMInfo(iff);
		}

	/*
	 * If error was IFFERR_EOF, then the parser encountered the end of
	 * the file without problems.  Otherwise, we print a diagnostic.
	 */
	if (error == IFFERR_EOF)
		printf("File scan complete.\n");
	else
		printf("File scan aborted, error %ld: %s\n",
			error, errormsgs[-error - 1]);

bye:
	if (iff) {
		/*
		 * Terminate the IFF transaction with the stream.  Free
		 * all associated structures.
		 */
		CloseIFF (iff);

		/*
		 * Close the stream itself.
		 */
		if (iff->iff_Stream)
			if (cbio)
				CloseClipboard ((struct ClipboardHandle *)
						iff->iff_Stream);
			else
				Close (iff->iff_Stream);

		/*
		 * Free the IFF_File structure itself.
		 */
		FreeIFF (iff);
		}
	if (IFFParseBase)	CloseLibrary (IFFParseBase);

	exit (RETURN_OK);
}


void
PrintILBMInfo(iff)
struct IFFHandle *iff;
{
	struct StoredProperty	*sp;
	BitMapHeader 	*bmhd;
	CamgChunk	*camg;

	/*
	 * Get a pointer to the stored propery BMHD
	 */
	if (!(sp = FindProp(iff, ID_ILBM, ID_BMHD)))
		printf("No BMHD found\n");
	else
		{
		/* If property is BMHD, sp->sp_Data is ptr to data in BMHD */
		bmhd = (BitMapHeader *)sp->sp_Data;
		printf("BMHD: Width      = %ld\n",bmhd->w);
		printf("      Height     = %ld\n",bmhd->h);
		printf("      PageWidth  = %ld\n",bmhd->PageWidth);
		printf("      PageHeight = %ld\n",bmhd->PageHeight);
		printf("      nplanes    = %ld\n",bmhd->nplanes);
```c
       		printf("      Masking    = %ld\n",bmhd->Masking);
                printf("      Compression= %ld\n",bmhd->Compression);
```
		printf("      TransColor = %ld\n",bmhd->TransparentColor);
		printf("      X/Y Aspect = %ld/%ld\n",bmhd->XAspect,bmhd->YAspect);
		}

	/*
	 * Get a pointer to the stored propery CMAP
	 */
	if (!(sp = FindProp(iff, ID_ILBM, ID_CMAP)))
		printf("No CMAP found\n");
	else
		{
		/* If property is CMAP, sp->sp_Data is ptr to data in CMAP */
		printf("CMAP: contains RGB values for %ld registers\n",
				sp->sp_Size / 3);
		}

	/*
	 * Get a pointer to the stored propery CAMG
	 */
	if (!(sp = FindProp(iff, ID_ILBM, ID_CAMG)))
		printf("No CAMG found\n");
	else
		{
		/* If property is CAMG, sp->sp_Data is ptr to data in CAMG */
		camg = (CamgChunk *)sp->sp_Data;
		printf("CAMG: ModeID     = $%08lx\n\n",camg->ViewModes);
		}

}

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)
