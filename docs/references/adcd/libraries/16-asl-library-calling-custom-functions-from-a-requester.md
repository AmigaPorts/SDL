---
title: 16 ASL Library / Calling Custom Functions from a Requester
manual: libraries
chapter: libraries
section: 16-asl-library-calling-custom-functions-from-a-requester
functions: []
libraries: []
---

# 16 ASL Library / Calling Custom Functions from a Requester

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The ASL_HookFunc tag passes an ASL requester a pointer to a custom
function.  The requester can use this function for two purposes.  The
first is to determine if the requester should display a particular file or
font name.  The other purpose is to process messages that the requester
receives at its IDCMP port that are not meant for the requester.  Hook
functions are set up through flag values used with the ASL_FuncFlags tag:




    Hook Function Flag  Used For
    ------------------  --------
    FILF_DOWILDFUNC     Call user hook function on each name in a file
                        requester
    FONF_DOWILDFUNC     Call user hook function on each name in a font
                        requester
    FILF_DOMSGFUNC      Call user hook function for IDCMP messages not
                        used by a file requester
    FONF_DOMSGFUNC      Call user hook function for IDCMP messages not
                        used by a font requester
The FILF_DOWILDFUNC and FONF_DOWILDFUNC flags cause a requester to call
the function you specify with the ASL_HookFunc tag for every file or font
entry.  The requester displays the file or font name only if your hook
function tells it to.  For a file requester, if your hook function returns
a zero, the file requester will display the file name.  For a font
requester, if your hook function returns anything but zero, the font
requester will display the font name and size.

The FILF_DOMSGFUNC and FONF_DOMSGFUNC flags cause a requester to call your
hook function whenever it receives an [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) that it cannot use at
the IDCMP port that it shares with your window.  (See the section on
"[ASL Requesters and Custom Screens](libraries/16-creating-a-file-requester-asl-requesters-and-custom.md)" earlier in this chapter for more
information about sharing IDCMP ports.)  If the requester receives any
messages that are not meant for the requester it will call your hook
function (specified with the ASL_HookFunc tag).  Your hook function is
responsible for returning a pointer to the IntuiMessage.  The requester
will take care of replying to the message.

 [Parameters Passed to Custom Hook Functions](libraries/16-calling-functions-parameters-passed-to-custom-hook.md) 
 [Example ASL Requester with Custom Hook Function](libraries/lib-examples-filehook-c.md) 

