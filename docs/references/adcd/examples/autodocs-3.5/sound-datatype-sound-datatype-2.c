/* Source: ADCD 2.1
 * Section: sound-datatype-sound-datatype
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/sound-datatype-sound-datatype.md
 */

            The sample data does not need to be in CHIP memory and does
            not need to start on a WORD-aligned address. Setting
            SDTA_RightSample to NULL will stop sound replay if sound.datatype
            was started playing with a non-NULL SDTA_RightSample parameter.

            The SDTA_RightSample parameter alone selects mono playback on
            any right sound channel that is currently available. Used
            together with the SDTA_LeftSample parameter, stereo playback
            on any available stereo channels is selected.

            The SDTA_RightSample parameter takes precedence over the
            the SDTA_Sample parameter.

            NOTE: For streaming sound playback, SDTA_LeftSample,
                  SDTA_RightSample, and SDTA_Sample will all be
                  NULL (V44).

            Applicability is (ISG).

        SDTA_SyncSampleChange (BOOL) -- If SDTA_Continuous was set to TRUE,
            sound.datatype will expect a continuous stream of data to be
            played. By specifying "SDTA_SyncSampleChange,TRUE" you request
            that new sound data will be played only if the old data has
            been played completely (otherwise, playback would restart
            immediately with the new sound). If playback is currently in
            progress, the [Task](../Includes_and_Autodocs_3._guide/node064B.html#line23) to change the sample data will be made to
            wait until playback of the old sound has finished.

            Default for this tag is FALSE. Applicability is (IS).

        DTA_Immediate (BOOL) -- Select and query whether playback should
            start immediately after the object has passed the layout
            process.

            Default for this tag is FALSE. Applicability is (ISG).

        DTA_Repeat (BOOL) -- Select and query whether playback should
            loop indefinitely, regardless of the current SDTA_Cycles
            settings.

            Default for this tag is FALSE. Applicability is (ISG).

    NOTES
        You cannot switch between mono and stereo playback on the fly while
        the sound is still playing. First, stop the sound, then change the
        SDTA_Sample/SDTA_LeftSample/SDTA_LeftSample attributes.

        The sound.datatype implementation has been cleaned up for V44 to
        allow for streaming subclasses to be written. Such subclasses will
        always return NULL when their SDTA_LeftSample, SDTA_RightSample and
        SDTA_Sample attributes are queried. However, they will never return
        0 for the SDTA_SampleLength and SDTA_SamplesPerSec attributes since
        these can be used to calculate the length of the entire sample.
        Streaming subclasses will respond to the DTM_TRIGGER method, to
        start, stop playback, etc. but may not support any other methods
        which rely upon the entire sample to reside in memory.
