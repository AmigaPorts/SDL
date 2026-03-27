# 37 Utility Library / International String Functions


The international string functions in utility library are a way to make
use of a future localization library which Amiga, Inc. will provide.
When the localization library is opened, the functions will be replaced by
ones which will take the locale as defined by the user into account. This
means that the compare order may change according to the locale, so care
should be taken not to rely on obtaining specific compare sequences.

Currently implemented are:

  _______________________________________________________________
 |                                                               |
 |  [Stricmp()](../Includes_and_Autodocs_2._guide/node03DF.html)  Compare string case-insensitive.                  |
 | [Strnicmp()](../Includes_and_Autodocs_2._guide/node03E0.html)  Compare string case-insensitive, with a specified |
 |             length.                                           |
 |  [ToLower()](../Includes_and_Autodocs_2._guide/node03E2.html)  Convert a character to lower case.                |
 |  [ToUpper()](../Includes_and_Autodocs_2._guide/node03E3.html)  Convert a character to upper case.                |
 |_______________________________________________________________|



    Table 37-4: Utility Library International String Functions
These functions operate in the same manner as their ANSI C equivalents,
for the most part.  For more information, see the "[Utility Library](../Includes_and_Autodocs_2._guide/node03CD.html)"
Autodocs in the Amiga ROM Kernel Reference Manual: Includes and Autodocs.
Here is a simple example of the usage of the international string
functions.


```c
     [istr.c](../Libraries_Manual_guide/node05C7.html) 
```
