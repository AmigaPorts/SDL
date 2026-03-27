---
title: FD/rexxsyslib_lib.fd
manual: autodocs-2.0
chapter: autodocs-2.0
section: fd-rexxsyslib-lib-fd
functions: []
libraries: []
---

# FD/rexxsyslib_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* "rexxsyslib.library"
##base _RexxSysBase
##bias 30
*--- functions in V33 or higher (distributed as Release 1.2) ---
*
##private
*--- (16 function slots reserved here) ---
##bias 126
##public
*
CreateArgstring(string,length)(a0,d0)
DeleteArgstring(argstring)(a0)
LengthArgstring(argstring)(a0)
CreateRexxMsg(port,extension,host)(a0/a1,d0)
DeleteRexxMsg(packet)(a0)
ClearRexxMsg(msgptr,count)(a0,d0)
FillRexxMsg(msgptr,count,mask)(a0,d0/d1)
IsRexxMsg(msgptr)(a0)
*
##private
*--- (46 function slots reserved here) ---
##bias 450
##public
*
LockRexxBase(resource)(d0)
UnlockRexxBase(resource)(d0)
*
##end

