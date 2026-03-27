---
title: commodities.library (basename: _CxBase)  V36
manual: amiga-mail
chapter: amiga-mail
section: commodities-library-basename-cxbase-v36
functions: []
libraries: []
---

# commodities.library (basename: _CxBase)  V36

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ActivateCxObj(co,true)(a0,d0)           - Change the activation state of a
                                          commodity object.
AddIEvents(events)(a0)                  - Add input events to commodities'
```c
                                          input stream. (V36)
```
AttachCxObj(headobj,co)(a0/a1)          - Attach a commodity object to the
                                          end of an existing
ClearCxObjError(co)(a0)                 - Clear the accumulated error
                                          value of a commodity
CreateCxObj(type,arg1,arg2)(d0/a0/a1)   - Create a new commodity object.
```c
                                          (V36)
```
CxBroker(nb,error)(a0,d0)               - Create a commodity broker. (V36)
CxMsgData(cxm)(a0)                      - Obtain a pointer to a commodity
```c
                                          message's data area. (V36)
```
CxMsgID(cxm)(a0)                        - Obtain the ID of a commodity
```c
                                          message. (V36)
```
CxMsgType(cxm)(a0)                      - Obtain the type of a commodity
```c
                                          message. (V36)
```
CxObjError(co)(a0)                      - Obtain a commodity object's
```c
                                          accumulated error. (V36)
```
CxObjType(co)(a0)                       - Obtain the type of a commodity
```c
                                          object. (V36)
```
DeleteCxObj(co)(a0)                     - Delete a commmodity object. (V36)

DeleteCxObjAll(co)(a0)                  - Recursively delete a tree of
                                          commodity objects.
DisposeCxMsg(cxm)(a0)                   - Delete a commodity message. (V36)

DivertCxMsg(cxm,headobj,ret)(a0/a1/a2)  - Send a commodity message down an
```c
                                          object list. (V36)
```
EnqueueCxObj(headobj,co)(a0/a1)         - Insert a commodity object within
                                          a list of objects
InsertCxObj(headobj,co,pred)(a0/a1/a2)  - Insert a commodity object in a
                                          list after a given
InvertKeyMap(ansicode,event,km)(d0/a0/a1)
```c
                                        - Generate an input event from an
                                          ANSI code. (V36)
```
ParseIX(description,ix)(a0/a1)          - Initialize an input expression
                                          given a description string.
RemoveCxObj(co)(a0)                     - Remove a commodity object from a
```c
                                          list. (V36)
```
RouteCxMsg(cxm,co)(a0/a1)               - Set the next destination of a
```c
                                          commodity message. (V36)
```
SetCxObjPri(co,pri)(a0,d0)              - Set the priority of a commodity
```c
                                          object. (V36)
```
SetFilter(filter,text)(a0/a1)           - Change the matching condition of
                                          a commodity filter.
SetFilterIX(filter,ix)(a0/a1)           - Change the matching condition of
                                          a commodity filter.
SetTranslate(translator,events)(a0/a1)  - Replace a translator object's

```c
                                          translation list. (V36)
```
