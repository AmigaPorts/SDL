# 6 / / Intercepting Menu Operations / IDCMP_MENUVERIFY and Deadlock


The program may call [ModifyIDCMP()](../Libraries_Manual_guide/node01E3.html#line5) to turn [IDCMP_MENUVERIFY](../Libraries_Manual_guide/node01DE.html#line6) and the other
VERIFY IDCMP options off.  It is important that this be done each and
every time that the application is directly or indirectly waiting for
Intuition, since Intuition may be waiting for the application, but not
watching the window message port for IDCMP_MENUVERIFY events.  The program
cannot wait for a gadget or mouse event without checking also for any
IDCMP_MENUVERIFY event messages that may require program response.

The most common problem area is System Requesters ([AutoRequest()](../Libraries_Manual_guide/node01B4.html#line21) and
[EasyRequest()](../Libraries_Manual_guide/node01AC.html)).  Before AutoRequest() and EasyRequest() return control to
the application, Intuition must be free to run and accept a response from
the user.  If the user presses the menu button, Intuition will wait for
the program to reply to the [IDCMP_MENUVERIFY](../Libraries_Manual_guide/node01DE.html#line6) event and a deadlock results.

Therefore, it is extremely important to use [ModifyIDCMP()](../Libraries_Manual_guide/node01E3.html#line5) to turn off all
verify messages before calling [AutoRequest()](../Libraries_Manual_guide/node01B4.html#line21), [EasyRequest()](../Libraries_Manual_guide/node01AC.html) or, directly
or indirectly, AmigaDOS, since many error conditions in the DOS require
user input in the form of an EasyRequest().  Indirect DOS calls include
[OpenLibrary()](../Libraries_Manual_guide/node028E.html#line15), [OpenDevice()](../Libraries_Manual_guide/node029E.html), and [OpenDiskFont()](../Libraries_Manual_guide/node03D6.html#line5).

Beginning with V36, all windows that have the [IDCMP_MENUVERIFY](../Libraries_Manual_guide/node01DE.html#line6) bit set
must respond to Intuition within a set time period, or the menu operation
will time out and the menu action will be canceled.  This prevents the
deadlocks that were possible under previous versions of the operating
system.

