---
title: FD/wb_lib.fd
manual: autodocs-2.0
chapter: autodocs-2.0
section: fd-wb-lib-fd
functions: []
libraries: []
---

# FD/wb_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* "workbench.library"
##base _WorkbenchBase
##bias 30
*--- functions in V36 or higher (distributed as Release 2.0) ---
*
##private
*
wbPrivate1()()
wbPrivate2()()
*
wbPrivate3()()
*
##public
*
AddAppWindowA(id,userdata,window,msgport,taglist)(d0/d1/a0/a1/a2)
*
RemoveAppWindow(appWindow)(a0)
*
AddAppIconA(id,userdata,text,msgport,lock,diskobj,taglist)(d0/d1/a0/a1/a2/a3/a4)
*
RemoveAppIcon(appIcon)(a0)
*
AddAppMenuItemA(id,userdata,text,msgport,taglist)(d0/d1/a0/a1/a2)
*
RemoveAppMenuItem(appMenuItem)(a0)
*
*--- (5 function slots reserved here) ---
##bias 114
*
##end

