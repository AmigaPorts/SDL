# intuition.library/RemoveClass



NAME

```c
    RemoveClass -- Make a public boopsi class unavailable. (V36)
```
SYNOPSIS

```c
    RemoveClass( classPtr )
                 A0

    VOID RemoveClass( struct IClass * );
```
FUNCTION

    Makes a public class unavailable for public consumption.
    It's OK to call this function for a class which is not
    yet in the internal public class list, or has been
    already removed.
INPUTS

```c
    ClassPtr = pointer to *public* class created by [MakeClass()](../Includes_and_Autodocs_2._guide/node0227.html),
            may be NULL.
```
RESULT

    None.
NOTES

BUGS

SEE ALSO

```c
    [MakeClass()](../Includes_and_Autodocs_2._guide/node0227.html), [FreeClass()](../Includes_and_Autodocs_2._guide/node0216.html), [AddClass()](../Includes_and_Autodocs_2._guide/node01FB.html)
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```
