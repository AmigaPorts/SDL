# intuition.library/AddClass



NAME

```c
    AddClass -- Make a public class available (V36)
```
SYNOPSIS

```c
    AddClass( Class )
              A0

    VOID AddClass( struct IClass * );
```
FUNCTION

```c
    Adds a public boopsi class to the internal list of classes available
    for public consumption.

    You must call this function after you call [MakeClass()](../Includes_and_Autodocs_2._guide/node0227.html).
```
INPUTS

```c
    Class = pointer returned by [MakeClass()](../Includes_and_Autodocs_2._guide/node0227.html)
```
RESULT

    Nothing returned.
NOTES

BUGS

    Although there is some protection against creating classes
    with the same name as an existing class, this function
    does not do any checking or other dealings with like-named
    classes.  Until this is rectified, only officially registered
    names can be used for public classes, and there is no
    "class replacement" policy in effect.
SEE ALSO

```c
    [MakeClass()](../Includes_and_Autodocs_2._guide/node0227.html), [FreeClass()](../Includes_and_Autodocs_2._guide/node0216.html), [RemoveClass()](../Includes_and_Autodocs_2._guide/node0245.html)
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```
