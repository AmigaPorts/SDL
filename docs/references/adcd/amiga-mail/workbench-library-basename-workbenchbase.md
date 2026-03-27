---
title: workbench.library (basename: _WorkbenchBase)
manual: amiga-mail
chapter: amiga-mail
section: workbench-library-basename-workbenchbase
functions: []
libraries: []
---

# workbench.library (basename: _WorkbenchBase)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

AddAppIconA(id,userdata,text,msgport,lock,diskobj,taglist)
```c
                                         (d0/d1/a0/a1/a2/a3/a4)
                                        - Also stack-based amiga.lib stub
                                          AddAppIcon().  Add an icon to workbench's list of appicons.        (V36)
```
AddAppMenuItemA(id,userdata,text,msgport,taglist)(d0/d1/a0/a1/a2)
```c
                                        - Also stack-based amiga.lib stub
                                          AddAppMenuItem().  Add a menuitem to workbench's list of appmenuitems (V36)
```
AddAppWindowA(id,userdata,window,msgport,taglist)(d0/d1/a0/a1/a2)
```c
                                        - Also stack-based amiga.lib stub
                                          AddAppWindow() add a window to workbench's list of appwindows.  (V36)
```
RemoveAppIcon(appIcon)(a0)              - Remove an icon from workbench's
```c
                                          list            (V36)
```
RemoveAppMenuItem(appMenuItem)(a0)      - Remove a menuitem from
```c
                                          workbench's list      (V36)
```
RemoveAppWindow(appWindow)(a0)          - Remove a window from workbench's

```c
                                          list         (V36)
```
