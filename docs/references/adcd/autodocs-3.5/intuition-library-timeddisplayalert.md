---
title: intuition.library/TimedDisplayAlert
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-timeddisplayalert
functions: [DisplayAlert]
libraries: [intuition.library]
---

# intuition.library/TimedDisplayAlert

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	TimedDisplayAlert -- Display an alert with automatic time-out. (V39)

    SYNOPSIS
	Response = TimedDisplayAlert( AlertNumber, String, Height, Time )
	D0                            D0           A0      D1      A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) TimedDisplayAlert( ULONG, [UBYTE](autodocs-3.5/include-exec-types-h.md) *, [UWORD](autodocs-3.5/include-exec-types-h.md), ULONG );

    FUNCTION
	This function is equivalent to [DisplayAlert()](autodocs-3.5/intuition-library-displayalert-2.md), except that if
	the user fails to respond in a given time, the alert comes
	down automatically.  See the autodoc for [DisplayAlert()](autodocs-3.5/intuition-library-displayalert-2.md) for
	full details.

    INPUTS
	AlertNumber = the number of this alert message.  The only pertinent
	    bits of this number are the ALERT_TYPE bit(s).  The rest of the
           number is ignored by this routine.
	String = pointer to the alert message string, as described above
	Height = minimum display lines required for your message
	Time = length of time the alert should wait for the user to
	    respond.  This time is the number of video frames the
	    alert should remain up for.

    RESULT
	A [BOOL](autodocs-3.5/include-exec-types-h.md) value of TRUE or FALSE.  If this is a DEADEND_ALERT, FALSE
	is always the return value.  If this is a RECOVERY_ALERT. The return
	value will be TRUE if the user presses the left mouse button in
	response to your message, and FALSE if the user presses the right hand
	button is response to your text, or if the alert could not
	be posted.  If the alert times out, the return value will be FALSE.

    BUGS

    SEE ALSO
	[DisplayAlert()](autodocs-3.5/intuition-library-displayalert-2.md)

---

## See Also

- [DisplayAlert — intuition.library](../autodocs/intuition.library.md#displayalert)
