---
title: include/dos/notify.h
manual: autodocs-3.5
chapter: autodocs-3.5
section: include-dos-notify-h
functions: []
libraries: []
---

# include/dos/notify.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef DOS_NOTIFY_H
#define DOS_NOTIFY_H
/*
**
**	$VER: notify.h 36.8 (29.8.1990)
**	Includes Release 44.1
**
**	dos notification definitions
**
**	(C) Copyright 1989-1999 Amiga, Inc.
**	    All Rights Reserved
**
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif

#ifndef EXEC_TASKS_H
#include <exec/tasks.h>
#endif


/* use of Class and code is discouraged for the time being - we might want to
   change things */
/* --- NotifyMessage Class ------------------------------------------------ */
#define NOTIFY_CLASS	0x40000000

/* --- NotifyMessage Codes ------------------------------------------------ */
#define NOTIFY_CODE	0x1234


/* Sent to the application if SEND_MESSAGE is specified.		    */

struct NotifyMessage {
```c
    struct Message nm_ExecMessage;
    ULONG  nm_Class;
    UWORD  nm_Code;
    struct NotifyRequest *nm_NReq;	/* don't modify the request! */
    ULONG  nm_DoNotTouch;		/* like it says!  For use by handlers */
    ULONG  nm_DoNotTouch2;		/* ditto */
```
};

/* Do not modify or reuse the notifyrequest while active.		    */
/* note: the first LONG of nr_Data has the length transfered		    */

struct NotifyRequest {
	UBYTE *nr_Name;
	UBYTE *nr_FullName;		/* set by dos - don't touch */
	ULONG nr_UserData;		/* for applications use */
	ULONG nr_Flags;

	union {

	    struct {
		struct MsgPort *nr_Port;	/* for SEND_MESSAGE */
	    } nr_Msg;

	    struct {
		struct Task *nr_Task;		/* for SEND_SIGNAL */
		UBYTE nr_SignalNum;		/* for SEND_SIGNAL */
		UBYTE nr_pad[3];
	    } nr_Signal;
	} nr_stuff;

	ULONG nr_Reserved[4];		/* leave 0 for now */

	/* internal use by handlers */
	ULONG nr_MsgCount;		/* # of outstanding msgs */
	struct MsgPort *nr_Handler;	/* handler sent to (for EndNotify) */
};

/* --- NotifyRequest Flags ------------------------------------------------ */
#define NRF_SEND_MESSAGE	1
#define NRF_SEND_SIGNAL		2
#define NRF_WAIT_REPLY		8
#define NRF_NOTIFY_INITIAL	16

/* do NOT set or remove NRF_MAGIC!  Only for use by handlers! */
#define NRF_MAGIC	0x80000000

/* bit numbers */
#define NRB_SEND_MESSAGE	0
#define NRB_SEND_SIGNAL		1
#define NRB_WAIT_REPLY		3
#define NRB_NOTIFY_INITIAL	4

#define NRB_MAGIC		31

/* Flags reserved for private use by the handler: */
#define NR_HANDLER_FLAGS	0xffff0000

#endif /* DOS_NOTIFY_H */

