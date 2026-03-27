# 13 / Preferences in 1.3 and Older Versions / Setting 1.3 Preferences


The instance of the [Preferences](../Libraries_Manual_guide/node0224.html) structure in memory can be changed with
the Intuition [SetPrefs()](../Includes_and_Autodocs_2._guide/node0256.html) function:


```c
    struct Preferences *SetPrefs(struct Preferences *preferences,
                                 LONG size, BOOL inform);
```
In addition to a buffer holding the [Preferences](../Libraries_Manual_guide/node0224.html) structure, and the buffer
size, this function takes an argument which indicates whether an
[IDCMP_NEWPREFS](../Libraries_Manual_guide/node01E1.html#line51) message should be broadcast to windows which have this flag
set in the [Window](../Libraries_Manual_guide/node0121.html).IDCMPFlags field of their window.


```c
    Avoid Using [SetPrefs()](../Includes_and_Autodocs_2._guide/node0256.html).
    -----------------------
    This function is normally only used by Preferences-like utilities.
    There should be no need for a normal application to set the system
    Preferences with SetPrefs().
```
