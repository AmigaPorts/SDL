/* Source: ADCD 2.1
 * Section: include-datatypes-animationclass-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-datatypes-animationclass-h.md
 */

    ULONG		MethodID;
    ULONG		alf_TimeStamp;		/* Timestamp of frame to load */

    /* The following fields are filled in by the ADTM_NEWLOADFRAME method, */
    /* and are read-only for any other methods. */

    ULONG		alf_Frame;		/* Frame number */
    ULONG		alf_Duration;		/* Duration of frame */

    struct BitMap *	alf_BitMap;		/* Loaded BitMap */
    struct ColorMap *	alf_CMap;		/* Colormap, if changed */

    BYTE *		alf_Sample;		/* Sound data */
    ULONG		alf_SampleLength;
    ULONG		alf_Period;

    APTR		alf_UserData;		/* Used by load frame for extra data */

    ULONG		alf_Size;		/* Size of this data structure (in bytes) */

    BYTE *		alf_LeftSample;		/* Sound for left channel, or NULL if none */
    BYTE *		alf_RightSample;	/* Sound for right channel, or NULL if none */
    ULONG		alf_SamplesPerSec;	/* Replay speed; if > 0, this overrides alf_Period */
