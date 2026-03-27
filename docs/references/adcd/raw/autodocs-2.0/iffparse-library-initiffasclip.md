# iffparse.library/InitIFFasClip



NAME

```c
    InitIFFasClip -- Initialize an [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) as a clipboard stream.
```
SYNOPSIS

```c
    InitIFFasClip (iff)
                   a0

    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
```
FUNCTION

```c
    Initializes the given [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) to be a clipboard stream.  The
    function initializes the stream processing vectors to operate on
    streams of the [ClipboardHandle](../Includes_and_Autodocs_2._guide/node010B.html#line115) type.  The iff_Stream field will still
    need to be initialized to point to a [ClipboardHandle](../Includes_and_Autodocs_2._guide/node010B.html#line115) as returned from
    [OpenClipboard()](../Includes_and_Autodocs_2._guide/node01CE.html).
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [OpenClipboard()](../Includes_and_Autodocs_2._guide/node01CE.html)
```
