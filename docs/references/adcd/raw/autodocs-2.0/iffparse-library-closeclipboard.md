# iffparse.library/CloseClipboard



NAME

```c
    CloseClipboard -- Close and free an open [ClipboardHandle](../Includes_and_Autodocs_2._guide/node010B.html#line115).
```
SYNOPSIS

```c
    CloseClipboard (clip)
                     a0

    struct [ClipboardHandle](../Includes_and_Autodocs_2._guide/node010B.html#line115) *clip;
```
FUNCTION

```c
    Closes the clipboard.device and frees the [ClipboardHandle](../Includes_and_Autodocs_2._guide/node010B.html#line115) structure.
```
INPUTS

```c
    clip    - pointer to [ClipboardHandle](../Includes_and_Autodocs_2._guide/node010B.html#line115) struct created with
              [OpenClipboard](../Includes_and_Autodocs_2._guide/node01CE.html).
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [OpenClipboard()](../Includes_and_Autodocs_2._guide/node01CE.html), [InitIFFasClip()](../Includes_and_Autodocs_2._guide/node01CB.html)
```
