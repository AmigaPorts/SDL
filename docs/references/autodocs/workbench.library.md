# workbench.library — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 8

## Function Index

- **AddAppIconA** (V36) — 
- **AddAppMenuItemA** (V36) — 
- **AddAppWindowA** (V36) — 
- **RemoveAppIcon** (V36) — 
- **RemoveAppMenuItem** (V36) — 
- **RemoveAppWindow** (V36) — 
- **UpdateWorkbench** (V37) — 
- **WBInfo** (V39) — 

## Functions

### workbench.library/AddAppIconA (V36)

**Synopsis:**
```c
AppIcon = AddAppIconA(id, userdata, text, msgport,
               lock, diskobj, taglist)

struct AppIcon *AddAppIconA(ULONG, ULONG, CONST_STRPTR,
 struct MsgPort *, BPTR, struct DiskObject *,
 const struct TagItem *);

Alternate, varargs version:
struct AppIcon *AddAppIcon(ULONG, ULONG, CONST_STRPTR,
                    struct MsgPort *, BPTR,
                    struct DiskObject *,
                    tag1, data1,
                    tag2, data2,
                    ...
                    TAG_END );
```

**Description:**
Attempt to add an icon to Workbench's list of AppIcons.  If
successful, the icon is displayed on the Workbench backdrop (the
same place disk icons are displayed).

This call is provided to allow applications to be notified when
a graphical object (not neccessarely associated with a file)
gets 'manipulated'.

The notification consists of an AppMessage (found in workbench.h/i)
of type 'AMTYPE_APPICON' arriving at the message port you specified.

The types of 'manipulation' that can occur are:

1. Double-clicking on the icon.  am_NumArgs will be zero and
   am_ArgList will be NULL.
2. Dropping an icon or icons on your AppIcon.  am_NumArgs will
   be the number of icons dropped on your AppIcon plus one.
   am_ArgList will be an array of pointers to WBArg structures.
   Refer to the 'WBStartup Message' section of the RKM for more info.
3. Dropping your AppIcon on another icon.  NOT SUPPORTED.
4. Invoking an "Icons" menu item with your icon selected. (V44)
   You have to tell Workbench which menu items your icon
   responds to using the tag item list you provide to AddAppIconA().
   When one of the supported menu items is invoked, you
   will receive an AppMessage with the am_Class entry set to
   a value out of AMCLASSICON_Open..AMCLASSICON_EmptyTrash,
   corresponding to the menu item used.

**Inputs:**
WBAPPICONA_SupportsOpen (BOOL) -- Set this to TRUE if your
    AppIcon should respond to the "Open" menu, to FALSE
    otherwise. Note that with this attribute set to FALSE,
    users will still be able to double-click on your AppIcon
    and drop icons on it. This attribute solely controls
    whether the "Open" menu item will be available.

    This tag defaults to TRUE. (V44)

WBAPPICONA_SupportsCopy (BOOL) -- Set this to TRUE if your
    AppIcon should respond to the "Copy" menu, to FALSE
    otherwise.

    This tag defaults to FALSE. (V44)

WBAPPICONA_SupportsRename (BOOL) -- Set this to TRUE if your
    AppIcon should respond to the "Rename" menu, to FALSE
    otherwise.

    This tag defaults to FALSE. (V44)

WBAPPICONA_SupportsInformation (BOOL) -- Set this to TRUE if your
    AppIcon should respond to the "Information" menu, to FALSE
    otherwise.

    This tag defaults to FALSE. (V44)

WBAPPICONA_SupportsSnapshot (BOOL) -- Set this to TRUE if your
    AppIcon should respond to the "Snapshot" menu, to FALSE
    otherwise.

    This tag defaults to FALSE. (V44)

WBAPPICONA_SupportsUnSnapshot (BOOL) -- Set this to TRUE if your
    AppIcon should respond to the "UnSnapshot" menu, to FALSE
    otherwise.

    This tag defaults to FALSE. (V44)

WBAPPICONA_SupportsLeaveOut (BOOL) -- Set this to TRUE if your
    AppIcon should respond to the "Leave Out" menu, to FALSE
    otherwise.

    This tag defaults to FALSE. (V44)

WBAPPICONA_SupportsPutAway (BOOL) -- Set this to TRUE if your
    AppIcon should respond to the "Put Away" menu, to FALSE
    otherwise.

    This tag defaults to FALSE. (V44)

WBAPPICONA_SupportsDelete (BOOL) -- Set this to TRUE if your
    AppIcon should respond to the "Delete" menu, to FALSE
    otherwise.

    This tag defaults to FALSE. (V44)

WBAPPICONA_SupportsFormatDisk (BOOL) -- Set this to TRUE if your
    AppIcon should respond to the "Format Disk" menu, to FALSE
    otherwise.

    This tag defaults to FALSE. (V44)

WBAPPICONA_SupportsEmptyTrash (BOOL) -- Set this to TRUE if your
    AppIcon should respond to the "Empty Trash" menu, to FALSE
    otherwise.

    This tag defaults to FALSE. (V44)

WBAPPICONA_PropagatePosition (BOOL) -- Set this to TRUE if you
    want the AppIcon's position to be propagated back to the
    original DiskObject you passed to this function. By
    default, Workbench will make a copy of that DiskObject's
    icon imagery, allowing you to free the DiskObject.
    But if you specify "WBAPPICONA_PropagatePosition,TRUE,"
    Workbench will assume that you will not free it and
    that the AppIcon's current position should be stored
    in its do_CurrentX/do_CurrentY members.

    This tag defaults to FALSE. (V44)

WBAPPICONA_RenderHook (struct Hook *) -- Pointer to a hook that
    will be invoked when rendering your AppIcon. With this hook
    and WorkbenchControlA() you can create dynamic or animated
    AppIcons. Your hook will be called with the following
    parameters and has to return a result value:

    result = hookFunc(hook,reserved,arm)
      D0               A0     A2     A1

    LONG hookFunc(struct Hook *hook,APTR reserved,
           struct AppIconRenderMsg *arm);

    The reserved parameter will be set to NULL (V44).

    If your hook code returns TRUE, the AppIcon's regular image
    will be drawn. If your code returns FALSE, the regular image
    will not be drawn; this allows you to do all the icon's on-screen
    rendering with the exception of the icon image used when dragging
    the icon on the screen.

    The render message contents are as follows:

 arm_RastPort
     A pointer to the RastPort to render into.

 arm_Icon
     A pointer to the Icon to be rendered.

 arm_Label
     A pointer to the label text to be printed
     below the icon.

 arm_Tags
     Further control tags which you should pass on
     to icon.library/DrawIconStateA, should you
     call this routine.

 arm_Left
 arm_Top
     Rendering origin; note that these coordinates
     DO NOT take the embossing border sizes into
     account.

 arm_Width
 arm_Height
     Size of the Icon's image area; you should limit
     your drawing to this area.

 arm_State
     An icon drawing state, such as used by
     icon.library/DrawIconStateA.

    Note that all the data in the render message is read-only.


    This tag defaults to NULL. (V44)

WBAPPICONA_NotifySelectState (BOOL) -- Set this tag to TRUE
    if you want to be be notified whenever the AppIcon becomes
    selected or unselected. You will hear only state transitions,
    i.e. changes from selected to unselected state and the other
    way round. On a state transition you will receive AppMessages
    with the AppMessage->am_Class member set to AMCLASSICON_Selected
    or AMCLASSICON_Unselected, respectively.

    This tag defaults to FALSE. (V44)

**Result:**
AppIcon - a pointer to an AppIcon structure which you pass to
   RemoveAppIcon when you want to remove the icon
   from Workbench's list of AppIcons.  NULL
   if Workbench was unable to add your icon; typically
   happens when Workbench is not running or under low
   memory conditions.

**Example:**
```c
You could design a print-spooler icon and add it to the Workbench.
Any file dropped on the print spooler would be printed.  If the
user double-clicked (opened) your printer-spooler icon, you could
open a window showing the status of the print spool, allow changes
to print priorities, allow deletions, etc.  If you registered this
window as an 'AppWindow' (explained in
workbench.library/AddAppWindow) files could also be dropped in the
window and added to the spool.
```

**Notes:**
For this function call to succeed, Workbench must be open. This
means that the LoadWB command was executed and the Workbench
screen has been opened.

**Bugs:**
In workbench.library versions 36 through 40 Info cannot be obtained
on appicons.

**See also:** workbench.library/RemoveAppIcon
workbench.library/WorkbenchControlA
icon.library/DrawIconStateA

---

### workbench.library/AddAppMenuItemA (V36)

**Synopsis:**
```c
AppMenuItem = AddAppMenuItemA(id, userdata, text, msgport, taglist)

struct AppMenuItem *AddAppMenuItemA(ULONG, ULONG, CONST_STRPTR,
                             struct MsgPort *,
                             const struct TagItem *);

Alternate, varargs version:
struct AppMenuItem *AddAppMenuItem(ULONG, ULONG, CONST_STRPTR,
                            struct MsgPort *,
                            tag1, data1,
                            tag2, data2,
                            ...
                            TAG_END );
```

**Description:**
Attempt to add the text as a menu item to Workbench's list
of AppMenuItems (the 'Tools' menu strip).

**Inputs:**
WBAPPMENUA_CommandKeyString (STRPTR) -- Command key to assign to
    this AppMenu. This must be a NUL-terminated string. If the
    string is empty, it will be ignored. Also, if the command key
    is already in use by a different menu item it will be ignored,
    too. In any case, only the first character of the string will
    be used (V44).

    This tag defaults to NULL.

WBAPPMENUA_GetKey (ULONG *) -- To add menus with sub menu items,
    you need to add a menu item first which the sub items will
    be added to later. In order to do this, add the item the sub
    items should be attached to and use the WBAPPMENUA_GetKey tag
    to obtain a key value. This key value is to be used later with
    the WBAPPMENUA_UseKey tag (V44).

    This feature was introduced in workbench.library 44.1511, it
    does not work in any of the older Workbench releases.

    This tag defaults to NULL.

WBAPPMENUA_GetTitleKey (ULONG *) -- To add new entries to the
    Workbench menu strip you first need to create a new title to
    which the new menu items can be attached later. To do this,
    first create a new menu entry and use the
    WBAPPMENUA_GetTitleKey tag to obtain a key value. This key
    value is to be used later with the WBAPPMENUA_UseKey tag (V45).

    This tag defaults to NULL.

WBAPPMENUA_UseKey (ULONG) -- When adding a menu item with the
    WBAPPMENUA_UseKey tag, using a key value obtained by a previous
    invocation of AddAppMenuItemA(), the new menu item will be
    added as a sub item (V44).

    If the key you provide was obtained via the
    WBAPPMENUA_GetTitleKey tag, then the item you add will be
    attached to the respective menu entry (V45).

    This tag defaults to NULL.

**Result:**
AppMenuItem - a pointer to an appmenuitem structure which you pass to
       RemoveAppMenuItem when you want to remove the menuitem
       from Workbench's list of AppMenuItems.  NULL if
       workbench was unable to add your menu item; typically
       happens when Workbench is not running or under low
       memory conditions.

   Starting with V44 NULL will be returned if you attempt to
   add an AppMenu item to a menu which already contains 63
   menu items.

**Example:**
```c
Here is how you create a menu item with two sub items attached:

struct MsgPort * port;
struct AppMenuItem * item;
struct AppMenuItem * sub1;
struct AppMenuItem * sub2;
ULONG key;

// IMPORTANT: you *must* initialize the key to zero
//            for backwards compatibility!

key = 0;
item = AddAppMenuItem(0,0,"AppMenu item with two sub items",port,
    WBAPPMENUA_GetKey,&key,
TAG_DONE);

// IMPORTANT: always check for the key value to be non-zero!
if(key != 0 && item != NULL)
{
    sub1 = AddAppMenuItem(0,0,"Sub item #1",port,
 WBAPPMENUA_UseKey,key,
    TAG_DONE);

    sub2 = AddAppMenuItem(0,0,"Sub item #2",port,
 WBAPPMENUA_UseKey,key,
    TAG_DONE);

    // ... do something useful with the menus ...

    RemoveAppMenuItem(sub1);
    RemoveAppMenuItem(sub2);
}

RemoveAppMenuItem(item);
```

**Notes:**
For this function call to succeed, Workbench must be open. This
means that the LoadWB command was executed and the Workbench
screen has been opened.

You can add only a maximum of 62 menu items to the "Tools" menu.
Only a maximum of 31 sub items can be added to a menu item.

When you add a new menu item which sub items should be attached
to, the new menu item will not appear until after the first sub
item has been attached. The same is true when adding new menu
entries to the Workbench menu strip; titles will not appear
until you add the first menu item.

You can add only a maximum of 27 menu entries to the Workbench
menu strip. Only a maximum of 63 menu items can be added to
a menu entry.

**Bugs:**
workbench.library V37 through V40 does not limit the number of menu
items to 63. Any menu items after the 63rd will not be selectable.
This bug was fixed in V44.

**See also:** workbench.library/RemoveAppMenuItem

---

### workbench.library/AddAppWindowA (V36)

**Synopsis:**
```c
AppWindow = AddAppWindowA(id, userdata, window, msgport, taglist)

struct AppWindow *AddAppWindowA(ULONG, ULONG, struct Window *,
                         struct MsgPort *,
                         const struct TagItem *);

Alternate, varargs version:
struct AppWindow *AddAppWindow(ULONG, ULONG, struct Window *,
                        struct MsgPort *
                        tag1, data1,
                        tag2, data2,
                        ...
                        TAG_END );
```

**Description:**
Attempt to add the window to Workbench's list of AppWindows.
Normally non-Workbench windows (those not opened by Workbench)
cannot have icons dropped in them.  This call is provided to
allow applications to be notified when an icon or icons get
dropped inside a window that they have registered with Workbench.
The notification consists of an AppMessage (found in workbench.h/i)
of type 'AMTYPE_APPWINDOW' arriving at the message port you specified.
What you do with the list of icons (pointed to by am_ArgList) is
up to you, but generally you would want to call GetDiskObjectNew on
them.

**Inputs:**
id - this variable is strictly for your own use and is ignored by
     Workbench.  Typical uses in C are in switch and case statements,
     and in assembly language table lookup.
userdata - this variable is strictly for your own use and is ignored
    by Workbench.
window - pointer to window to add.
msgport - pointer to message port Workbench will use to send you an
   AppMessage message of type 'AMTYPE_APPWINDOW' when your
   window gets an icon or icons dropped in it.
taglist - ptr to a list of tag items.  Must be NULL for V2.0.

**Result:**
AppWindow - a pointer to an AppWindow structure which you pass to
     RemoveAppWindow when you want to remove the window
     from Workbench's list of AppWindows.  NULL
     if Workbench was unable to add your window; typically
     happens when Workbench is not running or under low
     memory conditions.

**Notes:**
The V2.0 icon editor is an example of an AppWindow.  Note that app
window applications generally want to call GetDiskObjectNew
(as opposed to GetDiskObject) to get the disk object for the icon
dropped in the window.

For this function call to succeed, Workbench must be open. This
means that the LoadWB command was executed and the Workbench
screen has been opened.

When removing an AppWindow, all its drop zones will be automatically
removed.

**See also:** workbench.library/AddAppWindowDropZoneA
workbench.library/RemoveAppWindow

---

### workbench.library/RemoveAppIcon (V36)

**Synopsis:**
```c
success = RemoveAppIcon(AppIcon)

BOOL RemoveAppIcon(struct AppIcon *);
```

**Description:**
Attempt to remove an AppIcon from Workbench's list of AppIcons.

**Inputs:**
AppIcon - pointer to an AppIcon structure returned by AddAppIcon.

**Result:**
success - TRUE if the icon could be removed, FALSE otherwise.

**Notes:**
As with anything that deals with asynchronous operation, you will
need to do a final check for messages on your AppMessage port for
messages that may have come in between the last time you checked
and the call to remove the AppIcon.

**See also:** workbench.library/AddAppIconA

---

### workbench.library/RemoveAppMenuItem (V36)

**Synopsis:**
```c
success = RemoveAppMenuItem(AppMenuItem)

BOOL RemoveAppMenuItem(struct AppMenuItem *);
```

**Description:**
Attempt to remove an AppMenuItem from Workbench's list
of AppMenuItems.

**Inputs:**
AppMenuItem - pointer to an AppMenuItem structure returned by
       AddAppMenuItem.

**Result:**
success - TRUE if the menu could be removed, FALSE otherwise.

**Notes:**
As with anything that deals with asynchronous operation, you will
need to do a final check for messages on your AppMessage port for
messages that may have come in between the last time you checked
and the call to removed the AppMenuItem.

**See also:** workbench.library/AddAppMenuItemA

---

### workbench.library/RemoveAppWindow (V36)

**Synopsis:**
```c
success = RemoveAppWindow(AppWindow)

BOOL RemoveAppWindow(struct AppWindow *);
```

**Description:**
Attempt to remove an appwindow from Workbench's list of AppWindows.

**Inputs:**
AppWindow - pointer to an AppWindow structure returned by
     AddAppWindow.

**Result:**
success - TRUE if the window could be removed, FALSE otherwise.

**Notes:**
As with anything that deals with asynchronous operation, you will
need to do a final check for messages on your AppMessage port for
messages that may have come in between the last time you checked
and the call to removed the AppWindow.

Before the AppWindow is removed, all its drop zones will be removed
first. There is no need for you to call RemoveAppWindowDropZone()
for every single one.

**See also:** workbench.library/AddAppWindowA
workbench.library/RemoveAppWindowDropZone

---

### workbench.library/UpdateWorkbench (V37)

**Synopsis:**
```c
UpdateWorkbench(name, parentlock, action)

VOID UpdateWorkbench(CONST_STRPTR, BPTR, LONG);
```

**Description:**
This function does the "magic" of letting Workbench know that
an object has been added, changed, or removed. The name is
the name of the object, the lock is a lock on the directory that
contains the object. The action determines what has happened.
If UPDATEWB_ObjectAdded, the object is either NEW or has CHANGED.
If UPDATEWB_ObjectRemoved, the object has been deleted.

**Inputs:**
name - Name of the object (without the .info)

parentlock - Lock on the object's parent directory.

action - UPDATEWB_ObjectAdded for a new or changed object
  UPDATEWB_ObjectRemoved for a deleted object

**Result:**
Workbench will update its display, if needed. An object that has
been deleted will be removed from the display. An object that is
new will be added to the respective display if it is not already
there; if it is already there, its appearance will be changed if
necessary.

**Example:**
```c
// Remove the object named "Prefs" from the SYS: drawer display;
// note that this will affect only the display, the drawer will
// still remain on the file system, and telling Workbench to
// rescan the drawer will reveal it again.

BPTR lock,old_dir;

lock = Lock("SYS:",SHARED_LOCK);
UpdateWorkbench("Prefs",lock,UPDATEWB_ObjectRemoved);
UnLock(lock);

// Change the name of the file "RAM:Thursday"
// to "Friday"; this works by first removing the
// object from the display, renaming the object
// and then telling Workbench that the object has
// changed.

lock = Lock("RAM:",SHARED_LOCK);
UpdateWorkbench("Thursday",lock,UPDATEWB_ObjectRemoved);
old_dir = SetCurrentDir(lock);
Rename("Thursday","Friday");
SetCurrentDir(old_dir);
UpdateWorkbench("Friday",lock,UPDATEWB_ObjectAdded);
UnLock(lock);
```

**Notes:**
Note that saying that a DISK icon has been deleted may not do
much as disk icons must continue to be visible. Thus, this was
a NO-OP in previous versions of workbench.library. Starting
from V51, it changes the disk icon to the default if the disk
icon file does actually no longer exist.

**See also:** icon.library/PutDiskObject
icon.library/DeleteDiskObject

---

### workbench.library/WBInfo (V39)

**Synopsis:**
```c
worked = WBInfo(lock, name, screen)

ULONG WBInfo(BPTR, CONST_STRPTR, struct Screen *);
```

**Description:**
This is the LVO that Workbench calls to bring up the Icon Information
requester.  External applications may also call this requester.
In addition, if someone were to wish to replace this requester
with another one, they could do so via a SetFunction.

**Inputs:**
lock   - A lock on the parent directory
name   - The name of the icon contained within above directory
screen - A screen pointer on which the requester is to show up

**Result:**
worked - Returns TRUE if the requester came up, FALSE if it did not.

**Notes:**
Note that this LVO may be called many times by different tasks
before other calls return.  Thus, the code must be 100% re-entrant.

**See also:** icon.library

---
