---
title: Includes/clib/wb_protos.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-clib-wb-protos-h
functions: []
libraries: []
---

# Includes/clib/wb_protos.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef  CLIB_WB_PROTOS_H
#define  CLIB_WB_PROTOS_H
/*
**	$Filename: clib/wb_protos.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 37.3 $
**	$Date: 91/03/04 $
**
**	C prototypes. For use with 32 bit integers only.
**
**	(C) Copyright 1990-1999 Amiga, Inc.
**	    All Rights Reserved
*/
/*--- functions in V36 or higher (distributed as Release 2.0) ---*/
#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

struct AppWindow *AddAppWindowA( unsigned long id, unsigned long userdata,
	struct Window *window, struct MsgPort *msgport,
	struct TagItem *taglist );
struct AppWindow *AddAppWindow( unsigned long id, unsigned long userdata,
	struct Window *window, struct MsgPort *msgport, Tag tag1, ... );

BOOL RemoveAppWindow( struct AppWindow *appWindow );

struct AppIcon *AddAppIconA( unsigned long id, unsigned long userdata,
	UBYTE *text, struct MsgPort *msgport, struct FileLock *lock,
	struct DiskObject *diskobj, struct TagItem *taglist );
struct AppIcon *AddAppIcon( unsigned long id, unsigned long userdata,
	UBYTE *text, struct MsgPort *msgport, struct FileLock *lock,
	struct DiskObject *diskobj, Tag tag1, ... );

BOOL RemoveAppIcon( struct AppIcon *appIcon );

struct AppMenuItem *AddAppMenuItemA( unsigned long id, unsigned long userdata,
	UBYTE *text, struct MsgPort *msgport, struct TagItem *taglist );
struct AppMenuItem *AddAppMenuItem( unsigned long id, unsigned long userdata,
	UBYTE *text, struct MsgPort *msgport, Tag tag1, ... );

BOOL RemoveAppMenuItem( struct AppMenuItem *appMenuItem );


#endif	 /* CLIB_WB_PROTOS_H */

