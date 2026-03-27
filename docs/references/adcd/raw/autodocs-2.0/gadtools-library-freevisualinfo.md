# gadtools.library/FreeVisualInfo



NAME

```c
    FreeVisualInfo -- Return any resources taken by GetVisualInfo. (V36)
```
SYNOPSIS

```c
    FreeVisualInfo(vi)
                   A0

    VOID FreeVisualInfo(APTR);
```
FUNCTION

```c
    FreeVisualInfo() returns any memory or other resources that
    were allocated by [GetVisualInfoA()](../Includes_and_Autodocs_2._guide/node03EE.html).  You should only call this function
    once you are done with using the gadgets (i.e. after [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html)),
    but while the screen is still valid (i.e. before [CloseScreen()](../Includes_and_Autodocs_2._guide/node0207.html) or
    [UnlockPubScreen()](../Includes_and_Autodocs_2._guide/node025D.html)).
```
INPUTS

```c
    vi - Pointer that was obtained by calling [GetVisualInfoA()](../Includes_and_Autodocs_2._guide/node03EE.html).
```
RESULT

    None.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [GetVisualInfoA()](../Includes_and_Autodocs_2._guide/node03EE.html)
```
