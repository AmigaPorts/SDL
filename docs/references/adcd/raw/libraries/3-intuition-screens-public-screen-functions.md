# 3 Intuition Screens / Public Screen Functions


Public screens are a new feature of Release 2 (V36).  A public screen
allows multiple applications to share a single screen thus saving memory.
If your application opens a public screen, then other applications will be
able to open their windows on your screen.  In older versions of the
operating system, only the Workbench screen could be shared so
applications had to live within its limitations or use up Chip memory
creating their own private, [custom screens](../Libraries_Manual_guide/node00DF.html).

Now the system allows any screen to be set up as a public screen so there
may be many public screens in memory at once, not just Workbench.  This
permits the power user to set up different work environments that multiple
applications can share in a way that is memory efficient (each one with a
display mode appropriate to a particular job).

Workbench is a special case public screen because it is the initial
default public screen.  The default public screen is the screen
applications will get when they ask for a public screen but don't specify
a name.  Under normal conditions, Workbench is the default public screen
and is created by the system at startup time.  However, keep in mind that
the default public screen can be changed (it's not always guaranteed to be
Workbench).


```c
    Screens for the Novice.
    -----------------------
    If you're not sure what kind of screen to use, then use the default
    public screen.  Under Release 2, you can open a window on the default
    public screen without doing any screen set-up work.  See the
    "[Intuition Windows](../Libraries_Manual_guide/node0106.html)" chapter for more details.
```
Generally, it is much easier to use an existing, public screen than to set
up one of your own.  Here are the basic functions you use to work with an
existing public screen.


                Table 3-5: Public Screen Functions
  ______________________________________________________________________
 |                                                                      |
 |        [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html)  Find Workbench or any other public screen;   |
 |                         prevent it from closing while a window is    |
 |                         opened or its attributes copied.             |
 |                                                                      |
 |      [UnlockPubScreen()](../Includes_and_Autodocs_2._guide/node025D.html)  Release the lock allowing the screen to      |
 |                         later be closed.                             |
 |                                                                      |
 |  [SetDefaultPubScreen()](../Includes_and_Autodocs_2._guide/node024F.html)  Establishes a given public screen as the     |
 |                         default.                                     |
 |                                                                      |
 |  [GetDefaultPubScreen()](../Includes_and_Autodocs_2._guide/node021C.html)  Copies the name of the default screen to a   |
 |                         user supplied buffer for use by the screen   |
 |                         manager utility (the name is not needed by   |
 |                         normal applications, use LockPubScreen(NULL) |
 |                         instead).                                    |
 |                                                                      |
 |      [PubScreenStatus()](../Includes_and_Autodocs_2._guide/node023E.html)  Converts a screen to private or public       |
 |                         status.                                      |
 |                                                                      |
 |    [SetPubScreenModes()](../Includes_and_Autodocs_2._guide/node0257.html)  Controls the public screen global mode bits. |
 |______________________________________________________________________|


By using an existing public screen, an application is no longer
responsible for setting up the display, however, it also loses flexibility
and control.  It can no longer set the palette or depth, and it cannot
write directly into screen memory without cooperation from the owner of
the public screen.  (If these limitations are too confining, the
application can create a new screen instead.)

 [Accessing a Public Screen by Name](../Libraries_Manual_guide/node00E7.html) 
 [The Default Public Screen and Workbench](../Libraries_Manual_guide/node00E8.html) 
 [Taking a New Custom Screen Public](../Libraries_Manual_guide/node00E9.html) 
 [Searching the Public Screen List](../Libraries_Manual_guide/node00EA.html) 

