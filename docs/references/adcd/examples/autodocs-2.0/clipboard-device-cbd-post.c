/* Source: ADCD 2.1
 * Section: clipboard-device-cbd-post
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/clipboard-device-cbd-post.md
 */

    Indicate to the clipboard device that data is available for
    use by accessors of the clipboard.  This is intended to be
    used when a cut is large, in a private data format, and/or
    changing frequently, and it thus makes sense to avoid
    converting it to an IFF form and writing it to the clipboard
    unless another application wants it.  The post provides a
    message port to which the clipboard device will send a satisfy
    message if the data is required.

    If the satisfy message is received, the write associated with
    the post must be performed.  The act of writing the clip
    indicates that the message has been received: it may then be
    re-used by the clipboard device, and so must actually be
    removed from the satisfy message port so that the port is not
    corrupted.

    If the application wishes to determine if a post it has
    performed is still the current clip, it should check the
    post's io_ClipID with that returned by the [CBD_CURRENTREADID](../Includes_and_Autodocs_2._guide/node04DA.html)
    command.  If the current read io_ClipID is greater, the clip
    is not still current.

    If an application has a pending post and wishes to determine
    if it should satisfy it (e.g. before it exits), it should
    check the post's io_ClipID with that returned by the
    [CBD_CURRENTWRITEID](../Includes_and_Autodocs_2._guide/node04DB.html) command.  If the current write io_ClipID is
    greater, there is no need to satisfy the post.
