# 11 Intuition Special Functions / Intuition and Preferences


The [SetPrefs()](../Libraries_Manual_guide/node0225.html) function is used to configure Intuition's internal data
states according to a given [Preferences](../Libraries_Manual_guide/node0224.html) structure.  This call relies on
the Preferences system used in V34 and earlier versions of the OS.  The
old system has been largely superceded in Release 2.  See the
"[Preferences](../Libraries_Manual_guide/node0221.html)" chapter for details.  This routine is called only by:

  * The Preferences program itself after the user changes Preferences

```c
    settings (under V34 and earlier).
```
  * AmigaDOS when the system is being booted up.  AmigaDOS opens the

```c
    devs:system-configuration file and passes the information found there
    to the [SetPrefs()](../Libraries_Manual_guide/node0225.html) routine.  This way, the user can create an
    environment and have that environment restored every time the system
    is booted.
```
The function takes three arguments:


```c
    struct Preferences *SetPrefs(struct Preferences *prefbuf,
                                 long size, long realThing)
```
The prefbuf argument is a pointer to a Preferences structure that will be
used for Intuition's internal settings.  The  size is the number of bytes
contained in your [Preferences](../Libraries_Manual_guide/node0224.html) structure.  Typically, you will use
sizeof(struct Preferences) for this argument.  The realThing argument is a
boolean TRUE or FALSE designating whether or not this is an intermediate
or final version of the Preferences.  The difference is that final changes
to Intuition's internal Preferences settings cause a global broadcast of
NEWPREFS events to every application that is listening for this event.
Intermediate changes may be used, for instance, to update the screen
colors while the user is playing with the color gadgets.


```c
    About SetPrefs().
    -----------------
    The intended use for the [SetPrefs()](../Libraries_Manual_guide/node0225.html) call is entirely to serve
    the user.  You should never use this routine to make your programming
    or design job easier at the cost of yanking the rug out from beneath
    the user.
```
Refer to the chapter "[Preferences](../Libraries_Manual_guide/node0221.html)" for information about the [Preferences](../Libraries_Manual_guide/node0224.html)
structure and the new Preferences procedure calls used in Release 2.

