/* Source: ADCD 2.1
 * Section: intuition-library-setdmrequest
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-setdmrequest.md
 */

    Attempts to set the DMRequest into the specified window.
    The DMRequest is the special requester that you attach to
    the double-click of the menu button which the user can then
    bring up on demand.  This routine WILL NOT change the DMRequest
    if it's already set and is currently active (in use by the user).
    After having called SetDMRequest(), if you want to change the
    DMRequest, the correct way to start is by calling [ClearDMRequest()](../Includes_and_Autodocs_2._guide/node0204.html)
    until it returns a value of TRUE; then you can call SetDMRequest()
    with the new DMRequest.

    If the POINTREL flag is set in the DMRequest, the DMR will open as
    close to the pointer as possible.  The RelLeft/Top fields are
    for fine-tuning the position.
