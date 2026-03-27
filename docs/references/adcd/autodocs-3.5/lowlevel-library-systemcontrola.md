---
title: lowlevel.library/SystemControlA
manual: autodocs-3.5
chapter: autodocs-3.5
section: lowlevel-library-systemcontrola
functions: [OpenWindow, Wait]
libraries: [exec.library, intuition.library]
---

# lowlevel.library/SystemControlA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SystemControlA - Method for selectively disabling OS features. (V40)
	SystemControl - varargs stub for SystemControlA().

   SYNOPSIS
	failTag = SystemControlA(tagList);
	D0                       A1

	ULONG SystemControlA(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	failTag = SystemControl(firstTag, ...);

	ULONG SystemControl(Tag, ...);

   FUNCTION
	This function is used to alter the operation of the system. Some of
	the alterations involve controlling what are normally regarded as
	system resources. In order to minimize confusion only one task is
	allowed to control any part of the system resources. This prevents
	the possiblity of two tasks fighting, each controlling a part of the
	system. If a tag is identified as task exclusive, it means that
	only one task can hold (set to TRUE) that tag. If
	another task attempts to set the same tag to TRUE, the call to
	SystemControl() will fail.

	It is important to remember that SystemControl() can fail.

	This is a low level function and certain tags do not fit the normal
	Amiga multitasking model.

   INPUTS
	tagList - pointer to an array of tags listing the features of the
	          system to be enabled/disabled.

   TAGS
	SCON_TakeOverSys (BOOL)
		TRUE -	Takes over the CPU to ensure that a program gets every
			ounce of CPU time (with the exception of crucial
			interrupts). When in this mode, the CPU will belong
			completely to the program. [Task](autodocs-3.5/include-exec-tasks-h.md) switching will be
			disabled and the program will get all CPU cycles. This
			means any calls to the OS that involve multitasking in
			some way will not execute correctly. Other tasks will
			not run until this tag is used with FALSE. However,
			during a [Wait()](autodocs-3.5/exec-library-wait-2.md) on a signal, multitasking will
			automatically be turned back on until the signal is
			received. Once received, multitasking will again be
			disabled and the CPU will be exclusive to the owning
			program.
		FALSE - Relinquishes the CPU and reenables multitasking.
			This tag is task exculsive. This tag nests. A task may
			take over the CPU several times before relinquishing
			it.

	SCON_KillReq (BOOL)
	       TRUE - 	Disables system requesters.  These are the reasons for
			NOT disabling system requesters:

	                    1- No calls in the program will cause a system
			       requester.
	                    2- The only thing that could cause a requester
			       to appear is the lack of a CD in the drive and
			       SCON_CDReboot is set to CDReboot_On, therefore a
			       requester can't appear.
	    		    3- The only disk I/O is via a CD with SCON_CDReboot
			       set to CDReboot_On and/or nonvolatile.library.

	    		When requesters should not be disabled.
	    		GAME PROGRAMS:
	    		No DOS calls are used after loading; or SCON_CDReboot
			is CDReboot_On; and nonvolatile.library is used for
			loading and saving user data.

	    		This fits the above case since; After loading either
			DOS calls are not used fitting reason 1, or the game
			is accessing the CD and has SCON_CDReboot set to
			CDReboot_On fitting reason 2. The game accesses high
			scores, game position, etc through nonvolatile.library,
			fitting reason 3.

		FALSE -	Enables requesters for the program.

	    This tag nests. Tasks may disable requesters several times before
	    enabling them.  However, there must be a matching number of calls.

	SCON_CDReboot (ULONG)
		CDReboot_On - Ejecting the CD will cause a reboot of the
			system. Use this only if the program cannot deal with
			error conditions.
		CDReboot_Off - Ejecting the CD will not cause a reboot of the
	    		system. Use this if the program needs to insert CDs
			while running.
		CDReboot_Default - Restore the default reboot behavior for this
			system. This should be used upon exit, if this tag had
			been used to change the reboot behaviour. For the CD32
 			this value is synonomous with CDReboot_On. For Amiga
			computers this value is synonomous with CDReboot_Off.

	    Note that the default reboot behavior differs depending on the
	    platform. If a program requires a specific behavior it must
	    use this function to set the behavior. For example, a CD audio
	    mixer would use this tag with the data CDReboot_Off. This will
	    allow the changing of audio CDs on the game machine as well as
	    Amiga computers.

	    If, however, there is no error detection code at all this tag
	    should be used with the data CDReboot_On.

	    It is hoped that no program will require CDReboot_On. If all
	    programs check for error condition and recover gracefully such a
	    call should never be necessary. With the default behavior the
	    CD32 will always reset on disk ejects, and programs
	    run from Amiga computers will not reset. Thus, leaving the
	    default will increase the market for a program to include both
	    types of platforms.

	    This tag does not nest.

	SCON_StopInput (BOOL) - When TRUE, stops input.device from using any
	    CPU cycles. Also prevents input.device from passing along any
	    events from either the keyboard and/or port 0.

	    This tag is task exclusive. This tag is NOT reversible.
	    Attempting to reverse will result in confused/garbled input
	    events.

	SCON_AddCreateKeys (ULONG) - Starts creating rawkey codes for the
	    joystick/game controller on the given unit. The unit value is
	    checked for validity and must be either 0 or 1. Each different unit
	    used results in some code added to the VBlank interrupt chain.
	    This tag nests. The tag SCON_RemCreateKeys is used to undo this
	    tag. Tasks may create rawkey codes several times before stopping
	    them.

	    Note that when operating in an Intuition window, the controller's
	    blue button is the equivilent of the mouse menu button. Therefore,
	    Intuition will be capturing most blue button events. If
	    notificiation of these events is important, review the
	    documentation for WFLG_RMBTRAP in the
	    [intuition.library/OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md) autodoc.

	SCON_RemCreateKeys (ULONG) - stops rawkey codes for the joystick/game
	    controller on the given unit. The unit value is checked for
	    validity and must be either 0 or 1.

   RESULT
	failTag - zero if all tags succeeded. A non-zero return indicates a
		  tag that has failed. It is possible that other tags may
	          fail as well.

	          If any tag fails there will be no change in the system due
	          to other tags.

   SEE ALSO
	[<libraries/lowlevel.h>](autodocs-3.5/include-libraries-lowlevel-h.md)

---

## See Also

- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
