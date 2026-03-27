/* Source: ADCD 2.1
 * Section: intuition-library-buildeasyrequestargs
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-buildeasyrequestargs.md
 */

    This function is to EasyRequest() as [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html) is to
    AutoRequest(): it returns a pointer to the system requester
    window.  The input from that window can then be processed
    under application control.

    It is recommended that this processing be done with
    [SysReqHandler()](../Includes_and_Autodocs_2._guide/node025B.html), so that future enhancement to the
    processing will be enjoyed.

    After you have determined that the requester is satisfied or
    cancelled, you must free this requester using [FreeSysRequest()](../Includes_and_Autodocs_2._guide/node0219.html).

    Please see the autodoc for EasyRequest().

    NOTE: This function switches the processor stack to ensure
    sufficient stack space for the function to complete.
