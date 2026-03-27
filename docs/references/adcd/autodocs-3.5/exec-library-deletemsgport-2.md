---
title: exec.library/DeleteMsgPort
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-deletemsgport-2
functions: [CreateMsgPort]
libraries: [exec.library]
---

# exec.library/DeleteMsgPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DeleteMsgPort - Free a message port created by [CreateMsgPort](autodocs-3.5/exec-library-createmsgport-2.md)  (V36)

   SYNOPSIS
	DeleteMsgPort(msgPort)
		      a0

	void DeleteMsgPort(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *);

   FUNCTION
	Frees a message port created by [CreateMsgPort()](autodocs-3.5/exec-library-createmsgport-2.md).  All messages that
	may have been attached to this port must have already been
	replied to.

   INPUTS
	msgPort - A message port.  NULL for no action.

   SEE ALSO
	[CreateMsgPort()](autodocs-3.5/exec-library-createmsgport-2.md), [amiga.lib/DeletePort()](autodocs-3.5/amiga-lib-deleteport-2.md)

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
