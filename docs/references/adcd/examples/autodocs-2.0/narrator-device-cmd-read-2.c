/* Source: ADCD 2.1
 * Section: narrator-device-cmd-read
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/narrator-device-cmd-read.md
 */

    As long as the speech is in progress, each read returns the
    following information in the [mouth_rb](../Includes_and_Autodocs_2._guide/node0042.html#line130) [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block.

    If mouth shape changes are requested the following fields are
    modified:
       width  - Contains mouth width value in arbitrary units
       height - Contains mouth height value in arbitrary units
       shape  - Compressed form of mouth shapes (internal use only)

    ******  NEW FOR V37 NARRATOR

    If word synchronization is requested:
       sync   - Bit NDB_WORDSYNC is set

    If syllable synchronization is requested:
       sync   - Bit NDB_SYLSYNC is set

    Note that any or all of the above fields can be set and it is
    the user's responsibility to check for all possibilities.
