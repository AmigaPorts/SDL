---
title: 31 Commodities Exchange Library / Custom CxObjects
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-custom-cxobjects
functions: [CxMsgData]
libraries: [commodities.library]
---

# 31 Commodities Exchange Library / Custom CxObjects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Although the [CxObjects](libraries/31-commodities-exchange-library-cxobjects.md) mentioned so far take care of most of the input
event handling a commodity needs to do, they cannot do it all.  This is
why Commodities Exchange has a custom CxObject.  When a custom CxObject
receives a [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md), it calls a function provided by the commodity.


```c
    customCxObj = CxObj  *CxCustom(LONG *customfunction(), LONG  cxmID);
```
A custom [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) is the only means by which a commodity can directly
modify input events as they pass through the Commodities network as
[CxMessages](libraries/31-commodities-exchange-library-cxmessages.md).  For this reason, it is probably the most dangerous of the
CxObjects to use.


```c
    A Warning About Custom CxObjects.
    ---------------------------------
    Unlike the rest of the code a commodities programmer writes, the
    code passed to a custom [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) runs as part of the input.device
    task, putting severe restrictions on the function.  No DOS or
    Intuition functions can be called.  No assumptions can be made about
    the values of registers upon entry.  Any function passed to
    [CxCustom()](autodocs-2.0/amiga-lib-cxcustom.md) should be very quick and very simple, with a minimum of
    stack usage.
```
Commodities Exchange calls a custom [CxObject](libraries/31-commodities-exchange-library-cxobjects.md)'s function as follows:


```c
    void customfunction(CxMsg *cxm, CxObj *customcxobj);
```
where cxm is a pointer to a [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md) corresponding to a real input event,
and customcxobj is a pointer to the custom [CxObject](libraries/31-commodities-exchange-library-cxobjects.md).  The custom function
can extract the pointer to the input event by calling [CxMsgData()](libraries/31-commodities-exchange-library-cxmessages.md).  Before
passing the CxMessage to the custom function, Commodities Exchange sets
the CxMessage's ID to the ID passed to [CxCustom()](autodocs-2.0/amiga-lib-cxcustom.md).

The following is an example of a custom [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) function that swaps
the function of the left and right mouse buttons.


custom = CxCustom(CxFunction, 0L)

/* The custom function for the custom CxObject.  Any code for a */
/* custom CxObj must be short and sweet. This code runs as part */
/* of the input.device task                                     */
#define CODEMASK (0x00FF & IECODE_LBUTTON & IECODE_RBUTTON)
void CxFunction(register CxMsg *cxm, CxObj *co)
{
```c
    struct InputEvent *ie;
    UWORD mousequals = 0x0000;

    /* Get the struct InputEvent associated with this CxMsg.  Unlike
     * the InputEvent extracted from a CxSender's CxMsg, this is a
     *  *REAL* input event, be careful with it.
     */
    ie = (struct InputEvent *)CxMsgData(cxm);

    /* Check to see if this input event is a left or right mouse button
     * by itself (a mouse button can also be a qualifier).  If it is,
     * flip the low order bit to switch leftbutton <--> rightbutton.
     */
    if (ie->ie_Class == IECLASS_RAWMOUSE)
        if ((ie->ie_Code & CODEMASK) == CODEMASK)  ie->ie_Code ^= 0x0001;

    /* Check the qualifiers. If a mouse button was down when this */
    /* input event occurred, set the other mouse button bit.      */
    if (ie->ie_Qualifier & IEQUALIFIER_RBUTTON)  mousequals |=
                                                   IEQUALIFIER_LEFTBUTTON;
    if (ie->ie_Qualifier & IEQUALIFIER_LEFTBUTTON)  mousequals |=
                                                      IEQUALIFIER_RBUTTON;

    /* clear the RBUTTON and LEFTBUTTON qualifier bits */
    ie->ie_Qualifier &= ~(IEQUALIFIER_LEFTBUTTON | IEQUALIFIER_RBUTTON);

    /* set the mouse button qualifier bits to their new values */
    ie->ie_Qualifier |= mousequals;
```
}

---

## See Also

- [CxMsgData — commodities.library](../autodocs/commodities.library.md#cxmsgdata)
