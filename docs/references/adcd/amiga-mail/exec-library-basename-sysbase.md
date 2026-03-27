---
title: exec.library (basename: _SysBase)
manual: amiga-mail
chapter: amiga-mail
section: exec-library-basename-sysbase
functions: [AllocVec, CacheClearU, ColdReboot, CreateIORequest, CreateMsgPort]
libraries: [exec.library]
---

# exec.library (basename: _SysBase)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

AllocVec(byteSize,requirements)(d0/d1)  - Allocate memory and keep track
```c
                                          of the size  (V36)
```
CacheClearE(address,length,caches)(a0,d0/d1)
```c
                                        - Cache clearing with extended
                                          control (V37)
```
CacheClearU()()                         - User callable simple cache
```c
                                          clearing (V37)
```
CacheControl(cacheBits,cacheMask)(d0/d1)- Instruction & data cache control
CachePostDMA(address,length,flags)(a0/a1,d1)
```c
                                        - Take actions after to hardware
                                          DMA  (V37)
```
CachePreDMA(address,length,flags)(a0/a1,d1)
```c
                                        - Take actions prior to hardware
                                          DMA  (V37)
```
ColdReboot()()                          - Reboot the Amiga (V36)
CreateIORequest(port,size)(a0,d0)       - Create an IORequest structure
```c
                                          (V36)
```
CreateMsgPort()()                       - Allocate and initialize a new
```c
                                          message port  (V36)
```
DeleteIORequest(iorequest)(a0)          - Free a request made by
```c
                                          CreateIORequest()  (V36)
```
DeleteMsgPort(port)(a0)                 - Free a message port created by
```c
                                          CreateMsgPort  (V36)
```
FreeVec(memoryBlock)(a1)                - Return AllocVec() memory to the
```c
                                          system  (V36)
```
ObtainSemaphoreShared(sigSem)(a0)       - Gain shared access to a
```c
                                          semaphore (V36)
```
StackSwap(newSize,newSP,newStack)(d0/d1/a0)

                                        - Exec supported method of
                                          replacing a task's stack.

---

## See Also

- [AllocVec — exec.library](../autodocs/exec.library.md#allocvec)
- [CacheClearU — exec.library](../autodocs/exec.library.md#cacheclearu)
- [ColdReboot — exec.library](../autodocs/exec.library.md#coldreboot)
- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
