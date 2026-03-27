# 33 / Stream Management / Initialization


As shown above, the [IFFHandle](../Libraries_Manual_guide/node042C.html) structure contains the public field
iff_Stream.  This is a longword that must be initialized to contain
something meaningful to the stream manager.  IFFParse never looks at this
field itself (at least not directly).  Your iff_Stream may be an AmigaDOS
filehandle, or an IFFParse ClipboardHandle, or a custom stream of any type
if you provide your own custom stream handler (see the section on
"[Custom Stream Handlers](../Libraries_Manual_guide/node0454.html)" later in this chapter).  You must initialize your
IFFHandle structure's iff_Stream to your stream, and then initialize the
IFFHandle's flags and stream hook.

Three sample initializations are shown here.  In the case of the internal
DOS stream manager, iff_Stream is an AmigaDOS filehandle as returned by
[Open()](../Includes_and_Autodocs_2._guide/node02D6.html):


```c
    iff->iff_Stream = (ULONG) Open ("filename", MODE_OLDFILE);
    if(iff->iff_Stream) InitIFFasDOS (iff);
        /* use internal DOS stream manager */
```
In the case of the internal Clipboard stream manager, iff_Stream is a
pointer to an IFFParse ClipboardHandle structure (the [OpenClipboard()](../Includes_and_Autodocs_2._guide/node01CE.html) call
used here is a function of iffparse.library, not the clipboard.device):


```c
    iff->iff_Stream = (ULONG) OpenClipboard (PRIMARY_CLIP);
    InitIFFasClip (iff); /* use internal Clipboard stream manager  */
```
When using a custom handle such as an [fopen()](../Libraries_Manual_guide/node0455.html) file handle, or a device
other than the clipboard, you must provide your own flags and stream
handler:


```c
    iff->iff_Stream = (ULONG) OpenMyCustomStream("foo");
    InitIFF (iff, IFFF_FSEEK | IFFF_RSEEK, &mystreamhook);
```
IFFParse "knows" the seek capabilities of DOS and ClipboardHandle streams,
so [InitIFFasDOS()](../Includes_and_Autodocs_2._guide/node01CC.html) and [InitIFFasClip()](../Includes_and_Autodocs_2._guide/node01CB.html) set the flags for you.


```c
    You May Change the Seek Bits in iff_Flags:
    ------------------------------------------
    IFFParse sets IFFF_FSEEK | IFFF_RSEEK for DOS files.  This is not
    always true (e.g., pipes).  If you know that a DOS file has different
    seek characteristics, your application may correct the seek bits in
    iff_Flags after calling [InitIFFasDOS()](../Includes_and_Autodocs_2._guide/node01CC.html).
```
When using [InitIFF()](../Includes_and_Autodocs_2._guide/node01CA.html) to provide a custom handler, you must also provide
flags to tell IFFParse the capabilities of your stream.  The flags are:




    IFFF_FSEEK:  This stream has forward-seek capability only.
    IFFF_RSEEK:  This stream has random-seek capability.
                 IFFF_RSEEK tends to imply IFFF_FSEEK, but it's
                 best to specify both.
If neither flag is specified, you're telling IFFParse that it can't seek
through the stream.

After your stream is initialized, call [OpenIFF()](../Includes_and_Autodocs_2._guide/node01CF.html):


```c
    error = OpenIFF (iff, IFFF_READ);
```
Once you establish a read/write mode (by passing IFFF_READ or IFFF_WRITE),
you remain in that mode until you call [CloseIFF()](../Libraries_Manual_guide/node042F.html).

