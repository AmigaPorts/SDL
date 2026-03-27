/* Source: ADCD 2.1
 * Section: window-cl-wm-handleinput
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/window-cl-wm-handleinput.md
 */

       This method is used to handle the IDCMP input of a window. Call
       this method when the signal bit of the window's UserPort is
       set. This method will return when it encounters a message that
       requires notifying your application or when the message port no
       longer contains messages for the window.

       The return value is two-part. The upper word describes the
       class of the event the value represents, and the lower word is
       a modifier that describes the event.

       Defined class return codes are:

       WMHI_IGNORE            Ignore this event
       WMHI_LASTMSG        No more messages
       WMHI_CLOSEWINDOW    [Close](../Includes_and_Autodocs_3._guide/node0149.html) gadget hit
       WMHI_GADGETUP        [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) hit.
       WMHI_INACTIVE        [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) went inactive.
       WMHI_ACTIVE            [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) was activated.
       WMHI_NEWSIZE        [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) was resized.
       WMHI_MENUPICK        A menu item was selected.
       WMHI_MENUHELP        Help was pressed in a menu.
       WMHI_GADGETHELP        A gadget sends a help message.
       WMHI_ICONIFY        [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) should be iconified.
       WMHI_UNICONIFY        [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) was deiconified.
       WMHI_RAWKEY            Raw key code
       WMHI_VANILLAKEY        Vanilla key code
       WMHI_CHANGEWINDOW    [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) moved (or depth arranged)

       The value of the lower word is defined for WMHI_GADGETUP and
       WMHI_GADGETHELP as the ID of the gadget, and for WMHI_MENUPICK
       and WMHI_MENUHELP as the menu code. WMHI_GAGDETHELP uses the
       special values 0 and WMHI_GADGETMASK as messages "pointer not
       over your window" and "pointer over your window but not over a
       gadget".

       WMHI_RAWKEY returns the raw key ID of the key being
       pressed (to get the qualifiers also, you have to use the IDCMP
       hook), and WMHI_VANILLAKEY returns the ASCII value of the key.
       WMHI_VANILLAKEY is only returned when you set IDCMP_VANILLAKEY.
       Windowclass itself does not need vanilla key IDCMP.

       WMHI_NEWSIZE returns some extra information in the low word:
       if WMF_ZOOMED is set, the window is now in zoomed state. If
       WMF_ZIPWINDOW is set, this resize was caused by either a
       click of the zoom gadget or a call to [ZipWindow()](../Includes_and_Autodocs_3._guide/node0407.html).

       WMHI_CHANGEWINDOW is returned when the window is moved. For
       resizing of the window, listen to WMHI_NEWSIZE. By setting
       WA_NotifyDepth, this event will also be returned for depth
       arranging. The lower word contains CWCODE_DEPTH in this case.

       WMHI_CLASSMASK masks the lower word of the result code out,
       while WMHI_GADGETMASK and WMHI_MENUMASK mask out the high word,
       leaving only the ID part of the result value.

       A generic application side of WM_HANDLEINPUT looks like this:

       GetAttr( WINDOW_SigMask, winobj, &wsig );

       mask = Wait(wsig);    /* maybe other signals */

       if (mask & wsig)
           while ((result = DoMethod( winobj, WM_HANDLEINPUT, &code ))
                   != WMHI_LASTMSG)
               switch (result & WMHI_CLASSMASK)
               {
               case WMHI_CLOSEWINDOW:
                   close = TRUE;
                   break;

               case WMHI_GADGETUP:
                   switch (result & WMHI_GADGETMASK)
                   {
                   /* handle the gadgets here */
                   }

               /* handle whatever other events you want here */
               }

       if (close)
           DisposeObject( winobj ); /* destroy the window */

       If you have set up the window to use a shared message port, you
       can simply call this method on each of the windows:

       if (mask & wsig)
       {
           WmHandleInputWin1();
           WmHandleInputWin2();
           WmHandleInputWin3();
       }
