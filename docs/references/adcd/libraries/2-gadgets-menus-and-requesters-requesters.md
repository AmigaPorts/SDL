---
title: 2 / / Gadgets, Menus And Requesters / Requesters
manual: libraries
chapter: libraries
section: 2-gadgets-menus-and-requesters-requesters
functions: []
libraries: []
---

# 2 / / Gadgets, Menus And Requesters / Requesters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[Gadgets](libraries/2-gadgets-menus-and-requesters-gadgets.md) and [menus](libraries/2-gadgets-menus-and-requesters-menus.md) do much of the work of getting commands and option
choices from the user.  Sometimes though, an application needs to get
further information from a user in response to a command which has already
been initiated.  In that case, a requester can be used.  A requester is a
[temporary sub-window](libraries/7-intuition-requesters-and-alerts-types-of-requesters.md), usually containing several gadgets, used to confirm
actions, access files, or adjust the special options of a command the user
has already given.


```c
     [Figure 2-5: An Intuition Requester](libraries/lib-pics-2-5-pic.md) 
```
Requesters are discussed in detail in Chapter 7,
"[Intuition Requesters and Alerts](libraries/7-intuition-requesters-and-alerts.md)".  Additional information on programming
requesters for Release 2 of the system can be found in Chapter 16,
"[ASL Library](libraries/16-asl-library.md)".

