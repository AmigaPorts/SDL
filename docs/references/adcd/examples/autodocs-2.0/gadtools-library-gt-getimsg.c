/* Source: ADCD 2.1
 * Section: gadtools-library-gt-getimsg
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gadtools-library-gt-getimsg.md
 */

    Use GT_GetIMsg() in place of the usual [exec.library/GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html) when
    reading IntuiMessages from your window's UserPort.  If needed,
    the GadTools dispatcher will be invoked, and suitable processing
    will be done for gadget actions.  This function returns a pointer
    to a modified [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) (which is a copy of the original,
    possibly with some supplementary information from GadTools).
    If there are no messages (or if the only messages are meaningful
    only to GadTools, NULL will be returned.
