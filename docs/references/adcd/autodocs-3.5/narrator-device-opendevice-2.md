---
title: narrator.device/OpenDevice
manual: autodocs-3.5
chapter: autodocs-3.5
section: narrator-device-opendevice-2
functions: []
libraries: []
---

# narrator.device/OpenDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	OpenDevice - opens the narrator device.


   SYNOPSIS
	error = OpenDevice("narrator.device",  unit, [IORequest](autodocs-3.5/include-exec-io-h.md), flags);
	 D0                       A0            D0     A1         D1


   FUNCTION
	The OpenDevice routine grants access to the narrator device.
	OpenDevice checks the unit number, and if non-zero, returns an
	error (ND_UnitErr).  If this is the first time the driver has
	been opened, OpenDevice will attempt to open the audio device
	and allocate the driver's static buffers.  If either of these
	operations fail, an error is returned.  See the .h and .i
	include files for possible error return codes.  Next, OpenDevice
	(done for all opens, not just the first one) initializes various
	fields in the user's [IORequest](autodocs-3.5/include-exec-io-h.md) block (see below).  If users wish
	to use non-default values for these parms, the values must be set
	after the open is done.  OpenDevice also assigns a pseudo unit
	number to the IORB for use in synchronizing read and write requests.
	See the read command for more details.	Finally, OpenDevice stores
	the device node pointer in the [IORequest](autodocs-3.5/include-exec-io-h.md) block and clears the
	delayed expunge bit.

	***** NEW FOR V37 NARRATOR *****

	Several new fields in the [IORequest](autodocs-3.5/include-exec-io-h.md) block have been added for V37
	narrator.  These fields are initialized when the device is opened
	if the NDB_NEWIORB bit is set in the flags field of the user's
	[IORequest](autodocs-3.5/include-exec-io-h.md) block.  Note that NDB_NEWIORB is set in the [IORequest](autodocs-3.5/include-exec-io-h.md)
	block, NOT in the "flags" input parm to the OpenDevice call.


   INPUTS
	device     - "narrator.device"
	unit       - 0
	[IORequest](autodocs-3.5/include-exec-io-h.md)  - Pointer to the user's [IORequest](autodocs-3.5/include-exec-io-h.md) block
	flags	   - 0


   RESULTS
	The narrator device will initialize the [IORequest](autodocs-3.5/include-exec-io-h.md) block as follows
	(assume IORB points to the IOrequest block):

	IORB->rate = 150;		/* Speaking rate in words/minute */
	IORB->pitch = 110;		/* Baseline pitch in Hertz     	*/
	IORB->mode = NATURALF0;		/* Pitch (F0) mode		*/
	IORB->sex = MALE;		/* Sex of voice			*/
	IORB->volume = 64		/* Volume, full on		*/
	IORB->sampfreq = 22200		/* Audio sampling freq 		*/
	IORB->mouths = 0		/* Don't generate sync events	*/

	and if the NDB_NEWIORB bit is set:

	IORB->F0enthusiasm = 0		/* F0 excursion factor		*/
	IORB->F0perturb = 32		/* F0 perturbation (in 32nds)	*/
	IORB->F1adj = 0			/* F1 adjustment in ±5% steps	*/
	IORB->F2adj = 0 		/* F2 adjustment in ±5% steps	*/
	IORB->F3adj = 0			/* F3 adjustment in ±5% steps	*/
	IORB->A1adj = 0			/* A1 adjustment in decibels	*/
	IORB->A2adj = 0			/* A2 adjustment in decibels	*/
	IORB->A3adj = 0		 	/* A3 adjustment in decibels	*/
	IORB->articulate = 100		/* Transition time multiplier	*/
	IORB->centralize = 0		/* Degree of vowel centralization */
	IORB->centphon = ""		/* Pointer to central ASCII phon  */
	IORB->AVbias = 0		/* AV bias			*/
	IORB->AFbias = 0		/* AF bias			*/
	IORB->priority = 100		/* Priority while speaking	*/



   SEE ALSO
	The include files contain the complete [IORequest](autodocs-3.5/include-exec-io-h.md) block definition,
	    default settings, and error return codes.
	Exec input/output documentation.

