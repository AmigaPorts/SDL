---
title: Devices/IFFP_Modules.README
manual: devices
chapter: devices
section: devices-iffp-modules-readme
functions: [AllocIFF, FindCollection, FindProp, FreeIFF]
libraries: [iffparse.library]
---

# Devices/IFFP_Modules.README

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

			IFFP Modules - July 1991
			     version 37.5

These iffparse.library code modules and examples are designed as
replacements for the original EA IFF code.  In some modules, it has been
possible to retain much of the original code.  However, most structures
and most higher level function interfaces have changed.

On the plus side, these new modules contain many new high-level
easy-to-use functions for querying, loading, displaying, and saving ILBMs.
During their development, modules similar to these have been used inhouse
at Commodore for the 2.0 Display program and several other ILBM
applications.  The screen.c module provides powerful display-opening
functions which are 1.3-compatible yet provide a host of new options under
2.0 such as centered overscan screens, full-video display clips, border
transparency control, and autoscroll.  New modules have been added for
printing (screendump) and for preserving/adding chunks (copychunks). And
the 8SVX example now actually plays samples and instruments. In addition,
clipboard support is automatic for all applications that use the IFFP
modules because parse.c's openifile() interprets the filename -c[n] (ie.
"-c", "-c1", "-c2", etc.) as clipboard unit n.

All of the applications presented here require iffparse.library which is
distributed on Workbench 2.0.  Please note that iffparse.library is a
1.3-compatible library, and that all of these modules and examples have
been designed to take advantage of 2.0, but also work under 1.3.
Developers who wish to distribute iffparse.library on their commercial
products may execute a 2.0 Workbench license, or may get an addendum to
their 1.3 Workbench license to allow distribution of iffparse.library.

It was not necessary to port the gio IO speedup code since iffparse can
use your compiler's own buffered IO routines through the callback
stdio_stream() in parse.c.  Depending on your application, you may want to
add your own additional buffering to this stdio_stream() code.

Most of the high-level function pairs provided in these modules have been
designed to provide safe cleanup for themselves.  For example, a
loadbrush() that succeeds or fails at any point can be cleaned up via
unloadbrush.  The cleanup routines null out the appropriate pointers so
that allocations will not be freed twice.

All applications are built upon the parse.c module.  The basic concept of
using the parse.c module are:

	- Define tag-like arrays of your desired chunks (readers only)
	- Allocates one or more [form]Info structures as defined in
	    iffp/[form]app.h (for example an ILBMInfo defined in
	    iffp/ilbmapp.h).
	- Initialize the ParseInfo part of these structures to the desired
	    chunk arrays, and to an IFFHandle allocated via iffparse
	    AllocIFF().
	- Use the provided high level load/save functions, or use the
	    lower level parse.c openifile(), reader-only parseifile()/
	    getcontext()/nextcontext(), and closeifile().  The filename
	    -c[n] may be used to read/write clipboard unit n.
	- Clean up, FreeIFF(), and deallocate [form]Info's.


IMPORTANT NOTES - Most of the higher-level load functions keep the
	IFFHandle (file or clipboard) open.  While the handle is
	open, you may use parse.c functions (such as findpropdata)
	OR direct iffparse functions (FindProp(), FindCollection())
	for accessing the gathered chunks.  However, it is not a good
	idea to keep a filehandle OR the clipboard open.  While
	a clipboard unit is open, no other applications can clip
	to the unit.  And while a file is open, you can't write the
	file back out.  So, instead of keeping the file or unit
	open, you can use copychunks (in copychunks.c) to create
	a copy of your gathered chunks, and do an early closeifile()
	(parse.c).  Then access and later write back out (if you wish)
	and deallocate your copied chunks via the routines in the
	copychunks module (findchunk, writechunklist, freechunklist).

WARNING REGARDING COMPLEX FORMS
        Regarding Complex FORMs - The parse.c module will enter complex
	formats such as CATSs, LISTs, and nested FORMs to find the FORM
	that you are interested in.  This is great.  However, if you are
        a read-modify-write program, you should warn your user when this
        occurs unless YOU are capable of recreating the complex format.
	Otherwise, your user may unknowingly destroy his complex file
	by writing over it with your program.  Example - a paint
	program could read an ILBM out of a complex LIST containing
	pictures and music, and then save it back out as a simple ILBM,
	causing the user to lose his music and other pictures.
	To determine if a complex form was entered after a load,
	check the (form)Info.ParseInfo.hunt field.  If TRUE (non-zero),
	then your file was found inside a complex format.

COMPILATION NOTES
	These modules and examples have been compiled using SAS C 5.10a
	and Manx C 5.0d, with 2.0 (37.1) include files and 2.0 amiga.lib.
	You must have at least 37.1 alib_protos.h (older versions of
	this include file contained the amiga.lib stdio protos also
	which conflict with both SAS and Manx stdio).  For Manx, I
	also had to comment out the conditional definition of abs() in
	libraries/mathffp.h.  These modules do not use mathffp, but
	the mathffp include file is pulled in by alib_protos.h.
	When compiling with Manx, a warning seems to be generated for
	each string constant assigned to a UBYTE * field, and also
	by some references to ilbm->colortable.



		LIST OF IFFP MODULES AND APPLICATIONS
                -------------------------------------
	NOTE - Some useful functions are listed with each module
 	   See module source code for docs on each function.


APPLICATIONS (these require linkage with modules - see Makefiles)
------------
ILBMDemo	Displays an ILBM, loads a brush, saves an ILBM, opt. print
ILBMLoad	Queries an ILBM and loads it into an existing screen
ILBMtoC		Outputs an ILBM as C source code
ILBMtoRaw	Converts an ILBM to raw plane/color file
RawtoILBM	Converts raw plane/color file (from ILBMtoRaw) to an ILBM
24bitDemo	Saves a simple 24-bit ILBM and then shows it 4 planes at
		a time (if given filename, just does the show part)
Play8SVX	Reads and plays an 8SVX sound effect or instrument
		  - LoadSample, UnloadSample, PlaySample, OpenAudio,
		    CloseAudio, and body load/unpack functions
ScreenSave	Save the front screen as an ILBM, with an icon


OTHER EXAMPLES (use iffparse.library directly and require no modules)
--------------
Sift		Checks and prints outline of any IFF file (uses RAWSTEP)
ILBMScan	Prints out useful info about any ILBM
ClipFTXT	Demonstrates simply clipping of FTXT to/from clipboard
cycvb.c		Dan Silva's routine for interrupt based color cycling
apack.asm	Dr. Gerald Hull's assembler replacement for packer.c


GENERAL IFFPARSE SUPPORT MODULE
-------------------------------
parse.c		File/clipboard IO and general parsing
		  - openifile, closeifile, parseifile, getcontext,
		    nextcontext, contextis, currentchunkis, PutCk chunk
		    writing function, and IFFerr text error routine


ILBM READ MODULES
-----------------
loadilbm.c      High level ILBM load routines which are passed filenames
		(calls getbitmap)
		  - loadbrush/unloadbrush,loadilbm/unloadilbm,and queryilbm
getbitmap.c	brush/bitmap loading (non-display, calls ilbmr.c)
		  - createbrush/deletebrush, getbitmap/freebitmap
getdisplay.c	bitmap load/display (calls screen.c, ilbmr.c)
		  - showilbm/unshowilbm, createdisplay/deletedisplay
screen.c	1.3/2.0 ECS/non-ECS compatible screen/window module
		  - opendisplay, openidscreen, modefallback, clipit
ilbmr.c		Lower level ILBM body/color load routines(calls unpacker.c)
		  - loadbody, loadcmap, getcolors/freecolors,
		    alloccolortable, getcamg (gets or creates modeid)
unpacker.c	BODY unpacker


ILBM WRITE MODULES
------------------
saveilbm.c	High level ILBM saving routines which are passed filenames
		(calls ilbmw.c)
		  - screensave and saveilbm
ilbmw.c		Lower level ILBM body/color save routines (calls packer.c)
		  - InitBMHD, PutCMAP, PutBODY
packer.c	BODY packer


EXTRA MODULES
-------------
copychunks.c	Chunk cloning and chunk list writing routines
		  - copychunks, findchunk, writechunklist, freechunklist
screendump.c	Screen printing module (iffparse not required)
bmprintc.c	Module to output ILBM as C code


INCLUDE FILES
-------------
iffp/#?.h	This subdirectory may be kept in your current directory
		or in your main include directory.


Thanks to Steve Walton for his code changes for Manx/SAS compatibility,
and to Bill Barton and John Bittner for their comments and suggestions.

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)
- [FindCollection — iffparse.library](../autodocs/iffparse.library.md#findcollection)
- [FindProp — iffparse.library](../autodocs/iffparse.library.md#findprop)
- [FreeIFF — iffparse.library](../autodocs/iffparse.library.md#freeiff)
