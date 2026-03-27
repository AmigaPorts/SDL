---
title: asl.library (basename: _AslBase)  V36
manual: amiga-mail
chapter: amiga-mail
section: asl-library-basename-aslbase-v36
functions: [AllocFileRequest]
libraries: [asl.library]
---

# asl.library (basename: _AslBase)  V36

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

AllocAslRequest(type,tagList)(d0/a0)    - Also stack-based amiga.lib stub
```c
                                          AllocAslRequestTags() alloc an
                                          ASL requester, with TagItem
                                          modifiers (V36)
```
AllocFileRequest()()                    - Allocates a FileRequester
```c
                                          structure (V36)
```
AslRequest(request,tagList)(a0/a1)      - lso stack-based amiga.lib stub
```c
                                          AslRequestTags().  Get input
                                          from user for an ASL requester
                                          (V36)
```
FreeAslRequest(request)(a0)             - Frees requester obtained from
```c
                                          AllocAslRequest (V36)
```
FreeFileRequest(fileReq)(a0)            - Frees requester allocated by
```c
                                          AllocFileRequest (V36)
```
RequestFile(fileReq)(a0)                - request user to select file(s)

```c
                                          (V36)
```

---

## See Also

- [AllocFileRequest — asl.library](../autodocs/asl.library.md#allocfilerequest)
