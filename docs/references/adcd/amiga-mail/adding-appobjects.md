---
title: Adding AppObjects
manual: amiga-mail
chapter: amiga-mail
section: adding-appobjects
functions: []
libraries: []
---

# Adding AppObjects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The V37 workbench.library is made up of functions to add and remove
AppObjects, two for each type of AppObject:


```c
    struct AppWindow *AddAppWindow( unsigned long myID,
        unsigned long userdata, struct Window *mywindow,
        struct MsgPort *mymsgport, Tag tag1, ...);

    struct AppIcon *AddAppIcon( unsigned long myID,
        unsigned long userdata, UBYTE *mytext,
        struct MsgPort *mymsgport, struct FileLock *mylock,
        struct DiskObject *diskobj, Tag tag1, ... );

    struct AppMenuItem *AddAppMenuItem( unsigned long myid,
         unsigned long userdata, UBYTE *menutext,
         struct MsgPort *mymsgport, Tag tag1, ... );

    BOOL RemoveAppWindow( struct AppWindow *appWindow );

    BOOL RemoveAppIcon( struct AppIcon *appIcon );

    BOOL RemoveAppMenuItem( struct AppMenuItem *appMenuItem );
```
The "AddApp" functions have several parameters in common.  The myID and
userdata parameters are values the application assigns to the AppObject.
Workbench puts these values in the AppMessage's am_ID and am_UserData
fields when it sends an AppMessage about an AppObject.  If an application
receives AppMessages about several AppObjects at the same message port,
the application can use the am_ID field to tell which AppObject Workbench
is talking about.

The mymsgport field tells Workbench where to send this AppObject's
AppMessages.  To make it easy to distinguish AppMessages from other types
of messages, an application should devote a message port exclusively to
AppMessages.

In the future, these AddApp functions will be able to process tag pairs in
the parameter list.  Currently, there are no tags defined for any of the
AppObject functions.

All of the AddApp functions return a NULL if the function failed otherwise
they return a pointer to a private structure.  The pointer serves only as
a handle for the application to pass to the "RemoveApp" functions.  Do not
use it for anything else!

Each of the RemoveApp functions removes one type of AppObject using the
handle returned by the corresponding AddApp function.  At present, these
functions all return TRUE, but this behavior is not guaranteed to continue
in the future.

