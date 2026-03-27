---
title: rexxsyslib.library (basename: _RexxSysBase)  V36
manual: amiga-mail
chapter: amiga-mail
section: rexxsyslib-library-basename-rexxsysbase-v36
functions: [CreateArgstring, CreateRexxMsg]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library (basename: _RexxSysBase)  V36

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ClearRexxMsg(msgptr,count)(a0,d0)       - Releases and clears the argument
                                          array in a RexxMsg
CreateArgstring(string,length)(a0,d0)   - Create an argument string
                                          structure
CreateRexxMsg(port,extension,host)(a0/a1,d0)
                                        - Create an ARexx message
                                          structure
DeleteArgstring(argstring)(a0)          - Releases an Argstring created by
```c
                                          CreateArgstring()
```
DeleteRexxMsg(packet)(a0)               - Releases a RexxMsg structure
```c
                                          created by CreateRexxMsg()
```
FillRexxMsg(msgptr,count,mask)(a0,d0/d1)- Fill the argument strings as
                                          needed
IsRexxMsg(msgptr)(a0)                   - Function to determine if a
                                          message came from ARexx
LengthArgstring(argstring)(a0)          - Returns the length value stored
                                          in the argstring
LockRexxBase(resource)(d0)              - Obtain a semaphore lock on the
                                          RexxBase structure
UnlockRexxBase(resource)(d0)            - Release a semaphore lock on the

                                          RexxBase structure

---

## See Also

- [CreateArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createargstring)
- [CreateRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createrexxmsg)
