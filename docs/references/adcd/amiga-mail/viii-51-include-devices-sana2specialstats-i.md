---
title: VIII-51/include/devices/sana2specialstats.i
manual: amiga-mail
chapter: amiga-mail
section: viii-51-include-devices-sana2specialstats-i
functions: []
libraries: []
---

# VIII-51/include/devices/sana2specialstats.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	IFND	SANA2_SANA2SPECIALSTATS_I
SANA2_SANA2SPECIALSTATS_I	SET	1
**
**	$Filename: devices/sana2specialstats.i $
**	$Revision: 1.3 $
**	$Date: 92/01/10 15:10:35 $
**
**	Defined ids for SANA-II special statistics.
**
**
**	(C) Copyright 1991-1999 Amiga, Inc.
**		All Rights Reserved
**


	IFND	SANA2_SANA2DEVICE_I
	INCLUDE	"sana2/sana2device.i"
	ENDC	!SANA2_SANA2DEVICE_I

;
; The SANA-II special statistic identifier is an unsigned 32 number.
; The upper 16 bits identify the type of network wire type to which
; the statistic applies and the lower 16 bits identify the particular
; statistic.
;

; If you'd like to add new statistic identifiers, contact CATS.

;
; defined ethernet special statistics
;

S2SS_ETHERNET_BADMULTICAST	EQU	((((S2WIRETYPE_ETHERNET)&$ffff)<<16)|$0000)
;
; This count will record the number of times a received packet tripped
; the hardware's multicast filtering mechanism but was not actually in
; the current multicast table.
;

S2SS_ETHERNET_RETRIES		EQU	((((S2WIRETYPE_ETHERNET)&$ffff)<<16)|$0001)
;
; This count records the total number of retries which have resulted
; from transmissions on this board.
;


	ENDC	SANA2_SANA2SPECIALSTATS_I

