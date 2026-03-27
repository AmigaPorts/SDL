---
title: 1 / 1.3 Compatibility Issues / Design Decisions
manual: libraries
chapter: libraries
section: 1-1-3-compatibility-issues-design-decisions
functions: [CreateNewProc]
libraries: [dos.library]
---

# 1 / 1.3 Compatibility Issues / Design Decisions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The latest Amiga models, including all A3000's, are running [Release 2](libraries/1-operating-system-versions-about-release-2.md).
But many older Amigas are still running 1.3 at this time.  Depending on
your application and your market, you may choose to require the Release 2
operating system as a minimum platform.  This can be a reasonable
requirement for vertical markets and professional applications.  Release 2
can also be a reasonable requirement for new revisions of existing
software products, since you could continue to ship the older
1.3-compatible release in the same package.  If you have made the decision
to require Release 2, then you are free to take advantage of all of the
new libraries and features that Release 2 provides.

Throughout this latest edition of the Amiga Technical Reference Series,
features, functions and libraries that are new for [Release 2](libraries/1-operating-system-versions-about-release-2.md) are usually
indicated by (V36) or (V37) in the description of the feature.  Such
features are not available on Amiga models that are running 1.3 (V34) or
[earlier versions](libraries/1-programming-in-the-amiga-environment-operating-system.md) of the OS.  Unconditional use of Release 2 functions will
cause a program to fail when it is run on a machine with the 1.3 OS.  It
is very important to remember this when designing and writing your code.

Developers of consumer-priced productivity, entertainment and utility
software may not yet be ready to write applications that require
[Release 2](libraries/1-operating-system-versions-about-release-2.md), but even these developers can enhance their products by taking
advantage of Release 2 while remaining 1.3 compatible.

There are three basic methods that will allow you to take advantage of
enhanced Release 2 features while remaining 1.3 compatible:


      * Transparent Release 2 Extensions

      * Conditional Code

      * Compatible Libraries
 [Transparent Release 2 Extensions](libraries/1-design-decisions-transparent-release-2-extensions.md) 
 [Conditional Code](libraries/1-design-decisions-conditional-code.md) 
 [ASL Requesters](libraries/1-design-decisions-asl-requesters.md) 
 [DOS System(), CreateNewProc(), and CON: Enhancements](libraries/1-design-dos-system-createnewproc-and-con-enhancements.md) 
 [The Display Database](libraries/1-design-decisions-the-display-database.md) 
 [ARexx](libraries/1-design-decisions-arexx.md) 

---

## See Also

- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)
