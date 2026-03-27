/* Source: ADCD 2.1
 * Section: intuition-library-buildsysrequest
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-buildsysrequest.md
 */

    If the requester was successfully created, the value
    returned by this procedure is a pointer to the window in which the
    requester is rendered.  If the requester could not be created,
    this routine might have called [DisplayAlert()](../Includes_and_Autodocs_2._guide/node020B.html) before returning
    (it depends on the version) and will pass back TRUE if the user
    pressed the left mouse button and FALSE if the user pressed the
    right mouse button.   If the version of Intuition doesn't
    call [DisplayAlert()](../Includes_and_Autodocs_2._guide/node020B.html), or if it does, and there's not enough
    memory for the alert, the value of FALSE is returned.
