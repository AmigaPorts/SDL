---
title: 7 Intuition Requesters and Alerts / Function Reference
manual: libraries
chapter: libraries
section: 7-intuition-requesters-and-alerts-function-reference
functions: [AutoRequest, BuildEasyRequestArgs, BuildSysRequest, ClearDMRequest, DisplayAlert, EasyRequestArgs, EndRequest, FreeSysRequest, InitRequester, Request, SetDMRequest, SysReqHandler]
libraries: [intuition.library]
---

# 7 Intuition Requesters and Alerts / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the Intuition functions that
relate to the use of Intuition requesters and alerts.  See the Amiga ROM
Kernel Reference Manual: Includes and Autodocs for details on each
function call.

         Table 7-1: Functions for Intuition Requesters and Alerts
  ________________________________________________________________________
 |                                                                        |
 |          Function                   Description                        |
 |========================================================================|
 |               [Request()](autodocs-2.0/intuition-library-request.md)  Open a requester in an open window.           |
 |            [EndRequest()](autodocs-2.0/intuition-library-endrequest.md)  Close an open requester in a window.          |
 |         [InitRequester()](autodocs-2.0/intuition-library-initrequester.md)  Clear a requester structure before use.       |
 |------------------------------------------------------------------------|
 |       [EasyRequestArgs()](autodocs-2.0/intuition-library-easyrequestargs.md)  Open a [system](libraries/7-intuition-requesters-and-alerts-system-requesters.md) requester.                      |
 |           [EasyRequest()](autodocs-2.0/intuition-library-easyrequestargs.md)  Alternate calling sequence for                |
 |                          EasyRequestArgs().                            |
 |  [BuildEasyRequestArgs()](autodocs-2.0/intuition-library-buildeasyrequestargs.md)  Low level function to open an EasyRequester.  |
 |      [BuildEasyRequest()](autodocs-2.0/intuition-library-buildeasyrequestargs.md)  Alternate calling sequence for                |
 |                          BuildEasyRequestArgs().                       |
 |         [SysReqHandler()](autodocs-2.0/intuition-library-sysreqhandler.md)  Event handler function for EasyRequestArgs(). |
 |------------------------------------------------------------------------|
 |           [AutoRequest()](autodocs-2.0/intuition-library-autorequest.md)  Open a pre-V36 system requester.              |
 |       [BuildSysRequest()](autodocs-2.0/intuition-library-buildsysrequest.md)  Low level function to open an AutoRequest().  |
 |        [FreeSysRequest()](autodocs-2.0/intuition-library-freesysrequest.md)  Low level function to close an AutoRequest(). |
 |------------------------------------------------------------------------|
 |          [SetDMRequest()](autodocs-2.0/intuition-library-setdmrequest.md)  Set a [double menu](libraries/7-true-requesters-double-menu-requesters.md) requester for an open       |
 |                          window.                                       |
 |        [ClearDMRequest()](autodocs-2.0/intuition-library-cleardmrequest.md)  Clear a double menu requester from an open    |
 |                          window.                                       |
 |------------------------------------------------------------------------|
 |          [DisplayAlert()](autodocs-2.0/intuition-library-displayalert.md)  Open an alert on the screen.                  |
 |________________________________________________________________________|

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [BuildEasyRequestArgs — intuition.library](../autodocs/intuition.library.md#buildeasyrequestargs)
- [BuildSysRequest — intuition.library](../autodocs/intuition.library.md#buildsysrequest)
- [ClearDMRequest — intuition.library](../autodocs/intuition.library.md#cleardmrequest)
- [DisplayAlert — intuition.library](../autodocs/intuition.library.md#displayalert)
- [EasyRequestArgs — intuition.library](../autodocs/intuition.library.md#easyrequestargs)
- [EndRequest — intuition.library](../autodocs/intuition.library.md#endrequest)
- [FreeSysRequest — intuition.library](../autodocs/intuition.library.md#freesysrequest)
- [InitRequester — intuition.library](../autodocs/intuition.library.md#initrequester)
- [Request — intuition.library](../autodocs/intuition.library.md#request)
- [SetDMRequest — intuition.library](../autodocs/intuition.library.md#setdmrequest)
- [SysReqHandler — intuition.library](../autodocs/intuition.library.md#sysreqhandler)
