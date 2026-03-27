---
title: III-29/Armadillo_lib.fd
manual: amiga-mail
chapter: amiga-mail
section: iii-29-armadillo-lib-fd
functions: []
libraries: []
---

# III-29/Armadillo_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

*
* armadillo.library - Sample SAS/C run-time library
*
* © Copyright Amiga, Inc.
* All Rights Reserved.
*
##base _DilloBase
##bias 30
##public
CreateArmadillo()()
DeleteArmadillo(dillo)(A0)
NameArmadillo(dillo,name,len)(A0/A1,D0)
FillArmadillo(dillo,weight)(A0,D0)
FlattenArmadillo(dillo,flat)(A0,D0)
DilloFlat(dillo)(A0)
DilloWeight(dillo)(A0)
DilloName(dillo,buf,len)(A0/A1,D0)
ClearDillo(dillo)(A0)
DilloBirths()()
##end

