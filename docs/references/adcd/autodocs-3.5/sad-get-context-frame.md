---
title: SAD/GET_CONTEXT_FRAME
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-get-context-frame
functions: []
libraries: []
---

# SAD/GET_CONTEXT_FRAME

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 GET CONTEXT FRAME

 Command:	$AF $09
 Data:		<none>

 This command will return a pointer to the saved context.  This will be
 a pointer to all of the registers that were saved on the stack along
 with some other details.  Returns frame address <$wwxxyyzz>

 The pointer returned is to the following structure:

 STRUCTURE	SAD_FRAME,0
	; The first three are READ-ONLY...  Mainly used to make it
	; easier to understand what is going on in the system.
	ULONG	SAD_VBR		; Current VBR (always 0 on 68000 CPUs)
	ULONG	SAD_AttnFlags	; ULONG copy of the flags (UPPER WORD==0)
	ULONG	SAD_ExecBase	; [ExecBase](autodocs-3.5/include-exec-execbase-h.md)
	; These fields are the user registers...  The registers are
	; restored from these fields on exit from SAD...
	; Note that USP is only valid if SR was *NOT* supervisor...
	ULONG	SAD_USP		; User stack pointer
	ULONG	SAD_D0		; User register d0
	ULONG	SAD_D1		; User register d1
	ULONG	SAD_D2		; User register d2
	ULONG	SAD_D3		; User register d3
	ULONG	SAD_D4		; User register d4
	ULONG	SAD_D5		; User register d5
	ULONG	SAD_D6		; User register d6
	ULONG	SAD_D7		; User register d7
	ULONG	SAD_A0		; User register a0
	ULONG	SAD_A1		; User register a1
	ULONG	SAD_A2		; User register a2
	ULONG	SAD_A3		; User register a3
	ULONG	SAD_A4		; User register a4
	ULONG	SAD_A5		; User register a5
	ULONG	SAD_A6		; User register a6
	; This is for SAD internal use...  It is the prompt that
	; SAD is using...  Changing this will have no effect on SAD.
	ULONG	SAD_PROMPT	; SAD Prompt Longword...  (internal use)
	; From here on down is the standard exception frame
	; The first two entries (SR and PC) are standard on all 680x0 CPUs
	[UWORD](autodocs-3.5/include-exec-types-h.md)	SAD_SR		; Status register (part of exception frame)
	ULONG	SAD_PC		; Return address (part of exception frame)


 Command ACK:	$00 $09
 Command DONE:	$1F $09 $ww $xx $yy $zz

