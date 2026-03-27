---
title: 14 / / Argument Passing In Workbench / Two Arguments
manual: libraries
chapter: libraries
section: 14-argument-passing-in-workbench-two-arguments
functions: []
libraries: []
---

# 14 / / Argument Passing In Workbench / Two Arguments

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All project icons (data files) have a default tool field associated with
them that tells Workbench which application tool to run in order to
operate on the data that the icon represents.  When the user activates a
project icon, Workbench runs the application specified in the default tool
field passing it two arguments in the [WBStartup](libraries/14-workbench-environment-wbstartup-message.md) message: the name of the
tool and the project icon that the user activated.

