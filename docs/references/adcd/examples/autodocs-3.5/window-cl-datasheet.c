/* Source: ADCD 2.1
 * Section: window-cl-datasheet
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/window-cl-datasheet.md
 */

       The following standard Intuition [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) Tags are supported;

       You may set these while the window is NOT open, at [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html)
       time or SetAttrs() - between [WM_CLOSE](../Includes_and_Autodocs_3._guide/node05CB.html) and [WM_OPEN](../Includes_and_Autodocs_3._guide/node05CE.html) for example.

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

       You may set any of these at any time, [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html) or SetAttrs();

           WA_Top
           WA_Left
           WA_InnerWidth
           WA_InnerHeight
           WA_Width
           WA_Height
           WA_Title (NOTE: Calls [SetWindowTitles()](../Includes_and_Autodocs_3._guide/node03F8.html) if the window is open)
           WA_IDCMP (NOTE: Calls [ModifyIDCMP()](../Includes_and_Autodocs_3._guide/node03C5.html) if needed)
           WA_BusyPointer (NOTE: Creates/Removes a NULL requester)

       You may [GetAttr()](../Includes_and_Autodocs_3._guide/node03B5.html) these at any time;

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

       These are the [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) Class specific attributes.

       You may set these while the window is NOT open, at [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html)
       time or SetAttrs() - between [WM_CLOSE](../Includes_and_Autodocs_3._guide/node05CB.html) and [WM_OPEN](../Includes_and_Autodocs_3._guide/node05CE.html) for example.

       WINDOW_Position (UWORD)
           Set the intial opening position of the window.
           See Also, WINDOW_RefWindow.

               WPOS_CENTERSCREEN - Center in visible screen clip.
               WPOS_CENTERMOUSE  - Center under mouse.
               WPOS_TOPLEFT      - [Open](../Includes_and_Autodocs_3._guide/node0196.html) Top/Left, just below screen bar.
               WPOS_CENTERWINDOW - Center in some other window.
               WPOS_FULLSCREEN   - [Open](../Includes_and_Autodocs_3._guide/node0196.html) Top/Left, and fill the screen clip.

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

       WINDOW_SharedPort (struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *)
           Pointer to a custom UserPort this window should share.

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET, OM_GET)

       WINDOW_AppPort (struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *)
           Pointer to a [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) this window should use for AppMessages.
           By passing this tag the window turns into an [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160) and
           you can use the [WM_ICONIFY](../Includes_and_Autodocs_3._guide/node05CD.html) method. WindowClass must use the
           ID field of the AppMessages to identify the window to which
           the message was intended. You can use the UserData field
           yourself.

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_AppWindow (BOOL)
           By providing an AppPort and setting this to TRUE, the window
           will be made a Workbench [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160). If you don't set this
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
           [Cause](../Includes_and_Autodocs_3._guide/node01F4.html) the window to to be zipped via [ZipWindow()](../Includes_and_Autodocs_3._guide/node0407.html).

           Applicability is (OM_NEW, OM_SET)

       WINDOW_FrontBack (BOOL)
           Changes window depth arrangement via [WindowToFront()](../Includes_and_Autodocs_3._guide/node0406.html) or
           [WindowToBack()](../Includes_and_Autodocs_3._guide/node0405.html). Accepted settings;

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

               WGUD_HOOK   - UserData is hook pointer (struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *).
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

       WINDOW_MenuStrip (struct [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) *)
           Pointer to a menu to add to window with [SetMenuStrip()](../Includes_and_Autodocs_3._guide/node03F2.html).
           Closing the window via CA_CloseWindow, will remove
           the menustrip before closing the window.  Disposing the
           window does NOT free the menu strip.

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_Window (struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *)
           Pointer to the Intuition [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), or NULL when the
           window is closed.  Take care NOT to do a [CloseWindow()](../Includes_and_Autodocs_3._guide/node03A0.html)
           or you will invalidate window.class's internal pointer
           and window states.

           Applicability is (OM_GET)

       WINDOW_SigMask (ULONG)
           [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) signal bit mask.

           Applicability is (OM_GET)

       WINDOW_IconTitle (STRPTR)
           The title of the icon when the window is iconified.

           Defaults to window title.

           Applicability is (OM_NEW, OM_SET, OM_UPDATE)

       WINDOW_Icon (struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *)
           The icon to use when iconifying.

           Defaults to ENV:Sys/def_window.info or the default project
           window.

           Applicability is (OM_NEW, OM_SET, OM_UPDATE)

       WINDOW_GadgetHelp (BOOL)
           Set to TRUE to enabled gadget help processing.

           Defaults to FALSE.

           Applicability is (OM_NEW, OM_SET, OM_UPDATE)

       WINDOW_IDCMPHook (struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *)
           Pointer to a [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) that should be called for IDCMP messages.
           When the hook is called, the data argument points to the
           window object and message argument to the [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762).

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_IDCMPHookBits (ULONG)
           If WINDOW_IDCMPHook is set, it will be called for IDCMP
           messages matching this bit mask.

           Defaults to 0L.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_AppMsgHook (struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *)
           Pointer to a hook that should be called for AppMessages.
           When this called, the function data argument will point to
           the window object and data argument to the [AppMessage](../Includes_and_Autodocs_3._guide/node05D6.html#line115).

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET)

       WINDOW_RefWindow (struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *)
           Pointer to an Intuition window whose location will be the
           reference used for WINDOW_Position rather than the screen.

           Defaults to NULL.

           Applicability is (OM_NEW, OM_SET)


       WINDOW_InputEvent (struct [InputEvent](../Includes_and_Autodocs_3._guide/node061A.html#line256) *)
           Pointer to an [InputEvent](../Includes_and_Autodocs_3._guide/node061A.html#line256) structure which will be valid AFTER
           receiving a WHMI_RAWKEY return code from window class.
           This is a "fake" event, the structure is filled in based on
           the [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) and other data, and is suitable for calling
           [MapRawKey()](../Includes_and_Autodocs_3._guide/node0412.html), infact this is how window class handles managing
           gadget keyboard control.

           Applicability is (OM_GET)
