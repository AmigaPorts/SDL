---
title: intuition.library/SetEditHook
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-setedithook-2
functions: []
libraries: []
---

# intuition.library/SetEditHook

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetEditHook -- Set global processing for string gadgets. (V36)

    SYNOPSIS
	OldHook = SetEditHook( [Hook](autodocs-3.5/include-utility-hooks-h.md) )
	D0                     A0

	struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *SetEditHook( struct [Hook](autodocs-3.5/include-utility-hooks-h.md) * );

    FUNCTION
	Sets new global editing hook for string gadgets.

	WARNING: The use and integration of this function has not
	been explored, and thus should be considered a risky function.
	Do *NOT* use this in a commercial product until further notice.

    INPUTS
	[Hook](autodocs-3.5/include-utility-hooks-h.md) -- A pointer to a struct [Hook](autodocs-3.5/include-utility-hooks-h.md) which determines a function
	  in your code to be called every time the user types a key.
	  This is done before control is passed to the gadget custom
	  editing hook, so affects ALL string gadgets.

    RESULT
	Returns previous global edit hook structure.  You may need this
	hook if you wish to invoke the previous edit hook's behavior
	in addition to your own.

    NOTES
	There are a few key differences between a global edit hook and the
	more famililar per-gadget StringExtend->EditHook field.  In the
	case of the latter, the hook's creator supplies a WorkBuffer.
	Intuition's idea of the result of a keystroke is stored in
	the [SGWork](autodocs-3.5/include-intuition-sghooks-h.md) structure (which references the WorkBuffer).  The
	state of the gadget before Intuition's hook acted is available in
	the StringInfo->Buffer, ->BufferPos, and ->NumChars fields.

	In the case of a global editing hook, your hook _becomes_
	Intuition's hook, which affects all gadgets, most of which
	do not have a WorkBuffer.  This means that if you invoke
	Intuition's original hook (which you got as the result of this
	function), there isn't any easy way for you to "undo" that after
	the fact.  This means that if Intuition's behavior for certain
	keystrokes is incompatible with your hook's objectives, then
	you must avoid calling Intuition's hook for those keys.  One
	approach is to run through your hook's code first, acting on
	those keys you wish to recognize.  Then, call Intuition's
	hook for those keys you do not recognize, or for those keys
	whose default actions you wish to add to.

	Do not forget to set SGA_REDISPLAY when needed (see sghooks.h),
	and please be sure to give the SGWork->EditOp field a value
	which is as meaningful as possible.

	Currently, only SGH_KEY messages are sent to the global edit
	hook, though custom edit hooks do receive SGH_CLICK messages
	in addition.

	Finally, there is currently no arbitration between a global
	edit hook and a custom edit hook as to ownership of keystrokes.
	It would be fair to expect that a custom edit hook would be
	written to match the current Intuition edit hook.  If your
	global edit hook acts on (say) up and down arrow keystrokes,
	an undesirable result may occur if some string gadget's custom
	hook also acts on these keystrokes.  There is currently
	no easy way to resolve this issue.


    BUGS

    SEE ALSO
