---
title: intuition.library (basename: _IntuitionBase)
manual: amiga-mail
chapter: amiga-mail
section: intuition-library-basename-intuitionbase
functions: [AutoRequest, LockPubScreenList, MakeClass, OpenScreen, OpenWindow, UnlockPubScreenList]
libraries: [intuition.library]
---

# intuition.library (basename: _IntuitionBase)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

AddClass(class)(a0)                     - Make a public class available
```c
                                          (V36)
```
BuildEasyRequestArgs(window,easyStruct,idcmp,args)(a0/a1,d0/a3)
```c
                                        - Simple creation of system
                                          request. (V36)
```
ChangeWindowBox(window,left,top,width,height)(a0,d0/d1/d2/d3)
```c
                                        - Change window position and
                                          dimensions. (V36)
```
DisposeObject(object)(a0)               - Deletes a 'boopsi' object. (V36)
DrawImageState(rp,image,leftOffset,topOffset,state,drawInfo)
```c
                                         (a0/a1,d0/d1/d2/a2)
                                        - Draw an (extended) Intuition
                                          Image with
```
EasyRequestArgs(window,easyStruct,idcmpPtr,args)(a0/a1/a2/a3)
```c
                                        - Easy alternative to AutoRequest()
                                         . (V36)
```
EraseImage(rp,image,leftOffset,topOffset)(a0/a1,d0/d1)
```c
                                        - Erases an Image. (V36)
```
FreeClass(classPtr)(a0)                 - Frees a boopsi class created by
```c
                                          MakeClass(). (V36)
```
FreeScreenDrawInfo(screen,drawInfo)(a0/a1)
```c
                                        - Finish using a DrawInfo
                                          structure. (V36)
```
GadgetMouse(gadget,gInfo,mousePoint)(a0/a1/a2)
```c
                                        - Calculate gadget-relative mouse
                                          position. (V36)
```
GetAttr(attrID,object,storagePtr)(d0/a0/a1)
```c
                                        - Inquire the value of some
                                          attribute of an object. (V36)
```
GetDefaultPubScreen(nameBuffer)(a0)     - Get name of default public
```c
                                          screen. (V36)
```
GetScreenDrawInfo(screen)(a0)           - Get pointer to rendering
```c
                                          information. (V36)
```
LockPubScreen(name)(a0)                 - Prevent a public screen from
```c
                                          closing. (V36)
```
LockPubScreenList()()                   - Prevent changes to the system
```c
                                          list. (V36)
```
MakeClass(classID,superClassID,superClassPtr,instanceSize,flags)
```c
                                         (a0/a1/a2,d0/d1)
                                        - Create and initialize a boopsi
                                          class. (V36)
```
MoveWindowInFrontOf(window,behindWindow)(a0/a1)
```c
                                        - Arrange the relative depth of a
                                          window. (V36)
```
NewObjectA(class,classID,tagList)(a0/a1/a2)
```c
                                        - Create an object from a class.
                                          (V36)
```
NextObject(objectPtrPtr)(a0)            - Iterate through the object on an
```c
                                          Exec list. (V36)
```
NextPubScreen(screen,namebuf)(a0/a1)    - Identify next public screen in
```c
                                          the cycle. (V36)
```
ObtainGIRPort(gInfo)(a0)                - Set up a RastPort for a custom
```c
                                          gadget. (V36)
```
OpenScreenTagList(newScreen,tagList)(a0/a1)
```c
                                        - Also stack-based amiga.lib stub
                                          OpenScreenTags().  OpenScreen() with TagItem extension array. (V36)
```
OpenWindowTagList(newWindow,tagList)(a0/a1)
```c
                                        - Also stack-based amiga.lib stub
                                          OpenWindowTags().  OpenWindow() with TagItem extension. (V36)
```
PointInImage(point,image)(d0/a0)        - Tests whether an image
```c
                                          "contains" a point. (V36)
```
PubScreenStatus(screen,statusFlags)(a0,d0)
```c
                                        - Change status flags for a public
                                          screen. (V36)
```
QueryOverscan(displayID,rect,oScanType)(a0/a1,d0)
```c
                                        - Inquire about a standard
                                          overscan region. (V36)
```
ReleaseGIRPort(rp)(a0)                  - Release a custom gadget
```c
                                          RastPort. (V36)
```
RemoveClass(classPtr)(a0)               - Make a public boopsi class
```c
                                          unavailable. (V36)
```
ResetMenuStrip(window,menu)(a0/a1)      - Re-attach a menu strip to a
```c
                                          window. (V36)
```
SetAttrsA(object,tagList)(a0/a1)        - Specify attribute values for an
```c
                                          object. (V36)
```
SetDefaultPubScreen(name)(a0)           - Choose a new default public
```c
                                          screen. (V36)
```
SetEditHook(hook)(a0)                   - Set global processing for string
```c
                                          gadgets. (V36)
```
SetGadgetAttrsA(gadget,window,requester,tagList)(a0/a1/a2/a3)
```c
                                        - Specify attribute values for a
                                          boopsi gadget. (V36)
```
SetMouseQueue(window,queueLength)(a0,d0)- Change limit on pending mouse
```c
                                          messages. (V36)
```
SetPubScreenModes(modes)(d0)            - Establish global public screen
```c
                                          behavior. (V36)
```
SysReqHandler(window,idcmpPtr,waitInput)(a0/a1,d0)
```c
                                        - Handle system requester input.
                                          (V36)
```
UnlockPubScreen(name,screen)(a0/a1)     - Release lock on a public screen.
```c
                                          (V36)
```
UnlockPubScreenList()()                 - Release public screen list
```c
                                          semaphore. (V36)
```
ZipWindow(window)(a0)                   - Change window to "alternate"

                                          position and

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [LockPubScreenList — intuition.library](../autodocs/intuition.library.md#lockpubscreenlist)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [UnlockPubScreenList — intuition.library](../autodocs/intuition.library.md#unlockpubscreenlist)
