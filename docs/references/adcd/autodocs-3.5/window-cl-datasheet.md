---
title: window_cl/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: window-cl-datasheet
functions: [CloseWindow, GetAttr, MapRawKey, ModifyIDCMP, NewObject, SetMenuStrip, SetWindowTitles, WindowToBack, WindowToFront, ZipWindow]
libraries: [intuition.library, keymap.library]
---

# window_cl/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       window_cl -- create Intuition [Window](autodocs-3.5/include-intuition-intuition-h.md) objects
```
   SUPERCLASS

       rootclass
   REQUIRES

       layout.gadget, drawlist.image
   DESCRIPTION

```c
       This class creates standard Intuition Windows, and intelligently
       handles some ReAction house keeping for KeyBoard Control, Defer
       Layout processing, etc. [Window](autodocs-3.5/include-intuition-intuition-h.md) class properly handles processing
       messages using shared window message ports as well as safely
       closing intuition windows. [Window](autodocs-3.5/include-intuition-intuition-h.md) class will also intialize
       your window's parent layout group properly.

       All windowclass methods and the callback hooks you provide it are
       ran in the context of the task you call windowclass from. Thus if
       your application is a process, DOS is safe to use. However,
       remember the Intuition rules about DOS and IDCMP VERIFY messages.

       Window.class requires layout.gadget.
```
   WINDOW REFRESH

       Usually, when all the graphics in your window are handled by
       ReAction, you should not explicitly set the window refresh method
       to either smart or simple refresh. This is a user preference
       setting, and windowclass will automatically choose it. However,
       if your program for some reason requires one or the other refresh
       method and can not use the other, set the refresh type in your
       window object creation taglist.
   BACKFILL PATTERNS

```c
       Window.class will install the default backfill pattern on any
       window for which you do not pass a pointer to a custom backfill
       hook. The pattern bitmaps are cached by window.class, minimizing
       memory usage.

       If your windows have elements that look bad or do not work with
       a backfill pattern, install the default NULL backfill to the
       layout group(s) containing them.

       The backfill installed by window.class is NOT a standard, global
       window layer backfill hook. It is in fact passed to each of the
       layout groups of the window, which will install it during
       refreshes. This approach was chosen because datatypes fail to
       render correctly if their background has been backfilled. This
       method has the side effect that a gadget that is not aware of
       ReAction's method to install a backfill will only have a
       backfill during window refresh (GM_RENDER coming through from
       the parent layout), not during GM_HANDLEINPUT. To make the
       class use the backfill during input handling, it should have
       GA_BackFill as a settable attribute, and install that
       backfill hook before erasing its imagery.
```
   METHODS

```c
       OM_NEW -- Passed to superclass first, defaults set, then OM_SET.

       OM_SET -- Passed to superclass first, then custom tags set.

       OM_GET -- Returns requested setting or passed to superclass

       OM_DISPOSE -- Child object disposed then passed to superclass.

       [WM_OPEN](autodocs-3.5/window-cl-wm-open.md) -- Locks default pub screen if needed, domains child layout
           group min/max size, opens window, attaches layout to window.

       [WM_CLOSE](autodocs-3.5/window-cl-wm-close.md) -- Closes the intuition window, but does not dispose
           the layout group.

       [WM_ICONIFY](autodocs-3.5/window-cl-wm-iconify.md) -- Create [AppIcon](autodocs-3.5/include-workbench-workbench-h.md), and invokes [WM_CLOSE](autodocs-3.5/window-cl-wm-close.md).

       [WM_HANDLEINPUT](autodocs-3.5/window-cl-wm-handleinput.md) -- Handles IDCMP input processing, defer layout
           refresh requests, and returns the item ID and Code of
           and selected gadget or menu attached to the window.
           Transparently handles keyboard control.

       WM_NEWPREFS -- Handles update and visual refresh of new
           preference settings.

       WM_RETHINK -- Re-evaluate layout requirements and adjust
           window size if needed in support of dynamicly changing
           layout groups.. eg, adding, replacing and removing objects.
```
   ATTRIBUTES


```c
       The following standard Intuition [Window](autodocs-3.5/include-intuition-intuition-h.md) Tags are supported;

       You may set these while the window is NOT open, at [NewObject()](autodocs-3.5/intuition-library-newobject-2.md)
       time or SetAttrs() - between [WM_CLOSE](autodocs-3.5/window-cl-wm-close.md) and [WM_OPEN](autodocs-3.5/window-cl-wm-open.md) for example.

           WA_Flags
           WA_NoCareRefresh
           WA_SimpleRefresh
           WA_SmartRefresh
           WA_CloseGadget
           WA_DepthGadget
           WA_SizeGadget
           WA_SizeBRight
           WA_SizeBBottom
           WA_DragBar
           WA_GimmeZeroZero
           WA_Borderless
           WA_Activate
           WA_RMBTrap
           WA_Backdrop
           WA_SuperBitMap
           WA_BackFill
           WA_PubScreen
           WA_CustomScreen
           WA_HelpGroup
           WA_MenuHelp
           WA_Zoom
           WA_NotifyDepth

       You may set any of these at any time, [NewObject()](autodocs-3.5/intuition-library-newobject-2.md) or SetAttrs();

           WA_Top
           WA_Left
           WA_InnerWidth
           WA_InnerHeight
           WA_Width
           WA_Height
           WA_Title (NOTE: Calls [SetWindowTitles()](autodocs-3.5/intuition-library-setwindowtitles-2.md) if the window is open)
           WA_IDCMP (NOTE: Calls [ModifyIDCMP()](autodocs-3.5/intuition-library-modifyidcmp-2.md) if needed)
           WA_BusyPointer (NOTE: Creates/Removes a NULL requester)

       You may [GetAttr()](autodocs-3.5/intuition-library-getattr-2.md) these at any time;

           WA_Top
           WA_Left
           WA_InnerWidth
           WA_Height
           WA_Width
           WA_InnerHeight
           WA_PubScreen
           WA_CustomScreen
           WA_Title
           WA_ScreenTitle
           WA_Zoom

           Note well, WA_InnerHeight, and WA_InnerWidth will be 0
           unless previously set until the window has been opened
           atleast once. These values are not computed until the
           first window open.

       These are the [Window](autodocs-3.5/include-intuition-intuition-h.md) Class specific attributes.

       You may set these while the window is NOT open, at [NewObject()](autodocs-3.5/intuition-library-newobject-2.md)
       time or SetAttrs() - between [WM_CLOSE](autodocs-3.5/window-cl-wm-close.md) and [WM_OPEN](autodocs-3.5/window-cl-wm-open.md) for example.

       WINDOW_Position (UWORD)
           Set the intial opening position of the window.
           See Also, WINDOW_RefWindow.

               WPOS_CENTERSCREEN - Center in visible screen clip.
               WPOS_CENTERMOUSE  - Center under mouse.
               WPOS_TOPLEFT      - [Open](autodocs-3.5/dos-library-open-2.md) Top/Left, just below screen bar.
               WPOS_CENTERWINDOW - Center in some other window.
               WPOS_FULLSCREEN   - [Open](autodocs-3.5/dos-library-open-2.md) Top/Left, and fill the screen clip.

           If WINDOW_RefWindow is set, WPOS_CENTERSCREEN will center
           in the refwindow, not the screen. As of 42.42, WPOS_FULLSCREEN
           remains broken, window will open a minimum size.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_LockWidth (ULONG)
           If TRUE, lock the width of the window, ie, disallow
           resizing in this orientation.

           Defaults to FALSE.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_LockHeight (ULONG)
           If TRUE, lock the height of the window, ie, disallow
           resizing in this orientation.

           Defaults to FALSE.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_SharedPort (struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *)
           Pointer to a custom UserPort this window should share.

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET, OM_GET)

       WINDOW_AppPort (struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *)
           Pointer to a [MsgPort](autodocs-3.5/include-exec-ports-h.md) this window should use for AppMessages.
           By passing this tag the window turns into an [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) and
           you can use the [WM_ICONIFY](autodocs-3.5/window-cl-wm-iconify.md) method. WindowClass must use the
           ID field of the AppMessages to identify the window to which
           the message was intended. You can use the UserData field
           yourself.

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_AppWindow (BOOL)
           By providing an AppPort and setting this to TRUE, the window
           will be made a Workbench [AppWindow](autodocs-3.5/include-workbench-workbench-h.md). If you don't set this
           attribute, the AppPort will only be used to support
           iconification.

           Defaults to FALSE.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_IconifyGadget (BOOL)
           Set to TRUE to add an iconification gadget to the window
           titlebar. Please note that currently windowclass detects
           the iconify gadget being pressed by using the gadget ID
           0xfffe.  Do not use this ID in your application.

           Defaults to FALSE.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_BackFillName (STRPTR)
           Name for the custom backfill to use instead of global CAPrefs
           backfill. If you use this tag, make it a user preference.

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET)


       It is legal and safe to set any of these at any time, OM_NEW or
       OM_SET regardless of of the window being open or not, if
       not applicable, the setting will be ignored.

       WA_BusyPointer (BOOL)
           Set the window to a busy state. It will set busy pointer
           on the window. Setting the busy state will also clear the
           DeferLayout state, clearing the busy state restores the
           DeferLayout state to its last value.

           This is done since, its a logical assumption if the application
           is busy enough that a pointer change is waranted, then its
           probably busy to respond to defer requests in a timely fashion.

           Note, the window put to sleep creating a NULL requester.
           In prior versions of window class before V42.40, the layout
           group was set to readonly, and menu strip removed.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_Layout (Object *)
       WINDOW_ParentLayout
       WINDOW_ParentGroup
           Pointer to the parent level layout group object which
           will be added to the window.

           Note the tag has 2 aliased definitions which are now
           obsolete but still supported in the include files.

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_Zoom (BOOL)
           [Cause](autodocs-3.5/exec-library-cause-2.md) the window to to be zipped via [ZipWindow()](autodocs-3.5/intuition-library-zipwindow-2.md).

           Applicability is (OM_NEW, OM_SET)

       WINDOW_FrontBack (BOOL)
           Changes window depth arrangement via [WindowToFront()](autodocs-3.5/intuition-library-windowtofront-2.md) or
           [WindowToBack()](autodocs-3.5/intuition-library-windowtoback-2.md). Accepted settings;

               WT_FRONT - bring window to front.
               WT_BACK  - put window to back

           Applicability is (OM_NEW, OM_SET)

       WINDOW_UserData (APTR)
           Pointer to your user data. Take note, this is *NOT* the
           same pointer as the Intuition Window's UserData.

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET, OM_GET)

       WINDOW_GadgetUserData (UWORD)
           Determines how a gadget's UserData should be interpreted.
           If the userdata is non-null, and this setting is not
           WGUD_IGNORE, then the (hook) function will be called
           when the gadget is selected.

           A function gets the hook's "object" argument in a0 and the
           "message" argument in a1.

           Possible values are;

               WGUD_HOOK   - UserData is hook pointer (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *).
               WGUD_FUNC   - UserData is a pointer to function.
               WGUD_IGNORE - Ignore UserData.

           Defaults to WGUD_IGNORE.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_MenuUserData (UWORD)
           Like the WINDOW_GadgetUserData tag, but for menus. Using
           this implies that WINDOW_MenuStrip has been created with
           GadTools or otherwise has a 32 bit UserData field after
           each menuitem.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_MenuStrip (struct [Menu](autodocs-3.5/include-intuition-intuition-h.md) *)
           Pointer to a menu to add to window with [SetMenuStrip()](autodocs-3.5/intuition-library-setmenustrip-2.md).
           Closing the window via CA_CloseWindow, will remove
           the menustrip before closing the window.  Disposing the
           window does NOT free the menu strip.

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_Window (struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *)
           Pointer to the Intuition [Window](autodocs-3.5/include-intuition-intuition-h.md), or NULL when the
           window is closed.  Take care NOT to do a [CloseWindow()](autodocs-3.5/intuition-library-closewindow-2.md)
           or you will invalidate window.class's internal pointer
           and window states.

           Applicability is (OM_GET)

       WINDOW_SigMask (ULONG)
           [Window](autodocs-3.5/include-intuition-intuition-h.md) signal bit mask.

           Applicability is (OM_GET)

       WINDOW_IconTitle (STRPTR)
           The title of the icon when the window is iconified.

           Defaults to window title.

           Applicability is (OM_NEW, OM_SET, OM_UPDATE)

       WINDOW_Icon (struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *)
           The icon to use when iconifying.

           Defaults to ENV:Sys/def_window.info or the default project
           window.

           Applicability is (OM_NEW, OM_SET, OM_UPDATE)

       WINDOW_GadgetHelp (BOOL)
           Set to TRUE to enabled gadget help processing.

           Defaults to FALSE.

           Applicability is (OM_NEW, OM_SET, OM_UPDATE)

       WINDOW_IDCMPHook (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *)
           Pointer to a [Hook](autodocs-3.5/include-utility-hooks-h.md) that should be called for IDCMP messages.
           When the hook is called, the data argument points to the
           window object and message argument to the [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md).

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_IDCMPHookBits (ULONG)
           If WINDOW_IDCMPHook is set, it will be called for IDCMP
           messages matching this bit mask.

           Defaults to 0L.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_AppMsgHook (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *)
           Pointer to a hook that should be called for AppMessages.
           When this called, the function data argument will point to
           the window object and data argument to the [AppMessage](autodocs-3.5/include-workbench-workbench-h.md).

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_RefWindow (struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *)
           Pointer to an Intuition window whose location will be the
           reference used for WINDOW_Position rather than the screen.

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET)


       WINDOW_InputEvent (struct [InputEvent](autodocs-3.5/include-devices-inputevent-h.md) *)
           Pointer to an [InputEvent](autodocs-3.5/include-devices-inputevent-h.md) structure which will be valid AFTER
           receiving a WHMI_RAWKEY return code from window class.
           This is a "fake" event, the structure is filled in based on
           the [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) and other data, and is suitable for calling
           [MapRawKey()](autodocs-3.5/keymap-library-maprawkey-2.md), infact this is how window class handles managing
           gadget keyboard control.

           Applicability is (OM_GET)
```

---

## See Also

- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [MapRawKey — keymap.library](../autodocs/keymap.library.md#maprawkey)
- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
- [SetWindowTitles — intuition.library](../autodocs/intuition.library.md#setwindowtitles)
- [WindowToBack — intuition.library](../autodocs/intuition.library.md#windowtoback)
- [WindowToFront — intuition.library](../autodocs/intuition.library.md#windowtofront)
- [ZipWindow — intuition.library](../autodocs/intuition.library.md#zipwindow)
