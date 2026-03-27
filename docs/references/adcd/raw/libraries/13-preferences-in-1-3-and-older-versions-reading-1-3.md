# 13 / Preferences in 1.3 and Older Versions / Reading 1.3 Preferences


Applications can obtain a copy of Preferences by calling the Intuition
function [GetPrefs()](../Includes_and_Autodocs_2._guide/node021E.html).  In a system in which there is no
devs:system-configuration file, [GetDefPrefs()](../Includes_and_Autodocs_2._guide/node021D.html) can be used to obtain the
Intuition default Preference settings.


```c
    struct Preferences *GetPrefs(struct Preferences *preferences,
                                 LONG size);
    struct Preferences *GetDefPrefs(struct Preferences *preferences,
                                    LONG size);
```
[GetPrefs()](../Includes_and_Autodocs_2._guide/node021E.html) and [GetDefPrefs()](../Includes_and_Autodocs_2._guide/node021D.html) have two arguments, a pointer to a buffer to
receive the copy of the user Preferences and the size of this buffer.  The
most commonly used data is grouped near the beginning of the [Preferences](../Libraries_Manual_guide/node0224.html)
structure and you are free to read only as much as you need.  So, if you
are only interested in the first part of the Preferences structure, you do
not need to allocate a buffer large enough to hold the entire structure.
These functions return a pointer to your buffer if successful, NULL
otherwise.

If you are using Intuition IDCMP for input, you can set the IDCMP flag
[IDCMP_NEWPREFS](../Libraries_Manual_guide/node01E1.html#line51) (formerly the NEWPREFS flag under V34 and earlier versions
of the OS).  With this flag set, your program will receive an [IntuiMessage](../Libraries_Manual_guide/node01D9.html)
informing you changes have been made to Preferences.  To get the latest
settings, you would again call [GetPrefs()](../Includes_and_Autodocs_2._guide/node021E.html).

