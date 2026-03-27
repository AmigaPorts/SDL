---
title: FD/commodities_lib.fd
manual: autodocs-2.0
chapter: autodocs-2.0
section: fd-commodities-lib-fd
functions: []
libraries: []
---

# FD/commodities_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* "commodities.library"
##base _CxBase
##bias 30
##public
*--- functions in V36 or higher (distributed as Release 2.0) ---
*
*  OBJECT UTILITIES
*
CreateCxObj(type,arg1,arg2)(d0/a0/a1)
CxBroker(nb,error)(a0,d0)
ActivateCxObj(co,true)(a0,d0)
DeleteCxObj(co)(a0)
DeleteCxObjAll(co)(a0)
CxObjType(co)(a0)
CxObjError(co)(a0)
ClearCxObjError(co)(a0)
SetCxObjPri(co,pri)(a0,d0)
*
*  OBJECT ATTACHMENT
*
AttachCxObj(headObj,co)(a0/a1)
EnqueueCxObj(headObj,co)(a0/a1)
InsertCxObj(headObj,co,pred)(a0/a1/a2)
RemoveCxObj(co)(a0)
*
*  TYPE SPECIFIC
*
##private
commoditiesPrivate1()()
##public
SetTranslate(translator,events)(a0/a1)
SetFilter(filter,text)(a0/a1)
SetFilterIX(filter,ix)(a0/a1)
ParseIX(description,ix)(a0/a1)
*
*  COMMON MESSAGE
*
CxMsgType(cxm)(a0)
CxMsgData(cxm)(a0)
CxMsgID(cxm)(a0)
*
*  MESSAGE ROUTING
*
DivertCxMsg(cxm,headobj,ret)(a0/a1/a2)
RouteCxMsg(cxm,co)(a0/a1)
DisposeCxMsg(cxm)(a0)
*
*  INPUT EVENT HANDLING
*
InvertKeyMap(ansicode,event,km)(d0/a0/a1)
AddIEvents(events)(a0)
##private
*
* FOR USE ONLY BY CONTROLLER PROGRAM
*
commoditiesPrivate2()()
commoditiesPrivate3()()
commoditiesPrivate4()()
##public
##end

