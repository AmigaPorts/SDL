---
title: 33 / Stream Management / Initialization
manual: libraries
chapter: libraries
section: 33-stream-management-initialization
functions: [CloseIFF, InitIFF, InitIFFasClip, InitIFFasDOS, Open, OpenClipboard, OpenIFF]
libraries: [dos.library, iffparse.library]
---

# 33 / Stream Management / Initialization

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As shown above, the [IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md) structure contains the public field
iff_Stream.  This is a longword that must be initialized to contain
something meaningful to the stream manager.  IFFParse never looks at this
field itself (at least not directly).  Your iff_Stream may be an AmigaDOS
filehandle, or an IFFParse ClipboardHandle, or a custom stream of any type
if you provide your own custom stream handler (see the section on
"[Custom Stream Handlers](libraries/33-advanced-topics-custom-stream-handlers.md)" later in this chapter).  You must initialize your
IFFHandle structure's iff_Stream to your stream, and then initialize the
IFFHandle's flags and stream hook.

Three sample initializations are shown here.  In the case of the internal
DOS stream manager, iff_Stream is an AmigaDOS filehandle as returned by
[Open()](autodocs-2.0/dos-library-open.md):


```c
    iff->iff_Stream = (ULONG) Open ("filename", MODE_OLDFILE);
    if(iff->iff_Stream) InitIFFasDOS (iff);
        /* use internal DOS stream manager */
```
In the case of the internal Clipboard stream manager, iff_Stream is a
pointer to an IFFParse ClipboardHandle structure (the [OpenClipboard()](autodocs-2.0/iffparse-library-openclipboard.md) call
used here is a function of iffparse.library, not the clipboard.device):


```c
    iff->iff_Stream = (ULONG) OpenClipboard (PRIMARY_CLIP);
    InitIFFasClip (iff); /* use internal Clipboard stream manager  */
```
When using a custom handle such as an [fopen()](libraries/33-custom-stream-handlers-installing-a-custom-stream-handler.md) file handle, or a device
other than the clipboard, you must provide your own flags and stream
handler:


```c
    iff->iff_Stream = (ULONG) OpenMyCustomStream("foo");
    InitIFF (iff, IFFF_FSEEK | IFFF_RSEEK, &mystreamhook);
```
IFFParse "knows" the seek capabilities of DOS and ClipboardHandle streams,
so [InitIFFasDOS()](autodocs-2.0/iffparse-library-initiffasdos.md) and [InitIFFasClip()](autodocs-2.0/iffparse-library-initiffasclip.md) set the flags for you.


```c
    You May Change the Seek Bits in iff_Flags:
    ------------------------------------------
    IFFParse sets IFFF_FSEEK | IFFF_RSEEK for DOS files.  This is not
    always true (e.g., pipes).  If you know that a DOS file has different
    seek characteristics, your application may correct the seek bits in
    iff_Flags after calling [InitIFFasDOS()](autodocs-2.0/iffparse-library-initiffasdos.md).
```
When using [InitIFF()](autodocs-2.0/iffparse-library-initiff.md) to provide a custom handler, you must also provide
flags to tell IFFParse the capabilities of your stream.  The flags are:




    IFFF_FSEEK:  This stream has forward-seek capability only.
    IFFF_RSEEK:  This stream has random-seek capability.
                 IFFF_RSEEK tends to imply IFFF_FSEEK, but it's
                 best to specify both.
If neither flag is specified, you're telling IFFParse that it can't seek
through the stream.

After your stream is initialized, call [OpenIFF()](autodocs-2.0/iffparse-library-openiff.md):


```c
    error = OpenIFF (iff, IFFF_READ);
```
Once you establish a read/write mode (by passing IFFF_READ or IFFF_WRITE),
you remain in that mode until you call [CloseIFF()](libraries/33-stream-management-termination.md).

---

## See Also

- [CloseIFF — iffparse.library](../autodocs/iffparse.library.md#closeiff)
- [InitIFF — iffparse.library](../autodocs/iffparse.library.md#initiff)
- [InitIFFasClip — iffparse.library](../autodocs/iffparse.library.md#initiffasclip)
- [InitIFFasDOS — iffparse.library](../autodocs/iffparse.library.md#initiffasdos)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [OpenClipboard — iffparse.library](../autodocs/iffparse.library.md#openclipboard)
- [OpenIFF — iffparse.library](../autodocs/iffparse.library.md#openiff)
