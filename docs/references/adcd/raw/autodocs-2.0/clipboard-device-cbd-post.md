# clipboard.device/CBD_POST



NAME

    CBD_POST -- Post availability of a clip to the clipboard.
FUNCTION

```c
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
```
IO REQUEST

```c
    io_Message      mn_ReplyPort set up
    io_Device       preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      CBD_POST
    io_Data         pointer to satisfy message port
    io_ClipID       zero
```
RESULTS

    io_Error        non-zero if an error occurred
    io_ClipID       the clip ID assigned to this post, to be used
                    in the write command if this is satisfied
