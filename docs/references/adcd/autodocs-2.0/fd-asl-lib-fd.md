---
title: FD/asl_lib.fd
manual: autodocs-2.0
chapter: autodocs-2.0
section: fd-asl-lib-fd
functions: [AllocFileRequest]
libraries: [asl.library]
---

# FD/asl_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* "asl.library"
##base _AslBase
##bias 30
##public
*--- functions in V36 or higher (distributed as Release 2.0) ---
*
AllocFileRequest()()
FreeFileRequest(fileReq)(a0)
RequestFile(fileReq)(a0)
AllocAslRequest(type,tagList)(d0/a0)
FreeAslRequest(request)(a0)
AslRequest(request,tagList)(a0/a1)
##end

---

## See Also

- [AllocFileRequest — asl.library](../autodocs/asl.library.md#allocfilerequest)
