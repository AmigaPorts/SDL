/* Source: ADCD 2.1
 * Section: intuition-library-openwindow
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-openwindow.md
 */

    Left = the initial x-position for your window
    Top = the initial y-position for your window
    Width = the initial width of this window
    Height = the initial height of this window

    DetailPen = pen number (or -1) for the rendering of window details
     (like gadgets or text in title bar)
    BlockPen = pen number (or -1) for window block fills (like title bar)
    [For V36: Title bar colors are determined otherwise.]

    Flags = specifiers for your requirements of this window, including:
         which system gadgets you want attached to your window:

        - WFLG_DRAGBAR allows this window to be dragged
        - WFLG_DEPTHGADGET lets the user depth-arrange this window
        - WFLG_CLOSEGADGET attaches the standard close gadget
        - WFLG_SIZEGADGET allows this window to be sized.

        If you ask for the WFLG_SIZEGADGET gadget, you must specify one or
        both of the flags WFLG_SIZEBRIGHT and WFLG_SIZEBBOTTOM below; if
        you don't, the default is WFLG_SIZEBRIGHT.  See the following items
        WFLG_SIZEBRIGHT and WFLG_SIZEBBOTTOM for more details.

        - WFLG_SIZEBRIGHT is a special system gadget flag that
          you set to specify whether or not you want the
          RIGHT border adjusted to account for the physical size
          of the sizing gadget.  The sizing gadget must, after
          all, take up room in either the right or bottom border
          (or both, if you like) of the window.  Setting either
          this or the WFLG_SIZEBBOTTOM flag selects which edge
          will take up the slack.  This will be particularly
          useful to applications that want to use the extra space
          for other gadgets (like a proportional gadget and two
          Booleans done up to look like scroll bars) or, for
          for instance, applications that want every possible
          horizontal bit and are willing to lose lines vertically.
          NOTE:  if you select WFLG_SIZEGADGET, you must select
          either WFLG_SIZEBRIGHT or WFLG_SIZEBBOTTOM or both.  If
          you select neither, the default is WFLG_SIZEBRIGHT.
        - WFLG_SIZEBBOTTOM is a special system gadget flag that
          you set to specify whether or not you want the
          BOTTOM border adjusted to account for the physical size
          of the sizing gadget.  For details, refer to
          WFLG_SIZEBRIGHT above.

        - WFLG_GIMMEZEROZERO for easy but expensive output

        what type of window layer you want, either:
        - WFLG_SIMPLE_REFRESH
        - WFLG_SMART_REFRESH
        - WFLG_SUPER_BITMAP

        - WFLG_BACKDROP for whether or not you want this window to be one
          of Intuition's special backdrop windows.  See WFLG_BORDERLESS
          as well.

        - WFLG_REPORTMOUSE for whether or not you want to "listen" to
          mouse movement events whenever your window is the active
          one.  After you've opened your window, if you want to change
          you can later change the status of this via a call to
          [ReportMouse()](../Includes_and_Autodocs_2._guide/node0248.html).  Whether or not your window is listening to
          mouse is affected by gadgets too, since they can cause you
          to start getting reports too if you like.  The mouse move
          reports (either InputEvents or messages on the IDCMP) that
          you get will have the x/y coordinates of the current mouse
          position, relative to the upper-left corner of your window
          (WFLG_GIMMEZEROZERO notwithstanding).  This flag can work in
          conjunction with the IDCMP Flag called IDCMP_MOUSEMOVE, which
          allows you to listen via the IDCMP.

        - WFLG_BORDERLESS should be set if you want a window with no
          border padding.  Your window may have the border variables
          set anyway, depending on what gadgetry you've requested for
          the window, but you won't get the standard border lines and
          spacing that comes with typical windows.

          This is a good way to take over the entire screen, since you
          can have a window cover the entire width of the screen using
          this flag.  This will work particularly well in conjunction
          with the WFLG_BACKDROP flag (see above), since it allows you
          to open a window that fills the ENTIRE screen.  NOTE:  this is
          not a flag that you want to set casually, since it may cause
          visual confusion on the screen.  The window borders are the
          only dependable visual division between various windows and
          the background screen.  Taking away that border takes away
          that visual cue, so make sure that your design doesn't need
          it at all before you proceed.

        - WFLG_ACTIVATE is the flag you set if you want this window to
          automatically become the active window.  The active
          window is the one that receives input from the keyboard and
          mouse.  It's usually a good idea to to have the window you
          open when your application first starts up be an ACTIVATED
          one, but all others opened later not be ACTIVATED (if the
          user is off doing something with another screen, for
          instance, your new window will change where the input is
          going, which would have the effect of yanking the input rug
          from under the user).  Please use this flag thoughtfully and
          carefully.

          Some notes: First, your window may or may not be active
          by the time this function returns.  Use the IDCMP_ACTIVEWINDOW
          IDCMP message to know when your window has become active.
          Also, be very careful not to mistakenly specify the
          obsolete flag names WINDOWACTIVE or ACTIVEWINDOW.  These are
          used in other contexts, and their values unintentionally added
          to your flags can cause most unfortunate results.  To avoid
          confusion, they are now know as WFLG_WINDOWACTIVE and
          IDCMP_ACTIVEWINDOW.

        - WFLG_RMBTRAP, when set, causes the right mouse button events
          to be trapped and broadcast as events.  You can receive
          these events through either the IDCMP or the console.

        - WFLG_NOCAREREFRESH indicates that you do not wish to
          be responsible for calling [BeginRefresh()](../Includes_and_Autodocs_2._guide/node0200.html) and [EndRefresh()](../Includes_and_Autodocs_2._guide/node0213.html)
          when your window has exposed regions (i.e., when the
          IDCMP_REFRESHWINDOW message would be generated).  See also
          the descriptions of these two functions.

        - WFLG_NW_EXTENDED (V36) indicates that [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976) in fact points
          to an [ExtNewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line1046) structure, and that the 'Extension'
          field points to an array of [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) structures, with
          meaning described below.

    IDCMPFlags = IDCMP is the acronym for Intuition Direct Communications
        [Message](../Includes_and_Autodocs_2._guide/node0099.html#line48) Port.  (It's Intuition's sole acronym.) If any of the
        IDCMP Flags is selected, Intuition will create a pair of
        message ports and use them for direct communications with the
        task opening this window (as compared with broadcasting
        information via the Console device).  See the "Input and
        Output Methods" chapter of the Intuition Reference Manual for
        complete details.

        You request an IDCMP by setting any of these flags.  Except
        for the special VERIFY flags, every other flag you set tells
        Intuition that if a given event occurs which your program
        wants to know about, it is to broadcast the details of that
        event through the IDCMP rather than via the Console device.
        This allows a program to interface with Intuition directly,
        rather than going through the Console device.

        Many programs have elected to use IDCMP communication
        exclusively, and not to associate a console with their
        windows at all.  Some operations, such as IDCMP_MENUVERIFY,
        can ONLY be achieved using IDCMP.

        The IDCMP flags you can set are:

        - IDCMP_REQVERIFY is the flag which, like IDCMP_SIZEVERIFY and ...

        - IDCMP_MENUVERIFY (see immediately below), specifies that you
          want to make sure that your graphical state is quiescent
          before something extraordinary happens.  In this case, the
          extraordinary event is that a rectangle of graphical data is
          about to be blasted into your [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797).  If you're drawing
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
          Intuition will send you the IDCMP_SIZEVERIFY message and [Wait()](../Includes_and_Autodocs_2._guide/node038A.html)
          until you reply that it's OK to proceed with the sizing. NOTE:
          when we say that Intuition will [Wait()](../Includes_and_Autodocs_2._guide/node038A.html) until you reply, what
          we're really saying is that user will WAIT until you reply, which
          suffers the great negative potential of User-Unfriendliness.
          So remember:  use this flag sparingly, and, as always with any
          IDCMP [Message](../Includes_and_Autodocs_2._guide/node0099.html#line48) you receive, reply to it promptly!  Then, after
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
        lockup.  USE [ModifyIDCMP()](../Includes_and_Autodocs_2._guide/node0229.html) TO TURN OFF ANY VERIFY MESSAGES
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

          NOTE FOR V36: If you have both IDCMP_RAWKEY and IDCMP_VANILLAKEY
          set, Intuition will send an IDCMP_RAWKEY event for those
          *downstrokes* which do not map to single-byte characters
          ("non-vanilla" keys).  In this way you can easily detect cursor
          keys, function keys, and the Help key without sacrificing the
          convenience of IDCMP_VANILLAKEY.

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
          system-wide [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43) changes.  For V36, there is a new
          environment mechanism to replace [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43), which we
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
          by the user or the functions [SizeWindow()](../Includes_and_Autodocs_2._guide/node025A.html), [MoveWindow()](../Includes_and_Autodocs_2._guide/node022C.html),
          [ChangeWindowBox()](../Includes_and_Autodocs_2._guide/node0203.html), or [ZipWindow()](../Includes_and_Autodocs_2._guide/node0266.html).

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

    Gadgets = the pointer to the first of a linked list of the your own
          Gadgets which you want attached to this [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797).  Can be NULL
          if you have no Gadgets of your own
