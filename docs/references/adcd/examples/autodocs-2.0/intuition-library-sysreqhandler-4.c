/* Source: ADCD 2.1
 * Section: intuition-library-sysreqhandler
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-sysreqhandler.md
 */

    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) pointer returned from [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html) or
            BuildEasyRequest().  Those functions can also return
            values '0' or '1', and these values may also be
            passed to SysReqHandler(), which will immediately
            return the same value.

    IDCMPFlagsPtr = If you passed application specific IDCMP
            flags to [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html) or BuildEasyRequest(),
            SysReqHandler() will return -1 if that IDCMP message
            is received.  If IDCMPFlagsPtr is non-null, it
            points to a ULONG where the IDCMP class received
            will be copied for your examination.

            This pointer can be NULL if you have provided no
            application specific IDCMP flags or if you do
            not need to know which application specific IDCMP
            event occurred.

            If you provide more than on flag in the flags variable
            this pointer points to, you will have to refresh
            the variable whenever -1 is returned, since the
            variable will have been changed to show just the
            single IDCMP Class bit that caused the return.

    WaitInput = Specifies that you want SysReqHandler() to
            to wait for IDCMP input if there is none pending.
