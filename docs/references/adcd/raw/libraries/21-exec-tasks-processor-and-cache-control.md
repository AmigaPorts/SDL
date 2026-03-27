# 21 Exec Tasks / Processor and Cache Control


Exec provides a number of to control the processor mode and, if available,
the caches.  All these functions work independently of the specific M68000
family processor type.  This enables you to write code which correctly
controls the state of both the MC68000 and the MC68040.  Along with
processor mode and cache control, functions are provided to obtain
information about the condition code register (CCR) and status register
(SR).  No functions are provided to control a paged memory management unit
(PMMU) or floating point unit (FPU).


          Table 21-2: Processor and Cache Control Functions
   __________________________________________________________________
  |                                                                  |
  |     Function              Description                            |
  |==================================================================|
  |         [GetCC()](../Libraries_Manual_guide/node02CC.html)  Get processor condition codes.                  |
  |         [SetSR()](../Libraries_Manual_guide/node02CB.html)  Get/set processor status register.              |
  |    [SuperState()](../Libraries_Manual_guide/node02CA.html#line21)  Set supervisor mode with user stack.            |
  |    [Supervisor()](../Libraries_Manual_guide/node02CA.html#line10)  Execute a short supervisor mode function.       |
  |     [UserState()](../Libraries_Manual_guide/node02CA.html#line21)  Return to user mode with user stack.            |
  |------------------------------------------------------------------|
  |   [CacheClearE()](../Includes_and_Autodocs_2._guide/node0338.html)  Flush CPU instruction and/or data caches (V37). |
  |   [CacheClearU()](../Libraries_Manual_guide/node02CF.html#line45)  Flush CPU instruction and data caches (V37).    |
  |  [CacheControl()](../Includes_and_Autodocs_2._guide/node033A.html)  Global cache control (V37).                     |
  |  [CachePostDMA()](../Libraries_Manual_guide/node02CE.html)  Perform actions prior to hardware DMA (V37).    |
  |   [CachePreDMA()](../Libraries_Manual_guide/node02CE.html)  Perform actions after hardware DMA (V37).       |
  |__________________________________________________________________|


 [Supervisor Mode](../Libraries_Manual_guide/node02CA.html)    [Condition Code Register](../Libraries_Manual_guide/node02CC.html)    [DMA Cache Functions](../Libraries_Manual_guide/node02CE.html) 
 [Status Register](../Libraries_Manual_guide/node02CB.html)    [Cache Functions](../Libraries_Manual_guide/node02CD.html)            [The 68040 and CPU Caches](../Libraries_Manual_guide/node02CF.html) 

