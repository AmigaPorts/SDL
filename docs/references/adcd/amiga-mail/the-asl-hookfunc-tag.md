---
title: The ASL_HookFunc Tag
manual: amiga-mail
chapter: amiga-mail
section: the-asl-hookfunc-tag
functions: []
libraries: []
---

# The ASL_HookFunc Tag

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The ASL_HookFunc tag passes an ASL requester a pointer to a custom
function.  The requester can use this function for two purposes.  The
first is to determine if the requester should display a particular file or
font name.  The other purpose is to process messages that the requester
receives at its IDCMP port that are not meant for the requester.  Some
ASL_FuncFlags flags toggle these options:


    FILF_DOWILDFUNC
    FONF_DOWILDFUNC
    FILF_DOMSGFUNC
    FONF_DOMSGFUNC
The FILF_DOWILDFUNC and FONF_DOWILDFUNC flags cause a requester to call
the hook function for every file or font entry.  The requester displays
the file or font name only if the hook function tells it to.  For a file
requester, if the hook function returns a zero, the file requester will
display the file name.  For a font requester, if the hook function returns
anything but zero, the font requester will display the font name and size.
Note that if the DOWILDFUNC function changes the current directory, it
must restort the current directory before it exits.  Neglecting to restore
the current directory can confuse DOS.

The FILF_DOMSGFUNC and FONF_DOMSGFUNC flags cause a requester to call the
hook function when it receives certain IntuiMessages at the IDCMP port it
shares with a window (see the ASL_Window tag).  The requester passes on
IntuiMessages not meant for the requester.  The hook function is
responsible for returning a pointer to the IntuiMessage.  The requester
will take care of replying to the message.

A requester passes three parameters to the hook function:


```c
    ULONG MyHookFunc(ULONG type, CPTR object, CPTR AslRequester)
```
If MyHookFunc() is called from a file requester doing DOWILDFUNC:


```c
    type = FILF_DOWILDFUNC
    object is a pointer to an AnchorPath structure (from <dos/dosasl.h>)
    AslRequester is a pointer to the FileRequester that called the hook
    function
    (Return a zero to display this file)
```
Note that the AnchorPath structure is a dos.library structure used in
pattern matching.  See dos.library documentation for more details.

Referencing the specific file or directory from within the DOWILDFUNC hook
function is a little tricky.  For a file requester, the rf_Dir field is
not guaranteed to contain the name of the directory being scanned.  The
correct way to find the file and directory name is from the AnchorPath
structure passed to the DOWILDFUNC.  The structure contains a
FileInfoBlock structure called ap_Info that contains the file name
(fib_FileName).  The AnchorPath structure's ap_Current field contains a
pointer to an AChain structure (from <dos/dosasl.h>) which contains a
field called an_Lock.  This is a lock on the directory being scanned.

If MyHookFunc() is called from a font requester doing DOWILDFUNC:


```c
    type = FONF_DOWILDFUNC
    object is a pointer to a TextAttr structure (from <graphics/text.h>)
    AslRequester is a pointer to the FontRequester that called the hook
    function
    (Return non-zero to display this particular font size)
```
If MyHookFunc() is called from a file or font requester doing DOMSGFUNC:


```c
    type = FILF_DOMSGFUNC
    object is a pointer to the IntuiMessage for the function to process
    AslRequester is a pointer to the FileRequester or FontRequester that
    called the hook function
    (Return the pointer to the IntuiMessage)
```
Notice that it is possible for a requester to use both DOWILDFUNC and
DOMSGFUNC at the same time.  The hook function has to differentiate
between the two cases by testing the type passed to it.  It is not
possible for font and file requester to share a hook function for a
DOWILDFUNC, because FILF_DOWILDFUNC is defined to be the same value as
FONF_DOWILDFUNC, so the hook function cannot tell if object (from the
prototype above) is a pointer to an AnchorPath structure or a pointer to a
TextAttr structure.  It is possible for font and file requesters to share
one hook function for DOMSGFUNC (even though FILF_DOMSGFUNC and
FONF_DOMSGFUNC are equal) because, in this case, font and file requesters
both call the hook function in the same manner.

The example [FileHook.c](amiga-mail/i-7-filehook-c.md) illustrates the use of a hook function for both
DOWILDFUNC and DOMSGFUNC.

