---
title: IV-41: Writing a Boopsi Image Class
manual: amiga-mail
chapter: amiga-mail
section: iv-41-writing-a-boopsi-image-class
functions: []
libraries: []
---

# IV-41: Writing a Boopsi Image Class

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

By David N. Junod



    Editor's note: this article and its source code reference
    several functions that, at press time, were only available from
    the classface.asm and hookface.asm assembly source files that
    appear on the Atlanta and Milan DevCon disks.  The functions
    from these files should eventually appear in amiga.lib.
The most sophisticated level of Intuition programming is to write a boopsi
class.  The easiest way to enter the boopsi class writer's arena is to
write an image class.

Boopsi's imageclass is one of the standard classes built into Intuition.
As its name implies, it is a class of Intuition Images.  These boopsi
images can be used in place of traditional Image structure (as they
contain an Intuition Image structure), but they are much more powerful.
By using boopsi methods, an application or Intuition can tell an
imageclass object to render itself.  Because it renders itself (rather
than Intuition rendering it), the imageclass object is free to render
whatever it wants (well, within reason).  For example, a boopsi image
object can render itself according to the current display resolution, or
to scale itself to any size an application requests.

This article is designed to provide the novice boopsi programmer with the
information needed to write an image class for their application.  This
article assumes the reader is already familar with some boopsi concepts.
For more information on boopsi, see the article "[Introduction to Boopsi](amiga-mail/iv-23-introduction-to-boopsi.md)"
in the March/April 1991 issue of Amiga Mail or the Atlanta (or Milan)
DevCon notes and disks.  The example custom class at the end of this
article, [mytextlabelclass.c](amiga-mail/iv-41-mytextlabelclass-c.md), shows how to create a custom image class that
renders a text label with an underline beneath a character.  This
character can be used to trigger some event.

When designing a specific class, you must first choose a superclass that
is suitable for your needs.  If you are creating a new image class, then
its superclass will either be imageclass or some subclass of imageclass.

Classes may be public or private.  Any application can access a public
class.  Before a class can be considered public it must first have a name
and must be part of  the public class list maintained by Intuition.  It
can then be accessed by other applications.  A private class is not in the
public class list and can only be used by applications that have a pointer
to the Class structure (usually the application that implemented the
class).

 [Callback Hooks](amiga-mail/callback-hooks.md)                   [Boopsi Rootclass Methods](amiga-mail/boopsi-rootclass-methods.md) 
 [Initializing a Boopsi Class](amiga-mail/initializing-a-boopsi-class.md)      [Imageclass Methods](amiga-mail/imageclass-methods.md) 
 [Boopsi Dispatcher](amiga-mail/boopsi-dispatcher.md)                [Image Class Example](amiga-mail/image-class-example.md) 

