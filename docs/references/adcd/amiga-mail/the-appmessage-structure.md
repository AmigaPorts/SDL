---
title: The AppMessage Structure
manual: amiga-mail
chapter: amiga-mail
section: the-appmessage-structure
functions: []
libraries: []
---

# The AppMessage Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When Workbench notifies an application of AppWindow, AppIcon, or
AppMenuItem activity, it sends an AppMessage to the application's message
port (from <workbench/workbench.h>):


```c
    #define      AM_VERSION     1

    struct AppMessage {
        struct Message am_Message;    /* standard message structure */
        UWORD am_Type;                /* message type */
        ULONG am_UserData;            /* application specific */
        ULONG am_ID;                  /* application definable ID */
        LONG am_NumArgs;              /* # of elements in arglist */
        struct WBArg *am_ArgList;     /* the arguments themselves */
        UWORD am_Version;             /* will be AM_VERSION */
        UWORD am_Class;               /* message class */
        WORD am_MouseX;               /* mouse x position of event */
        WORD am_MouseY;               /* mouse y position of event */
        ULONG am_Seconds;             /* current system clock time */
        ULONG am_Micros;              /* current system clock time */
        ULONG am_Reserved[8];
    };
```
The AppMessage's am_Type field tells the application which type of
AppObject the message is about.  The field will be:


        MTYPE_APPWINDOW if the message is about an AppWindow,
        MTYPE_APPICON if the message is about an AppIcon, or
        MTYPE_APPMENUITEM if the message is about an AppMenuItem.
When an application creates an AppObject, it can assign the AppObject
application specific data (most likely a pointer) and an ID.  Workbench
will pass an AppObject's data and ID back to the application when it sends
an AppMessage about the AppObject.  The AppMessage's am_UserData and am_ID
fields hold the user data and the ID.

The am_NumArgs field tells how many icons were involved in the user's
AppObject action.  For an AppWindow or AppIcon, am_NumArgs is the number
of icons the user dropped on the AppWindow or AppIcon.  For an
AppMenuItem, am_NumArgs represents the number of icons that were selected
when the user selected this AppMenuItem.  If no icons were selected during
an AppMenuItem event or the user double-clicked on an AppIcon, am_NumArgs
will be zero. Workbench does not send AppMessages if the user
double-clicks an AppWindow.

The am_ArgList field is a pointer to a list of WBArgs (from
<workbench/startup.h>) corresponding to each icon dropped (or selected).
If there were no icons dropped or selected, this field will be NULL.

For future expansion possibilities, the AppMessage structure has a version
number.  The version number is #defined as AM_VERSION in
<workbench/workbench.h>.

The am_MouseX and am_MouseY fields apply only to AppWindows and contain
the coordinates of the mouse pointer when the user dropped the icon(s).
These coordinates are relative to the AppWindow's upper left corner.

The am_Seconds and am_Micros fields represent the time that the event took
place.

Any remaining fields are undefined at present and should be set to NULL.

