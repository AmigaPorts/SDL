# intuition.library/GetPrefs



NAME

```c
    GetPrefs -- Get the current Intuition [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43) structure.
```
SYNOPSIS

```c
    Prefs = GetPrefs( PrefBuffer, Size )
    D0                A0          D0

    struct [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43) *GetPrefs( struct [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43) *, WORD );
```
FUNCTION

```c
    Gets a copy of the current Intuition [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43) structure.
    Writes the data into the buffer you specify.  The number of bytes you
    want copied is specified by the size argument.

    It is legal to take a partial copy of the [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43) structure.
    The more pertinent preferences variables have been grouped near
    the top of the structure to facilitate the memory conservation
    that can be had by taking a copy of only some of the [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43)
    structure.

    New for V36:  A new and more extensible method for supplying
    [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43) has been introduced in V36, and relies on file
    system notification.  The Intuition preferences items rely
    also on the IPrefs program.  Certain elements of the
    [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43) structure have been superceded by this new method.
    As much as possible, the [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43) structure returned by
    GetPrefs() reflect the current state of [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43).  However,
    it is impossible to represent some of the V36-style preferences
    items using the existing [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43) structure.
```
INPUTS

```c
    PrefBuffer = pointer to the memory buffer to receive your copy of the
       Intuition [Preferences](../Includes_and_Autodocs_2._guide/node00D5.html#line43)
    Size = the number of bytes in your PrefBuffer, the number of bytes
       you want copied from the system's internal Preference settings
```
RESULT

    Returns your parameter PrefBuffer.
BUGS

SEE ALSO

```c
    [GetDefPrefs()](../Includes_and_Autodocs_2._guide/node021D.html), [SetPrefs()](../Includes_and_Autodocs_2._guide/node0256.html)
```
