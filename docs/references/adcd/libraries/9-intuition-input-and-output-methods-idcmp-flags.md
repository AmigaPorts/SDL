---
title: 9 Intuition Input and Output Methods / IDCMP Flags
manual: libraries
chapter: libraries
section: 9-intuition-input-and-output-methods-idcmp-flags
functions: [ModifyIDCMP]
libraries: [intuition.library]
---

# 9 Intuition Input and Output Methods / IDCMP Flags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The application specifies the information it wants Intuition to send to it
via the IDCMP by setting IDCMP flags.  These may be set either when
opening the window or by calling [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md).

The flags set may be viewed as a filter, in that Intuition will only post
[IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)s to an IDCMP if the matching flag is set.  Thus, the
application will only receive the IDCMP messages whose [Class](libraries/9-using-the-idcmp-intuimessages.md) matches one
of the bits set in the window's IDCMP.

For many of these messages, there is a separation of the act of filtering
these messages and causing Intuition to send the messages in the first
place.  For instance, menu help events may be activated for a window by
setting the [WA_MenuHelp](libraries/4-window-attributes-boolean-window-attribute-tags.md) attribute when the window is opened.  However, the
IDCMP will only receive the messages if the [IDCMP_MENUHELP](libraries/9-event-message-classes-and-flags-menu-flags.md) flag is set.
If this flag is not set, then the events are passed downstream in the
input and may be picked up by the console device.

 [Event Message Classes and Flags](libraries/9-idcmp-flags-event-message-classes-and-flags.md)    [Verification Functions](libraries/9-idcmp-flags-verification-functions.md) 

---

## See Also

- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
