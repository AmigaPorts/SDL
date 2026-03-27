---
title: Other CxObjects
manual: amiga-mail
chapter: amiga-mail
section: other-cxobjects
functions: [CxMsgData]
libraries: [commodities.library]
---

# Other CxObjects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are three remaining CxObjects:


```c
    signalCxObj = CxObj  *CxSignal(struct Task *,LONG signal);
    debugCxObj  = CxObj  *CxDebug(LONG ID);
    customCxObj = CxObj  *CxCustom(LONG *customfunction(), LONG  cxmID);
```
When a signal CxObject receives a CxMessage, it signals a task.  When
a debug CxObject receives a CxMessage, it sends debugging information
to the serial port using kprintf().  Note that the debug CxObj did not
work before V37.

A custom CxObject is the only means by which a commodity can directly
modify input events as they pass through the Commodities network as
CxMessages.  The custom CxObject is probably the most dangerous of the
CxObjects to use.  Unlike the rest of the code
 a commodities programmer writes, the code passed to a custom CxObject
runs as part of the input.device task, putting severe restrictions on
the function.  No DOS or Intuition functions can be called.  No
assumptions can be made about the values of regist ers upon entry.
Any function passed to CxCustom() should be very quick and very
simple, with a minimum of stack usage.

Commodities Exchange calls a custom CxObject's function as follows:


```c
    void customfunction(CxMsg *cxm, CxObj *customcxobj);
```
where cxm is a pointer to a CxMessage corresponding to a real input
event, and customcxobj is a pointer to the custom CxObject.  The
custom function can extract the pointer to the input event by calling
CxMsgData().  Before passing the CxMessage to the cu stom function,
Commodities Exchange sets the CxMessage's ID to the ID passed to
CxCustom().

---

## See Also

- [CxMsgData — commodities.library](../autodocs/commodities.library.md#cxmsgdata)
