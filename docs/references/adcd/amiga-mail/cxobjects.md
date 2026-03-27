---
title: CxObjects
manual: amiga-mail
chapter: amiga-mail
section: cxobjects
functions: []
libraries: []
---

# CxObjects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

CxObjects are the basic building blocks used to construct a
commodity. A commodity uses CxObjects to take care of all
manipulations of CxMessages. When a CxMessage "arrives" at a
CxObject, that CxObject carries out its primitive action and then, if
it has not deleted the CxMessage, it passes the CxMessage on to the
next CxObject.  A commodity links together CxObjects into a tree,
organizing these simple action objects to perform some higher
function.

A CxObject is in one of two states, active or inactive.  An active
CxObject performs its primitive action every time it receives a
CxMessage.  If a CxObject is inactive, CxMessages bypass it,
continuing to the CxObject that follows the inactive one.  By d
efault, all CxObjects except the type called brokers are created in
the active state.

   [Figure 1: The Commodities Network](amiga-mail/xi-1-cx-ilbm.md) 

