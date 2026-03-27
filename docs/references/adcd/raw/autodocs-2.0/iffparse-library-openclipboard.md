# iffparse.library/OpenClipboard



NAME

    OpenClipboard -- Create a handle on a clipboard unit.
SYNOPSIS

```c
    ch = OpenClipboard (unit)
    d0                   d0

    struct [ClipboardHandle](../Includes_and_Autodocs_2._guide/node010B.html#line115)   *ch;
    LONG                    unit;
```
FUNCTION

```c
    Opens the clipboard.device and opens a stream for the specified unit
    (usually PRIMARY_CLIP).  This handle structure will be used as the
    clipboard stream for IFFHandles initialized as clipboard streams by
    [InitIFFasClip()](../Includes_and_Autodocs_2._guide/node01CB.html).
```
INPUTS

```c
    unit    - clipboard unit number (usually PRIMARY_CLIP).
```
RESULT

```c
    ch      - pointer to [ClipboardHandle](../Includes_and_Autodocs_2._guide/node010B.html#line115) structure or NULL if
              unsuccessful.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [InitIFFasClip()](../Includes_and_Autodocs_2._guide/node01CB.html), [CloseClipboard()](../Includes_and_Autodocs_2._guide/node01BA.html)
```
