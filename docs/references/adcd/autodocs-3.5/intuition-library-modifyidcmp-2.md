---
title: intuition.library/ModifyIDCMP
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-modifyidcmp-2
functions: [ChangeWindowBox, CloseWindow, GetUniqueID, HelpControl, ModifyIDCMP, MoveWindow, OpenWindow, OpenWindowTagList, SizeWindow, Wait, ZipWindow]
libraries: [exec.library, intuition.library, utility.library]
---

# intuition.library/ModifyIDCMP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ModifyIDCMP -- Modify the state of a window's IDCMPFlags.

    SYNOPSIS
	Success = ModifyIDCMP( [Window](autodocs-3.5/include-intuition-intuition-h.md), IDCMPFlags )
	D0 (V37)               A0      D0

	[BOOL](autodocs-3.5/include-exec-types-h.md) ModifyIDCMP( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, ULONG );
	/* returns [BOOL](autodocs-3.5/include-exec-types-h.md) in V37 and greater */

    FUNCTION
	This routine modifies the state of your window's IDCMP (Intuition
	Direct Communication [Message](autodocs-3.5/include-exec-ports-h.md) Port).  The state is modified to reflect
	your desires as described by the flag bits in the value IDCMPFlags.

	The four actions that might be taken are:

```c
       - if there is currently no IDCMP in the given window, and IDCMPFlags
         is zero, nothing happens
       - if there is currently no IDCMP in the given window, and any of the
         IDCMPFlags is selected (set), then the IDCMP of the window is
         created, including allocating and initializing the message ports
         and allocating a signal bit for your port.  See the "Input and
         [Output](autodocs-3.5/dos-library-output-2.md) Methods" chapter of the Intuition Reference Manual for full
```
	  details
```c
       - if the IDCMP for the given window exists, and the
         IDCMPFlags argument is zero, this says that you want
         Intuition to close the ports, free the buffers and free
         your signal bit.  You MUST be the same task that was active
         when this signal bit was allocated (either by ModifyIDCMP()
```
	  or [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md) ).

       - if the IDCMP for the given window is opened, and the IDCMPFlags
         argument is not zero, this means that you want to change the
         state of which events will be broadcast to you through the IDCMP
	NOTE:  You can set up the Window->UserPort to any port of your own
	before you call ModifyIDCMP().  If IDCMPFlags is non-null but
	your UserPort is already initialized, Intuition will assume that
	it's a valid port with task and signal data preset and Intuition
	won't disturb your set-up at all, Intuition will just allocate
	the Intuition message port half of it.  The converse is true
	as well:  if UserPort is NULL when you call here with
	IDCMPFlags == NULL, Intuition will deallocate only the Intuition
	side of the port.

	This allows you to use a port that you already have allocated:
```c
       - [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md) with IDCMPFlags equal to NULL (open no ports)
       - set the UserPort variable of your window to any valid port of your
         own choosing
       - call ModifyIDCMP with IDCMPFlags set to what you want
       - then, to clean up later, set UserPort equal to NULL before calling
         [CloseWindow()](autodocs-3.5/intuition-library-closewindow-2.md) (leave IDCMPFlags alone)  BUT FIRST: you must make
```
	  sure that no messages sent your window are queued at the port,
	  since they will be returned to the memory free pool.

	For an example of how to close a window with a shared IDCMP,
	see the description for [CloseWindow()](autodocs-3.5/intuition-library-closewindow-2.md).


    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the [Window](autodocs-3.5/include-intuition-intuition-h.md) structure containing the IDCMP ports
	IDCMPFlags = the flag bits describing the new desired state of
		the IDCMP.  The flags are:

	    - IDCMP_REQVERIFY is the flag which, like IDCMP_SIZEVERIFY and ...

	    - IDCMP_MENUVERIFY (see immediately below), specifies that you
	      want to make sure that your graphical state is quiescent
	      before something extraordinary happens.  In this case, the
	      extraordinary event is that a rectangle of graphical data is
	      about to be blasted into your [Window](autodocs-3.5/include-intuition-intuition-h.md).  If you're drawing
	      directly into its screen, you probably will wish to make sure
	      that you've ceased drawing before the user is allowed to bring
	      up the DMRequest you've set up, and the same for when system
	      has a request for the user.  Set this flag to ask for that
	      verification step.

	    - IDCMP_REQCLEAR is the flag you set to hear a message whenever
	      a requester is cleared from your window.  If you are using
	      IDCMP_REQVERIFY to arbitrate access to your screen's bitmap, it
	      is safe to start your output once you have heard an
	      IDCMP_REQCLEAR for each IDCMP_REQSET.

	    - IDCMP_REQSET is a flag that you set to receive a broadcast
	      for each requester that is opened in your window.  Compare
	      this with IDCMP_REQCLEAR above.  This function is distinct
	      from IDCMP_REQVERIFY.  This functions merely tells you that a
	      requester has opened, whereas IDCMP_REQVERIFY requires you to
	      respond before the requester is opened.

	    - IDCMP_MENUVERIFY is the flag you set to have Intuition stop
	      and wait for you to finish all graphical output to your
	      window before rendering the menus.  Menus are currently
	      rendered in the most memory-efficient way, which involves
	      interrupting output to all windows in the screen before the
	      menus are drawn.  If you need to finish your graphical
	      output before this happens, you can set this flag to make
	      sure that you do.

	    - IDCMP_SIZEVERIFY means that you will be doing output to your
	      window which depends on a knowledge of the current size of the
	      window.  If the user wants to resize the window,  you may want
	      to make sure that any queued output completes before the sizing
	      takes place (critical text, for instance).  If this is the
	      case, set this flag.   Then, when the user wants to size,
	      Intuition will send you the IDCMP_SIZEVERIFY message and [Wait()](autodocs-3.5/exec-library-wait-2.md)
	      until you reply that it's OK to proceed with the sizing. NOTE:
	      when we say that Intuition will [Wait()](autodocs-3.5/exec-library-wait-2.md) until you reply, what
	      we're really saying is that user will WAIT until you reply, which
	      suffers the great negative potential of User-Unfriendliness.
	      So remember:  use this flag sparingly, and, as always with any
	      IDCMP [Message](autodocs-3.5/include-exec-ports-h.md) you receive, reply to it promptly!  Then, after
	      user has sized the window, you can find out about it using
	      IDCMP_NEWSIZE.

	    With all the "VERIFY" functions, it is not save to leave them
	    enabled at any time when your task may not be able to respond
	    for a long period.

	    It is NEVER safe to call AmigaDOS, directly or indirectly, when
	    a "VERIFY" function is active.  If AmigaDOS needs to put up a
	    disk requester for you, your task might end up waiting for the
	    requester to be satisfied, at the same time as Intuition is
	    waiting for your response.  The result is a complete machine
	    lockup.  USE ModifyIDCMP() TO TURN OFF ANY VERIFY MESSAGES
	    BEFORE CALLING dos.library!!

	    For V36: If you do not respond to the verification IntuiMessages
	    within the user specified timeout duration, Intuition will abort
	    the operation.  This eliminates the threat of these easy
	    deadlocks, but can result in a confused user.  Please try
	    hard to continue to avoid "logical deadlocks".

	    - IDCMP_NEWSIZE is the flag that tells Intuition to send an IDCMP
	      message to you after the user has resized your window.  At
	      this point, you could examine the size variables in your
	      window structure to discover the new size of the window.
	      See also the IDCMP_CHANGEWINDOW IDCMP flag.

	    - IDCMP_REFRESHWINDOW when set will cause a message to be sent
	      whenever your window needs refreshing.  This flag makes
	      sense only with WFLG_SIMPLE_REFRESH and WFLG_SMART_REFRESH
	      windows.

	    - IDCMP_MOUSEBUTTONS will get reports about mouse-button up/down
	      events broadcast to you (Note:  only the ones that
	      don't mean something to Intuition.  If the user clicks the
	      select button over a gadget, Intuition deals with it and you
	      don't find out about it through here).

	    - IDCMP_MOUSEMOVE will work only if you've set the
	      WFLG_REPORTMOUSE flag above, or if one of your gadgets has the
	      GACT_FOLLOWMOUSE flag set.  Then all mouse movements will be
	      reported here, providing your window is active.

	    - IDCMP_GADGETDOWN means that when the User "selects" a gadget
	      you've created with the GACT_IMMEDIATE flag set, the fact
	      will be broadcast through the IDCMP.

	    - IDCMP_GADGETUP means that when the user "releases" a gadget that
	      you've created with the GACT_RELVERIFY flag set, the fact
	      will be broadcast through the IDCMP.  This message is
	      only generated if the release is "good", such as releasing
	      the select button over a Boolean gadget, or typing ENTER
	      in a string gadget.

	    - IDCMP_MENUPICK selects that menu number data will be sent via
	      the IDCMP.

	    - IDCMP_CLOSEWINDOW means broadcast the IDCMP_CLOSEWINDOW event
	      through the IDCMP rather than the console.

	    - IDCMP_RAWKEY selects that all IDCMP_RAWKEY events are
	      transmitted via the IDCMP.  Note that these are absolutely RAW
	      keycodes, which you will have to translate before using.
	      Setting this and the MOUSE flags effectively eliminates the need
	      to open a Console device to get input from the keyboard and
	      mouse.  Of course, in exchange you lose all of the console
	      features, most notably the "cooking" of input data and
	      the systematic output of text to your window.

	    - IDCMP_VANILLAKEY is for developers who don't want the hassle
	      of IDCMP_RAWKEYS.  This flag will return all the keycodes after
	      translation via the current country-dependent keymap.  When
	      you set this flag, you will get IntuiMessages where the Code
	      field has a decoded ANSI character code representing the key
	      struck on the keyboard.  Only codes that map to a single
	      character are returned: you can't read such keys as HELP or
	      the function keys with IDCMP_VANILLAKEY.

	      NEW FOR V36: If you have both IDCMP_RAWKEY and IDCMP_VANILLAKEY
	      set, Intuition will send an IDCMP_RAWKEY event for those
	      *downstrokes* which do not map to single-byte characters
	      ("non-vanilla" keys).  In this way you can easily detect cursor
	      keys, function keys, and the Help key without sacrificing the
	      convenience of IDCMP_VANILLAKEY.  NB: A side-effect of having
	      both IDCMP_RAWKEY and IDCMP_VANILLAKEY set is that you never
	      hear IDCMP_RAWKEY upstrokes, even for keys that caused
	      IDCMP_RAWKEY downstrokes.

	    - IDCMP_INTUITICKS gives you simple timer events from Intuition
	      when your window is the active one; it may help you avoid
	      opening and managing the timer device.  With this flag set,
	      you will get only one queued-up INTUITICKS message at a
	      time.  If Intuition notices that you've been sent an
	      IDCMP_INTUITICKS message and haven't replied to it, another
	      message will not be sent.  Intuition receives timer events and
	      considers sending you an IDCMP_INTUITICKS message approximately
	      ten times a second.

	    - IDCMP_DELTAMOVE gives raw (unscaled) input event delta X/Y
	      values.  This is so you can detect mouse motion regardless of
	      screen/window/display boundaries.  This works a little
	      strangely: if you set both IDCMP_MOUSEMOVE and IDCMP_DELTAMOVE.
	      IDCMPFlags, you will get IDCMP_MOUSEMOVE messages with delta
	      x/y values in the MouseX and MouseY fields of the
	      IDCMPMessage.

	    - IDCMP_NEWPREFS indicates you wish to be notified when the
	      system-wide [Preferences](autodocs-3.5/include-intuition-preferences-h.md) changes.  For V36, there is a new
	      environment mechanism to replace [Preferences](autodocs-3.5/include-intuition-preferences-h.md), which we
	      recommend you consider using instead.

	    - Set IDCMP_ACTIVEWINDOW and IDCMP_INACTIVEWINDOW to get messages
	      when those events happen to your window.  Take care not to
	      confuse this "ACTIVEWINDOW" with the familiar sounding, but
	      totally different "WINDOWACTIVE" flag.  These two flags have
	      been supplanted by "IDCMP_ACTIVEWINDOW" and "WFLG_WINDOWACTIVE".
	      Use the new equivalent terms to avoid confusion.

	    - Set IDCMP_DISKINSERTED or IDCMP_DISKREMOVED to learn when
	      removable disks are inserted or removed, respectively.

	    - IDCMP_IDCMPUPDATE is a new class for V36 which is used as
	      a channel of communication from custom and boopsi gadgets
	      to your application.

	    - IDCMP_CHANGEWINDOW is a new class for V36 that will be sent
	      to your window whenever its dimensions or position are changed
	      by the user or the functions [SizeWindow()](autodocs-3.5/intuition-library-sizewindow-2.md), [MoveWindow()](autodocs-3.5/intuition-library-movewindow-2.md),
	      [ChangeWindowBox()](autodocs-3.5/intuition-library-changewindowbox-2.md), or [ZipWindow()](autodocs-3.5/intuition-library-zipwindow-2.md).

	    - IDCMP_MENUHELP is new for V37.  If you specify the WA_MenuHelp
	      tag when you open your window, then when the user presses the
	      HELP key on the keyboard during a menu session, Intuition will
	      terminate the menu session and issue this even in place of an
	      IDCMP_MENUPICK message.
		- NEVER follow the NextSelect link for MENUHELP messages.
		- You will be able to hear MENUHELP for ghosted menus.
		  (This lets you tell the user why the option is ghosted.)
		- Be aware that you can receive a MENUHELP message whose code
		  corresponds to a menu header or an item that has sub-items
		  (which does not happen for MENUPICK).  The code may also be
		  MENUNULL.
		- LIMITATION:  if the user extend-selects some checkmarked
		  items with the mouse, then presses MENUHELP, your
		  application will only hear the MENUHELP report.  You
		  must re-examine the state of your checkmarks when you
		  get a MENUHELP.
		- Availability of MENUHELP in V36 is not directly
		  controllable.  We apologize...

	    - IDCMP_GADGETHELP is new for V39.  If you turn on
	      gadget help for your window (using the [HelpControl()](autodocs-3.5/intuition-library-helpcontrol.md))
	      function, then Intuition will send IDCMP_GADGETHELP
	      messages when the mouse passes over certain gadgets or
	      your window.  The IntuiMessage->Code field is normally
	      ~0, but a boopsi gadget can return any word value it wishes.

	      Ordinarily, gadget help is only processed for the active
	      window.  When Intuition has determined that the mouse is
	      pointing at a gadget which has the GMORE_GADGETHELP
	      property, you will be sent an IDCMP_GADGETHELP message
	      whose IAddress points to the gadget.  When the mouse is
	      over your window but not over any help-aware gadget, you
	      will be sent a message whose IAddress is the window
	      itself.  When the mouse is not over your window,
	      Intuition sends a message whose IAddress is zero.

	      A multi-window application can use the WA_HelpGroup or
	      WA_HelpGroupWindow tags to indicate that all its windows
	      belong in a group.  (The help group identifier should be
	      obtained with utility.library/GetUniqueID().) This makes
	      Intuition test gadget help in all windows of the group
	      when any one of them is the active one.  Inactive windows
	      whose WA_HelpGroup matches the active window's receive
	      IDCMP_GADGETHELP messages when the mouse is over that
	      window or any of its help-aware gadgets.  The GADGETHELP
	      message with an IAddress of zero means the mouse is not
	      over the active window or any other window of the same
	      group.  It is always sent to the active window (which is
	      not necessarily the window in your group that last got a
	      message).

	      To maximize performance, gadget help is not checked
	      while the mouse is travelling quickly, or if it has not
	      moved at all since the last test.  As well, if Intuition
	      discovers that the mouse is still over same gadget and
	      that gadget does not wish to send a different
	      IntuiMessage->Code from the last message, no new
	      [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) is sent.

    RESULT
	Starting in V37, this function returns NULL if it was unable
	to create the necessary message ports.  (The possibility of
	failure exists in earlier releases, but no return code was offered).
	Do not check the return code under V36 or earlier.

    BUGS

    SEE ALSO
	[OpenWindowTagList()](autodocs-3.5/intuition-library-openwindowtaglist-2.md), [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md), [CloseWindow()](autodocs-3.5/intuition-library-closewindow-2.md)

---

## See Also

- [ChangeWindowBox — intuition.library](../autodocs/intuition.library.md#changewindowbox)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [GetUniqueID — utility.library](../autodocs/utility.library.md#getuniqueid)
- [HelpControl — intuition.library](../autodocs/intuition.library.md#helpcontrol)
- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
- [MoveWindow — intuition.library](../autodocs/intuition.library.md#movewindow)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [ZipWindow — intuition.library](../autodocs/intuition.library.md#zipwindow)
